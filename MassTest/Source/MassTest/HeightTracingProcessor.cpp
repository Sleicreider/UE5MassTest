// Fill out your copyright notice in the Description page of Project Settings.


#include "HeightTracingProcessor.h"
#include "MassNavigationFragments.h"
#include "MassSimulationLOD.h"
#include "MassCommonFragments.h"
#include "AttachedAgentProcessor.h"

UHeightTracingProcessor::UHeightTracingProcessor()
{
	bAutoRegisterWithProcessingPhases = true;
	ExecutionFlags = (int32)EProcessorExecutionFlags::All;
	ExecutionOrder.ExecuteAfter.Add(UE::Mass::ProcessorGroupNames::Movement);
}

void UHeightTracingProcessor::ConfigureQueries()
{
	//EntityQuery.AddRequirement<FMassMoveTargetFragment>(EMassFragmentAccess::ReadWrite);
	EntityQuery.AddRequirement<FTransformFragment>(EMassFragmentAccess::ReadWrite);
	EntityQuery.AddChunkRequirement<FMassSimulationVariableTickChunkFragment>(EMassFragmentAccess::ReadOnly);
	EntityQuery.SetChunkFilter(FMassSimulationVariableTickChunkFragment::ShouldTickChunkThisFrame);
	EntityQuery.AddTagRequirement<FMassRideTag>(EMassFragmentPresence::None);
}

void UHeightTracingProcessor::Initialize(UObject& Owner)
{

}

void UHeightTracingProcessor::Execute(UMassEntitySubsystem& EntitySubsystem, FMassExecutionContext& Context)
{
	EntityQuery.ForEachEntityChunk(EntitySubsystem, Context, ([this](FMassExecutionContext& Context)
		{
			const TArrayView<FTransformFragment> TransformList = Context.GetMutableFragmentView<FTransformFragment>();
			//const TArrayView<FMassMoveTargetFragment> TargetList = Context.GetMutableFragmentView<FMassMoveTargetFragment>();

			for (int32 EntityIndex = 0; EntityIndex < Context.GetNumEntities(); EntityIndex++)
			{
				FTransform& Transform = TransformList[EntityIndex].GetMutableTransform();
				//FMassMoveTargetFragment& MoveTarget = TargetList[EntityIndex];				

				FHitResult HitResult(ForceInit);
				FCollisionQueryParams TraceParams(TEXT("MassHeight_Trace"));

				GetWorld()->LineTraceSingleByChannel(HitResult, Transform.GetLocation() + FVector(0.f, 0.f, 75.f), Transform.GetLocation() + FVector(0.f, 0.f, -150.f),
					ECollisionChannel::ECC_PhysicsBody, TraceParams);

				auto CurrentLocation = Transform.GetLocation();
				CurrentLocation.Z = HitResult.Location.Z;
				Transform.SetLocation(CurrentLocation);
			}
		}));
}
