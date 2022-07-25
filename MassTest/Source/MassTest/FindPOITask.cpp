// Fill out your copyright notice in the Description page of Project Settings.

#pragma optimize( "", off )

#include "FindPOITask.h"
#include "MassStateTreeExecutionContext.h"
#include "MassAIBehaviorTypes.h"

bool FFindPOITask::Link(FStateTreeLinker& Linker)
{
	Linker.LinkExternalData(MoveTargetHandle);
	Linker.LinkExternalData(TransformHandle);
	Linker.LinkExternalData(POISubsystemHandle);
	Linker.LinkInstanceDataProperty(TargetLocationHandle, STATETREE_INSTANCEDATA_PROPERTY(FFindPOITaskInstanceData, TargetLocation));

	return true;
}

EStateTreeRunStatus FFindPOITask::EnterState(FStateTreeExecutionContext& Context, const EStateTreeStateChangeType ChangeType, const FStateTreeTransitionResult& Transition) const
{
	FMassMoveTargetFragment& MoveTarget = Context.GetExternalData(MoveTargetHandle);
	FTransformFragment& Transform = Context.GetExternalData(TransformHandle);
	const UPOISubsystem& POISubystem = Context.GetExternalData(POISubsystemHandle);
	Context.GetInstanceData(TargetLocationHandle) = POISubystem.POILocations[FMath::RandHelper(POISubystem.POILocations.Num())];

	/*MoveTarget.Center = POISubystem.POILocations[FMath::RandHelper(POISubystem.POILocations.Num())];
	MoveTarget.DistanceToGoal = (MoveTarget.Center - Transform.GetTransform().GetLocation()).Size();*/

	MASSBEHAVIOR_LOG(Error, TEXT("FindPOI Enter"));
	return EStateTreeRunStatus::Succeeded;
}

#pragma optimize( "", on )