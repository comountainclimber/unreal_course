// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Grabber2.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber2 : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber2();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
    
    
private:
    // How far ahead of the player can we reach in cm
    float Reach = 100.f;
    
    UPhysicsHandleComponent* PhysicsHandle = nullptr;
    
    UInputComponent* InputComponent = nullptr;
    
    // Raycast and grab what is in reach
    void Grab();
    
    // Called when grab is released
    void Release();
    
    // Find (assumed) attached phsyics handle
    void FindPhysicsHandleComponent();
    
    // Setup (assumed) attached input component
    void SetupInputComponent();
    
    // Return hit for first physics body in reach
    FHitResult GetFirstPhysicsBodyInReach() const;
};
