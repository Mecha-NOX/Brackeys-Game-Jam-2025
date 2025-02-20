// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/Lights/PowerGameLightController.h"

#include "Actor/Breaker/PowerGameBreaker.h"
#include "Actor/Lights/PowerGameLight.h"
#include "Components/LightComponent.h"
#include "Engine/PointLight.h"
#include "Engine/SpotLight.h"
#include "Kismet/GameplayStatics.h"

APowerGameLightController::APowerGameLightController()
{
	PrimaryActorTick.bCanEverTick = false;
}

void APowerGameLightController::TurnOfAllLights()
{
	for (ULightComponent* WorldLight : WorldLights)
	{
		WorldLight->SetIntensity(0.f);
	}
	for (APowerGameLight* CustomLight : CustomLights)
	{
		CustomLight->TurnOff();
	}
}

void APowerGameLightController::TurnOnAllLights()
{
	for (ULightComponent* WorldLight : WorldLights)
	{
		WorldLight->SetIntensity(2.f);
	}
	for (APowerGameLight* CustomLight : CustomLights)
	{
		CustomLight->TurnOn();
	}
}

void APowerGameLightController::BeginPlay()
{
	Super::BeginPlay();

	// Store a reference to the breaker and bind to the event
	Breaker = Cast<APowerGameBreaker>(UGameplayStatics::GetActorOfClass(GetWorld(), APowerGameBreaker::StaticClass()));
	if (Breaker)
	{
		Breaker->OnBreakerActivated.AddDynamic(this, &ThisClass::DetermineLightState);
	}

	// Store all lights in the world so we don't need to keep scanning for them, kept separate because our custom lights contain functions
	AddWorldLightsToArray();
	AddCustomLightsToArray();
}

// All of these lights are placed PointLights or SpotLights - excludes the world lighting so as not to shut off the moon
void APowerGameLightController::AddWorldLightsToArray()
{
	TArray<AActor*> SpotlightActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APointLight::StaticClass(), SpotlightActors);

	for (AActor* Actor : SpotlightActors)
	{
		if (APointLight* PointLight = Cast<APointLight>(Actor))
		{
			WorldLights.Add(PointLight->GetLightComponent());
		}
	}

	TArray<AActor*> SpotlightLightsActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpotLight::StaticClass(), SpotlightLightsActors);

	for (AActor* Actor : SpotlightLightsActors)
	{
		if (ASpotLight* SpotLight = Cast<ASpotLight>(Actor))
		{
			WorldLights.Add(SpotLight->GetLightComponent());
		}
	}
}

// All of these lights are going to be based from our BP_LightSource_Base and kept separate so we can manipulate functions on them
void APowerGameLightController::AddCustomLightsToArray()
{
	TArray<AActor*> ActorsToAdd;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APowerGameLight::StaticClass(), ActorsToAdd);

	for (AActor* Actor : ActorsToAdd)
	{
		CustomLights.Add(Cast<APowerGameLight>(Actor));
	}
}

// When the breaker is flipped, we need to know the position of the lever / switch, but also if the fuse is placed or not (tripped)
void APowerGameLightController::DetermineLightState(const EBreakerState BreakerState)
{
	switch (BreakerState)
	{
		case EBS_Off:
			TurnOfAllLights();
			break;
		case EBS_Tripped:
			TurnOfAllLights();
			break;
		case EBS_On:
			TurnOnAllLights();
			break;
		default:
			UE_LOG(LogTemp, Display, TEXT("DetermineLightState: Unknown"));
	}
}