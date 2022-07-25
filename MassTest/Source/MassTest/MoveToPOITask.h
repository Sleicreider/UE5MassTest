// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeTypes.h"
#include "MassAIBehavior/Public/MassStateTreeTypes.h"
#include "MassNavigationFragments.h"
#include "MoveToPOITask.generated.h"


USTRUCT()
struct MASSTEST_API FMoveToPOITaskInstanceData
{
	GENERATED_BODY()
};

USTRUCT(meta = (DisplayName = "Move To POI"))
struct MASSTEST_API FMoveToPOITask : public FMassStateTreeTaskBase
{
	GENERATED_BODY()

	virtual bool Link(FStateTreeLinker& Linker) override;
	virtual const UStruct* GetInstanceDataType() const override { return FMoveToPOITaskInstanceData::StaticStruct(); }

	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const EStateTreeStateChangeType ChangeType, const FStateTreeTransitionResult& Transition) const override;
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;

protected:
	TStateTreeExternalDataHandle<FMassMoveTargetFragment> MoveTargetHandle;
};
