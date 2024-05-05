#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "List.h"
#include "stuList.h"

void createStuList_head(LIST* stuList) {
	//�����������������Ϣ
	uint64 id;
	char name[10];
	byte sex;
	unsigned age;
	float score;
	system("cls");
	printf("������ѧ��ѧ�ţ�����0����ֹ¼�룩:");
	scanf("%llu", &id);
	while (id)
	{
		printf("������ѧ��������");
		scanf("%s", name);  getchar();
		printf("������ѧ���Ա���1Ů0����");
		scanf("%d", &sex);
		printf("������ѧ�����䣺");
		scanf("%u", &age);
		printf("������ѧ���ɼ���");
		scanf("%f", &score);
		STU* stu = createStu(id, name, sex, age, score);
		addList_h(stuList, stu);
		printf("����ɹ���\n\n��������һλѧ��ѧ�ţ�����0����ֹ¼�룩:");
	loop_7:
		scanf("%llu", &id);
		if (checkID(stuList, id)) {
			if (checkID(stuList, id)) {
				printf("ѧ���ظ����������������ѧ�ţ�");
				goto loop_7;
			}
		}
	}
	printf("¼�������\n");
	return;
}

void createStuList_tail(LIST* stuList) {
	//�����������������Ϣ
	uint64 id;
	char name[10];
	byte sex;
	unsigned age;
	float score;
	system("cls");
	printf("������ѧ��ѧ�ţ�����0����ֹ¼�룩:");
	scanf("%llu", &id);
	while (id)
	{
		//��������
		printf("������ѧ��������");
		scanf("%s", name);  getchar();
		printf("������ѧ���Ա���1Ů0����");
		scanf("%d", &sex);
		printf("������ѧ�����䣺");
		scanf("%u", &age);
		printf("������ѧ���ɼ���");
		scanf("%f", &score);
		STU* stu = createStu(id, name, sex, age, score);
		//β�����
		addList_t(stuList, stu);
		printf("����ɹ���\n\n��������һλѧ��ѧ�ţ�����0����ֹ¼�룩:");
	loop_5:
		scanf("%llu", &id);
		if (checkID(stuList, id)) {
			printf("ѧ���ظ����������������ѧ�ţ�");
			goto loop_5;
		}
	}
	printf("¼�������\n");
	return;
}

void createStuList_order_id(LIST* stuList) {
	//�����������������Ϣ
	uint64 id;
	char name[10];
	byte sex;
	unsigned age;
	float score;
	system("cls");
	printf("������ѧ��ѧ�ţ�����0����ֹ¼�룩:");
	scanf("%llu", &id);
	while (id)
	{
		//��������
		printf("������ѧ��������");
		scanf("%s", name); getchar();
		printf("������ѧ���Ա���1Ů0����");
		scanf("%d", &sex);
		printf("������ѧ�����䣺");
		scanf("%u", &age);
		printf("������ѧ���ɼ���");
		scanf("%f", &score);
		STU* stu = createStu(id, name, sex, age, score);
		NODE* newNode = createNode(stu);
		//��ѧ��˳�����
		addList_order_id(newNode, stuList);
		printf("����ɹ���\n\n��������һλѧ��ѧ�ţ�����0����ֹ¼�룩:");
	loop_4:
		scanf("%llu", &id);
		if (checkID(stuList, id)) {
			printf("ѧ���ظ����������������ѧ�ţ�");
			goto loop_4;
		}
	}
	printf("¼�������\n");
	return;
}

void createStuList_file(LIST* stuList) {
	FILE* fp;
	fp = fopen("stuList.dat", "rb");
	while (!feof(fp)) {
		STU* stu = (STU*)malloc(sizeof(STU));
		fread(stu, sizeof(STU), 1, fp);
		addList_t(stuList, stu);
	}

	if (ferror(fp)) {
		puts("��ȡ����");
		destrList(stuList);
	}
	else if (feof(fp)) {
		puts("�ļ���ȡ�������������ɹ���");
		deleteNode_pos(stuList, stuList->size);
	}
	fclose(fp);
	return;
}

void printStuList(LIST* stuList) {
	printHeader();
	foreach(stuList, printStu);
	return;
}

void addStuList_position(LIST* stuList) {
	system("cls");
	//�����������������Ϣ
	unsigned pos;
	uint64 id;
	char name[10];
	byte sex;
	unsigned age;
	float score;
	//��������
loop_1:
	printf("������ѧ���������е�λ������0����ֹ¼�룩��");
	scanf("%u", &pos);
	if (pos == 0)
		return;
	if (pos > stuList->size + 1) {//�Ϸ��Լ��
		printf("��ǰѧ������Ϊ%d���������λ��������������룡\n", stuList->size); system("pause");
		goto loop_1;
	}
	printf("������ѧ��ѧ��:");
loop_3:
	scanf("%llu", &id);
	if (checkID(stuList, id)) {
		printf("ѧ���ظ����������������ѧ�ţ�");
		goto loop_3;
	}
	printf("������ѧ��������");
	scanf("%s", name);  getchar();
	printf("������ѧ���Ա���1Ů0����");
	scanf("%d", &sex);
	printf("������ѧ�����䣺");
	scanf("%u", &age);
	printf("������ѧ���ɼ���");
	scanf("%f", &score);
	//����ѧ��
	STU* stu = createStu(id, name, sex, age, score);
	//��������
	addList_pos(stuList, stu, pos);
	printf("����ɹ���\n");
	return;
}

