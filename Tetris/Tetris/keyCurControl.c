#include <conio.h>
#include "common.h"
#include "point.h"

void SetCurrentCursorPos(int x, int y)  // 운영체제에 의존적인 코드라 다른 운영체제에 이식할 때 이부분만 바꿔주면 되기때문에 함수로따로 지정
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

Point GetCurrentCursorPos(void)
{
	Point curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;

	GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curPoint.x = curInfo.dwCursorPosition.X;
	curPoint.y = curInfo.dwCursorPosition.Y;

	return curPoint;
}

void RemoveCursor(void)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
