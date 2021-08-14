// Copyright 2021 Red J


#include "Framework/FlecsBootstrap.h"


#include "Framework/FlecsSubsystem.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AFlecsBootstrap::AFlecsBootstrap()
{	
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AFlecsBootstrap::BeginPlay()
{
	UGameInstance* gameInstance = UGameplayStatics::GetGameInstance(GetWorld());
	UFlecsSubsystem* subSystem = gameInstance->GetSubsystem<UFlecsSubsystem>();

	Bootstrap(*subSystem->GetECSWorldById(worldIndex));
	
	Super::BeginPlay();
}

void AFlecsBootstrap::Bootstrap(flecs::world& ecs)
{
	// Here we initialize flecs systems and components
}