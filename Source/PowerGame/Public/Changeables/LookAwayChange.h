// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChangeableInterface.h"
#include "LookAwayChange.generated.h"

UCLASS()
class POWERGAME_API ALookAwayChange : public AActor, public IChangeableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALookAwayChange();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Change() override;
	bool bIsLookingAway;
	
};
