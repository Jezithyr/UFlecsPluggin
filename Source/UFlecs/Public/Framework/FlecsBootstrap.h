#pragma once

#include "CoreMinimal.h"

#include "flecs.h"
#include "GameFramework/Actor.h"
#include "FlecsBootstrap.generated.h"

UCLASS()
class UFLECS_API AFlecsBootstrap : public AActor
{
	GENERATED_BODY()
	public:
	AFlecsBootstrap();

	protected:
	virtual void BeginPlay() override;
	virtual void Bootstrap(flecs::world& ecs);
};