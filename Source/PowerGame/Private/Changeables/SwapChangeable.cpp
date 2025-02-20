// Fill out your copyright notice in the Description page of Project Settings.


#include "Changeables/SwapChangeable.h"

#include "Actor/ActorUtils.h"


// Sets default values
ASwapChangeable::ASwapChangeable()
{
	PrimaryActorTick.bCanEverTick = false;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;


}

// Called when the game starts or when spawned
void ASwapChangeable::BeginPlay()
{
	Super::BeginPlay();

	//set default mesh
	if (Meshes.Num() > 0)
	{
		MeshComponent->SetStaticMesh(Meshes[0]);
	}
}



void ASwapChangeable::Change()
{
	if (ActorUtils::IsActorOnScreen(this))
	{
		return;
	}
	
	// if We have more than 1 mesh get a new random mesh from the array
	if (Meshes.Num() > 1)
	{
		TObjectPtr<UStaticMesh> CurrentMesh = MeshComponent->GetStaticMesh();
		TObjectPtr<UStaticMesh> NewMesh = Meshes[FMath::RandRange(0, Meshes.Num() - 1)];

		while (CurrentMesh == NewMesh)
		{
			NewMesh = Meshes[FMath::RandRange(0, Meshes.Num() - 1)];
		}

		MeshComponent->SetStaticMesh(NewMesh);
	}
}
