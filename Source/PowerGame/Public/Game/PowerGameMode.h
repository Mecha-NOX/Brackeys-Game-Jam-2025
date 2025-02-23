// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PowerGameMode.generated.h"

/**
 * 
 */
UCLASS()
class POWERGAME_API APowerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	
	void SwitchLights(bool bIsOn);
};
