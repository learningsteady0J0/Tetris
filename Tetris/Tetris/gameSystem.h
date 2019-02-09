#ifndef __GAMESYSTEM_H__
#define __GAMESYSTEM_H__

int GetCurrentBlockIdx(void);
void InitNewBlockPos(int x, int y);
void ShowBlock(char blockInfo[][4]);
int ChooseBlock(void);
void BlockDown();
void RemoveBlock(char blockInfo[][4]);

#endif

/* end of file */