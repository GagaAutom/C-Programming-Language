#include <stdio.h>
int main()
{
	int i, j;
	for (i = 101; i <= 200; i+=2)//ż���϶���2������������ֱ�ӹ��ż����ʹ������ѭ��
	{
		for (j = 2; j < i; j++)
		{
			if (i%j == 0)
				break; 
		}
		if (j >= i)//����������j��ѭ������Ȼ�����������Ǳ�break������˵���������ܱ�2������ǰ������������
			printf("%d\t", i);
	}
	system("pause");
	return 0;
}