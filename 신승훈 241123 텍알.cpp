#include "pch.h"
#include "Main_Game.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // 메모리 누수 체크 명령어
	srand(unsigned(time(NULL)));

	CMain_Game Main;
	bool bStart = Main.Start_Game();
	if (bStart == false)
		return 0;
	Main.Update();

	return 0;
}
