// Fill out your copyright notice in the Description page of Project Settings.

#include "MovementNavigationProcessor.h"
#include "MassCommonFragments.h"
#include "MassMovementFragments.h"
#include "MassNavigationFragments.h"
#include "MassSimulationLOD.h"
#include "AttachedAgentProcessor.h"

//#pragma optimize( "", off )

UMovementNavigationProcessor::UMovementNavigationProcessor()
{
	//bAutoRegisterWithProcessingPhases = true;
	ExecutionFlags = (int32)EProcessorExecutionFlags::All;
	ExecutionOrder.ExecuteBefore.Add(UE::Mass::ProcessorGroupNames::Avoidance);
}

void UMovementNavigationProcessor::ConfigureQueries()
{
	EntityQuery.AddRequirement<FTransformFragment>(EMassFragmentAccess::ReadOnly);
	EntityQuery.AddRequirement<FMassMoveTargetFragment>(EMassFragmentAccess::ReadWrite);
	//EntityQuery.AddRequirement<FMassSimulationVariableTickFragment>(EMassFragmentAccess::ReadOnly);
	EntityQuery.AddChunkRequirement<FMassSimulationVariableTickChunkFragment>(EMassFragmentAccess::ReadOnly);
	EntityQuery.SetChunkFilter(FMassSimulationVariableTickChunkFragment::ShouldTickChunkThisFrame);
	EntityQuery.AddConstSharedRequirement<FMassMovementParameters>(EMassFragmentPresence::All);
	EntityQuery.AddTagRequirement<FMassRideTag>(EMassFragmentPresence::None);
}

void UMovementNavigationProcessor::Initialize(UObject& Owner)
{
	Super::Initialize(Owner);
	POISubsystem = UWorld::GetSubsystem<UPOISubsystem>(Owner.GetWorld());
	SignalSubsystem = UWorld::GetSubsystem<UMassSignalSubsystem>(Owner.GetWorld());
}

void UMovementNavigationProcessor::Execute(UMassEntitySubsystem& EntitySubsystem, FMassExecutionContext& Context)
{
	TArray<FMassEntityHandle> EntitiesToSignalDone;
	//EntityQuery.ForEachEntityChunk(EntitySubsystem, Context, ([this](FMassExecutionContext& Context)
	//	{
	//		const TConstArrayView<FTransformFragment> TransformList = Context.GetFragmentView<FTransformFragment>();
	//		const TArrayView<FMassMoveTargetFragment> NavTargetList = Context.GetMutableFragmentView<FMassMoveTargetFragment>();
	//		const FMassMovementParameters& MovementParams = Context.GetConstSharedFragment<FMassMovementParameters>();

	//		for (int32 EntityIndex = 0; EntityIndex < Context.GetNumEntities(); EntityIndex++)
	//		{
	//			const FTransform& Transform = TransformList[EntityIndex].GetTransform();
	//			FMassMoveTargetFragment& MoveTarget = NavTargetList[EntityIndex];

	//			FVector CurrentLocation = Transform.GetLocation();
	//			FVector TargetVector = MoveTarget.Center - CurrentLocation;
	//			TargetVector.Z = 0.f;
	//			MoveTarget.DistanceToGoal = TargetVector.Size();
	//			MoveTarget.Forward = TargetVector.GetSafeNormal();
	//			MoveTarget.SlackRadius = 300.f;

	//			if (MoveTarget.DistanceToGoal <= MoveTarget.SlackRadius || MoveTarget.Center == FVector::ZeroVector)
	//			{
	//				if (!POISubsystem->POILocations.IsEmpty())
	//				{
	//					MoveTarget.Center = POISubsystem->POILocations[FMath::RandHelper(POISubsystem->POILocations.Num())];
	//					//MoveTarget.Center = FVector(1.f, 1.f, CurrentLocation.Z); // FVector(FMath::RandRange(-1.f, 1.f) * 1., FMath::RandRange(-1.f, 1.f) * 1., CurrentLocation.Z);
	//					auto Direction = MoveTarget.Center - CurrentLocation;
	//					MoveTarget.DistanceToGoal = Direction.Size();
	//					MoveTarget.Forward = Direction.GetSafeNormal();
	//					MoveTarget.DesiredSpeed = FMassInt16Real(MovementParams.DefaultDesiredSpeed);
	//				}
	//				else
	//				{
	//					MoveTarget.Center = FVector(10, 10, 10);
	//					MoveTarget.DesiredSpeed = FMassInt16Real(0.f);
	//				}
	//			}
	//		}
	//	}));

	EntityQuery.ForEachEntityChunk(EntitySubsystem, Context, ([this, &EntitiesToSignalDone](FMassExecutionContext& Context)
		{
			const TConstArrayView<FTransformFragment> TransformList = Context.GetFragmentView<FTransformFragment>();
			const TArrayView<FMassMoveTargetFragment> NavTargetList = Context.GetMutableFragmentView<FMassMoveTargetFragment>();
			const FMassMovementParameters& MovementParams = Context.GetConstSharedFragment<FMassMovementParameters>();
			//const TConstArrayView<FMassSimulationVariableTickFragment>& VariableTickList = Context.GetFragmentView<FMassSimulationVariableTickFragment>();

			for (int32 EntityIndex = 0; EntityIndex < Context.GetNumEntities(); EntityIndex++)
			{
				const FTransform& Transform = TransformList[EntityIndex].GetTransform();
				FMassMoveTargetFragment& MoveTarget = NavTargetList[EntityIndex];

				if (MoveTarget.DistanceToGoal <= MoveTarget.SlackRadius) //MoveTarget.Center == FVector::ZeroVector)
				{
					//TODO - this signlas should be sent only once but the processor keeps running - either leave check of add a flag to see if target is active
					if (MoveTarget.DistanceToGoal > 0.f)
					{
						EntitiesToSignalDone.Add(Context.GetEntity(EntityIndex));
						MoveTarget.DesiredSpeed = FMassInt16Real(0.f);
						MoveTarget.DistanceToGoal = -1.f;
					}
				}
				else
				{
					FVector CurrentLocation = Transform.GetLocation();
					FVector TargetVector = MoveTarget.Center - CurrentLocation;
					TargetVector.Z = 0.f;
					MoveTarget.DistanceToGoal = TargetVector.Size();
					MoveTarget.Forward = TargetVector.GetSafeNormal();
					//MoveTarget.SlackRadius = 250.f;
					MoveTarget.DesiredSpeed = FMassInt16Real(MovementParams.DefaultDesiredSpeed);
				}
			}
		}));

	if (EntitiesToSignalDone.Num())
	{
		//MASSBEHAVIOR_LOG(Error, TEXT("AdvancedRandom Signal done"));
		SignalSubsystem->SignalEntities(UE::Mass::Signals::FollowPointPathDone, EntitiesToSignalDone);
	}
}

//#pragma optimize( "", on )