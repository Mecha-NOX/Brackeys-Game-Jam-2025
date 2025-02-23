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
	//TimeSinceLastFlicker += DeltaSeconds;

	//if (TimeSinceLastFlicker >= FlickerDelay)
	//{
	//	FlickerLights();
	//}
	
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

void APowerGameLight::FlickerLights()
{
	FlickerLightIntensity = FMath::RandRange(0.f, 250.f);
	// Flip intensity between two values
	static bool bUseFlickerIntensity = false;
	float NewIntensity = bUseFlickerIntensity ? FlickerLightIntensity : DefaultLightIntensity;
	bUseFlickerIntensity = !bUseFlickerIntensity;

	// Apply intensity to all light components
	for (ULightComponent* Light : LightComponents)
	{
		if (Light)
		{
			Light->SetIntensity(NewIntensity);
		}
	}

	FlickerDelay = FMath::RandRange(MinFlickerDelay, MaxFlickerDelay);
	//GetWorldTimerManager().SetTimer(FlickerLightTimer, this, &ThisClass::FlickerLights, FlickerDelay);

	TimeSinceLastFlicker = 0.0f;
}
