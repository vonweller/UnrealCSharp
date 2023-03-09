﻿#include "Registry/FMultiRegistry.h"

FMultiRegistry::FMultiRegistry()
{
	Initialize();
}

FMultiRegistry::~FMultiRegistry()
{
	Deinitialize();
}

void FMultiRegistry::Initialize()
{
}

void FMultiRegistry::Deinitialize()
{
	GarbageCollectionHandle2SubclassOfAddress.Empty();

	SubclassOfAddress2GarbageCollectionHandle.Empty();
}

bool FMultiRegistry::AddReference(MonoObject* InMonoObject, const FSubclassOfAddress::Type& InValue)
{
	const auto GarbageCollectionHandle = FCSharpEnvironment::GetEnvironment()->GetDomain()->GCHandle_New_WeakRef(
		InMonoObject, true);

	GarbageCollectionHandle2SubclassOfAddress.Emplace(GarbageCollectionHandle,
	                                                  FSubclassOfAddress{nullptr, InValue});

	return true;
}

bool FMultiRegistry::AddReference(void* InAddress, MonoObject* InMonoObject, const FSubclassOfAddress::Type& InValue)
{
	auto GarbageCollectionHandle = FCSharpEnvironment::GetEnvironment()->GetDomain()->GCHandle_New_WeakRef(
		InMonoObject, true);

	SubclassOfAddress2GarbageCollectionHandle.Emplace(InAddress, GarbageCollectionHandle);

	GarbageCollectionHandle2SubclassOfAddress.Emplace(GarbageCollectionHandle,
	                                                  FSubclassOfAddress{InAddress, InValue});

	return true;
}

bool FMultiRegistry::AddReference(MonoObject* InMonoObject, const FWeakObjectPtrAddress::Type& InValue)
{
	const auto GarbageCollectionHandle = FCSharpEnvironment::GetEnvironment()->GetDomain()->GCHandle_New_WeakRef(
		InMonoObject, true);

	GarbageCollectionHandle2WeakObjectPtrAddress.Emplace(GarbageCollectionHandle,
	                                                     FWeakObjectPtrAddress{nullptr, InValue});

	return true;
}

bool FMultiRegistry::AddReference(void* InAddress, MonoObject* InMonoObject, const FWeakObjectPtrAddress::Type& InValue)
{
	auto GarbageCollectionHandle = FCSharpEnvironment::GetEnvironment()->GetDomain()->GCHandle_New_WeakRef(
		InMonoObject, true);

	WeakObjectPtrAddress2GarbageCollectionHandle.Emplace(InAddress, GarbageCollectionHandle);

	GarbageCollectionHandle2WeakObjectPtrAddress.Emplace(GarbageCollectionHandle,
	                                                     FWeakObjectPtrAddress{InAddress, InValue});

	return true;
}
