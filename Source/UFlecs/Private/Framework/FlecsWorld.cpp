// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/FlecsWorld.h"

void UFlecsWorld::Initialize()
{
	ECSWorld = new flecs::world();
}

flecs::world* UFlecsWorld::GetEcsWorld() const
{
	return ECSWorld;
}

UFlecsWorld::~UFlecsWorld()
{
	delete ECSWorld;
}
