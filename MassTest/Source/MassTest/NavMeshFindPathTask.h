// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "StateTreeTypes.h"
#include "MassAIBehavior/Public/MassStateTreeTypes.h"
#include "MassNavigationFragments.h"
#include "MassCommonFragments.h"
#include "MassMovementFragments.h"
#include "AI/Navigation/NavigationTypes.h"

#include "NavMeshFindPathTask.generated.h"

USTRUCT()
struct MASSTEST_API FNavMeshFindPathTaskInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Input)
	FVector TargetLocation;

	UPROPERTY()
	TArray<FVector> PathPoints;

	UPROPERTY()
	uint32 CurrentPath;
};

USTRUCT(meta = (DisplayName = "Find & Move to Path Task"))
struct MASSTEST_API FNavMeshFindPathTask : public FMassStateTreeTaskBase
{
	GENERATED_BODY()

	virtual bool Link(FStateTreeLinker& Linker) override;
	virtual const UStruct* GetInstanceDataType() const override { return FNavMeshFindPathTaskInstanceData::StaticStruct(); }

	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const EStateTreeStateChangeType ChangeType, const FStateTreeTransitionResult& Transition) const override;
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;

protected:
	TStateTreeExternalDataHandle<FAgentRadiusFragment> AgentRadiusHandle;
	TStateTreeExternalDataHandle<FMassMoveTargetFragment> MoveTargetHandle;
	TStateTreeExternalDataHandle<FTransformFragment> TransformHandle;
	TStateTreeExternalDataHandle<FMassMovementParameters> MovementParamsHandle;

	TStateTreeInstanceDataPropertyHandle<FVector> TargetLocationHandle;
	TStateTreeInstanceDataPropertyHandle<TArray<FVector>> PathPointsHandle;
	TStateTreeInstanceDataPropertyHandle<uint32> CurrentPathHandle;
};