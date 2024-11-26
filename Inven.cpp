#include "pch.h"
#include "Inven.h"
#include "Player.h"

CInven::CInven() : m_iMoney(0), m_pPlayer_Manager(nullptr), m_pEquipItem{nullptr}
{
	m_vecInven.reserve(MAX_INVEN);
}

CInven::CInven(int iMoney) : m_pPlayer_Manager(nullptr), m_pEquipItem{ nullptr }
{
	m_iMoney = iMoney;
	m_vecInven.reserve(MAX_INVEN);
}

CInven::~CInven()
{
	Release();
}

void CInven::Initialize()
{
}

void CInven::Update()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		Render();
		cout << "1. ����  2. Ż��  3. ����  4. �����޴�  : ";
		cin >> iInput;

		switch (iInput)
		{
		case EQUIP:
			Equip_Menu();
			break;
		case UNEQUIP:
			Unequip_Menu();
			break;
		case SORT:
			Sort_Menu();
			break;
		case INVEN_BACK:
			return;
		default:
			continue;
		}
	}
}

void CInven::Release()
{
	for_each(m_vecInven.begin(), m_vecInven.end(), Safe_Delete<CItem*>);
	m_vecInven.clear();
	for (CItem* pItem : m_pEquipItem)
		Safe_Delete<CItem*>(pItem);
}

int CInven::Get_Money()
{
	return m_iMoney;
}

void CInven::Set_Money(int iMoney)
{
	m_iMoney += iMoney;
}

vector<CItem*>* CInven::Get_Vector()
{
	return &m_vecInven;
}

void CInven::Set_Player_Manager(CPlayer_Manager* pPlayer_Manager)
{
	if (m_pPlayer_Manager == nullptr && pPlayer_Manager != nullptr)
		m_pPlayer_Manager = pPlayer_Manager;
}

void CInven::Set_Equip_Item(CItem* pItem, ITEM_TYPE eType)
{
	if (pItem != nullptr)
	{
		Safe_Delete<CItem*>(m_pEquipItem[eType]);
		m_pEquipItem[eType] = new CItem(*pItem);
	}
}

void CInven::Render()
{
	cout << "����" << endl;
	if(m_pPlayer_Manager != nullptr)
		m_pPlayer_Manager->Get_Player()->Render();
	LINE;
	for (int i = 0; i < m_vecInven.size(); i++)
	{
		cout << "[" << i + 1 << "]";
		m_vecInven[i]->Render();
		cout << '\n';
	}
	LINE;
}

void CInven::Equip_Render()
{
	cout << "���� ĭ" << endl;
	if (m_pPlayer_Manager != nullptr)
		m_pPlayer_Manager->Get_Player()->Render();
	LINE;
	for (int i = 0; i < ITEM_END; i++)
	{
		cout << "[" << i + 1 << "]";
		if (m_pEquipItem[i] != nullptr)
			m_pEquipItem[i]->Render();
		cout << '\n';
	}
	LINE;
}

void CInven::Storage_Item(CItem* pItem)
{
	m_vecInven.push_back(new CItem(*pItem));
}

void CInven::Delete_Item(int iInput)
{
	int i = 0;
	for (auto iter = m_vecInven.begin(); iter != m_vecInven.end(); i++)
	{
		if (i == iInput)
		{
			Safe_Delete<CItem*>(*iter);
			iter = m_vecInven.erase(iter);
			break;
		}
		else
			iter++;
	}
}

void CInven::Equip_Menu()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		Render();
		cout << "������ �������� �������ּ��� (��� : 0)  : ";
		cin >> iInput;

		if (0 == iInput)
		{
			return;
		}
		else if (iInput <= m_vecInven.size())
		{
			if (CPlayer* Temp = dynamic_cast<CPlayer*>(m_pPlayer_Manager->Get_Player()))
			{
				cout << m_vecInven[iInput - 1]->Get_Info().szName << "��(��) �����ߴ� ! " << endl;

				if (ITEM_WEAPON == m_vecInven[iInput - 1]->Get_Info().eType)
				{
					Temp->Equip_Item(m_vecInven[iInput - 1], ITEM_WEAPON, iInput - 1);
				}
				else if (ITEM_ARMOR == m_vecInven[iInput - 1]->Get_Info().eType)
				{
					Temp->Equip_Item(m_vecInven[iInput - 1], ITEM_ARMOR, iInput - 1);
				}
			}
		}
		else
			continue;
		system("pause");
	}
}

void CInven::Unequip_Menu()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		Equip_Render();
		cout << "Ż���� �������� �������ּ���" << endl;
		cout << "1. ����  2. ����  3. ���  : ";
		cin >> iInput;


		switch (iInput)
		{
		case UN_WEAPON:
			Unequip_Item(ITEM_WEAPON);
			break;
		case UN_ARMOR:
			Unequip_Item(ITEM_ARMOR);
			break;
		case UN_BACK:
			return;
		default:
			continue;
		}
	}
}

void CInven::Unequip_Item(ITEM_TYPE eType)
{
	if (CPlayer* Temp = dynamic_cast<CPlayer*>(m_pPlayer_Manager->Get_Player()))
	{
		if (m_pEquipItem[eType] != nullptr)
		{
			cout << m_pEquipItem[eType]->Get_Info().szName << "��(��) Ż���ߴ� ! " << endl;
			Temp->Unequip_Item(m_pEquipItem[eType], eType);
			Safe_Delete<CItem*>(m_pEquipItem[eType]);
		}
		else
			cout << "������ �������� �����ϴ� !" << endl;
	}
	system("pause");
}

