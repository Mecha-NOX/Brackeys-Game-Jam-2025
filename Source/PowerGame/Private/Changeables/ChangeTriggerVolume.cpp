// Fill out your copyright notice in the Description page of Project Settings.

#include "Changeables/ChangeTriggerVolume.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"

void AChangeTriggerVolume::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);

	// Check if the actor that exited is the player
	if (OtherActor && OtherActor->IsA(ACharacter::StaticClass()))
	{
		// Get all overlapping actors
		TArray<AActor*> OverlappingActors;
		GetOverlappingActors(OverlappingActors);

		// Iterate through the overlapping actors
		for (AActor* Actor : OverlappingActors)
		{
			// Check if the actor implements the IChangeableInterface
			IChangeableInterface* ChangeableActor = Cast<IChangeableInterface>(Actor);
			if (ChangeableActor)
			{
				// Call the Change function
				ChangeableActor->Change();
			}
		}
	}
}

