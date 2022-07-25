// Fill out your copyright notice in the Description page of Project Settings.


#include "NavMeshFindPathTask.h"

#include "MassStateTreeExecutionContext.h"
#include "MassAIBehaviorTypes.h"
#include "NavigationSystem.h"

//#pragma optimize( "", off )


bool FNavMeshFindPathTask::Link(FStateTreeLinker& Linker)
{
	Linker.LinkExternalData(AgentRadiusHandle);
	Linker.LinkExternalData(MoveTargetHandle);
	Linker.LinkExternalData(TransformHandle);
	Linker.LinkExternalData(MovementParamsHandle);

	Linker.LinkInstanceDataProperty(TargetLocationHandle, STATETREE_INSTANCEDATA_PROPERTY(FNavMeshFindPathTaskInstanceData, TargetLocation));
	Linker.LinkInstanceDataProperty(PathPointsHandle, STATETREE_INSTANCEDATA_PROPERTY(FNavMeshFindPathTaskInstanceData, PathPoints));
	Linker.LinkInstanceDataProperty(CurrentPathHandle, STATETREE_INSTANCEDATA_PROPERTY(FNavMeshFindPathTaskInstanceData, CurrentPath));

	return false;
}

EStateTreeRunStatus FNavMeshFindPathTask::EnterState(FStateTreeExecutionContext& Context, const EStateTreeStateChangeType ChangeType, const FStateTreeTransitionResult& Transition) const
{
	const FAgentRadiusFragment& AgentRadius = Context.GetExternalData(AgentRadiusHandle);
	FMassMoveTargetFragment& MoveTarget = Context.GetExternalData(MoveTargetHandle);

	const auto CurrentLocation = Context.GetExternalData(TransformHandle).GetTransform().GetLocation();
	const auto TargetLocation = Context.GetInstanceData(TargetLocationHandle);

	auto NavMeshSubsystem = Cast<UNavigationSystemV1>(Context.GetWorld()->GetNavigationSystem());
	
	const FNavAgentProperties NavAgentProperties(AgentRadius.Radius);
	if (const ANavigationData* NavData = NavMeshSubsystem->GetNavDataForProps(NavAgentProperties))
	{
		FPathFindingQuery PathQuery(NavMeshSubsystem, *NavData, CurrentLocation, TargetLocation);
		if (!PathQuery.NavData.IsValid())
		{
			PathQuery.NavData = NavMeshSubsystem->GetNavDataForProps(NavAgentProperties, PathQuery.StartLocation);
		}

		FPathFindingResult Result = ENavigationQueryResult::Error;
		if (PathQuery.NavData.IsValid())
		{
			Result = PathQuery.NavData->FindPath(NavAgentProperties, PathQuery);
		}
		else
		{
			return EStateTreeRunStatus::Failed;
		}

		auto& PathPoints = Context.GetInstanceData(PathPointsHandle);
		if (!PathPoints.IsEmpty())
		{
			PathPoints.Empty();
		}

		if (Result.IsSuccessful())
		{
			if (Result.Path->GetPathPoints().Num() <= 1)
			{
				return EStateTreeRunStatus::Failed;
			}

			if (PathPoints.GetAllocatedSize() < Result.Path->GetPathPoints().Num())
			{
				PathPoints.Reserve(Result.Path->GetPathPoints().Num());
			}

			for (const FNavPathPoint& NavPathPoint : Result.Path->GetPathPoints())
			{
				PathPoints.Add(NavPathPoint.Location);
			}

			auto& CurrentPath = Context.GetInstanceData(CurrentPathHandle);
			CurrentPath = 0;
			MoveTarget.Center = PathPoints[++CurrentPath];
			MoveTarget.DistanceToGoal = (MoveTarget.Center - CurrentLocation).Size();
			MoveTarget.SlackRadius = 250.f;

			//Result.Path.Get()->DebugDraw(PathQuery.NavData.Get(), FColor::Blue, Context.GetWorld()->GetCanvasForRenderingToTarget(), false, 15.f);
		}
		else
		{
			return EStateTreeRunStatus::Failed;
		}
	}

	return EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FNavMeshFindPathTask::Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const
{

	const auto& TargetLocation = Context.GetInstanceData(TargetLocationHandle);
	auto& MoveTarget = Context.GetExternalData(MoveTargetHandle);
	const auto& PathPoints = Context.GetInstanceData(PathPointsHandle);
	auto& CurrentPath = Context.GetInstanceData(CurrentPathHandle);
	const auto& CurrentLocation = Context.GetExternalData(TransformHandle).GetTransform().GetLocation();

	if (PathPoints.IsEmpty())
	{
		return EStateTreeRunStatus::Failed;
	}

	
	auto bIsLastPoint = static_cast<int32>(CurrentPath) >= PathPoints.Num() - 1;
	MoveTarget.SlackRadius = bIsLastPoint ? 250.f : 70.f;
 
	if ((MoveTarget.DistanceToGoal > MoveTarget.SlackRadius || MoveTarget.Center != PathPoints.Last()))
	{
		if (!bIsLastPoint && MoveTarget.DistanceToGoal <= MoveTarget.SlackRadius)
		{
			MoveTarget.Center = PathPoints[++CurrentPath];
			MoveTarget.DistanceToGoal = (MoveTarget.Center - CurrentLocation).Size();
		}

		return EStateTreeRunStatus::Running;
	}

	return EStateTreeRunStatus::Succeeded;
}


//#pragma optimize( "", on )
