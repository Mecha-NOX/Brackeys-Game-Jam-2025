// Fill out your copyright notice in the Description page of Project Settings.



#include "Actor/Breaker/PowerGameBreaker.h"

#include "Components/PoseableMeshComponent.h"

APowerGameBreaker::APowerGameBreaker()
{
	PrimaryActorTick.bCanEverTick = false;

	BreakerMesh = CreateDefaultSubobject<UPoseableMeshComponent>("BreakerMesh");
	SetRootComponent(BreakerMesh);
}

void APowerGameBreaker::ActivateBreaker(const EBreakerState NewBreakerState)
{
	BreakerState = NewBreakerState;
	OnBreakerActivated.Broadcast();
}
