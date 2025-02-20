// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "ChangeableInterface.h"
#include "ChangeTriggerVolume.generated.h"

UCLASS()
class POWERGAME_API AChangeTriggerVolume : public ATriggerVolume
{
	GENERATED_BODY()

protected:
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;
};
