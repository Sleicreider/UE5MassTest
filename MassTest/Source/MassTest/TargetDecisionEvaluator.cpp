// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetDecisionEvaluator.h"
#include "MassStateTreeExecutionContext.h"


bool FTargetDecisionEvaluator::Link(FStateTreeLinker& Linker)
{
	Linker.LinkInstanceDataProperty(IsTiredHandle, STATETREE_INSTANCEDATA_PROPERTY(FTargetDecisionEvaluatorInstanceData, bIsTired));
	return true;
}

void FTargetDecisionEvaluator::ExitState(FStateTreeExecutionContext& Context, const EStateTreeStateChangeType ChangeType, const FStateTreeTransitionResult& Transition) const
{
	if (ChangeType != EStateTreeStateChangeType::Changed)
	{
		return;
	}

	Reset(Context);
}

void FTargetDecisionEvaluator::Evaluate(FStateTreeExecutionContext& Context, const EStateTreeEvaluationType EvalType, const float DeltaTime) const
{
	if (EvalType == EStateTreeEvaluationType::PreSelect)
	{
		Context.GetInstanceData(IsTiredHandle) = static_cast<uint32>(FMath::RandHelper(100)) < ChanceOfBeingTired;
	}
}

void FTargetDecisionEvaluator::Reset(FStateTreeExecutionContext& Context) const
{
	Context.GetInstanceData(IsTiredHandle) = false;
}
