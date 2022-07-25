// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RideBase.generated.h"

UCLASS()
class MASSTEST_API ARideBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARideBase();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION()
	uint64 GetNumberOfSockets(USceneComponent* Mesh) const;

public:
	FTransform GetSocketTransform(int32 SeatIndex) const;
	void UseSeat(int32 SeatIndex);
	void ExitSeat(int32 SeatIndex);
	bool IsSeatAvailable() const;
	int32 GetAvailableSeat() const;


public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPrimitiveComponent* BaseStaticMesh;

private:
	int32 AvailableSeats;
	TArray<bool> Seats;
};

FORCEINLINE FTransform ARideBase::GetSocketTransform(int32 SeatIndex) const
{
	return BaseStaticMesh->GetSocketTransform(FName(FString("pos_") + FString::FromInt(SeatIndex)));
}

FORCEINLINE bool ARideBase::IsSeatAvailable() const
{
	return AvailableSeats > 0;
}

FORCEINLINE void ARideBase::UseSeat(int32 SeatIndex)
{
	Seats[SeatIndex] = false;
	AvailableSeats--;
}

FORCEINLINE void ARideBase::ExitSeat(int32 SeatIndex)
{
	Seats[SeatIndex] = true;
	AvailableSeats++;
}