/* Name: keyCurControl.h  ver 1.1
 * Content: 커서, 키보드 컨트롤 함수들의 정의
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */

#ifndef __KEY_CURSOR_H_
#define __KEY_CURSOR_H_

#include "point.h"

void RemoveCursor(void);
point GetCurrentCursorPos(void);
void SetCurrentCursorPos(int x, int y);
void ProcessKeyInput(void);
void InitKeyDelayRate(int rate);

#endif
/* end of file */