// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/Lights/PowerGameLight.h"

APowerGameLight::APowerGameLight()
{
	LightMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("LightMeshComponent");
	LightMeshComponent->SetupAttachment(GetRootComponent());
}
