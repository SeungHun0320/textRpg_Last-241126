#pragma once
#include "Object.h"

enum JOB {WARRIOR = 1, MAGE, THIEF, WERTCH};

class CPlayer_Manager
{
public:
	CPlayer_Manager();
	~CPlayer_Manager();
public:
	void Initialize();
	void Update();
	void Release();
public:
	CObject* Get_Player();
private:
	CObject* m_pPlayer;
};

