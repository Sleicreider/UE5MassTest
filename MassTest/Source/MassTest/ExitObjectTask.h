// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassAIBehavior/Public/MassStateTreeTypes.h"
#include "AttachedAgentProcessor.h"
#include "ExitObjectTask.generated.h"


USTRUCT()
struct MASSTEST_API FExitObectTaskInstancedData
{
	GENERATED_BODY()

};

USTRUCT(meta = (DisplayName = "Exit Bench Socket Task"))
struct MASSTEST_API FExitObectTask : public FMassStateTreeTaskBase
{
	GENERATED_BODY()

	virtual bool Link(FStateTreeLinker& Linker) override;
	virtual const UStruct* GetInstanceDataType() const override { return FExitObectTaskInstancedData::StaticStruct(); }
	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const EStateTreeStateChangeType ChangeType, const FStateTreeTransitionResult& Transition) const override;

private:
	TStateTreeExternalDataHandle<FRideFragment> RideFragmentHandle;
};