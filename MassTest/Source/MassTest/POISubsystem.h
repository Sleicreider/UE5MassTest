// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "POISubsystem.generated.h"

/**
 * 
 */
UCLASS()
class MASSTEST_API UPOISubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddPOILocation(const FVector& Location);

public:
	TArray<FVector> POILocations;
	
};

FORCEINLINE void UPOISubsystem::AddPOILocation(const FVector& Location)
{
	POILocations.Add(Location);
}
