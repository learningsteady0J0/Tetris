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
			puts("Ű �Է�`");
			Sleep(1000);

		}
		ch = _getch();
		ch2 = _getch();
		printf("�Էµ� Ű�� �ƽ�Ű �ڵ� : %d %d \n", ch,ch2);
	}
	return 0;
}