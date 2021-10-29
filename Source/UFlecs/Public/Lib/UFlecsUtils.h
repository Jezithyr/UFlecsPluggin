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
		target.set<T>(comp);
		AddComponentsToEntity(target, std::forward(args)...);
	}
private:
	template<typename T>
	void AddComponentsToEntity(flecs::entity target, T comp) {
		target.set<T>(comp);
	}
};
