#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

int count_one_bits(unsigned int value)
{
	int count = 0;
	while (value) {
		value &= (value - 1);
		count++;
	}
	return count;
}

int main()
{
	int num = 0;
	printf("�������޷���������");
	scanf("%d", &num);
	printf("�����������1�ĸ���Ϊ��%d\n",count_one_bits(num));
	system("pause");
	return 0;
}