#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"

void LoadContact(Contact *pcon)
{
	FILE *pf = fopen("Contact.bat","rb");
	PersonInfo tmp = {0};
	if(pf == NULL)
	{
		return;
	}
	//fread�����ķ���ֵ�ǣ���ȡ�ɹ����ֽ���
	while(fread(&tmp,sizeof(PersonInfo),1,pf) > 0)
	{
		//�����ж��Ƿ�Ϊ���������������
		CheckFullAndRe(pcon);
		pcon->per[pcon->usedSize++] = tmp;
	}
	fclose(pf);
	pf = NULL;
}

void InitContact(Contact *pcon)
{
	/*pcon->usedSize = 0; ��ͨ�汾
	memset(pcon->per,0,sizeof(pcon->per));*/

	pcon ->usedSize = 0;
	pcon->cpaticty = DEFAULT_SIZE;
	pcon->per = (PersonInfo *)malloc(
		sizeof(PersonInfo) * pcon->cpaticty);
	assert(pcon->per != NULL);

	LoadContact(pcon);
}
//����ֵ���� �����Ƿ�ɹ�  1
static int CheckFullAndRe(Contact *pcon)
{
	if(pcon->usedSize == pcon->cpaticty)
	{
		PersonInfo * ptr = NULL;
		ptr = (PersonInfo *)realloc(pcon->per,
			sizeof(PersonInfo) * pcon->cpaticty * 2);
		if(ptr !=NULL)
		{
			pcon->per = ptr;
			pcon->cpaticty *= 2; 
			printf("���ݳɹ�\n");
			return 1;
		}
		else
		{
			return 0;//����ʧ��
		}
	}

	return 1;
}

void AddContact(Contact *pcon)
{
	/*if(pcon->usedSize == MAX_NUMBER)
	{
		printf("������˼����������\n");
		return;
	}*/

	if(CheckFullAndRe(pcon) != 1)
	{
		printf("����ʧ��\n");
		return;
	}

	printf("������������");
	scanf("%s",pcon->per[pcon->usedSize].name);
	printf("���������䣺");
	scanf("%d",&(pcon->per[pcon->usedSize].age));
	printf("�������Ա�");
	scanf("%s",pcon->per[pcon->usedSize].sex);
	printf("������绰��");
	scanf("%s",pcon->per[pcon->usedSize].tele);
	printf("������סַ��");
	scanf("%s",pcon->per[pcon->usedSize].addr);
	pcon->usedSize++;
	printf("��ӳɹ�\n");
}

int SearchContact(Contact *pcon)
{
	int i = 0;
	char name[MAX_NAME] = {0};
	if(pcon->usedSize == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		return -1;
	}
	printf("��������Ҫɾ����������");
	scanf("%s",name);
	for(i = 0;i < pcon->usedSize;i++)
	{
		if(strcmp(pcon->per[i].name,name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void DelContact(Contact *pcon)
{
	int index = SearchContact(pcon);
	int i = 0;
	if(index == -1)
	{
		printf("���޴���\n");
		return;
	}
	for(i = index;i < pcon->usedSize-1;i++)
	{
		pcon->per[i] = pcon->per[i+1];
	}
	pcon->usedSize--;
	printf("ɾ���ɹ�\n");
}


void ShowContact(Contact *pcon)
{
	int i = 0;
	printf("%-10s %-5s %-5s %-11s %-20s\n","����","����",
		"�Ա�","�绰","סַ");
	for(i = 0;i < pcon->usedSize;i++)
	{
		printf("%-10s %-5d %-5s %-11s %-20s\n",
			pcon->per[i].name,pcon->per[i].age,
			pcon->per[i].sex,pcon->per[i].tele,
			pcon->per[i].addr);
	}
}

void ClearContact(Contact *pcon)
{
	pcon->usedSize = 0;
}
//........... 
void SaveContact(Contact *pcon)
{
	int i = 0;
	FILE *pf = fopen("Contact.bat","wb");
	assert(pf != NULL);
	for(i = 0;i < pcon->usedSize;i++)
	{
		fwrite(pcon->per+i,sizeof(PersonInfo),1,pf);
	}
	fclose(pf);
	pf = NULL;
}
void DestoryContact(Contact *pcon)
{
	SaveContact(pcon);
	free(pcon->per);
	pcon->per = NULL;//Ԥ��Ұָ��  
	pcon->cpaticty = 0;
	pcon->usedSize = 0;
}
