// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassStateTreeTypes.h"
#include "TargetDecisionEvaluator.generated.h"

USTRUCT()
struct MASSTEST_API FTargetDecisionEvaluatorInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Output)
	bool bIsTired = false;
};

USTRUCT()
struct MASSTEST_API FTargetDecisionEvaluator : public FMassStateTreeEvaluatorBase
{
	GENERATED_BODY()

protected:
	virtual bool Link(FStateTreeLinker& Linker) override;
	virtual const UStruct* GetInstanceDataType() const override { return FTargetDecisionEvaluatorInstanceData::StaticStruct(); }
	virtual void ExitState(FStateTreeExecutionContext& Context, const EStateTreeStateChangeType ChangeType, const FStateTreeTransitionResult& Transition) const override;
	virtual void Evaluate(FStateTreeExecutionContext& Context, const EStateTreeEvaluationType EvalType, const float DeltaTime) const override;
	void Reset(FStateTreeExecutionContext& Context) const;

	TStateTreeInstanceDataPropertyHandle<bool> IsTiredHandle;

	UPROPERTY(EditAnywhere, Category = Parameter)
	uint32 ChanceOfBeingTired = 50;
};
