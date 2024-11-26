#pragma once
#include "Field.h"

enum BATTLE_MOVE {ATTACK = 1, RUN};
enum BATTLE_RESULT {RESULT_WIN, RESULT_LOSE, RESULT_RUN};

class CDungeon : public CField
{
public:
	CDungeon();
	virtual ~CDungeon();
public:
	virtual void Update()override;
	virtual void Release()override;
private:
	void Make_Dungeon();
	void Render();
	void Make_Mob(GRADE eGrade);
	void Research(GRADE eGrade);
	int Fight();
private:
	int m_iMapArray[MAP_SIZE][MAP_SIZE];
	CObject* m_pMob;
};

