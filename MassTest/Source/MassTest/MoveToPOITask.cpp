// Fill out your copyright notice in the Description page of Project Settings.

#pragma optimize( "", off )

#include "MoveToPOITask.h"
#include "MassAIBehaviorTypes.h"
#include "MassStateTreeExecutionContext.h"

bool FMoveToPOITask::Link(FStateTreeLinker& Linker)
{
	Linker.LinkExternalData(MoveTargetHandle);
	return true;
}

EStateTreeRunStatus FMoveToPOITask::EnterState(FStateTreeExecutionContext& Context, const EStateTreeStateChangeType ChangeType, const FStateTreeTransitionResult& Transition) const
{
	Context.GetExternalData(MoveTargetHandle);
	MASSBEHAVIOR_LOG(Error, TEXT("MoveToPOI Enter"));
	return EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FMoveToPOITask::Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const
{
	FMassMoveTargetFragment& MoveTarget = Context.GetExternalData(MoveTargetHandle);
	
	if (MoveTarget.DistanceToGoal <= MoveTarget.SlackRadius)
	{
		MASSBEHAVIOR_LOG(Error, TEXT("MoveToPOI Tick Succeeded"));
		return EStateTreeRunStatus::Succeeded;
	}

	MASSBEHAVIOR_LOG(Error, TEXT("MoveToPOI Tick Running"));
	return EStateTreeRunStatus::Running;
}

#pragma optimize( "", on )