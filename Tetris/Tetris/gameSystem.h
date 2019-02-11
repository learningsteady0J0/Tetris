#ifndef __GAMESYSTEM_H__
#define __GAMESYSTEM_H__

int GetCurrentBlockIdx(void);
void InitNewBlockPos(int x, int y);
void ShowBlock(char blockInfo[][4]);
void ChooseBlock(void);
int BlockDown();
void RemoveBlock(char blockInfo[][4]);
void BlockLeft(void);
int DetectCollision(int posX, int posY, char blcokModel[][4]);
void BlockRight(void);
void RotateBlock(void);
void InitRotate(void);
void DrawGameBoard(void);

#endif

/* end of file */