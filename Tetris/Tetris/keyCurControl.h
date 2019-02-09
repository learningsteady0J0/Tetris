#ifndef __GETCURSORPOS_H__
#define __GETCURSORPOS_H__

#include "common.h"
#include "point.h"

void SetCurrentCursorPos(int x, int y);
Point GetCurrentCursorPos(void);
void RemoveCursor(void);

#endif

/* end of file */