#include <stdio.h>
int main()
{
	int i;
	for (i = 1000; i <= 2000; i++)
	{
		if (i % 100 != 0)
		{
			if (i % 4 == 0)//�������궨�壬���Ȳ��ܱ�100��������ͨ�꣬����ܱ�4������Ϊ����
				printf("%d\t", i);
		}
		else if (i % 400 == 0)//������ܱ�100�����������꣬���ܱ�400��������Ϊ����
			printf("%d\t", i);
		/*if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
			printf("%d\t", i);*/
	}
	system("pause");
	return 0;
}