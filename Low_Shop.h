#pragma once
#include "Shop.h"
class CLow_Shop : public CShop
{
public:
	CLow_Shop();
	virtual ~CLow_Shop();
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Release()override;
};

