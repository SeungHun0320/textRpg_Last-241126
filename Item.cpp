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
	cout << "====== ���� ========" << endl;
	cout << "�̸� : " << m_tInfo.szName << endl;
	cout << "�ִ� ü�� ������ : " << m_tInfo.iMaxHp << endl;
	cout << "���ݷ� ������ : " << m_tInfo.iAtk << endl;
	cout << "���� : " << m_tInfo.iPrice << endl;
}
