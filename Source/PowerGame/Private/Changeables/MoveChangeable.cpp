#include "Changeables/MoveChangeable.h"

#include "Actor/ActorUtils.h"
#include "Kismet/GameplayStatics.h"


AMoveChangeable::AMoveChangeable()
{
	PrimaryActorTick.bCanEverTick = false;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;
}

void AMoveChangeable::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMoveChangeable::Change()
{
	if (ActorUtils::IsActorOnScreen(this))
	{
		return;
	}

	if (MoveVectors.Num() > 0)
	{
		TObjectPtr<AMoveVector> NewMoveVector = MoveVectors[FMath::RandRange(0, MoveVectors.Num() - 1)];
		while (NewMoveVector == CurrentMoveVector)
		{
			NewMoveVector = MoveVectors[FMath::RandRange(0, MoveVectors.Num() - 1)];
		}
		CurrentMoveVector = NewMoveVector;
		SetActorLocation(CurrentMoveVector->GetActorLocation());
		SetActorRotation(CurrentMoveVector->GetActorRotation());
	}
}


