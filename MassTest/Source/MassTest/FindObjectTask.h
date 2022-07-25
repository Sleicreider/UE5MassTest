// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "StateTreeTypes.h"
#include "MassAIBehavior/Public/MassStateTreeTypes.h"
#include "BenchSubsystem.h"
#include "MassNavigationFragments.h"
#include "MassCommonFragments.h"
#include "RideBase.h"
#include "FindObjectTask.generated.h"

USTRUCT()
struct MASSTEST_API FFindBenchInstancedData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Output)
	FTransform BenchTransform;

	UPROPERTY(EditAnywhere, Category = Output)
	ARideBase* Ride;

};

USTRUCT(meta = (DisplayName = "Find Random Bench Socket Task"))
struct MASSTEST_API FFindObjectTask : public FMassStateTreeTaskBase
{
	GENERATED_BODY()

	virtual bool Link(FStateTreeLinker& Linker) override;
	virtual const UStruct* GetInstanceDataType() const override { return FFindBenchInstancedData::StaticStruct(); }

	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const EStateTreeStateChangeType ChangeType, const FStateTreeTransitionResult& Transition) const override;

protected:
	TStateTreeExternalDataHandle<FMassMoveTargetFragment> MoveTargetHandle;
	TStateTreeExternalDataHandle<FTransformFragment> TransformHandle;
	TStateTreeExternalDataHandle<UBenchSubsystem> BenchSubsystemHandle;
	TStateTreeInstanceDataPropertyHandle<FTransform> BenchTransformHandle;
	TStateTreeInstanceDataPropertyHandle<ARideBase*> RideHandle;
};