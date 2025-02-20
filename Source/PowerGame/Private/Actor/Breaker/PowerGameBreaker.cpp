// Fill out your copyright notice in the Description page of Project Settings.



#include "Actor/Breaker/PowerGameBreaker.h"

APowerGameBreaker::APowerGameBreaker()
{
	PrimaryActorTick.bCanEverTick = false;
}

void APowerGameBreaker::ActivateBreaker(const EBreakerState BreakerState)
{
	OnBreakerActivated.Broadcast(BreakerState);
}
