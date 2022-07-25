// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeTypes.h"
#include "MassAIBehavior/Public/MassStateTreeTypes.h"
#include "MassSignalSubsystem.h"
#include "SimpleWaitTask.generated.h"


USTRUCT()
struct MASSTEST_API FSimpleWaitTaskInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Parameter)
	float WaitTime;

	/** Accumulated time used to stop task if duration is set */
	UPROPERTY()
	float Time = 0.f;
};

USTRUCT(meta = (DisplayName = "Simple Wait Task"))
struct MASSTEST_API FSimpleWaitTask : public FMassStateTreeTaskBase
{
	GENERATED_BODY()

	virtual bool Link(FStateTreeLinker& Linker) override;
	virtual const UStruct* GetInstanceDataType() const override { return FSimpleWaitTaskInstanceData::StaticStruct(); }

	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const EStateTreeStateChangeType ChangeType, const FStateTreeTransitionResult& Transition) const override;
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;

protected:
	TStateTreeInstanceDataPropertyHandle<float> WaitTimeHandle;
	TStateTreeInstanceDataPropertyHandle<float> TimeHandle;
	TStateTreeExternalDataHandle<UMassSignalSubsystem> MassSignalSubsystemHandle;
};
