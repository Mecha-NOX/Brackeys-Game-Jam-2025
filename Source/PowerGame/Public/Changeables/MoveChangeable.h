#pragma once

#include "CoreMinimal.h"
#include "ChangeableInterface.h"
#include "GameFramework/Actor.h"
#include "MoveVector.h"
#include "MoveChangeable.generated.h"

UCLASS()
class POWERGAME_API AMoveChangeable : public AActor, public IChangeableInterface
{
	GENERATED_BODY()

public:
	AMoveChangeable();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditInstanceOnly, Category = "Moveable")
	TArray<AMoveVector*> MoveVectors;

	TObjectPtr<AMoveVector> CurrentMoveVector;
protected:
	virtual void BeginPlay() override;

public:
	virtual void Change() override;
};
