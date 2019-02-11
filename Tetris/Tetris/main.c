#include "common.h"
#include "keyCurControl.h"
#include "gameSystem.h"

#define START_CURPOS_X	(6*2)
#define START_CURPOS_Y	(2)

int main(void)
{
	int i;
	RemoveCursor();
	InitKeyDelayRate(3);
	DrawGameBoard();


	while (1)
	{
		InitNewBlockPos(START_CURPOS_X, START_CURPOS_Y);
		ChooseBlock();
		InitRotate();


		while (1)
		{
			UserKeyInput();
		}
		

	}

	return 0;
}