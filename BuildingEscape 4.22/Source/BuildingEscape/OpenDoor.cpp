// Fill out your copyright notice in the Description page of Project Settings.
#include <iostream>

#include "OpenDoor.h"
#include "Gameframework/Actor.h"

#define OUT

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()

{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
    
    Owner = GetOwner();
    
    if (!PressurePlate)
    {
       UE_LOG(LogTemp, Error, TEXT("%s missing pressure plate."), *GetOwner()->GetName());
    }
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume on every frame
    if (GetTotalMassOfActorsOnPlate() >= TriggerMass)
    {
        // if the ActorThatOpens is in the volume - open the door
        OnOpenRequest.Broadcast();
    }
    else
    {
        OnCloseRequest.Broadcast();
    }
}

float UOpenDoor::GetTotalMassOfActorsOnPlate()
{
    float TotalMass = 0.f;
    
    if (!PressurePlate)
    {
        return TotalMass;
    }
    
    // find all the overlapping actors
    TArray<AActor*> OverlappingActors;
    PressurePlate->GetOverlappingActors(OUT OverlappingActors);
    
    // iterate through adding their masses
    for (const auto* Actor : OverlappingActors)
    {
        UE_LOG(LogTemp, Warning, TEXT("%s"), *Actor->GetName());
        TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
    }

    return TotalMass;
}

