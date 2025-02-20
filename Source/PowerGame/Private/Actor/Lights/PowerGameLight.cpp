// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/Lights/PowerGameLight.h"

#include "Components/LightComponent.h"

APowerGameLight::APowerGameLight()
{
	PrimaryActorTick.bCanEverTick = true;
	
	LightMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("LightMeshComponent");
	LightMeshComponent->SetupAttachment(GetRootComponent());
}

void APowerGameLight::BeginPlay()
{
	Super::BeginPlay();

	StoreLightSources();
}

void APowerGameLight::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// Flicker lights here and pulse etc
}

void APowerGameLight::StoreLightSources()
{
	TArray<USceneComponent*> SceneComponents;
	LightMeshComponent->GetChildrenComponents(false, SceneComponents);

	for (USceneComponent* Child : SceneComponents)
	{
		if (ULightComponent* LightComponent = Cast<ULightComponent>(Child))
		{
			LightComponents.Add(LightComponent);
		}
	}
}

void APowerGameLight::TurnOff()
{
	for (ULightComponent* LightComponent : LightComponents)
	{
		LightComponent->SetIntensity(0.f);
	}
}

void APowerGameLight::TurnOn()
{
	for (ULightComponent* LightComponent : LightComponents)
	{
		LightComponent->SetIntensity(DefaultLightIntensity);
	}
}

void APowerGameLight::FlickerLights(float MaxFlickerDelay)
{
	
}
