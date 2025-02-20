#pragma once

#include "CoreMinimal.h"

class POWERGAME_API ActorUtils
{
public:
	static bool IsActorOnScreen(const AActor* Actor);

	static bool IsActorBehindPlayer(const AActor* Actor);
};
