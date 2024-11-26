#pragma once
#include "Object.h"
#include "Inven.h"

class CPlayer final : public CObject 
{
public:
	CPlayer();
	CPlayer(const char* szName, int iHp, int iAtk);
	virtual ~CPlayer();
public:
	virtual void Release()override;
public:
	CInven* Get_Inven();
	void Init_Inven(int iMoney);
	void Set_MaxHp();
	void Set_Equip_Stat(int iHp, int iAtk);
public:
	virtual void Render()override;
public:
	bool Move(int (_iMapArray[])[MAP_SIZE], int iInput);
public:
	void Equip_Item(CItem* pItem, ITEM_TYPE eType, int iInput);
	void Unequip_Item(CItem* pItem, ITEM_TYPE eType);
private:
	CInven* m_pInven;
	CItem* m_pItemCheck[ITEM_END];
};

