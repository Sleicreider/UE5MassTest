// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassProcessor.h"
#include "HeightTracingProcessor.generated.h"

/**
 * 
 */
UCLASS()
class MASSTEST_API UHeightTracingProcessor : public UMassProcessor
{
	GENERATED_BODY()

public:
	UHeightTracingProcessor();

protected:
	virtual void ConfigureQueries() override;
	virtual void Initialize(UObject& Owner) override;
	virtual void Execute(UMassEntitySubsystem& EntitySubsystem, FMassExecutionContext& Context) override;
	
private:
	FMassEntityQuery EntityQuery;
};
