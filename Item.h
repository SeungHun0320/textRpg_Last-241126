#pragma once

enum ITEM_TYPE {ITEM_WEAPON, ITEM_ARMOR, ITEM_END};

typedef struct tagItemInfo
{
	char szName[32] = "";
	int iMaxHp, iAtk, iPrice;
	ITEM_TYPE eType;
}ITEM_INFO;

class CItem
{
public:
	CItem();
	CItem(const char* szName, int iHp, int iAtk, int iPrice, ITEM_TYPE eType);
	~CItem();
public:
	void Initialize();
	void Update();
	void Release();
public:
	ITEM_INFO Get_Info();
	void Render();
private:
	ITEM_INFO m_tInfo;
};

