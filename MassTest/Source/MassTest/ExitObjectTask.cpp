// Fill out your copyright notice in the Description page of Project Settings.


#include "ExitObjectTask.h"
#include "MassCommandBuffer.h"
#include "MassStateTreeExecutionContext.h"
#include "AttachedAgentProcessor.h"

bool FExitObectTask::Link(FStateTreeLinker& Linker)
{
	Linker.LinkExternalData(RideFragmentHandle);
	return true;
}

EStateTreeRunStatus FExitObectTask::EnterState(FStateTreeExecutionContext& Context, const EStateTreeStateChangeType ChangeType, const FStateTreeTransitionResult& Transition) const
{
	auto& RideFragment = Context.GetExternalData(RideFragmentHandle);
	RideFragment.Ride->ExitSeat(RideFragment.SeatIndex);

	const FMassStateTreeExecutionContext& MassContext = static_cast<FMassStateTreeExecutionContext&>(Context);
	MassContext.GetEntitySubsystem().Defer().PushCommand(FCommandRemoveTag(MassContext.GetEntity(), FMassRideTag::StaticStruct()));

	return EStateTreeRunStatus::Succeeded;
}
