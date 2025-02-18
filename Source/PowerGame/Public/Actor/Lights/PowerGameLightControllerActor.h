// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/PowerGameActor.h"
#include "PowerGameLightControllerActor.generated.h"

class APowerGameLight;
/**
 * 
 */
UCLASS()
class POWERGAME_API APowerGameLightControllerActor : public APowerGameActor
{
	GENERATED_BODY()

public:
	
protected:
	virtual void BeginPlay() override;
	
private:
	void AddLightToArray(APowerGameLight* Light);
	TArray<APowerGameLight*> Lights;
};
