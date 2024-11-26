#include "pch.h"
#include "Player.h"

CPlayer::CPlayer() : m_pInven(nullptr), m_pItemCheck{nullptr}
{
}

CPlayer::CPlayer(const char* szName, int iHp, int iAtk)
	: CObject(szName, iHp, iAtk), m_pInven(nullptr), m_pItemCheck{ nullptr }
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Release()
{
	Safe_Delete<CInven*>(m_pInven);
	for (CItem* i : m_pItemCheck)
		Safe_Delete<CItem*>(i);
}

CInven* CPlayer::Get_Inven()
{
	return m_pInven;
}

void CPlayer::Init_Inven(int iMoney)
{
	if (m_pInven == nullptr)
		m_pInven = new CInven(iMoney);
}

void CPlayer::Set_MaxHp()
{
	m_tInfo.iHp = m_tInfo.iMaxHp;
}

void CPlayer::Set_Equip_Stat(int iHp, int iAtk)
{
	m_tInfo.iMaxHp += iHp;
	m_tInfo.iAtk += iAtk;
}

void CPlayer::Render()
{
	cout << "====================== 정보 ======================" << endl;
	cout << "직업 : " << m_tInfo.szName << endl;
	cout << "체력 : " << m_tInfo.iHp << "/" << m_tInfo.iMaxHp << endl;
	cout << "공격력 : " << m_tInfo.iAtk << endl;
	cout << "소지금 : " << m_pInven->Get_Money() << endl;
}

bool CPlayer::Move(int (_iMapArray[])[MAP_SIZE], int iInput)
{
	int iSaveVerti(0), iVerti(0);
	int iSaveHoriz(0), iHoriz(0);
	while (true)
	{
		for (int i = 0; i < MAP_SIZE; i++)
		{
			for (int j = 0; j < MAP_SIZE; j++)
			{
				if (PLAYER == _iMapArray[i][j])
				{
					iVerti = i;
					iHoriz = j;
				}
			}
		}

		iSaveHoriz = iHoriz;
		iSaveVerti = iVerti;
		
		switch (iInput)
		{
		case UP:
			if (0 >= iVerti)
				return false;
			else
				iVerti--;
			break;
		case DOWN:
			if (MAP_SIZE - 1 <= iVerti)
				return false;
			else
				iVerti++;
			break;
		case LEFT:
			if (0 >= iHoriz)
				return false;
			else
				iHoriz--;
			break;
		case RIGHT:
			if (MAP_SIZE - 1 <= iHoriz)
				return false;
			else
				iHoriz++;
			break;
		default:
			continue;
		}

		if (MOB == _iMapArray[iVerti][iHoriz])
		{
			swap(_iMapArray[iSaveVerti][iSaveHoriz], _iMapArray[iVerti][iHoriz]);
			_iMapArray[iSaveVerti][iSaveHoriz] = EMPTY;
			return true;
		}
		swap(_iMapArray[iSaveVerti][iSaveHoriz], _iMapArray[iVerti][iHoriz]);
		_iMapArray[iSaveVerti][iSaveHoriz] = EMPTY;
		return false;
	}
}

void CPlayer::Equip_Item(CItem* pItem, ITEM_TYPE eType, int iInput)
{
	if (m_pItemCheck[eType] != nullptr)
	{
		m_pInven->Get_Vector()->push_back(new CItem(*m_pItemCheck[eType]));
		Set_Equip_Stat(-m_pItemCheck[eType]->Get_Info().iMaxHp, -m_pItemCheck[eType]->Get_Info().iAtk);
		Safe_Delete<CItem*>(m_pItemCheck[eType]);
	}

	Set_Equip_Stat(pItem->Get_Info().iMaxHp, pItem->Get_Info().iAtk);
	m_pItemCheck[eType] = new CItem(*pItem);
	m_pInven->Set_Equip_Item(m_pItemCheck[eType], eType);

	int i = 0;
	for (auto iter = m_pInven->Get_Vector()->begin(); iter != m_pInven->Get_Vector()->end(); i++)
	{
		if (i == iInput)
		{
			Safe_Delete<CItem*>(*iter);
			iter = m_pInven->Get_Vector()->erase(iter);
		}
		else
			iter++;
	}
}

void CPlayer::Unequip_Item(CItem* pItem, ITEM_TYPE eType)
{
	if (pItem->Get_Info().eType == eType)
	{
		if (m_pItemCheck[eType] != nullptr)
		{
			m_pInven->Get_Vector()->push_back(new CItem(*m_pItemCheck[eType]));
			Set_Equip_Stat(-m_pItemCheck[eType]->Get_Info().iMaxHp, -m_pItemCheck[eType]->Get_Info().iAtk);
			Safe_Delete<CItem*>(m_pItemCheck[eType]);
		}
	}

}
