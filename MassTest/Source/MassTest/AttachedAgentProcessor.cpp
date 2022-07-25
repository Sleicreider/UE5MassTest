// Fill out your copyright notice in the Description page of Project Settings.


#include "AttachedAgentProcessor.h"
#include "MassCommonFragments.h"


UAttachedAgentProcessor::UAttachedAgentProcessor()
{
	ExecutionFlags = static_cast<int32>(EProcessorExecutionFlags::All);
}

void UAttachedAgentProcessor::ConfigureQueries()
{
	EntityQuery.AddRequirement<FTransformFragment>(EMassFragmentAccess::ReadWrite);
	EntityQuery.AddRequirement<FRideFragment>(EMassFragmentAccess::ReadOnly);
	EntityQuery.AddTagRequirement<FMassRideTag>(EMassFragmentPresence::All);
}

//void URideCrowdProcessor::Initialize(UObject& Owner)
//{
//
//}

void UAttachedAgentProcessor::Execute(UMassEntitySubsystem& EntitySubsystem, FMassExecutionContext& Context)
{
	EntityQuery.ForEachEntityChunk(EntitySubsystem, Context, ([this](FMassExecutionContext& Context)
		{
			const auto& TransformFragments = Context.GetMutableFragmentView<FTransformFragment>();
			const auto& RideFraments = Context.GetFragmentView<FRideFragment>();

			for (int32 EntityIndex = 0; EntityIndex < Context.GetNumEntities(); EntityIndex++)
			{
				auto& Transform = TransformFragments[EntityIndex].GetMutableTransform();
				auto SeatIndex = RideFraments[EntityIndex].SeatIndex;
				auto TransformRide = RideFraments[EntityIndex].Ride->GetSocketTransform(SeatIndex);
				Transform.SetLocation(TransformRide.GetLocation());
				Transform.SetRotation(TransformRide.GetRotation());
			}
		}));
}
