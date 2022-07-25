// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "StateTreeTypes.h"
#include "MassAIBehavior/Public/MassStateTreeTypes.h"
#include "MassNavigationFragments.h"
#include "MassCommonFragments.h"
#include "POISubsystem.h"
#include "FindPOITask.generated.h"

USTRUCT()
struct MASSTEST_API FFindPOITaskInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Output)
	FVector TargetLocation;
};

USTRUCT(meta = (DisplayName = "Find Random POI Task"))
struct MASSTEST_API FFindPOITask : public FMassStateTreeTaskBase
{
	GENERATED_BODY()

	virtual bool Link(FStateTreeLinker& Linker) override;
	virtual const UStruct* GetInstanceDataType() const override { return FFindPOITaskInstanceData::StaticStruct(); }

	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const EStateTreeStateChangeType ChangeType, const FStateTreeTransitionResult& Transition) const override;

protected:
	TStateTreeExternalDataHandle<FMassMoveTargetFragment> MoveTargetHandle;
	TStateTreeExternalDataHandle<FTransformFragment> TransformHandle;
	TStateTreeExternalDataHandle<UPOISubsystem> POISubsystemHandle;
	TStateTreeInstanceDataPropertyHandle<FVector> TargetLocationHandle;
};
