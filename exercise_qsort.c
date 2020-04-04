#include<stdio.h>
#include<Windows.h>

int int_cmp(const void *x, const void *y)
{
	const int *_x = (int *)x;
	const int *_y = (int *)y;
	if (*_x > *_y) {
		return -1;
	}
	else if (*_x < *_y) {
		return 1;
	}
	else {
		return 0;
	}
}

int main()
{
	int a[10] = { 10,29,4,5,23,63,23,66,27,72 };
	
	qsort(a, sizeof(a) / sizeof(a[0]), sizeof(int), int_cmp);
	
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		printf("%3d", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}