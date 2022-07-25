// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassEntityTypes.h"
#include "AgentFragment.generated.h"

USTRUCT()
struct MASSTEST_API FAgentFragment : public FMassFragment
{
	GENERATED_BODY()

	float SkinIndex = -1;
};