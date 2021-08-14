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

	// Getting the Flecs world if we need it
	flecs::world* GetEcsWorld() const;
protected:
	// UnrealSubsystem doesn't have a Tick function; instead
	// we use `FTickerDelegate` 
	FTickerDelegate OnTickDelegate;
	FDelegateHandle OnTickHandle;

	// UUnrealFlecsSubsystem contains a pointer to the current Flecs world
	flecs::world* ECSWorld = nullptr;

private:
	//Our custom Tick function used by `FTickerDelegate`
	bool Tick(float DeltaTime);
};