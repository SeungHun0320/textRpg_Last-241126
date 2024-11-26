#pragma once
#include "define.h"
#include "Player_Manager.h"

enum GRADE {LOW = 1, MIDDLE, HIGH, GD_BACK};

class CField
{
public:
	CField();
	virtual ~CField();
public:
	virtual void Initialize();
	virtual void Update()PURE;
	virtual void Release()PURE;
public:
	void Set_Player_Manager(CPlayer_Manager* pPlayer_Manager);
protected:
	CPlayer_Manager* m_pPlayer_Manager;
};

