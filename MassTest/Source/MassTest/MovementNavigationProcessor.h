// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassProcessor.h"
#include "POISubsystem.h"
#include "MassSignalSubsystem.h"
#include "MovementNavigationProcessor.generated.h"

/**
 * 
 */
UCLASS()
class MASSTEST_API UMovementNavigationProcessor : public UMassProcessor
{
	GENERATED_BODY()

public:
	UMovementNavigationProcessor();

protected:
	virtual void ConfigureQueries() override;
	virtual void Initialize(UObject& Owner) override;
	virtual void Execute(UMassEntitySubsystem& EntitySubsystem, FMassExecutionContext& Context) override;

private:
	FMassEntityQuery EntityQuery;
	TObjectPtr<UPOISubsystem> POISubsystem;
	TObjectPtr<UMassSignalSubsystem> SignalSubsystem;
};
