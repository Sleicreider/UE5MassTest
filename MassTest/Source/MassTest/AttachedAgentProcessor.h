// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassProcessor.h"
#include "RideBase.h"
#include "AttachedAgentProcessor.generated.h"

USTRUCT()
struct MASSTEST_API FMassRideTag : public FMassTag
{
	GENERATED_BODY()
};

USTRUCT()
struct MASSTEST_API FRideFragment : public FMassFragment
{
	GENERATED_BODY()

	ARideBase* Ride = nullptr;
	int32 SeatIndex = -1;
};

/**
 * 
 */
UCLASS()
class MASSTEST_API UAttachedAgentProcessor : public UMassProcessor
{
	GENERATED_BODY()

public:
	UAttachedAgentProcessor();

protected:
	virtual void ConfigureQueries() override;
	//virtual void Initialize(UObject& Owner) override;
	virtual void Execute(UMassEntitySubsystem& EntitySubsystem, FMassExecutionContext& Context) override;

private:
	FMassEntityQuery EntityQuery;
};