void CInven::Sort_Menu()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		Render();
		cout << "������ �������� �����Ͻ��� ������ �ּ��� (��� : 0)" << endl;
		cout << "1. ���ݷ�  2. ü��  3. ����  4. �̸�  : ";
		cin >> iInput;

		switch (iInput)
		{
		case SORT_BACK:
			return;
		case SORT_ATK:
			Sort_Atk();
			break;
		case SORT_HP:
			Sort_Hp();
			break;
		case SORT_PRICE:
			Sort_Price();
			break;
		case SORT_NAME:
			Sort_Name();
			break;
		default:
			continue;
		}
	}
}

void CInven::Sort_Atk()
{
	int iInput(0);
	system("cls");
	Render();
	cout << "� ������� �����Ͻðڽ��ϱ�?" << endl;
	cout << "1. ��������  2. ��������  3. ���  : ";
	cin >> iInput;

	switch (iInput)
	{
	case LESS:
		sort(m_vecInven.begin(), m_vecInven.end(), [](CItem* Dst, CItem* Src)->bool
			{
				return Dst->Get_Info().iAtk < Src->Get_Info().iAtk;
			});
		cout << "���ݷ�(��������) ���� �Ϸ� !" << endl;
		break;
	case GREATER:
		sort(m_vecInven.begin(), m_vecInven.end(), [](CItem* Dst, CItem* Src)->bool
			{
				return Dst->Get_Info().iAtk > Src->Get_Info().iAtk;
			});
		cout << "���ݷ�(��������) ���� �Ϸ� !" << endl;
		break;
	case SS_BACK:
		return;
	default:
		cout << "�߸��� �Է��Դϴ�" << endl;
		break;
	}
	system("pause");
	return;
}

void CInven::Sort_Hp()
{
	int iInput(0);
	system("cls");
	Render();
	cout << "� ������� �����Ͻðڽ��ϱ�?" << endl;
	cout << "1. ��������  2. ��������  3. ���  : ";
	cin >> iInput;

	switch (iInput)
	{
	case LESS:
		sort(m_vecInven.begin(), m_vecInven.end(), [](CItem* Dst, CItem* Src)->bool
			{
				return Dst->Get_Info().iMaxHp < Src->Get_Info().iMaxHp;
			});
		cout << "ü��(��������) ���� �Ϸ� !" << endl;
		break;
	case GREATER:
		sort(m_vecInven.begin(), m_vecInven.end(), [](CItem* Dst, CItem* Src)->bool
			{
				return Dst->Get_Info().iMaxHp > Src->Get_Info().iMaxHp;
			});
		cout << "ü��(��������) ���� �Ϸ� !" << endl;
		break;
	case SS_BACK:
		return;
	default:
		cout << "�߸��� �Է��Դϴ�" << endl;
		break;
	}
	system("pause");
	return;
}

void CInven::Sort_Price()
{
	int iInput(0);
	system("cls");
	Render();
	cout << "� ������� �����Ͻðڽ��ϱ�?" << endl;
	cout << "1. ��������  2. ��������  3. ���  : ";
	cin >> iInput;

	switch (iInput)
	{
	case LESS:
		sort(m_vecInven.begin(), m_vecInven.end(), [](CItem* Dst, CItem* Src)->bool
			{
				return Dst->Get_Info().iPrice < Src->Get_Info().iPrice;
			});
		cout << "����(��������) ���� �Ϸ� !" << endl;
		break;
	case GREATER:
		sort(m_vecInven.begin(), m_vecInven.end(), [](CItem* Dst, CItem* Src)->bool
			{
				return Dst->Get_Info().iPrice > Src->Get_Info().iPrice;
			});
		cout << "����(��������) ���� �Ϸ� !" << endl;
		break;
	case SS_BACK:
		return;
	default:
		cout << "�߸��� �Է��Դϴ�" << endl;
		break;
	}
	system("pause");
	return;
}

void CInven::Sort_Name()
{
	int iInput(0);
	system("cls");
	Render();
	cout << "� ������� �����Ͻðڽ��ϱ�?" << endl;
	cout << "1. ��������  2. ��������  3. ���  : ";
	cin >> iInput;

	switch (iInput)
	{
	case LESS:
		sort(m_vecInven.begin(), m_vecInven.end(), [](CItem* Dst, CItem* Src)->bool
			{
				int iResult = strcmp(Dst->Get_Info().szName, Src->Get_Info().szName);
				if (0 > iResult)
					return true;
				else
					return false;
			});
		cout << "�̸�(��������) ���� �Ϸ� !" << endl;
		break;
	case GREATER:
		sort(m_vecInven.begin(), m_vecInven.end(), [](CItem* Dst, CItem* Src)->bool
			{
				int iResult = strcmp(Dst->Get_Info().szName, Src->Get_Info().szName);
				if (0 < iResult)
					return true;
				else
					return false;
			});
		cout << "�̸�(��������) ���� �Ϸ� !" << endl;
		break;
	case SS_BACK:
		return;
	default:
		cout << "�߸��� �Է��Դϴ�" << endl;
		break;
	}
	system("pause");
	return;
}
