#include "Changeables/MoveVector.h"


AMoveVector::AMoveVector()
{
	PrimaryActorTick.bCanEverTick = false;
	//show actor in edit mode only
	AActor::SetActorHiddenInGame(true);
}



