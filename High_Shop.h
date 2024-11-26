#pragma once
#include "Shop.h"
class CHigh_Shop : public CShop
{
public:
	CHigh_Shop();
	virtual ~CHigh_Shop();
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Release()override;
};

