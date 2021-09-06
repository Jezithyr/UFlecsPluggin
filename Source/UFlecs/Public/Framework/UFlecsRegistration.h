// Copyright by FCR Team

#pragma once

#include "CoreMinimal.h"
#include "UFlecsRegistration.generated.h"

struct ComponentStruct {};

USTRUCT()
struct FComponentUStruct
{
	GENERATED_BODY();
};

class UFlecsRegContainer
{
public:
	UFLECS_API
		//flecs component registration functions
		static TArray<void (*)(flecs::world&)>& GetFlecsRegs();
		static TMap<UStruct*, void (*)(flecs::entity&, FComponentUStruct&)>& GetFlecsSetters();
		static TMap<UStruct*, const FComponentUStruct* (*)(flecs::entity&)>& GetFlecsGetters();
		static TMap<FString, void (*)(flecs::entity&, ComponentStruct&)>& GetFlecsRawSetters();
		static TMap<FString, const ComponentStruct* (*)(flecs::entity&)>& GetFlecsRawGetters();


		static const FComponentUStruct* GetComponent(UStruct* compType, flecs::entity& target)
		{
			return GetFlecsGetters()[compType](target);
		}

		//set a component struct by UStruct
		static void SetComponent(UStruct* compType,flecs::entity& target, FComponentUStruct& component)
		{
			//TODO: Find a way to grab the UStruct* from the component value
			GetFlecsSetters()[compType](target, component);
		}

		//get a component struct by string
		static const ComponentStruct* GetComponent(FString compType, flecs::entity& target)
		{
			return GetFlecsRawGetters()[compType](target);
		}
		//set a component struct by string
		static void SetComponent(FString compType, flecs::entity& target, ComponentStruct& component)
		{
			GetFlecsRawSetters()[compType](target, component);
		}

};

template<class T>
class UFlecsComponentRegistration
{
	static const FString Name;
	static bool IsReg;
	static bool InitRaw()
	{
		TArray<void (*)(flecs::world&)>& regs = UFlecsRegContainer::GetFlecsRegs();
		auto& setterStructRegs = UFlecsRegContainer::GetFlecsRawSetters();
		auto& getterStructRegs = UFlecsRegContainer::GetFlecsRawGetters();

		void (*func)(flecs::world&);
		func = &FuncReg;
		regs.Add(func);

		//register setter function
		void (*setterFunc)(flecs::entity&, FComponentUStruct&);
		setterFunc = &FuncSetter;
		setterStructRegs.Add(Name, setterFunc);

		//register getter function
		FComponentUStruct* (*getterFunc)(flecs::entity&);
		getterFunc = &FuncGetter;
		getterStructRegs.Add(Name, getterFunc);
		return true;
	}
	static bool Init()
	{
		auto& regs = UFlecsRegContainer::GetFlecsRegs();
		auto& setterUStructRegs = UFlecsRegContainer::GetFlecsSetters();
		auto& getterUStructRegs = UFlecsRegContainer::GetFlecsGetters();

		void (*func)(flecs::world&);
		func = &FuncReg;
		regs.Add(func);

		//register setter function
		void (*setterFunc)(flecs::entity&, FComponentUStruct*);
		setterFunc = &FuncSetter;
		setterUStructRegs.Emplace(T::StaticStruct(),setterFunc);

		//register getter function
		const FComponentUStruct* (*getterFunc)(flecs::entity&);
		getterFunc = &FuncGetter;
		getterUStructRegs.Emplace(T::StaticStruct(),getterFunc);
		return true;
	}
	static void FuncReg(flecs::world& InWorld)
	{
		InWorld.component<T>();
		UE_LOG(LogTemp, Warning, TEXT("FlecsComponent %s is registered"), *Name);
	}
	static const FComponentUStruct* FuncGetter(flecs::entity& target)
	{
		return (const FComponentUStruct*)target.get<T>();
	}
	static void FuncSetter(flecs::entity& target, FComponentUStruct* component)
	{
		T* temp = (T*)(component);
		target.set<T>(*temp);
	}
};


template<class T>
const FString UFlecsComponentRegistration<T>::Name = FString("ComponentName");
template<class T>
bool UFlecsComponentRegistration<T>::IsReg = UFlecsComponentRegistration<T>::Init();

#define FLECS_COMPONENT(Type) \
struct Type; \
const FString UFlecsComponentRegistration<Type>::Name = FString(#Type); \
bool UFlecsComponentRegistration<Type>::IsReg = UFlecsComponentRegistration<Type>::InitRaw(); \
struct Type

#define REG_COMPONENT(Type) \
const FString UFlecsComponentRegistration<Type>::Name = FString(#Type); \
bool UFlecsComponentRegistration<Type>::IsReg = UFlecsComponentRegistration<Type>::Init();