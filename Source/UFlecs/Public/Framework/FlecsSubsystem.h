// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "flecs.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FlecsSubsystem.generated.h"

/** Unreal engine FLECs subsystem
 * Source: https://jtferson.github.io/blog/quickstart_with_flecs_in_unreal_part_1/
 */
UCLASS()
class UFLECS_API UFlecsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// Getting the default ecs world if we need it
	flecs::world* GetDefaultEcsWorld() const;
	//get an ecs world by id
	flecs::world* GetECSWorldById(int id) const;
	int CreateECSWorld();
	int GetECSWorldIndex(flecs::world* world);
protected:
	// UnrealSubsystem doesn't have a Tick function; instead
	// we use `FTickerDelegate` 
	FTickerDelegate OnTickDelegate;
	FDelegateHandle OnTickHandle;

	// UUnrealFlecsSubsystem contains a pointer to the current Flecs world
	TArray< flecs::world*> worlds;

private:
	//Our custom Tick function used by `FTickerDelegate`
	bool Tick(float DeltaTime);
};