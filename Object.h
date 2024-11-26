#pragma once
#include "define.h"

typedef struct tagInfo
{
	char szName[32] = "";
	int iHp, iMaxHp, iAtk;
}INFO;

class CObject abstract
{
public:
	CObject();
	CObject(const char* szName, int iHp, int iAtk);
	virtual ~CObject();
public:
	void Initialize();
	void Update();
	virtual void Release();
public:
	INFO Get_Info();
	int Get_Damage(int iAtk);
	void Set_Hp(int iHp);
public:
	virtual void Render()PURE;
protected:
	INFO m_tInfo;
};

