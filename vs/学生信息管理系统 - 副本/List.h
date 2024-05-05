#pragma once
#include <stdlib.h>

//#include <stdio.h>
//#include <string.h>
//#include <Windows.h>
//������������
typedef void* variant;

//����һ���ڵ�
typedef struct node {
	variant data;
	struct node* next;
}NODE;

//�����½ڵ�
NODE* createNode(variant data) {
	NODE* newNode = (NODE*)calloc(1, sizeof(NODE));
	if (!newNode)
		return NULL;
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//����ṹ��
typedef struct list {
	int size;		//�ڵ����
	NODE* head;		//ͷָ��
	NODE* tail;		//βָ��
}LIST;
//�ж������Ƿ�Ϊ��
int empty(LIST* list) {
	return list->size == 0;
}

//��ʼ������
void initList(LIST* list) {
	//����ͷ�ڵ�
	list->head = list->tail = NULL;
	list->size = 0;
}
//�������_ͷ�巨
void addList_h(LIST* list, variant data) {
	NODE* newNode = createNode(data);
	if (!list->head)
		list->tail = newNode;
	else
		newNode->next = list->head;
	list->head = newNode;
	list->size++;
}

//�������_β�巨
void addList_t(LIST* list, variant data) {
	NODE* newNode = createNode(data);
	if (!list->head)
		list->head = newNode;
	else
		list->tail->next=newNode;
	list->tail = newNode;
	list->size++;
}

//�������_��ָ��λ��
int addList_pos(LIST* list, variant data, unsigned pos) {
	if (pos == 0)
		return 0;
	if (pos > list->size + 1)
		return -1;
	if (!list->head) {
		NODE* newNode = createNode(data);
		list->head = newNode;
		list->tail = newNode;
	}
	else  if (pos==1) {
		NODE* newNode = createNode(data);
		newNode->next = list->head;
		list->head = newNode;
	}
	else{
		NODE* p = list->head;
		for (int i = 1; i < pos-1; i++)
			p = p->next;
		NODE* newNode = createNode(data);
		newNode->next = p->next;
		p->next = newNode;
		if (pos == list->size)
			list->tail = newNode;
	}
	list->size++;
	return list->size;
}

//ɾ������_��ָ����λ��
int deleteNode_pos(LIST* list, unsigned pos) {
	if (pos == 0)
		return 0;
	if (pos > list->size||!list->head)
		return -1;
	NODE* p = list->head;
	if (pos == 1){
		list->head = p->next;
		free(p);
	}
	else{
		NODE* q = p;
		for (int i = 1; i < pos; i++) {
			q = p;
			p = p->next;
		}
		q->next = p->next;
		if (p == list->tail)
			list->tail = q;
		free(p);
	}
	list->size--;
	return list->size;
}

//��������
void destrList(LIST* list) {
	while (list->head) {
		NODE* temp = list->head;
		list->head = list->head->next;
		free(temp);
	}
	list->head=list->tail=NULL;
	list->size = 0;
	return;
}

//��дһ���������������лص��Ǽ�
typedef void (*FUN)(variant data);
void foreach(LIST* list,  FUN fun) {
	NODE* curNode = list->head;
	while (curNode) {
		fun(curNode->data);
		curNode = curNode->next;
	}
	return ;
}
