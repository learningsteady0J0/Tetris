#include <conio.h>
#include "common.h"
#include "point.h"
#include "gameSystem.h"

#define KEY_SENSITIVE		100
#define SYS_DELAY			20

#define LEFT	75
#define RIGHT	77
#define UP		72
#define DOWN	80

static int keyDelayRate;   // ���� Ŭ���� �ӵ� ����

void SetCurrentCursorPos(int x, int y)  // �ü���� �������� �ڵ�� �ٸ� �ü���� �̽��� �� �̺κи� �ٲ��ָ� �Ǳ⶧���� �Լ��ε��� ����
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

// ����� Ű �Է� ó��
void UserKeyInput(void)
{
	int i;
	int key;

	for (i = 0; i < 100; i++)
	{
		if (_kbhit())
		{
			key = _getch();

			switch(key)
			{
			case LEFT :
				BlockLeft();
				break;
			case RIGHT :
				BlockRight();
				break;
			case UP :
				RotateBlock();
			}
		}

		if (i%keyDelayRate == 0)
			Sleep(SYS_DELAY);
	}

}

// �ӵ� ����, ���� Ŭ ���� �ӵ� ����
void InitKeyDelayRate(int rate)
{
	if (rate < 1)
		return;
	keyDelayRate = rate;
}
