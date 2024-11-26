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
		cout << "������ ������ �ּ���" << endl;
		cout << "1. ����  2. ������  3. ����  4. ��������  : ";
		cin >> iInput;

		if (m_pPlayer != nullptr)
		{
			cout << "m_pPlayer�� nullptr�� �ƴմϴ� ! (��ġ : Player_Manager Ŭ����)" << endl;
			system("pause");
			return;
		}

		switch (iInput)
		{
		case WARRIOR:
			m_pPlayer = new CPlayer("����", 100, 10);
			if (CPlayer* Temp = dynamic_cast<CPlayer*>(m_pPlayer))
				Temp->Init_Inven(50000);
			return;
		case MAGE:
			m_pPlayer = new CPlayer("������", 100, 10);
			if (CPlayer* Temp = dynamic_cast<CPlayer*>(m_pPlayer))
				Temp->Init_Inven(50000);
			return;
		case THIEF:
			m_pPlayer = new CPlayer("����", 100, 10);
			if (CPlayer* Temp = dynamic_cast<CPlayer*>(m_pPlayer))
				Temp->Init_Inven(75000);
			return;
		case WERTCH:
			m_pPlayer = new CPlayer("��������", 100, 10);
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
