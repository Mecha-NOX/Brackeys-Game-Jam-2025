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

	void TurnOffAllLights();
	void TurnOnAllLights();
	UFUNCTION(BlueprintCallable)
	void TurnOffWorldLights();
	void TurnOnWorldLights();
	void FlickerLights();
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lights")
	float DefaultWorldLightIntensity = 2.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lights")
	float FlickerLightIntensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lights")
	float MinFlickerDelay = 0.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lights")
	float MaxFlickerDelay = 0.4f;
	
private:
	/*** Game initialisation functionality ***/
	void AddWorldLightsToArray();
	void AddCustomLightsToArray();
	TArray<ULightComponent*> WorldLights;
	TArray<APowerGameLight*> CustomLights;	

	UPROPERTY()
	TObjectPtr<class APowerGameBreaker> Breaker;
	/*** End Game initialisation functionality ***/

	UFUNCTION()
	void DetermineLightState(const EBreakerState BreakerState);

	FTimerHandle FlickerLightTimer;
	float TimeSinceLastFlicker = 0;
	float FlickerDelay = 0;
};

