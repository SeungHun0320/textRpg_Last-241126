#pragma once
#ifdef _DEBUG            // 메모리 누수 체크 매크로

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif

#define PURE = 0
#define LINE cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl
#define LINE2 cout << "==================================================" << endl
#define MAP_SIZE 5
#define MOB_COUNT 4
#define SHOP_MAX_ITEM 2
#define MAX_INVEN 6

// 맵 이동 관련 열거체
enum RESEARCH { ESCAPE, DOWN = 2, LEFT = 4, RIGHT = 6, UP = 8 };
enum TILE { NONE, PLAYER = 5, MOB, EMPTY = 999 };

template<typename T>
void Safe_Delete(T& p)
{
	if (p != nullptr)
	{
		delete p;
		p = nullptr;
	}
}

template<typename T>
void Safe_Delete_Array(T& p)
{
	if (p != nullptr)
	{
		delete[] p;
		p = nullptr;
	}
}