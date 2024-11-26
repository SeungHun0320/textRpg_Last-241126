#pragma once
#include "Shop.h"

class CMiddle_Shop : public CShop
{
public:
	CMiddle_Shop();
	virtual ~CMiddle_Shop();
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Release()override;
};

