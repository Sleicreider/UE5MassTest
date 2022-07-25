// Fill out your copyright notice in the Description page of Project Settings.


#include "FindObjectTask.h"
#include "MassStateTreeExecutionContext.h"
#include "MassAIBehaviorTypes.h"


bool FFindObjectTask::Link(FStateTreeLinker& Linker)
{
	Linker.LinkExternalData(MoveTargetHandle);
	Linker.LinkExternalData(TransformHandle);
	Linker.LinkExternalData(BenchSubsystemHandle);
	Linker.LinkInstanceDataProperty(BenchTransformHandle, STATETREE_INSTANCEDATA_PROPERTY(FFindBenchInstancedData, BenchTransform));
	Linker.LinkInstanceDataProperty(RideHandle, STATETREE_INSTANCEDATA_PROPERTY(FFindBenchInstancedData, Ride));

	return false;
}

EStateTreeRunStatus FFindObjectTask::EnterState(FStateTreeExecutionContext& Context, const EStateTreeStateChangeType ChangeType, const FStateTreeTransitionResult& Transition) const
{
	auto& MoveTarget = Context.GetExternalData(MoveTargetHandle);
	const auto& Transform = Context.GetExternalData(TransformHandle);
	const auto& BenchSubsystem = Context.GetExternalData(BenchSubsystemHandle);
	auto& BenchTransformData = Context.GetInstanceData(BenchTransformHandle);
	auto& RideData = Context.GetInstanceData(RideHandle);

	RideData = BenchSubsystem.Rides[FMath::RandHelper(BenchSubsystem.Rides.Num())];

	//BenchTransformData = BenchSubsystem.Benches[FMath::RandHelper(BenchSubsystem.Benches.Num())];
	BenchTransformData = RideData->GetActorTransform();
	//MoveTarget.Center = BenchTransformData.GetLocation();
	//MoveTarget.DistanceToGoal = (MoveTarget.Center - Transform.GetTransform().GetLocation()).Size();

	MASSBEHAVIOR_LOG(Error, TEXT("Find Bench Succeeded"));
	return EStateTreeRunStatus::Succeeded;
}
