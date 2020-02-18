#include <stdio.h>
#include <malloc.h>
#pragma warning(disable:4996)
typedef int SElemType;
typedef int Status;
#define INIT_SIZE 100
#define STACKINCREMENT 10
#define Ok 1
#define Error 0
#define True 1
#define False 0
typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;
// ��ʼ��ջ
Status InitStack(SqStack *s)
{
	s->base = (SElemType *)malloc(INIT_SIZE * sizeof(SElemType));
	if (!s->base)
	{
		puts(" �洢�ռ����ʧ�ܣ� ");
		return Error;
	}
	s->top = s->base;
	s->stacksize = INIT_SIZE;
	return Ok;
}
// ���ջ
Status ClearStack(SqStack *s)
{
	s->top = s->base;
	return Ok;
}
// ջ�Ƿ�Ϊ��
Status StackEmpty(SqStack *s)
{
	if (s->top == s->base)
		return True;
	else
		return False;
}
// ����ջ
Status Destroy(SqStack *s)
{
	free(s->base);
	s->base = NULL;
	s->top = NULL;
	s->stacksize = 0;
	return Ok;
}
// ���ջ��Ԫ��
Status GetTop(SqStack *s, SElemType *e)
{
	if (s->top == s->base) return Error;
	e = *(s->top - 1);
	return Ok;
}
// ѹջ
Status Push(SqStack *s, SElemType e)
{
	if (s->top - s->base >= s->stacksize)
	{
		s->base = (SElemType *)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!s->base)
		{
			puts(" �洢�ռ����ʧ�ܣ� ");
			return Error;
		}
		s->top = s->base + s->stacksize;
		s->stacksize += STACKINCREMENT;
	}
	*s->top++ = e;
	return Ok;
}
// ��ջ
Status Pop(SqStack *s, SElemType *e)
{
	if (s->top == s->base) 
		return Error;
	--s->top;
	*e = *(s->top);
	return Ok;
}
// ����ջ
Status StackTraverse(SqStack *s, Status(*visit)(SElemType))
{
	SElemType *b = s->base;
	SElemType *t = s->top;
	while (t > b)
		visit(*b++);
	printf("\n");
	return Ok;
}
Status visit(SElemType c)
{
	printf("%d ", c);
	return Ok;
}
int main()
{
	SqStack a;
	SqStack *s = &a;
	SElemType e;
	InitStack(s);
	int n;
	puts(" ������Ҫ��ջ�ĸ����� ");
	scanf("%d", &n);
	while (n--)
	{
		int m;
		scanf("%d", &m);
		Push(s, m);
	}
	StackTraverse(s, visit);
	puts("");
	while (n--)
	{
		int m;
		Pop(s, &e);
	}
	printf("%d\n", e);
	printf("%d\n", *s->top);
	Destroy(s);
	system("pause");
	return 0;
}