  
#pragma once
#include "flecs.h"
#include "FlecsModuleBase.generated.h"

UCLASS(Abstract)
class UFLECS_API UFlecsModuleBase : public UObject
{
	GENERATED_BODY()
public:
	virtual void Initialize(flecs::world& ecs);
};