#include<stdio.h>
#pragma warning(disable:4996)

int count_different_bits(int x, int y)
{
	int num = 0;
	int count = 0;
	num = x ^ y;
	while (num) {
		num &= (num - 1);
		count++;
	}
	return count;
}

int main()
{
	int m, n;
	printf("����������m��");
	scanf("%d", &m);
	printf("����������n��");
	scanf("%d", &n);
	printf("m , n���� %d �ı���λ��ͬ\n", count_different_bits(m, n));
	system("pause");
	return 0;
}