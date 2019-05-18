// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber2.h"
#include "DrawDebugHelpers.h"

#define OUT

// TODO: Rename to UGrabber or update existing class

// Sets default values for this component's properties
UGrabber2::UGrabber2()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UGrabber2::BeginPlay()
{
	Super::BeginPlay();
    FindPhysicsHandleComponent();
    SetupInputComponent();
}

void UGrabber2::Grab()
{
    UE_LOG(LogTemp, Warning, TEXT("Grabbing!"));
    
    // LINE TRACE and try and reach any actors with physics body collision channel set
    auto HitResult = GetFirstPhysicsBodyInReach();
    auto ComponentToGrab = HitResult.GetComponent();
    auto ActorHit = HitResult.GetActor();
    
    if (ActorHit) {
        // If we hit something than attach a phsyics handle
        // attach physics handle
        PhysicsHandle->GrabComponent(ComponentToGrab, NAME_None, ComponentToGrab->GetOwner()->GetActorLocation(), true);
    }
}

void UGrabber2::Release()
{
    UE_LOG(LogTemp, Warning, TEXT("Releasing!"));
    
    // TODO release phsyics handle
}

// Look for attached Input Component and bind controls
void UGrabber2::SetupInputComponent()
{
    InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
    if (InputComponent)
    {
        UE_LOG(LogTemp, Warning, TEXT("Input component found!"));
        
        // Bind the input axix
        // & is the address of operator
        InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber2::Grab);
        InputComponent->BindAction("Grab", IE_Released, this, &UGrabber2::Release);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("%s missing input component."), *GetOwner()->GetName());
    }
}

// Look for attached Physics  Handle
void UGrabber2::FindPhysicsHandleComponent()
{
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
    
        FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
    
    // if the phsyics handle is attached
    if (PhysicsHandle->GrabbedComponent) {
        PhysicsHandle->SetTargetLocation(LineTraceEnd);
    }
        // move the object we are grabbing

}



FHitResult UGrabber2::GetFirstPhysicsBodyInReach() const
{ 

    FVector PlayerViewPointLocation;
    FRotator PlayerViewPointRotation;
    // Get player view point this tick
    GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
        OUT PlayerViewPointLocation,
        OUT PlayerViewPointRotation
    );

    // UE_LOG(LogTemp, Warning, TEXT("%s : %s!"), *PlayerViewPointLocation.ToString(), *PlayerViewPointRotation.ToString());
        
    FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
        
    // Draw a red trace in the world to visualize
    //    DrawDebugLine(
    //        GetWorld(),
    //        PlayerViewPointLocation,
    //        LineTraceEnd,
    //        FColor(255, 0, 0),
    //        false,
    //        0.f, 0.f, 10.f
    //    );
        
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
    return Hit;
}
