// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/Lights/PowerGameLightControllerActor.h"

void APowerGameLightControllerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void APowerGameLightControllerActor::AddLightToArray(APowerGameLight* Light)
{
	Lights.AddUnique(Light);
}

