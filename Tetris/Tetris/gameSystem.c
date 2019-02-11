#include <time.h>
#include <stdlib.h>
#include "common.h"
#include "keyCurControl.h"
#include "point.h"
#include "blockModel.h"
#include "gameSystem.h"

//������ ũ��
#define GBOARD_WIDTH	10
#define GBOARD_HEIGHT	20

//���� ���� �׸� ������ �Ǵ� ��ġ
#define GBOARD_ORIGIN_X	(2*2)
#define GBOARD_ORIGIN_Y 4

static int currentBlockModel;
static int curPosX, curPosY;
static int rotateSte;
static int gameBoardInfo[GBOARD_HEIGHT + 1][GBOARD_WIDTH + 2] = { 0, };


// ����� ù ��ġ ����
void InitNewBlockPos(int x, int y)
{
	if (x < 0 || y < 0)
		return;

	curPosX = x;
	curPosY = y;

	SetCurrentCursorPos(x, y);
}

// ����� �� ������ ����
void ChooseBlock(void)
{
	srand((int)time(NULL));
	currentBlockModel = (rand() % NUM_OF_BLOCK_MODEL) * 4;
}

// ���� ����ؾ� �ϴ� ����� index ���� ��ȯ
int GetCurrentBlockIdx(void)
{
	return (currentBlockModel + rotateSte);
}

// �� �׸���
void ShowBlock(char blockInfo[][4])
{
	int y, x;
	Point curPos = GetCurrentCursorPos();
	Point test;

	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			SetCurrentCursorPos(curPos.x + (x * 2), curPos.y + y);  //Ư�� ���� �ϳ��� ��� �� ��ĭ�� ����
			test = GetCurrentCursorPos();
			if (blockInfo[y][x] == 1)
				printf("%d",test.x);
		}
	}
	SetCurrentCursorPos(curPos.x, curPos.y); // Ŀ�� ��ġ �������
}

// �� �����
void RemoveBlock(char blockInfo[][4])
{
	int y, x;
	Point curPos = GetCurrentCursorPos();

	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			SetCurrentCursorPos(curPos.x + (x * 2), curPos.y + y);  //Ư�� ���� �ϳ��� ��� �� ��ĭ�� ����

			if (blockInfo[y][x] == 1)
				printf("  ");
		}
	}
	SetCurrentCursorPos(curPos.x, curPos.y); 
}

//�� ��ĭ ������
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

//�� �������� �̵�
void BlockLeft(void)
{
	if (!DetectCollision(curPosX-2, curPosY, blockModel[GetCurrentBlockIdx()]))
		return 0;

		RemoveBlock(blockModel[GetCurrentBlockIdx()]);
		curPosX -= 2;
		SetCurrentCursorPos(curPosX, curPosY);
		ShowBlock(blockModel[GetCurrentBlockIdx()]);
	
}

//�� �浹 Ȯ��
//�浹�� 0, �̵� �����ҽ� 1��ȯ
int DetectCollision(int posX, int posY, char blcokModel[][4])
{
	int x, y;

	int arrX = (posX - GBOARD_ORIGIN_X) / 2;
	int arrY = posY - GBOARD_ORIGIN_Y;

	//�浹 �˻�
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

//�� ���������� �̵�
void BlockRight(void)
{
	if (!DetectCollision(curPosX +2, curPosY, blockModel[GetCurrentBlockIdx()]))
		return 0;
		RemoveBlock(blockModel[GetCurrentBlockIdx()]);
		curPosX += 2;

		SetCurrentCursorPos(curPosX, curPosY);
		ShowBlock(blockModel[GetCurrentBlockIdx()]);
	
}

//�� �������� 90�� ȸ��
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

//rotateste �� 0���� �ʱ�ȭ
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
			printf("��");
		else
			printf("��");
	}

	for (y = 0; y <= GBOARD_HEIGHT; y++)
	{
		SetCurrentCursorPos(
			GBOARD_ORIGIN_X + (GBOARD_WIDTH + 1) * 2,
			GBOARD_ORIGIN_Y + y);

		if (y == GBOARD_HEIGHT)
			printf("��");
		else
			printf("��");
	}

	for (x = 1; x < GBOARD_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(
			GBOARD_ORIGIN_X + x * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT);
		printf("��");
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