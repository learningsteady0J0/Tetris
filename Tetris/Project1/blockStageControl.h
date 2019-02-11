/* Name: blockStageControl.h ver 1.2
 * Content: ����, ����ȭ�� ��Ʈ�� �Լ����� ����
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */

#ifndef __BLOCK_STAGE_H_
#define __BLOCK_STAGE_H_

void InitNewBlockPos(int x, int y);
void ChooseBlock(void);
int GetCurrentBlockIdx(void);
void ShowBlock(char blockInfo[][4]);
void DeleteBlock(char blockInfo[][4]);
int BlockDown(void);
void ShiftLeft(void);
void ShiftRight(void);
void RotateBlock(void);

void AddCurrentBlockInfoToBoard(void);
void DrawGameBoard(void);
int IsGameOver(void);

#endif