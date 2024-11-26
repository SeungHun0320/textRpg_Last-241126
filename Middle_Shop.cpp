#include "pch.h"
#include "Middle_Shop.h"

CMiddle_Shop::CMiddle_Shop()
{
}

CMiddle_Shop::~CMiddle_Shop()
{
	Release();
}

void CMiddle_Shop::Initialize()
{
	m_pItem = new CItem("롱소드", 0, 10, 2500, ITEM_WEAPON);
	m_vecShop.push_back(m_pItem);
	m_pItem = new CItem("기사의 갑옷", 20, 0, 2000, ITEM_ARMOR);
	m_vecShop.push_back(m_pItem);
}

void CMiddle_Shop::Update()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		cout << "중급 상점" << endl;
		Render();
		cout << "1. 무기 구매  2. 방어구 구매  3. 판매  4. 이전메뉴  : ";
		cin >> iInput;

		switch (iInput)
		{
		case BUY_WEAPON:
			Buy_Item(ITEM_WEAPON);
			break;
		case BUY_ARMOR:
			Buy_Item(ITEM_ARMOR);
			break;
		case SELL:
			Sell_Item();
			break;
		case DEAL_BACK:
			return;
		default:
			continue;
		}
	}
}

void CMiddle_Shop::Release()
{
	for_each(m_vecShop.begin(), m_vecShop.end(), Safe_Delete<CItem*>);
	m_vecShop.clear();
}