void addStuList_order_id(LIST* stuList) {
	system("cls");
	//�����������������Ϣ
	unsigned pos;
	uint64 id;
	char name[10];
	byte sex;
	unsigned age;
	float score;
	//��������
	if (!IsInOrder(stuList)) {
		printf("����δ����ѧ���������У���������ٽ��д˲�����\n");
		return;
	}
	printf("������ѧ��ѧ�ţ�����0����ֹ¼�룩:");
loop_6:
	scanf("%llu", &id);
	if (!id)
		return;
	if (checkID(stuList, id)) {
		printf("ѧ���ظ����������������ѧ�ţ�");
		goto loop_6;
	}
	printf("������ѧ��������");
	scanf("%s", name);  getchar();
	printf("������ѧ���Ա���1Ů0����");
	scanf("%d", &sex);
	printf("������ѧ�����䣺");
	scanf("%u", &age);
	printf("������ѧ���ɼ���");
	scanf("%f", &score);
	//����ѧ��
	STU* stu = createStu(id, name, sex, age, score);
	NODE* newNode = createNode(stu);
	//��������
	addList_order_id(newNode, stuList);
	printf("����ɹ���\n");
	return;
}

void deleteStu_position(LIST* stuList) {
	system("cls");
	//�����������������Ϣ
	unsigned pos;
	uint64 id;
	//��������
loop_2:
	printf("������ѧ���������е�λ������0����ֹ¼�룩��\n");
	scanf("%u", &pos);
	if (pos == 0)
		return;
	//�Ϸ��Լ��
	if (pos > stuList->size) {
		printf("��ǰѧ������Ϊ%d���������λ��������������룡\n", stuList->size);
		goto loop_2;
	}
	deleteNode_pos(stuList, pos);
	printf("ɾ���ɹ���\n");
	return;
}

void deleteStu_by_id(LIST* stuList) {
	//�����������������Ϣ
	uint64 id;
	printf("������ѧ��ѧ��:\n");
	scanf("%llu", &id);
	int flag = deleteStu_id(stuList, id);
	if (flag == -1)
		printf("δ�ҵ���ѧ����\n");
	else if (flag > -1)
		printf("ɾ���ɹ���\n");
	return;
}

void searchStu(LIST* stuList) {
	uint64 id;
	printf("������ѧ��ѧ��:\n");
	scanf("%llu", &id);
	NODE* found = findStu(stuList, id);
	if (!found)
		printf("δ�ҵ���ѧ����\n");
	else {
		STU* stu = found->data;
		printHeader();
		printStu(stu);
	}
	return;
}

void statistics(LIST* stuList) {
	if (!stuList->head) {
		printf("ͳ��ʧ�ܣ����ȴ��������ʼ��ѧ����Ϣ��\n");
		return;
	}
	printf("ѧ��������%d\n", stuList->size);
	printf("ƽ���ɼ���%.2f\n", scoreAve(stuList));
	printf("��߷֣�%.2f\n", scoreMax(stuList->head));
	printf("������������%d\n", failedNum(stuList->head));
	printf("************************\n");
	return;
}

void reWriteStuListFile(LIST* stuList) {
	FILE* fp;
	if (!stuList->head) {
		printf("û�п���д���ѧ����Ϣ��\n");
		return;
	}
	fp = fopen("stuList.dat", "wb");
	if (!fp) {
		printf("����δ֪�����´��ļ�ʧ�ܣ�\n");
		return;
	}
	foreach_fp1(stuList, fp, writeStu);
	fclose(fp);
	printf("��д�ɹ�������ѧ����Ϣ�Ķ������ļ�\"stuList.dat\"λ�ڳ�������ͬһĿ¼�£�\n");
	return;
}


void clearStuListFile(LIST* stuList) {
	FILE* fp;
	fp = fopen("stuList.dat", "wb");
	if (!fp) {
		printf("����δ֪�����´��ļ�ʧ�ܣ�\n");
		return;
	}
	fclose(fp);
	printf("���ѧ���ļ��ɹ���\n");
	return;
}
//typedef void* FUN_fp(variant data, FILE* fp);
////void foreach_fp1(LIST* list, FILE* fp, FUN_fp fun_fp)
//void foreach_fp1(LIST* list, FILE* fp)
//
//{
//	NODE* curNode = list->head;
//	while (curNode) {
//		fun_fp(curNode->data, fp);
//		curNode = curNode->next;
//	}
//	return;
//}

void addStuListFile(LIST* stuList) {
	FILE* fp;
	if (!stuList->head) {
		printf("û�п���׷�ӵ�ѧ����Ϣ��\n");
		return;
	}
	fp = fopen("stuList.dat", "ab");
	if (!fp) {
		printf("����δ֪�����´��ļ�ʧ�ܣ�\n");
		return;
	}
	foreach_fp1(stuList, fp, writeStu);
	//foreach_fp1(stuList, fp);
	fclose(fp);
	printf("׷�ӳɹ�������ѧ����Ϣ�Ķ������ļ�\"stuList.dat\"λ�ڳ�������ͬһĿ¼�£�\n");
	return;
}
