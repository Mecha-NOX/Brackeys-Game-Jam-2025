// Fill out your copyright notice in the Description page of Project Settings.


#include "Changeables/LookAwayChange.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
ALookAwayChange::ALookAwayChange()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALookAwayChange::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALookAwayChange::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PlayerController)
	{
		FVector PlayerLocation = PlayerController->GetPawn()->GetActorLocation();
		FVector PlayerForward = PlayerController->GetPawn()->GetActorForwardVector();
		FVector DirectionToActor = GetActorLocation() - PlayerLocation;
		DirectionToActor.Normalize();

		// Check if actor is behind the player
		float DotProduct = FVector::DotProduct(PlayerForward, DirectionToActor);
		bool bIsBehindPlayer = DotProduct < 0.0f;

		// Check if actor is out of view
		FVector2D ScreenPosition;
		bool bIsOnScreen = PlayerController->ProjectWorldLocationToScreen(GetActorLocation(), ScreenPosition);

		bIsLookingAway = bIsBehindPlayer && !bIsOnScreen;
		Change();
	}
}

void ALookAwayChange::Change()
{
	SetActorHiddenInGame(!bIsLookingAway);
}

