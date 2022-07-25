// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "RideBase.h"
#include "BenchSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class MASSTEST_API UBenchSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void AddSocketLocation(FTransform Location);

	UFUNCTION(BlueprintCallable)
	void AddRide(ARideBase* Ride);

public:
	TArray<FTransform> Benches;
	TArray<ARideBase*> Rides;
};


FORCEINLINE void UBenchSubsystem::AddSocketLocation(FTransform Location)
{
	Benches.Add(Location);
}

FORCEINLINE void UBenchSubsystem::AddRide(ARideBase* Ride)
{
	Rides.Add(Ride);
}
