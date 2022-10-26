﻿#pragma once

#include "Reflection/Property/FPropertyDescriptor.h"

class FObjectPropertyDescriptor : public FPropertyDescriptor
{
public:
	using FPropertyDescriptor::FPropertyDescriptor;

public:
	virtual void Get(void* Src, void* Dest) const override;

	virtual void Set(void* Src, void* Dest) const override;

	virtual void Get(UObject* Src, void* Dest) const override;

	virtual void Set(void* Src, UObject* Dest) const override;
};
