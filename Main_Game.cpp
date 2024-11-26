#include "pch.h"
#include "Main_Game.h"
#include "Player.h"
#include "Dungeon.h"
#include "Shop.h"

CMain_Game::CMain_Game() : m_pPlayer_Manager(nullptr), m_pField{nullptr}
{
}

CMain_Game::~CMain_Game()
{
    Release();
}

void CMain_Game::Initialize()
{
    if (m_pPlayer_Manager == nullptr)
    {
        m_pPlayer_Manager = new CPlayer_Manager;
        m_pPlayer_Manager->Update();
    }

    if (CPlayer* Temp = dynamic_cast<CPlayer*>(m_pPlayer_Manager->Get_Player()))
        Temp->Get_Inven()->Set_Player_Manager(m_pPlayer_Manager);
}

void CMain_Game::Update()
{
    int iInput(0);
    while (true)
    {
        system("cls");
        cout << "���� �޴�" << endl;
        if (m_pPlayer_Manager != nullptr)
            m_pPlayer_Manager->Get_Player()->Render();
        cout << "\n1. ����  2. ����  3. ����  4. ����  : ";
        cin >> iInput;

        switch (iInput)
        {
        case DUN:
            Make_Field(FD_DUN);
            break;
        case SHOP:
            Make_Field(FD_SHOP);
            break;
        case INVEN:
            if (m_pPlayer_Manager != nullptr)
            {
                if (CPlayer* Temp = dynamic_cast<CPlayer*>(m_pPlayer_Manager->Get_Player()))
                    Temp->Get_Inven()->Update();
            }
            break;
        case MN_END:
            return;
        default:
            continue;
        }
    }
}

void CMain_Game::Release()
{
    Safe_Delete<CPlayer_Manager*>(m_pPlayer_Manager);
    for (CField* Field : m_pField)
        Safe_Delete<CField*>(Field);
}

bool CMain_Game::Start_Game()
{
    int iInput(0);
    while (true)
    {
        system("cls");
        cout << "�ؾ�" << endl;
        cout << "1. ������  2. ����  : ";
        cin >> iInput;

        switch (iInput)
        {
        case NEW:
            Initialize();
            return true;
        case ST_END:
            return false;
        default:
            continue;
        }
    }
}

void CMain_Game::Make_Field(FIELD eField)
{
    if (m_pField[eField] == nullptr)
    {
        if (FD_DUN == eField)
            m_pField[eField] = new CDungeon;
        else if (FD_SHOP == eField)
            m_pField[eField] = new CShop;

        if (m_pPlayer_Manager != nullptr)
        {
            m_pField[eField]->Set_Player_Manager(m_pPlayer_Manager);
            m_pField[eField]->Update();
        }
    }
    else
        m_pField[eField]->Update();
}
