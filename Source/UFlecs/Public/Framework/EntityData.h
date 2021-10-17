// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "flecs.h"
#include "CoreMinimal.h"
#include "EntityData.generated.h"

/**
 * 
 */


UINTERFACE(MinimalAPI)
class UHasComponentData : public UInterface {
	GENERATED_BODY()
};

class UFLECS_API IHasComponentData
{
	GENERATED_BODY()
public:
	virtual void GetECSComponents(flecs::entity target) {};
	virtual void SetECSComponents(flecs::entity target) {};
};

UINTERFACE(MinimalAPI)
class UComponentReader : public UInterface {
	GENERATED_BODY()
};

class UFLECS_API IComponentReader
{
	GENERATED_BODY()
public:
	virtual void GetECSComponents(flecs::entity target) {};
};

UINTERFACE(MinimalAPI)
class UComponentWriter : public UInterface {
	GENERATED_BODY()
};

class UFLECS_API IComponentWriter
{
	GENERATED_BODY()
public:
	virtual void SetECSComponents(flecs::entity target) {};
};