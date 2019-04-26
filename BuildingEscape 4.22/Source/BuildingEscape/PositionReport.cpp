// Fill out your copyright notice in the Description page of Project Settings.

#include "PositionReport.h"
#include "Gameframework/Actor.h"

// Sets default values for this component's properties
UPositionReport::UPositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
    
	// ...
}


// Called when the game starts
void UPositionReport::BeginPlay()
{
	Super::BeginPlay();
    
    // a pointer is a memory address
    FString ObjectName = GetOwner()->GetName();
    FString ObjectPosition = GetOwner()->GetTransform().GetLocation().ToString();
    // *FString syntax converts the data type to char array (dereferences string)
    UE_LOG(LogTemp, Warning, TEXT("%s is at %s!"), *ObjectName, *ObjectPosition);
	
}


// Called every frame
void UPositionReport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

