
#include "Actor/ActorUtils.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"

bool ActorUtils::IsActorOnScreen(const AActor* Actor)
{
	if (!GEngine || !GEngine->GameViewport || !Actor)
	{
		return false;
	}

	FVector2D ScreenPosition;
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(Actor->GetWorld(), 0);
	if (!PlayerController)
	{
		return false;
	}

	// Project the actor's location to screen coordinates
	bool bIsOnScreen = PlayerController->ProjectWorldLocationToScreen(Actor->GetActorLocation(), ScreenPosition);

	if (bIsOnScreen)
	{
		// Get the viewport size
		FVector2D ViewportSize;
		GEngine->GameViewport->GetViewportSize(ViewportSize);

		// Check if the screen position is within the viewport bounds
		return ScreenPosition.X >= 0 && ScreenPosition.X <= ViewportSize.X &&
			   ScreenPosition.Y >= 0 && ScreenPosition.Y <= ViewportSize.Y;
	}

	return false;
}

bool ActorUtils::IsActorBehindPlayer(const AActor* Actor)
{
	if (!Actor)
	{
		return false;
	}

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(Actor->GetWorld(), 0);
	if (!PlayerController || !PlayerController->GetPawn())
	{
		return false;
	}

	FVector PlayerLocation = PlayerController->GetPawn()->GetActorLocation();
	FVector PlayerForward = PlayerController->GetPawn()->GetActorForwardVector();
	FVector DirectionToActor = Actor->GetActorLocation() - PlayerLocation;
	DirectionToActor.Normalize();

	// Check if actor is behind the player
	float DotProduct = FVector::DotProduct(PlayerForward, DirectionToActor);
	return DotProduct < 0.0f;
}
