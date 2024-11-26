#include "pch.h"
#include "Monster.h"

CMonster::CMonster()
{
}

CMonster::CMonster(const char* szName, int iHp, int iAtk)
	: CObject(szName, iHp, iAtk)
{
}

CMonster::~CMonster()
{
}

void CMonster::Render()
{
	cout << "====================== ���� ======================" << endl;
	cout << "�̸� : " << m_tInfo.szName << endl;
	cout << "ü�� : " << m_tInfo.iHp << "/" << m_tInfo.iMaxHp << endl;
	cout << "���ݷ� : " << m_tInfo.iAtk << endl;
}
