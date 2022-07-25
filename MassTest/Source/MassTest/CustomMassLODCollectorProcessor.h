// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassLODCollectorProcessor.h"
#include "CustomMassLODCollectorProcessor.generated.h"

/**
 * 
 */
UCLASS()
class MASSTEST_API UCustomMassLODCollectorProcessor : public UMassLODCollectorProcessor
{
	GENERATED_BODY()
public:
	UCustomMassLODCollectorProcessor()
	{
		bAutoRegisterWithProcessingPhases = true;
	}
	
};
