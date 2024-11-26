#include "pch.h"
#include "Dungeon.h"
#include "Monster.h"
#include "Player.h"

CDungeon::CDungeon() : m_iMapArray{ NONE }, m_pMob{nullptr}
{
}

CDungeon::~CDungeon()
{
	Release();
}

void CDungeon::Update()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		cout << "던전" << endl;
		if (m_pPlayer_Manager != nullptr)
			m_pPlayer_Manager->Get_Player()->Render();
		cout << "\n1. 하급던전  2. 중급던전  3. 상급던전  4. 이전메뉴  : ";
		cin >> iInput;

		Make_Dungeon();

		switch (iInput)
		{
		case LOW:
			Make_Mob(LOW);
			Research(LOW);
			break;
		case MIDDLE:
			Make_Mob(MIDDLE);
			Research(MIDDLE);
			break;
		case HIGH:
			Make_Mob(HIGH);
			Research(HIGH);
			break;
		case GD_BACK:
			return;
		default:
			continue;
		}
	}
}

void CDungeon::Release()
{
	Safe_Delete<CObject*>(m_pMob);
}

void CDungeon::Make_Dungeon()
{

	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			m_iMapArray[i][j] = NONE;
		}
	}

	for (int i = 0; i < MOB_COUNT; i++)
	{
		m_iMapArray[rand() % MAP_SIZE][rand() % MAP_SIZE] = MOB;
	}
	m_iMapArray[rand() % MAP_SIZE][rand() % MAP_SIZE] = PLAYER;
}

void CDungeon::Make_Mob(GRADE eGrade)
{
	int iRandom = rand() % 10 + 1;

	if (m_pMob == nullptr)
	{
		switch (eGrade)
		{
		case LOW:
			if (0 < iRandom && 5 >= iRandom)
				m_pMob = new CMonster("하급1", 20, 2);
			else if (5 < iRandom && 10 >= iRandom)
				m_pMob = new CMonster("하급2", 30, 3);
			break;
		case MIDDLE:
			if (0 < iRandom && 5 >= iRandom)
				m_pMob = new CMonster("중급1", 50, 5);
			else if (5 < iRandom && 10 >= iRandom)
				m_pMob = new CMonster("중급2", 60, 6);
			break;
		case HIGH:
			if (0 < iRandom && 5 >= iRandom)
				m_pMob = new CMonster("상급1", 80, 8);
			else if (5 < iRandom && 10 >= iRandom)
				m_pMob = new CMonster("상급1", 90, 9);
			break;
		}
		return;
	}
}

void CDungeon::Render()
{
	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			if (NONE == m_iMapArray[i][j])
				cout << "^^^" << '\t';
			else if (PLAYER == m_iMapArray[i][j])
				cout << "♡" << '\t';
			else if (MOB == m_iMapArray[i][j])
				cout << "^^^" << '\t';
			else if (EMPTY == m_iMapArray[i][j])
				cout << " " << '\t';
		}
		cout << "\n\n";
	}
}

void CDungeon::Research(GRADE eGrade)
{
	int iInput(0), iResult(0);
	bool bMeet(false);
	while (true)
	{
		system("cls");
		cout << "던전 내부" << endl;
		LINE2;
		Render();
		LINE2;
		cout << "플레이어 : ♡" << endl;
		cout << "8. 위(△)  2. 아래(▽)  4. 왼쪽(◁)  6. 오른쪽(▷)  (던전탈출 : 0)  : ";
		cin >> iInput;

		if (CPlayer* Temp = dynamic_cast<CPlayer*>(m_pPlayer_Manager->Get_Player()))
		{
			switch (iInput)
			{
			case UP:
				bMeet = Temp->Move(m_iMapArray, iInput);
				break;
			case DOWN:
				bMeet = Temp->Move(m_iMapArray, iInput);
				break;
			case LEFT:
				bMeet = Temp->Move(m_iMapArray, iInput);
				break;
			case RIGHT:
				bMeet = Temp->Move(m_iMapArray, iInput);
				break;
			case ESCAPE:
				Release();
				return;
			default:
				continue;
			}

			if (bMeet != true)
				continue;
			else
				iResult = Fight();

			if (RESULT_WIN == iResult)
			{
				cout << "승리" << endl;
				Temp->Get_Inven()->Set_Money(rand() % (1000 - 300 + 1) + 300);
			}
			else if (RESULT_LOSE == iResult)
			{
				cout << "패배" << endl;
				Temp->Get_Inven()->Set_Money(-Temp->Get_Inven()->Get_Money() / 4);
				Temp->Set_MaxHp();
				system("pause");
				return;
			}
			else if (RESULT_RUN == iResult)
			{
				cout << "도망쳤다 !" << endl;
				Temp->Get_Inven()->Set_Money(-Temp->Get_Inven()->Get_Money() / 2);
			}
			Release();
			system("pause");

			if (m_pMob == nullptr)
				Make_Mob(eGrade);
		}
	}
}

int CDungeon::Fight()
{
	int iInput(0);
	system("cls");
	cout << "앗 ! 야생의 " << m_pMob->Get_Info().szName << " 이(가) 나타났다 ! " << endl;
	system("pause");

	while (true)
	{
		system("cls");
		cout << "전투" << endl;
		if(m_pPlayer_Manager != nullptr)
			m_pPlayer_Manager->Get_Player()->Render();
		if(m_pMob != nullptr)
			m_pMob->Render();
		cout << "\n1. 싸우다  2. 도망가다  : ";
		cin >> iInput;

		switch (iInput)
		{
		case ATTACK:
			m_pMob->Set_Hp(m_pMob->Get_Damage(m_pPlayer_Manager->Get_Player()->Get_Info().iAtk));
			m_pPlayer_Manager->Get_Player()->Set_Hp(m_pPlayer_Manager->Get_Player()->Get_Damage(m_pMob->Get_Info().iAtk));

			if (0 >= m_pMob->Get_Info().iHp)
				return RESULT_WIN;
			
			if (0 >= m_pPlayer_Manager->Get_Player()->Get_Info().iHp)
				return RESULT_LOSE;

			break;
		case RUN:
			return RESULT_RUN;
		default:
			continue;
		}
	}
}
