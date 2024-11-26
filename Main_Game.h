#pragma once
#include "Player_Manager.h"
#include "Field.h"

enum START {NEW = 1, ST_END};
enum MAIN {DUN = 1, SHOP, INVEN, MN_END};
enum FIELD {FD_DUN, FD_SHOP, FD_END};

class CMain_Game
{
public:
	CMain_Game();
	~CMain_Game();
public:
	void Initialize();
	void Update();
	void Release();
public:
	bool Start_Game();
	void Make_Field(FIELD eField);
private:
	CPlayer_Manager* m_pPlayer_Manager;
	CField* m_pField[FD_END];
};

