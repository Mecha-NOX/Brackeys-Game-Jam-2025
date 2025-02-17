// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/PowerGameActor.h"

// Sets default values
APowerGameActor::APowerGameActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APowerGameActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APowerGameActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

