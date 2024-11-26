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
	cout << "====================== 정보 ======================" << endl;
	cout << "이름 : " << m_tInfo.szName << endl;
	cout << "체력 : " << m_tInfo.iHp << "/" << m_tInfo.iMaxHp << endl;
	cout << "공격력 : " << m_tInfo.iAtk << endl;
}
