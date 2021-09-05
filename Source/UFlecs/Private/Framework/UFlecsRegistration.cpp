// Copyright by FCR Team


#include "Framework/UFlecsRegistration.h"
TArray<void(*)(flecs::world&)>& UFlecsRegContainer::GetFlecsRegs()
{
	static TArray<void(*)(flecs::world&)> instance;
	return instance;
};

TMap<UStruct*, void (*)(flecs::entity&, FComponentStruct&)>& UFlecsRegContainer::GetFlecsSetters()
{
	static TMap<UStruct*, void (*)(flecs::entity&, FComponentStruct&)> instance;
	return instance;
}

TMap <UStruct*, FComponentStruct* (*)(flecs::entity&)> & UFlecsRegContainer::GetFlecsGetters()
{
	static TMap<UStruct*, FComponentStruct* (*)(flecs::entity&)> instance;
	return instance;
}

