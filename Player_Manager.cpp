#include "pch.h"
#include "Player_Manager.h"
#include "Player.h"

CPlayer_Manager::CPlayer_Manager() : m_pPlayer(nullptr)
{
}

CPlayer_Manager::~CPlayer_Manager()
{
	Release();
}

void CPlayer_Manager::Initialize()
{
}

void CPlayer_Manager::Update()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		cout << "직업을 선택해 주세요" << endl;
		cout << "1. 전사  2. 마법사  3. 도적  4. 못가진자  : ";
		cin >> iInput;

		if (m_pPlayer != nullptr)
		{
			cout << "m_pPlayer가 nullptr이 아닙니다 ! (위치 : Player_Manager 클래스)" << endl;
			system("pause");
			return;
		}

		switch (iInput)
		{
		case WARRIOR:
			m_pPlayer = new CPlayer("전사", 100, 10);
			if (CPlayer* Temp = dynamic_cast<CPlayer*>(m_pPlayer))
				Temp->Init_Inven(50000);
			return;
		case MAGE:
			m_pPlayer = new CPlayer("마법사", 100, 10);
			if (CPlayer* Temp = dynamic_cast<CPlayer*>(m_pPlayer))
				Temp->Init_Inven(50000);
			return;
		case THIEF:
			m_pPlayer = new CPlayer("도적", 100, 10);
			if (CPlayer* Temp = dynamic_cast<CPlayer*>(m_pPlayer))
				Temp->Init_Inven(75000);
			return;
		case WERTCH:
			m_pPlayer = new CPlayer("못가진자", 100, 10);
			if (CPlayer* Temp = dynamic_cast<CPlayer*>(m_pPlayer))
				Temp->Init_Inven(0);
			return;
		default:
			continue;
		}
	}
}

void CPlayer_Manager::Release()
{
	Safe_Delete<CObject*>(m_pPlayer);
}

CObject* CPlayer_Manager::Get_Player()
{
	return m_pPlayer;
}
