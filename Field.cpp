#include "pch.h"
#include "Field.h"

CField::CField() : m_pPlayer_Manager(nullptr)
{
}

CField::~CField()
{
}

void CField::Initialize()
{
}

void CField::Set_Player_Manager(CPlayer_Manager* pPlayer_Manager)
{
	if (m_pPlayer_Manager == nullptr && pPlayer_Manager != nullptr)
		m_pPlayer_Manager = pPlayer_Manager;
}
