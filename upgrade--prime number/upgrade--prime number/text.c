#include <stdio.h>
#include <math.h>
int main()
{
	int i, j;//iΪ��������jΪ����
	int k;//�ݴ��ƽ�������
	for (i = 100; i <= 200; i++)
	{
		k = (int)sqrt((double)i);// ��ƽ������ע��sqrt()�Ĳ���Ϊ double ���ͣ�����Ҫǿ��ת��i������
		for (j = 2; j < k; j++)
		{
			if (i % j == 0)
				break;
		}
		if (j >= k)
			printf("%d\t", i);
	}
	system("pause");
	return 0;
}