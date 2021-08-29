// Copyright by FCR Team

#pragma once
#include "flecs.h"
#include "CoreMinimal.h"

/**
 * 
 */
class UFLECS_API UFlecsUtils
{
public:
	//variadic to add components to an entity
	template<typename T, typename... Args>
	static void AddComponentsToEntity(flecs::entity target, T comp, Args... args) {
		target.Set<T>(comp);
		AddComponentsToEntity(target, args);
	}
private:
	template<typename T>
	void AddComponentsToEntity(flecs::entity target, T comp) {
		target.Set<T>(comp);
	}
};
