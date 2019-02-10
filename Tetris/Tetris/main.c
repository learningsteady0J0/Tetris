#include "common.h"
#include "keyCurControl.h"
#include "gameSystem.h"

#define START_CURPOS_X	(5*2)
#define START_CURPOS_Y	(0)

int main(void)
{
	int i;
	RemoveCursor();

	InitNewBlockPos(START_CURPOS_X, START_CURPOS_Y);

	ChooseBlock();

	InitKeyDelayRate(5);

	while (1)
	{
		BlockDown();
		UserKeyInput();
	}
	return 0;
}