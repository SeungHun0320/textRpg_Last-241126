#pragma once
#include "define.h"
#include "Player_Manager.h"
#include "Item.h"

enum INVEN {EQUIP = 1, UNEQUIP, SORT, INVEN_BACK};
enum UNEQUIP {UN_WEAPON = 1, UN_ARMOR, UN_BACK};
enum SORT {SORT_BACK, SORT_ATK, SORT_HP, SORT_PRICE, SORT_NAME};
enum SORT_SELECT {LESS = 1, GREATER, SS_BACK};

class CInven
{
public:
	CInven();
	CInven(int iMoney);
	~CInven();
public:
	void Initialize();
	void Update();
	void Release();
public:
	int Get_Money();
	void Set_Money(int iMoney);
	vector<CItem*>* Get_Vector();
	void Set_Player_Manager(CPlayer_Manager* pPlayer_Manager);
	void Set_Equip_Item(CItem* pItem, ITEM_TYPE eType);
public:
	void Render();
	void Equip_Render();
public:
	void Storage_Item(CItem* pItem);
	void Delete_Item(int iInput);
private:
	void Equip_Menu();
	void Unequip_Menu();
	void Unequip_Item(ITEM_TYPE eType);
	void Sort_Menu();
private:
	void Sort_Atk();
	void Sort_Hp();
	void Sort_Price();
	void Sort_Name();

private:
	int m_iMoney;
	vector<CItem*> m_vecInven;
	CPlayer_Manager* m_pPlayer_Manager;
	CItem* m_pEquipItem[ITEM_END];
};

