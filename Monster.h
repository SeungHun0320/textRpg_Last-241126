#pragma once
#include "Object.h"

class CMonster : public CObject
{
public:
	CMonster();
	CMonster(const char* szName, int iHp, int iAtk);
	virtual ~CMonster();
public:
	virtual void Render()override;
};

