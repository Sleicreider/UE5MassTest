// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "StateTreeTypes.h"
#include "MassAIBehavior/Public/MassStateTreeTypes.h"
#include "MassNavigationFragments.h"
#include "MassCommonFragments.h"
#include "RideBase.h"
#include "AttachedAgentProcessor.h"

#include "UseObjectTask.generated.h"


USTRUCT()
struct MASSTEST_API FUseObjectTaskInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Input)
	FTransform TargetBenchTransform;

	UPROPERTY(EditAnywhere, Category = Input)
	ARideBase* Ride;
};

USTRUCT(meta = (DisplayName = "Use Bench Socket Task"))
struct MASSTEST_API FUseObjectTask : public FMassStateTreeTaskBase
{
	GENERATED_BODY()

	virtual bool Link(FStateTreeLinker& Linker) override;
	virtual const UStruct* GetInstanceDataType() const override { return FUseObjectTaskInstanceData::StaticStruct(); }

	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const EStateTreeStateChangeType ChangeType, const FStateTreeTransitionResult& Transition) const override;


protected:
	TStateTreeExternalDataHandle<FMassMoveTargetFragment> MoveTargetHandle;
	TStateTreeExternalDataHandle<FTransformFragment> TransformHandle;
	TStateTreeExternalDataHandle<FRideFragment> RideFragmentHandle;
	TStateTreeInstanceDataPropertyHandle<FTransform> TargetBenchTransformHandle;
	TStateTreeInstanceDataPropertyHandle<ARideBase*> RideHandle;
};
