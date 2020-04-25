#ifndef __CONTACT_H__ 
#define __CONTACT_H__ 
#include<string.h> 
#include<stdio.h> 
#include<assert.h> 
#include<stdlib.h> 
enum Option
{
	QUIT,
	ADD,
	SHOW,
	DEL,
	SEARCH,
	EMPTY,
	DESTORY,
	SAVE,
	LOAD
};
#define MAX_NAME 20 
#define SEX_NAME 5 
#define TEL_NAME 12 
#define ADDR_NAME 20 
//ͨѶ¼���Ϊ1000�� 
#define MAX_PER_NUM 1000 
//��̬���ݰ汾 
#define DEFAULT_SIZE 2; 

#pragma warning(disable:4996)

typedef struct PersonInfo
{
	char name[MAX_NAME];
	char sex[SEX_NAME];
	short age;
	char tele[TEL_NAME];
	char addr[TEL_NAME];
}PersonInfo;
typedef struct Contact
{
	//PersonInfo per[MAX_PER_NUM] ;��ͨ�汾 
	PersonInfo* per;
	int usedsize;//��Ч���ݸ��� 
	int capacity;//��ʼ���� 
}Contact;//ͨѶ¼ 
//��ʼ��ͨѶ¼ 
void InitContact(Contact *con);
//��ӳ�Ա 
void AddContact(Contact *con);
//��ӡͨѶ¼ 
void ShowContact(Contact *con);
//ɾ����Ա 
void DelContact(Contact *con);
//���ҳ�Ա 
int SearchContact(Contact *con);
//���ͨѶ¼ 
void EmptyContact(Contact *con);
//�ݻ�ͨѶ¼(��̬�汾) 
void DestoryContact(Contact *con);
//�ļ��汾 //������ϵ�˵��ļ� 
void SaveContact(Contact *con);
//������ϵ�� 
void LoadContact(Contact *con);
#endif //__CONTACT_H__