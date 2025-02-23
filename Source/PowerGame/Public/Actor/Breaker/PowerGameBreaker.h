// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/PowerGameActor.h"
#include "PowerGameBreaker.generated.h"

class UPoseableMeshComponent;

UENUM()
enum EBreakerState : uint8
{
	EBS_Off UMETA(DisplayName = "Off"),
	EBS_Tripped UMETA(DisplayName = "Tripped"),
	EBS_On UMETA(DisplayName = "On"),
	EBS_MAX UMETA(DisplayName = "DefaultMAX"),
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBreakerActivatedEvent);

/**
 * 
 */
UCLASS()
class POWERGAME_API APowerGameBreaker : public APowerGameActor
{
	GENERATED_BODY()

public:
	APowerGameBreaker();

	UPROPERTY()
	FBreakerActivatedEvent OnBreakerActivated;

	UFUNCTION(BlueprintCallable, Category="Breaker")
	void ActivateBreaker(const EBreakerState NewBreakerState);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Breaker")
	TObjectPtr<UPoseableMeshComponent> BreakerMesh;

	// TODO IDEA - Use curves to change the way the door opens, fast & furious or slow and subtle.. or a mix, can use many curves for many effects
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Breaker")
	TObjectPtr<UCurveFloat> BreakerCurve;

private:
	UPROPERTY()
	TEnumAsByte<EBreakerState> BreakerState;

	// Getters & Setters
public:
	EBreakerState GetBreakerState() const {return BreakerState;}
};
