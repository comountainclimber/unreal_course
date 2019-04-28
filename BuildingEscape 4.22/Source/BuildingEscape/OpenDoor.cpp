// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "Gameframework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()

{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UOpenDoor::OpenDoor()
{
    AActor* Owner = GetOwner();

    // Create a rotator
    FRotator NewRotation = FRotator(0.0f, -60.0f, 0.0f);

    // Set the door rotation
    Owner->SetActorRotation(NewRotation);
}

// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
    
    // Top down from world to the player controller to the pawn
    ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume on every frame
    if (PressurePlate->IsOverlappingActor(ActorThatOpens))
    {
        // if the ActorThatOpens is in the volume - open the door
        OpenDoor();
    }
}

