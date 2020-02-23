#include<stdio.h>
#include<malloc.h>
#define MAX 20
#pragma warning(disable:4996)

typedef struct BTNode {       /*�ڵ�ṹ����*/
	char data;               /*�ڵ�����*/
	struct BTNode *lchild;
	struct BTNode *rchild;  /*ָ��*/
}*BiTree;

void createBiTree(BiTree *t) { /* �����������������*/
	char s;
	BiTree q;
	s = getchar();
	if (s == '#') { 
		*t = NULL; 
		return;
	}
	q = (BiTree)malloc(sizeof(struct BTNode));
	if (q == NULL) { 
		printf("Memory alloc failure!"); 
		exit(0);
	}
	q->data = s;
	*t = q;
	createBiTree(&q->lchild); /*�ݹ齨��������*/
	createBiTree(&q->rchild); /*�ݹ齨��������*/
}

void PreOrder(BiTree p) {  /* �������������*/
	if (p != NULL) {
		printf("%c", p->data);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
}
void InOrder(BiTree p) {  /* �������������*/
	if (p != NULL) {
		InOrder(p->lchild);
		printf("%c", p->data);
		InOrder(p->rchild);
	}
}
void PostOrder(BiTree p) {  /* �������������*/
	if (p != NULL) {
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		printf("%c", p->data);
	}
}
void release(BiTree t) { /*�ͷŶ������ռ�*/
	if (t != NULL) {
		release(t->lchild);
		release(t->rchild);
		free(t);
	}
}

int main() {
	BiTree t = NULL;
	printf("\n���������ݣ�(���� # ��ʾ)");
	createBiTree(&t);
	printf("\n\n��������ǣ�");
	PreOrder(t);
	printf("\n\n��������ǣ�");
	InOrder(t);
	printf("\n\n��������ǣ�");
	PostOrder(t);
	release(t);
	system("pause");
	return 0;
}