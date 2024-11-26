#include "pch.h"
#include "Low_Shop.h"

CLow_Shop::CLow_Shop()
{
}

CLow_Shop::~CLow_Shop()
{
	Release();
}

void CLow_Shop::Initialize()
{
	m_pItem = new CItem("낡은 검", 0, 5, 1500, ITEM_WEAPON);
	m_vecShop.push_back(m_pItem);
	m_pItem = new CItem("천갑옷", 10, 0, 1000, ITEM_ARMOR);
	m_vecShop.push_back(m_pItem);
}

void CLow_Shop::Update()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		cout << "하급 상점" << endl;
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

void CLow_Shop::Release()
{
	for_each(m_vecShop.begin(), m_vecShop.end(), Safe_Delete<CItem*>);
	m_vecShop.clear();
}
