#include <time.h>
#include <stdlib.h>
#include "common.h"
#include "keyCurControl.h"
#include "point.h"
#include "blockModel.h"

static int currentBlockModel;
static int curPosX, curPosY;

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
	return currentBlockModel;
}

// �� �׸���
void ShowBlock(char blockInfo[][4])
{
	int y, x;
	Point curPos = GetCurrentCursorPos();

	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			SetCurrentCursorPos(curPos.x + (x * 2), curPos.y + y);  //Ư�� ���� �ϳ��� ��� �� ��ĭ�� ����

			if (blockInfo[y][x] == 1)
				printf("��");
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
void BlockDown()
{
	RemoveBlock(blockModel[GetCurrentBlockIdx()]);
	curPosY += 1;

	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}