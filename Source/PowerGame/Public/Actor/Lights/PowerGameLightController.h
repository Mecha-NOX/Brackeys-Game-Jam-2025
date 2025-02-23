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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lights")
	float DefaultWorldLightIntensity = 2.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lights")
	float FlickerLightIntensity = 0.f;

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

	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess="true"))
	TObjectPtr<class APowerGameBreaker> Breaker;
	/*** End Game initialisation functionality ***/

	void TurnOffAllLights();
	void TurnOnAllLights();
	void TurnOffWorldLights();
	void TurnOnWorldLights();
	void FlickerLights();

	UFUNCTION(BlueprintCallable)
	void DetermineLightState();

	UFUNCTION(BlueprintCallable)
	EBreakerState GetBreakerState() const;

	FTimerHandle FlickerLightTimer;
	float TimeSinceLastFlicker = 0;
	float FlickerDelay = 0;
};



