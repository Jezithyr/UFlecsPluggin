// Copyright by FCR Team


#include "Framework/UFlecsRegistration.h"
TArray<void(*)(flecs::world&)>& UFlecsRegContainer::GetFlecsRegs()
{
	static TArray<void(*)(flecs::world&)> instance;
	return instance;
};

TMap<UStruct*, void (*)(flecs::entity&, FComponentUStruct&)>& UFlecsRegContainer::GetFlecsSetters()
{
	static TMap<UStruct*, void (*)(flecs::entity&, FComponentUStruct&)> instance;
	return instance;
}

TMap <UStruct*, FComponentUStruct* (*)(flecs::entity&)> & UFlecsRegContainer::GetFlecsGetters()
{
	static TMap<UStruct*, FComponentUStruct* (*)(flecs::entity&)> instance;
	return instance;
}

TMap<FString, void (*)(flecs::entity&, ComponentStruct&)>& UFlecsRegContainer::GetFlecsRawSetters()
{
	static TMap<FString, void (*)(flecs::entity&, ComponentStruct&)> instance;
	return instance;
}

TMap <FString, ComponentStruct* (*)(flecs::entity&)>& UFlecsRegContainer::GetFlecsRawGetters()
{
	static TMap<FString, ComponentStruct* (*)(flecs::entity&)> instance;
	return instance;
}

