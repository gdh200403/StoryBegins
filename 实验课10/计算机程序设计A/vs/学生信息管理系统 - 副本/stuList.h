#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "List.h"
typedef unsigned long long uint64;
typedef unsigned char byte;
typedef struct student {
	uint64 id;
	char name[10];
	byte sex;
	unsigned int age;
	float score;
}STU;

//����һ��ѧ����¼
STU* createStu(uint64 id, char* name, byte sex, unsigned int age, float score) {
	STU* stu = (STU*)malloc(sizeof(STU));
	if (!stu)
		return NULL;
	stu->id = id;
	strcpy(stu->name, name);
	stu->sex = sex;
	stu->age = age;
	stu->score = score;
	return stu;
}

//��ӡһ��ѧ����¼
void printStu(STU* stu) {
	printf("%llu\t", stu->id);
	printf("%s\t", stu->name);
	printf("%s\t", stu->sex ? "��" : "Ů");
	printf("%u\t", stu->age);
	printf("%.2f\n", stu->score);
	return;
}

//��������ļ���д��һ��ѧ����¼
void writeStu(STU* stu, FILE* fp) {
	fwrite(stu, sizeof(STU), 1, fp);
	return;
}

//��ӡ��ͷ
void printHeader(void) {
	printf("ѧ��\t\t����\t�Ա�\t����\t�ɼ�\n");
	return;
}

//��ʾ���˵�
void showMenu(void) {
	printf("****ѧ����Ϣ����ϵͳ****\n");
	printf("0�˳�����\n");
	printf("1����ѧ����¼����\n");
	printf("2��ӡȫ��ѧ����¼\n");
	printf("3����һ���µ�ѧ����¼\n");
	printf("4������ɾ��һ��ѧ����¼\n");
	printf("5��ѧ�Ų���ѧ����¼\n");
	printf("6ͳ��\n");
	printf("7����ѧ������\n");
	printf("8��ѧ����Ϣд������ļ�\n");
	printf("9��ѧ����������\n");
	printf("************************\n");
	printf("��������Ӧ������ִ�й��ܣ�\n");
	return;
}

//��ѧ��˳�����
void addList_order_id(NODE* newNode, LIST* stuList) {
	STU* newData = newNode->data;
	if (stuList->head == NULL) {
		newNode->next = stuList->head;
		stuList->head = newNode;
	}
	else {
		STU* headData = stuList->head->data;
		//ͷ�ļ���ʹ����void*���͵�ָ��data��Ҫ����data������STU*���͵�ֵ���ڲ���id��ֵ�������½�STU*���͵�ָ��
		if (headData->id > newData->id) {
			newNode->next = stuList->head;
			stuList->head = newNode;
		}
		else {
			NODE* p = stuList->head;
			while (p->next != NULL) {
				STU* p_next_data = p->next->data;
				if (p_next_data->id < newData->id) {
					p = p->next;
				}
				else
					break;
			}
			newNode->next = p->next;
			p->next = newNode;
		}
	}
	stuList->size++;
	return;
}

//�ж������Ƿ�ѧ��˳������
int IsInOrder(LIST* stuList) {
	if (stuList->size == 1 || stuList->size == 0)
		return 1;
	NODE* cur = stuList->head;
	while (cur && cur->next) {
		STU* curData = cur->data;
		STU* nextData = cur->next->data;
		if (curData->id > nextData->id)
			return 0;
		cur = cur->next;
	}
	return 1;
}

//ɾ��ָ��ѧ�ŵļ�¼
int deleteStu_id(LIST* stuList, uint64 id) {
	STU* headData = stuList->head->data;
	if (stuList->head && headData->id == id) {
		NODE* p = stuList->head;
		stuList->head = p->next;
		free(p);
		stuList->size--;
		return stuList->size;
	}
	NODE* p = stuList->head;
	while (p->next != NULL) {
		STU* p_next_data = p->next->data;
		if (p_next_data->id != id) {
			p = p->next;
		}
		else
			break;
	}
	if (p->next) {
		NODE* q = p->next;
		p->next = q->next;
		free(q);
		stuList->size--;
		return stuList->size;
	}
	return -1;
}

