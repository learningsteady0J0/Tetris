#include <time.h>
#include <stdlib.h>
#include "common.h"
#include "keyCurControl.h"
#include "point.h"
#include "blockModel.h"
#include "gameSystem.h"

//게임판 크기
#define GBOARD_WIDTH	10
#define GBOARD_HEIGHT	20

//게임 판을 그릴 기준이 되는 위치
#define GBOARD_ORIGIN_X	(2*2)
#define GBOARD_ORIGIN_Y 4

static int currentBlockModel;
static int curPosX, curPosY;
static int rotateSte;
static int gameBoardInfo[GBOARD_HEIGHT + 1][GBOARD_WIDTH + 2] = { 0, };


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
	return (currentBlockModel + rotateSte);
}

// 블럭 그리기
void ShowBlock(char blockInfo[][4])
{
	int y, x;
	Point curPos = GetCurrentCursorPos();
	Point test;

	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			SetCurrentCursorPos(curPos.x + (x * 2), curPos.y + y);  //특수 문자 하나는 출력 시 두칸을 차지
			test = GetCurrentCursorPos();
			if (blockInfo[y][x] == 1)
				printf("%d",test.x);
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
int BlockDown()
{
	if (!DetectCollision(curPosX, curPosY + 1, blockModel[GetCurrentBlockIdx()]))
		return 0;
	RemoveBlock(blockModel[GetCurrentBlockIdx()]);
	curPosY += 1;

	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);

	return 1;
}

//블럭 왼쪽으로 이동
void BlockLeft(void)
{
	if (!DetectCollision(curPosX-2, curPosY, blockModel[GetCurrentBlockIdx()]))
		return 0;

		RemoveBlock(blockModel[GetCurrentBlockIdx()]);
		curPosX -= 2;
		SetCurrentCursorPos(curPosX, curPosY);
		ShowBlock(blockModel[GetCurrentBlockIdx()]);
	
}

//블럭 충돌 확인
//충돌시 0, 이동 가능할시 1반환
int DetectCollision(int posX, int posY, char blcokModel[][4])
{
	int x, y;

	int arrX = (posX - GBOARD_ORIGIN_X) / 2;
	int arrY = posY - GBOARD_ORIGIN_Y;

	//충돌 검사
	for (x = 0; x < 4; x++)
	{
		for (y = 0; y < 4; y++)
		{
			if (blockModel[y][x] == 1 )
			{
				printf("\a");
				return 0;
			}
		}
	}

	return 1;
}

//블럭 오른쪽으로 이동
void BlockRight(void)
{
	if (!DetectCollision(curPosX +2, curPosY, blockModel[GetCurrentBlockIdx()]))
		return 0;
		RemoveBlock(blockModel[GetCurrentBlockIdx()]);
		curPosX += 2;

		SetCurrentCursorPos(curPosX, curPosY);
		ShowBlock(blockModel[GetCurrentBlockIdx()]);
	
}

//블럭 왼쪽으로 90도 회전
void RotateBlock(void)
{
	int nextRotSte;
	int returnRotste = rotateSte;
	RemoveBlock(blockModel[GetCurrentBlockIdx()]);
	nextRotSte = rotateSte + 1;
	nextRotSte %= 4;
	rotateSte = nextRotSte;
	if (!DetectCollision(curPosX, curPosY + 1, blockModel[GetCurrentBlockIdx()]))
	{
		rotateSte = returnRotste;
		return 0;
	}
	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);

}

//rotateste 값 0으로 초기화
void InitRotate(void)
{
	rotateSte = 0;
}

void DrawGameBoard(void)
{
	int x, y;

	for (y = 0; y <= GBOARD_HEIGHT; y++)
	{
		SetCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y + y);

		if (y == GBOARD_HEIGHT)
			printf("┗");
		else
			printf("┃");
	}

	for (y = 0; y <= GBOARD_HEIGHT; y++)
	{
		SetCurrentCursorPos(
			GBOARD_ORIGIN_X + (GBOARD_WIDTH + 1) * 2,
			GBOARD_ORIGIN_Y + y);

		if (y == GBOARD_HEIGHT)
			printf("┛");
		else
			printf("┃");
	}

	for (x = 1; x < GBOARD_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(
			GBOARD_ORIGIN_X + x * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT);
		printf("━");
	}

	SetCurrentCursorPos(0, 0);

	for (y = 0; y < GBOARD_HEIGHT; y ++)
	{
		gameBoardInfo[y][0] = 1;
		gameBoardInfo[y][GBOARD_WIDTH + 1] = 1;
	}

	for (x = 0; x < GBOARD_WIDTH + 2; x++)
	{
		gameBoardInfo[GBOARD_HEIGHT][x] = 1;
	}
}