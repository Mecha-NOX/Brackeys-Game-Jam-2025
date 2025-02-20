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

	void TurnOfAllLights();
	void TurnOnAllLights();
	
protected:
	virtual void BeginPlay() override;
	
private:
	/*** Game initialisation functionality ***/
	void AddWorldLightsToArray();
	void AddCustomLightsToArray();
	TArray<ULightComponent*> WorldLights;
	TArray<APowerGameLight*> CustomLights;	

	UPROPERTY()
	TObjectPtr<class APowerGameBreaker> Breaker;
	/*** End Game initialisation functionality ***/

	UFUNCTION(BlueprintCallable)
	void DetermineLightState(const EBreakerState BreakerState);
};

