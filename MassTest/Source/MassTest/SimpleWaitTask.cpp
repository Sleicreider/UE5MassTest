// Fill out your copyright notice in the Description page of Project Settings.

#pragma optimize( "", off )

#include "SimpleWaitTask.h"
#include "MassAIBehaviorTypes.h"
#include "MassStateTreeExecutionContext.h"


bool FSimpleWaitTask::Link(FStateTreeLinker& Linker)
{
	Linker.LinkExternalData(MassSignalSubsystemHandle);

	Linker.LinkInstanceDataProperty(WaitTimeHandle, STATETREE_INSTANCEDATA_PROPERTY(FSimpleWaitTaskInstanceData, WaitTime));
	Linker.LinkInstanceDataProperty(TimeHandle, STATETREE_INSTANCEDATA_PROPERTY(FSimpleWaitTaskInstanceData, Time));
	return true;
}

EStateTreeRunStatus FSimpleWaitTask::EnterState(FStateTreeExecutionContext& Context, const EStateTreeStateChangeType ChangeType, const FStateTreeTransitionResult& Transition) const
{
	auto& Time = Context.GetInstanceData(TimeHandle);
	Time = 0.f;

	auto WaitTime = Context.GetInstanceData(WaitTimeHandle);
	if (WaitTime > 0.0f)
	{
		const auto& MassContext = static_cast<FMassStateTreeExecutionContext&>(Context);

		UMassSignalSubsystem& MassSignalSubsystem = MassContext.GetExternalData(MassSignalSubsystemHandle);
		MassSignalSubsystem.DelaySignalEntity(UE::Mass::Signals::StandTaskFinished, MassContext.GetEntity(), WaitTime);
	}

	MASSBEHAVIOR_LOG(Error, TEXT("WaitTask Enter"));

	return EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FSimpleWaitTask::Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const
{
	auto& WaitTime = Context.GetInstanceData(WaitTimeHandle);
	auto& Time = Context.GetInstanceData(TimeHandle);
	Time += DeltaTime;
	if (Time >= WaitTime)
	{
		MASSBEHAVIOR_LOG(Error, TEXT("WaitTask Tick Succeeded"));
		return EStateTreeRunStatus::Succeeded;
	}
	else
	{
		MASSBEHAVIOR_LOG(Error, TEXT("WaitTask Tick Running"));
		return EStateTreeRunStatus::Running;
	}
}



#pragma optimize( "", on )