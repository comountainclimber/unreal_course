// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber2.h"
#include "DrawDebugHelpers.h"

#define OUT

// Sets default values for this component's properties
UGrabber2::UGrabber2()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber2::BeginPlay()
{
	Super::BeginPlay();
    
    UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty!"));
    
    // Look for attached Physics  Handle
    PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
    if (PhysicsHandle)
    {
        
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("%s missing physics handle component."), *GetOwner()->GetName());
    }
}


// Called every frame
void UGrabber2::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    FVector PlayerViewPointLocation;
    FRotator PlayerViewPointRotation;
	// Get player view point this tick
    GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
        OUT PlayerViewPointLocation,
        OUT PlayerViewPointRotation
    );
    
    // TODO: Log out to test
    // UE_LOG(LogTemp, Warning, TEXT("%s : %s!"), *PlayerViewPointLocation.ToString(), *PlayerViewPointRotation.ToString());
    
    FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
    
    // Draw a red trace in the world to visualize
    DrawDebugLine(
        GetWorld(),
        PlayerViewPointLocation,
        LineTraceEnd,
        FColor(255, 0, 0),
        false,
        0.f, 0.f, 10.f
    );
    
    /// Set up query parameters
    FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
    
    FHitResult Hit;
    // Line-trace (AKA Ray-cast) out to reach distance (private variable)
    GetWorld()->LineTraceSingleByObjectType(
        OUT Hit,
        PlayerViewPointLocation,
        LineTraceEnd,
        FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
        TraceParameters
    );
    
    AActor* ActorHit = Hit.GetActor();
    
    if (ActorHit)
    {
        UE_LOG(LogTemp, Warning, TEXT("%s"), *(ActorHit->GetName()));
    }
    
    // See what we hit
}

