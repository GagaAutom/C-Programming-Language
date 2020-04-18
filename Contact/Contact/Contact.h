#ifndef  ___CONTACT__H__
#define ___CONTACT__H__
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include<assert.h>
//#include<vld.h>
enum Oper
{
	EXIT,
	ADD,
	DEL,
	SEAR,
	SHOW,
	CLEAR,
	SORT,
	DESTORY
};
#define MAX_NAME 10
#define MAX_SEX  5
#define MAX_TELE  11
#define MAX_ADDR 20

#define MAX_NUMBER 1000

#define DEFAULT_SIZE 2

typedef struct PersonInfo
{
	char name[MAX_NAME];//����
	short age;
	char sex[MAX_SEX];//�Ա�
	char tele[MAX_TELE];
	char addr[MAX_ADDR];

}PersonInfo;//ÿһ���˵���Ϣ

typedef struct Contact
{
	//PersonInfo per[MAX_NUMBER]; ��ͨ�汾
	PersonInfo *per;
	int usedSize;//
	int cpaticty;//����
}Contact;//ͨѶ¼

void InitContact(Contact *pcon);
void AddContact(Contact *pcon);
void ShowContact(Contact *pcon);
void DelContact(Contact *pcon);

void ClearContact(Contact *pcon);


void DestoryContact(Contact *pcon);
#endif 