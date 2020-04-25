#include "contact.h"

//��ʼ��ͨѶ¼ 
void InitContact(Contact *pcon) {
	//��ͨ�汾
	//pcon->usedSize = 0; 
	//memset(pcon->per,0,sizeof(pcon->per));

	pcon->usedsize = 0;
	pcon->capacity = DEFAULT_SIZE;
	pcon->per = (PersonInfo *)malloc(
		sizeof(PersonInfo) * pcon->capacity);
	assert(pcon->per != NULL);

	LoadContact(pcon);
}
//��ӳ�Ա 
void AddContact(Contact *pcon) {
	//��ͨ�汾�������ݽ���취
	//if(pcon->usedSize == MAX_NUMBER)
	//{
	//	printf("this contact is full\n");
	//	return;
	//}

	if (CheckFullAndRe(pcon) != 1)
	{
		printf("����ʧ��\n");
		return;
	}

	printf("������������");
	scanf("%s", pcon->per[pcon->usedsize].name);
	printf("���������䣺");
	scanf("%d", &(pcon->per[pcon->usedsize].age));
	printf("�������Ա�");
	scanf("%s", pcon->per[pcon->usedsize].sex);
	printf("������绰��");
	scanf("%s", pcon->per[pcon->usedsize].tele);
	printf("������סַ��");
	scanf("%s", pcon->per[pcon->usedsize].addr);
	pcon->usedsize++;
	printf("��ӳɹ�\n");
}
//��ӡͨѶ¼ 
void ShowContact(Contact *pcon) {
	int i = 0;
	printf("%-10s %-5s %-5s %-11s %-20s\n", "����", "����",
		"�Ա�", "�绰", "סַ");
	for (i = 0; i < pcon->usedsize; i++)
	{
		printf("%-10s %-5d %-5s %-11s %-20s\n",
			pcon->per[i].name, pcon->per[i].age,
			pcon->per[i].sex, pcon->per[i].tele,
			pcon->per[i].addr);
	}
}
//ɾ����Ա 
void DelContact(Contact *pcon) {
	int index = SearchContact(pcon);
	int i = 0;
	if (index == -1)
	{
		printf("ɾ��ʧ�ܣ����޴���\n");
		return;
	}
	for (i = index; i < pcon->usedsize - 1; i++)
	{
		pcon->per[i] = pcon->per[i + 1];
	}
	pcon->usedsize--;
	printf("ɾ���ɹ�\n");
}
//���ҳ�Ա 
int SearchContact(Contact *pcon) {
	int i = 0;
	char name[MAX_NAME] = { 0 };
	if (pcon->usedsize == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		return -1;
	}
	printf("��������Ҫɾ����������");
	scanf("%s", name);
	for (i = 0; i < pcon->usedsize; i++)
	{
		if (strcmp(pcon->per[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
//���ͨѶ¼ 
void EmptyContact(Contact *pcon) {
	pcon->usedsize = 0;
}
//�ݻ�ͨѶ¼(��̬�汾) 
void DestoryContact(Contact *pcon) {
	SaveContact(pcon);
	free(pcon->per);
	pcon->per = NULL;//Ԥ��Ұָ��  
	pcon->capacity = 0;
	pcon->usedsize = 0;
}
//�ļ��汾 //������ϵ�˵��ļ� 
void SaveContact(Contact *pcon) {
	int i = 0;
	FILE *pf = fopen("Contact.bat", "wb");
	assert(pf != NULL);
	for (i = 0; i < pcon->usedsize; i++)
	{
		fwrite(pcon->per + i, sizeof(PersonInfo), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}
//������ϵ�� 
void LoadContact(Contact *pcon) {
	FILE *pf = fopen("Contact.bat", "rb");
	PersonInfo tmp = { 0 };
	if (pf == NULL)
	{
		return;
	}
	//fread�����ķ���ֵ�ǣ���ȡ�ɹ����ֽ���
	while (fread(&tmp, sizeof(PersonInfo), 1, pf) > 0)
	{
		//�����ж��Ƿ�Ϊ���������������
		CheckFullAndRe(pcon);
		pcon->per[pcon->usedsize++] = tmp;
	}
	fclose(pf);
	pf = NULL;
}
//����ͨѶ¼
static int CheckFullAndRe(Contact *pcon) {
	if (pcon->usedsize == pcon->capacity)
	{
		PersonInfo * ptr = NULL;
		ptr = (PersonInfo *)realloc(pcon->per,
			sizeof(PersonInfo) * pcon->capacity * 2);
		if (ptr != NULL)
		{
			pcon->per = ptr;
			pcon->capacity *= 2;
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