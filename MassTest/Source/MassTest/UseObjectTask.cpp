// Fill out your copyright notice in the Description page of Project Settings.


#include "UseObjectTask.h"
#include "MassStateTreeExecutionContext.h"
#include "MassAIBehaviorTypes.h"
#include "MassCommandBuffer.h"

bool FUseObjectTask::Link(FStateTreeLinker& Linker)
{
	Linker.LinkExternalData(MoveTargetHandle);
	Linker.LinkExternalData(TransformHandle);
	Linker.LinkExternalData(RideFragmentHandle);
	Linker.LinkInstanceDataProperty(TargetBenchTransformHandle, STATETREE_INSTANCEDATA_PROPERTY(FUseObjectTaskInstanceData, TargetBenchTransform));
	Linker.LinkInstanceDataProperty(RideHandle, STATETREE_INSTANCEDATA_PROPERTY(FUseObjectTaskInstanceData, Ride));
	return true;
}

EStateTreeRunStatus FUseObjectTask::EnterState(FStateTreeExecutionContext& Context, const EStateTreeStateChangeType ChangeType, const FStateTreeTransitionResult& Transition) const
{


	//const auto& MoveTarget = Context.GetExternalData(MoveTargetHandle);
	auto& Transform = Context.GetExternalData(TransformHandle);
	auto& RideFragment = Context.GetExternalData(RideFragmentHandle);
	auto& BenchTransform = Context.GetInstanceData(TargetBenchTransformHandle);
	auto& Ride = Context.GetInstanceData(RideHandle);
	
	if (Ride->IsSeatAvailable())
	{
		auto SeatIndex = Ride->GetAvailableSeat();
		Ride->UseSeat(SeatIndex);

		const FMassStateTreeExecutionContext& MassContext = static_cast<FMassStateTreeExecutionContext&>(Context);
		MassContext.GetEntitySubsystem().Defer().PushCommand(FCommandAddTag(MassContext.GetEntity(), FMassRideTag::StaticStruct()));

		FTransform NewTransform = BenchTransform;
		NewTransform.SetScale3D(Transform.GetTransform().GetScale3D());
		RideFragment.SeatIndex = SeatIndex;
		RideFragment.Ride = Ride;
		Transform.SetTransform(NewTransform);

		MASSBEHAVIOR_LOG(Error, TEXT("Use Bench Enter Succeeded"));
		return EStateTreeRunStatus::Succeeded;
	}
	
	return EStateTreeRunStatus::Failed;

}