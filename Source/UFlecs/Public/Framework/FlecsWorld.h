// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "flecs.h"
#include "FlecsWorld.generated.h"

/**
 * 
 */
UCLASS()
class UFLECS_API UFlecsWorld : public UObject
{
	GENERATED_BODY()
	
public:
	void Initialize();
	flecs::world* GetEcsWorld() const;
	~UFlecsWorld();
protected:
	// UUnrealFlecsSubsystem contains a pointer to the current Flecs world
	flecs::world* ECSWorld = nullptr;
};
