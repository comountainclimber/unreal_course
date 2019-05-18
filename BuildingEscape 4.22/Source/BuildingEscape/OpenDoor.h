// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/TriggerVolume.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
    
    UPROPERTY(BlueprintAssignable)
    FDoorEvent OnOpenRequest;
    
    UPROPERTY(BlueprintAssignable)
    FDoorEvent OnCloseRequest;
    
private:
    // UPROPERTY macro allows these to be configurable in the editor
    UPROPERTY(EditAnywhere)
    ATriggerVolume* PressurePlate;
    
    UPROPERTY(EditAnywhere)
    float TriggerMass = 50.f;
    
    AActor* Owner = nullptr;
    
    float GetTotalMassOfActorsOnPlate();
};
