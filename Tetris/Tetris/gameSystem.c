#include <time.h>
#include <stdlib.h>
#include "common.h"
#include "keyCurControl.h"
#include "point.h"
#include "blockModel.h"

static int currentBlockModel;
static int curPosX, curPosY;

// 블록의 첫 위치 지정
void InitNewBlockPos(int x, int y)
{
	if (x < 0 || y < 0)
		return;

	curPosX = x;
	curPosY = y;

	SetCurrentCursorPos(x, y);
}

// 출력할 블럭 무작위 선택
void ChooseBlock(void)
{
	srand((int)time(NULL));
	currentBlockModel = (rand() % NUM_OF_BLOCK_MODEL) * 4;
}

// 현재 출력해야 하는 블록의 index 정보 반환
int GetCurrentBlockIdx(void)
{
	return currentBlockModel;
}

// 블럭 그리기
void ShowBlock(char blockInfo[][4])
{
	int y, x;
	Point curPos = GetCurrentCursorPos();

	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			SetCurrentCursorPos(curPos.x + (x * 2), curPos.y + y);  //특수 문자 하나는 출력 시 두칸을 차지

			if (blockInfo[y][x] == 1)
				printf("■");
		}
	}
	SetCurrentCursorPos(curPos.x, curPos.y); // 커서 위치 원래대로
}

// 블럭 지우기
void RemoveBlock(char blockInfo[][4])
{
	int y, x;
	Point curPos = GetCurrentCursorPos();

	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			SetCurrentCursorPos(curPos.x + (x * 2), curPos.y + y);  //특수 문자 하나는 출력 시 두칸을 차지

			if (blockInfo[y][x] == 1)
				printf("  ");
		}
	}
	SetCurrentCursorPos(curPos.x, curPos.y); 
}

//블럭 한칸 내리기
void BlockDown()
{
	RemoveBlock(blockModel[GetCurrentBlockIdx()]);
	curPosY += 1;

	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}