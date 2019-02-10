#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main(void)
{
	int i, j;
	int ch,ch2;
	while (1)
	{
		while (!_kbhit())
		{
			puts("키 입력`");
			Sleep(1000);

		}
		ch = _getch();
		ch2 = _getch();
		printf("입력된 키의 아스키 코드 : %d %d \n", ch,ch2);
	}
	return 0;
}