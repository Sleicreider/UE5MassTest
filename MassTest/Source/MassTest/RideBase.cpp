// Fill out your copyright notice in the Description page of Project Settings.


#include "RideBase.h"

// Sets default values
ARideBase::ARideBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//SetRootComponent(BaseStaticMesh);
}

// Called when the game starts or when spawned
void ARideBase::BeginPlay()
{
	Super::BeginPlay();

	auto NumSockets = BaseStaticMesh->GetAllSocketNames().Num();
	Seats.Init(true, NumSockets);
	AvailableSeats = NumSockets;
}

uint64 ARideBase::GetNumberOfSockets(USceneComponent* Mesh) const
{
	return Mesh->GetAllSocketNames().Num();
}

int32 ARideBase::GetAvailableSeat() const
{
	for (int32 Index = 0; Index < Seats.Num(); Index++)
	{
		if (Seats[Index])
		{
			return Index;
		}
	}

	return -1;
}

// Called every frame
void ARideBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

