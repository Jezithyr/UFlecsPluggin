// Copyright by FCR Team

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "flecs.h"
#include "EntityWrapper.generated.h"

/**
 * Contains a mutable reference to an entity for use in blueprint
 */
UCLASS(Transient)
class UFLECS_API UEntityRef : public UObject
{
	GENERATED_BODY()
private:
	flecs::entity Entity;
public:
	UEntityRef()
	{
		Entity = flecs::entity::null();
	}
	void Initialize(flecs::entity targetEntity)
	{
		if (isValid()) //safety check to prevent overriding entity references
		{
			UE_LOG(LogTemp, Error, TEXT("Error cannot override entity reference!"));
			return;
		}
		Entity = targetEntity;
	}

	const bool isValid(){
		return Entity.is_valid();
	};
};
