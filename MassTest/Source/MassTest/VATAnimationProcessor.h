// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassProcessor.h"
#include "MassRepresentationSubsystem.h"
#include "VATAnimationProcessor.generated.h"

/**
 * 
 */
UCLASS()
class MASSTEST_API UVATAnimationProcessor : public UMassProcessor
{
	GENERATED_BODY()

public:
	UVATAnimationProcessor();

protected:
	virtual void ConfigureQueries() override;
	virtual void Initialize(UObject& Owner) override;
	virtual void Execute(UMassEntitySubsystem& EntitySubsystem, FMassExecutionContext& Context) override;

private:
	FMassEntityQuery EntityQuery;
	TObjectPtr<UMassRepresentationSubsystem> RepresentationSubsystem;
};
