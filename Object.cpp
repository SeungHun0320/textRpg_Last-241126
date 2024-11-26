#include "pch.h"
#include "Object.h"

CObject::CObject()
{
}

CObject::CObject(const char* szName, int iHp, int iAtk)
{
	strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), szName);
	m_tInfo.iHp = iHp;
	m_tInfo.iMaxHp = m_tInfo.iHp;
	m_tInfo.iAtk = iAtk;
}

CObject::~CObject()
{
}

void CObject::Initialize()
{
}

void CObject::Update()
{
}

void CObject::Release()
{
}

INFO CObject::Get_Info()
{
	return m_tInfo;
}

int CObject::Get_Damage(int iAtk)
{
	int iHp(0);
	return iHp = m_tInfo.iHp - iAtk;
}

void CObject::Set_Hp(int iHp)
{
	m_tInfo.iHp = iHp;
}
