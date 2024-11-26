#pragma once
#include "Field.h"
#include "Item.h"

enum DEAL {BUY_WEAPON = 1, BUY_ARMOR, SELL, DEAL_BACK};
enum SHOP_GRADE {SHOP_LOW, SHOP_MIDDLE, SHOP_HIGH, SHOP_END};
class CShop : public CField
{
public:
	CShop();
	virtual ~CShop();
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Release()override;
protected:
	void Make_Shop(SHOP_GRADE eGrade);
	void Render();
	void Buy_Item(ITEM_TYPE eType);
	void Sell_Item();
protected:
	CItem* m_pItem;
	vector<CItem*> m_vecShop;
	CField* m_pShop[SHOP_END];
};
