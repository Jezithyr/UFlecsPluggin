// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/FlecsSubsystem.h"

void UFlecsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	OnTickDelegate = FTickerDelegate::CreateUObject(this, &UFlecsSubsystem::Tick);
	OnTickHandle = FTicker::GetCoreTicker().AddTicker(OnTickDelegate);

	//Create the Flecs world immediately after initialization of Game Instance
	CreateECSWorld();

	UE_LOG(LogTemp, Warning, TEXT("UUnrealFlecsSubsystem has started!"));

	Super::Initialize(Collection);
}

void UFlecsSubsystem::Deinitialize()
{
	FTicker::GetCoreTicker().RemoveTicker(OnTickHandle);

	//Destroying the Flecs world as part of the deinitialization of Game Instance
	for (int i = 0; i < worlds.Num(); i++)
	{
		if (worlds[i]) delete worlds[i];
	}
	worlds.Empty();

	UE_LOG(LogTemp, Warning, TEXT("UUnrealFlecsSubsystem has shut down!"));

	Super::Deinitialize();
}

flecs::world* UFlecsSubsystem::GetDefaultEcsWorld() const
{
	//todo: error messages
	return worlds[0];
}

flecs::world* UFlecsSubsystem::GetECSWorldById(int id) const
{
	//todo: error messages
	return worlds[id];
}

int UFlecsSubsystem::CreateECSWorld()
{
	//todo: check if world is already present
	return worlds.Add(new flecs::world());
}

int UFlecsSubsystem::GetECSWorldIndex(flecs::world* world)
{
	//todo: error messages
	return worlds.Find(world);
}

bool UFlecsSubsystem::Tick(float DeltaTime)
{
	// Every Tick we progress Flcs system 
	// and pass the value of Delta Time to the Flecs World
	for (int i = 0; i < worlds.Num(); i++)
	{
		if (worlds[i]) worlds[i]->progress((DeltaTime));
	}
	return true;
}