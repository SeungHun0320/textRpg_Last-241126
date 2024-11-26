#include "pch.h"
#include "Shop.h"
#include "Low_Shop.h"
#include "Middle_Shop.h"
#include "High_Shop.h"
#include "Player.h"

CShop::CShop() : m_pItem(nullptr), m_pShop{nullptr}
{
	m_vecShop.reserve(SHOP_MAX_ITEM);
}

CShop::~CShop()
{
	Release();
}

void CShop::Initialize()
{
}

void CShop::Update()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		cout << "상점" << endl;
		m_pPlayer_Manager->Get_Player()->Render();
		cout << "\n1. 하급상점  2. 중급상점  3. 상급상점  4. 이전메뉴  : ";
		cin >> iInput;

		switch (iInput)
		{
		case LOW:
			Make_Shop(SHOP_LOW);
			break;
		case MIDDLE:
			Make_Shop(SHOP_MIDDLE);
			break;
		case HIGH:
			Make_Shop(SHOP_HIGH);
			break;
		case GD_BACK:
			return;
		default:
			continue;
		}
	}
}

void CShop::Release()
{
	for (CField* Shop : m_pShop)
		Safe_Delete<CField*>(Shop);
}

void CShop::Make_Shop(SHOP_GRADE eGrade)
{

	if (m_pShop[eGrade] == nullptr)
	{
		switch (eGrade)
		{
		case SHOP_LOW:
			m_pShop[eGrade] = new CLow_Shop;
			break;
		case SHOP_MIDDLE:
			m_pShop[eGrade] = new CMiddle_Shop;
			break;
		case SHOP_HIGH:
			m_pShop[eGrade] = new CHigh_Shop;
			break;
		}

		if (m_pPlayer_Manager != nullptr)
		{
			m_pShop[eGrade]->Initialize();
			m_pShop[eGrade]->Set_Player_Manager(m_pPlayer_Manager);
			m_pShop[eGrade]->Update();
		}
	}
	else
		m_pShop[eGrade]->Update();
}

void CShop::Render()
{
	if (m_pPlayer_Manager != nullptr)
		m_pPlayer_Manager->Get_Player()->Render();
	LINE;
	for (int i = 0; i < m_vecShop.size(); i++)
	{
		cout << "[" << i + 1 << "]";
		m_vecShop[i]->Render();
		cout << '\n';
	}
	LINE;
}

void CShop::Buy_Item(ITEM_TYPE eType)
{
	if (CPlayer* Temp = dynamic_cast<CPlayer*>(m_pPlayer_Manager->Get_Player()))
	{
		if (m_vecShop[eType]->Get_Info().iPrice > Temp->Get_Inven()->Get_Money())
		{
			cout << "소지금이 부족합니다" << endl;
			system("pause");
			return;
		}

		if (MAX_INVEN > Temp->Get_Inven()->Get_Vector()->size())
		{
			Temp->Get_Inven()->Set_Money(-m_vecShop[eType]->Get_Info().iPrice);
			Temp->Get_Inven()->Storage_Item(m_vecShop[eType]);
			cout << m_vecShop[eType]->Get_Info().szName << "을(를) 구매했다 !" << endl;
		}
		else
			cout << "가방이 가득 찼다 !" << endl;
	}
	system("pause");
}

void CShop::Sell_Item()
{
	int iInput(0);

	if (CPlayer* Temp = dynamic_cast<CPlayer*>(m_pPlayer_Manager->Get_Player()))
	{
		while (true)
		{
			system("cls");
			Temp->Get_Inven()->Render();
			cout << "판매할 아이템을 결정해주세요 (취소 : 0)  : ";
			cin >> iInput;

			if (0 == iInput)
			{
				return;
			}
			else if (iInput <= Temp->Get_Inven()->Get_Vector()->size())
			{
				int i = 0;
				for (vector<CItem*>::iterator iter = Temp->Get_Inven()->Get_Vector()->begin();
					iter != Temp->Get_Inven()->Get_Vector()->end(); i++)
				{
					if (i == iInput - 1)
					{
						cout << (*iter)->Get_Info().szName << "을(를) 판매했습니다 !" << endl;
						Temp->Get_Inven()->Set_Money((*iter)->Get_Info().iPrice / 4);
						Safe_Delete<CItem*>(*iter);
						iter = Temp->Get_Inven()->Get_Vector()->erase(iter);
						break;
					}
					else
						iter++;
				}

			}
			else
			{
				continue;
			}
			system("pause");
		}
	}
}