//����ָ��ѧ�ŵļ�¼
NODE* findStu(LIST* stuList, uint64 id) {
	NODE* curNode = stuList->head;
	while (curNode) {
		STU* curData = curNode->data;
		if (curData->id == id)
			break;
		curNode = curNode->next;
	}
	return curNode;
}

//ѧ�Ų��أ�����1�ظ�������0���ظ�
int checkID(LIST* stuList, uint64 id) {
	if (!stuList->head)
		return 0;
	NODE* curNode = stuList->head;
	STU* curData = curNode->data;
	int flag = 0;
	while (curNode) {
		curData = curNode->data;
		if (curData->id == id)
			return 1;
		curNode = curNode->next;
	}
	return 0;
}

//ͳ��ƽ����
float scoreAve(LIST* stuList) {
	float sum = 0;
	NODE* curNode = stuList->head;
	while (curNode) {
		STU* curData = curNode->data;
		sum += curData->score;
		curNode = curNode->next;
	}
	return sum / stuList->size;
}

//ͳ����߷�
float scoreMax(NODE* head) {
	float max = 0;
	NODE* curNode = head;
	while (curNode) {
		STU* curData = curNode->data;
		if (max < curData->score) {
			max = curData->score;
		}
		curNode = curNode->next;
	}
	return max;
}

//ͳ�Ʋ���������
unsigned failedNum(NODE* head) {
	unsigned sum = 0;
	NODE* cur = head;
	while (cur) {
		STU* data = cur->data;
		if (data->score < 60)
			sum++;
		cur = cur->next;
	}
	return sum;
}

//��������
LIST* rearrange(LIST* stuList) {
	if (empty(stuList)) {
		return NULL;
	}
	LIST* newList = (LIST*)malloc(sizeof(LIST));
	initList(newList);
	int n = stuList->size;
	for (int i = 0; i < n; i++) {
		NODE* cur = stuList->head;
		int i = 0;
		int flag = 0;
		STU* minData = cur->data;
		while (cur) {
			STU* curData = cur->data;
			i++;
			if (curData->id <= minData->id) {
				flag = i;
				minData = curData;
			}
			cur = cur->next;
		}
		STU* stu = (STU*)malloc(sizeof(STU));
		stu->age = minData->age;
		stu->id = minData->id;
		strcpy(stu->name, minData->name);
		stu->score = minData->score;
		stu->sex = minData->sex;
		addList_t(newList, stu);
		deleteNode_pos(stuList, flag);
	}
	destrList(stuList);
	return newList;
}

 void createStuList_head(LIST* stuList);
 void createStuList_tail(LIST* stuList);
 void createStuList_order_id(LIST* stuList);
 void createStuList_file(LIST* stuList);
 void printStuList(LIST* stuList);
 void addStuList_position(LIST* stuList);
 void addStuList_order_id(LIST* stuList);
 void deleteStu_position(LIST* stuList);
 void deleteStu_by_id(LIST* stuList);
 void  searchStu(LIST* stuList);
 void statistics(LIST* stuList);
 void reWriteStuListFile(LIST* stuList);
 void addStuListFile(LIST* stuList);
 void clearStuListFile(LIST* stuList);

typedef void* FUN_fp(variant data, FILE* fp);
 void foreach_fp1(LIST* list, FILE* fp, FUN_fp* fun_fp)
 /*void foreach_fp1(LIST* list, FILE* fp)*/
 {
	 NODE* curNode = list->head;
	 while (curNode) {
		 //FUN_fp(curNode->data, fp);
		 fun_fp(curNode->data,fp);
		 curNode = curNode->next;
	 }
	 return;
 }
