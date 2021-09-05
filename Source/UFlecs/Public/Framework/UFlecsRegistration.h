// Copyright by FCR Team

#pragma once

#include "CoreMinimal.h"
#include "UFlecsRegistration.generated.h"

//THIS ONLY SUPPORTS USTRUCTS FOR NOW!

USTRUCT()
struct FComponentStruct
{
	GENERATED_BODY();
};

class UFlecsRegContainer
{
public:
	UFLECS_API
		//flecs component registration functions
		static TArray<void (*)(flecs::world&)>& GetFlecsRegs();
		static TMap<UStruct*, void (*)(flecs::entity&, FComponentStruct&)>& GetFlecsSetters();
		static TMap<UStruct*, FComponentStruct* (*)(flecs::entity&)>& GetFlecsGetters();

		static FComponentStruct* GetComponent(UStruct* compType, flecs::entity& target)
		{
			return GetFlecsGetters()[compType](target);
		}
		static void SetComponent(UStruct* compType,flecs::entity& target, FComponentStruct& component)
		{
			GetFlecsSetters()[compType](target, component);
		}
};

template<class T>
class UFlecsComponentRegistration
{
	static const FString Name;
	static bool IsReg;
	static bool Init()
	{
		void (*func)(flecs::world&);
		func = &FuncReg;
		auto& regs = UFlecsRegContainer::GetFlecsRegs();
		regs.Add(func);

		//register setter function
		void (*setterFunc)(flecs::entity&, FComponentStruct&);
		setterFunc = &FuncSetter;
		auto& setterRegs = UFlecsRegContainer::GetFlecsSetters();
		setterRegs.Add(T::StaticStruct(),setterFunc);

		//register getter function
		FComponentStruct* (*getterFunc)(flecs::entity&);
		getterFunc = &FuncGetter;
		auto& getterRegs = UFlecsRegContainer::GetFlecsGetters();
		getterRegs.Add(T::StaticStruct(),getterFunc);

		return true;
	}
	static void FuncReg(flecs::world& InWorld)
	{
		InWorld.component<T>();
		UE_LOG(LogTemp, Warning, TEXT("FlecsComponent %s is registered"), *Name);
	}
	static FComponentStruct* FuncGetter(flecs::entity& target)
	{
		return target.get<T>();
	}
	static void FuncSetter(flecs::entity& target, FComponentStruct* component)
	{
		T* Cast<T>(component);
		target.set<T>(*component);
	}
};


//TODO: Add macros