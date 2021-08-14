// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/FlecsSubsystem.h"

void UFlecsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	OnTickDelegate = FTickerDelegate::CreateUObject(this, &UFlecsSubsystem::Tick);
	OnTickHandle = FTicker::GetCoreTicker().AddTicker(OnTickDelegate);

	//Create the Flecs world immediately after initialization of Game Instance
	ECSWorld = new flecs::world();

	UE_LOG(LogTemp, Warning, TEXT("UUnrealFlecsSubsystem has started!"));

	Super::Initialize(Collection);
}

void UFlecsSubsystem::Deinitialize()
{
	FTicker::GetCoreTicker().RemoveTicker(OnTickHandle);

	//Destroying the Flecs world as part of the deinitialization of Game Instance
	if (!ECSWorld) delete(ECSWorld);

	UE_LOG(LogTemp, Warning, TEXT("UUnrealFlecsSubsystem has shut down!"));

	Super::Deinitialize();
}

flecs::world* UFlecsSubsystem::GetEcsWorld() const
{
	return ECSWorld;
}

bool UFlecsSubsystem::Tick(float DeltaTime)
{
	// Every Tick we progress Flcs system 
	// and pass the value of Delta Time to the Flecs World
	if (ECSWorld) ECSWorld->progress(DeltaTime);
	return true;
}