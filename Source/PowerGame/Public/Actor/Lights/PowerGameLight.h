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

protected:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> LightMeshComponent;
};
