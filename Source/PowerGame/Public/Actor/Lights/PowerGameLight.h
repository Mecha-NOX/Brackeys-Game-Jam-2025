// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/PowerGameActor.h"
#include "PowerGameLight.generated.h"

/**
 * 
 */
UCLASS()
class POWERGAME_API APowerGameLight : public APowerGameActor
{
	GENERATED_BODY()
	
public:
	APowerGameLight();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lights")
	bool bIsLightOn = false;

	void TurnOff();
	void TurnOn();
	void FlickerLights(float MaxFlickerDelay);

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> LightMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lights")
	int DefaultLightIntensity = 75.f;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lights")
	//float MaxFlickerDelay = 0.7f;

private:
	UPROPERTY()
	TArray<ULightComponent*> LightComponents;

	void StoreLightSources();
};

