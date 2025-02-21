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

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBreakerActivatedEvent, EBreakerState, BreakerState);

/**
 * 
 */
UCLASS()
class POWERGAME_API APowerGameBreaker : public APowerGameActor
{
	GENERATED_BODY()

public:
	APowerGameBreaker();

	UPROPERTY(BlueprintAssignable, Category="Event")
	FBreakerActivatedEvent OnBreakerActivated;

	UFUNCTION(BlueprintCallable, Category="Breaker")
	void ActivateBreaker(const EBreakerState BreakerState);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Breaker")
	TObjectPtr<UPoseableMeshComponent> BreakerMesh;
};
