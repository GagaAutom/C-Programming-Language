#include <stdio.h> 
#include <windows.h>
int main()
{
	int i, j;
	for (i = 1; i < 10; i++)//ѭ��Ƕ�ף�ʹ������1~9����
	{
		for (j = 1; j < 10; j++)//ѭ��Ƕ�ף�ʹ����1~9����
		{
			Sleep(1000);
			printf("%d*%d=%d\t", i, j, i*j);
		}
		printf("\n");
	}	
	system("pause");
	return 0;
}