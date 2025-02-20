// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ChangeableInterface.h"
#include "GameFramework/Actor.h"
#include "SwapChangeable.generated.h"

UCLASS()
class POWERGAME_API ASwapChangeable : public AActor, public IChangeableInterface
{
	GENERATED_BODY()

public:
	ASwapChangeable();
	UPROPERTY(EditAnywhere)
	TArray<UStaticMesh*> Meshes;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* MeshComponent;
protected:
	virtual void BeginPlay() override;

public:
	virtual void Change() override;
	
};
