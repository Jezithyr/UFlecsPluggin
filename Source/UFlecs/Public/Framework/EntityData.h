// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Flecs.h"
#include "CoreMinimal.h"
#include "EntityData.generated.h"

/**
 * 
 */
USTRUCT()
struct UFLECS_API FEntityData
{
GENERATED_BODY()
public:
	virtual void ReadComponents(flecs::entity* target){};
	virtual void SetComponents(flecs::entity* target){};
};
