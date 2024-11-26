#include "pch.h"
#include "Item.h"

CItem::CItem()
{
}

CItem::CItem(const char* szName, int iHp, int iAtk, int iPrice, ITEM_TYPE eType)
{
	strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), szName);
	m_tInfo.iMaxHp = iHp;
	m_tInfo.iAtk = iAtk;
	m_tInfo.iPrice = iPrice;
	m_tInfo.eType = eType;
}

CItem::~CItem()
{
}

void CItem::Initialize()
{
}

void CItem::Update()
{
}

void CItem::Release()
{
}

ITEM_INFO CItem::Get_Info()
{
	return m_tInfo;
}

void CItem::Render()
{
	cout << "====== 정보 ========" << endl;
	cout << "이름 : " << m_tInfo.szName << endl;
	cout << "최대 체력 증가량 : " << m_tInfo.iMaxHp << endl;
	cout << "공격력 증가량 : " << m_tInfo.iAtk << endl;
	cout << "가격 : " << m_tInfo.iPrice << endl;
}
