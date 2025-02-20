// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/PowerGameActor.h"
#include "PowerGameLightController.generated.h"


enum EBreakerState : uint8;
class APowerGameLight;
/**
 * 
 */
UCLASS()
class POWERGAME_API APowerGameLightController : public APowerGameActor
{
	GENERATED_BODY()

public:
	APowerGameLightController();
	
protected:
	virtual void BeginPlay() override;
	
private:
	void AddWorldLightsToArray();
	void AddCustomLightsToArray();
	TArray<ULightComponent*> WorldLights;
	TArray<APowerGameLight*> CustomLights;

	UPROPERTY()
	TObjectPtr<class APowerGameBreaker> Breaker;

	UFUNCTION(BlueprintCallable)
	void DetermineLightState(const EBreakerState BreakerState);
};

