#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
//#include "List.h"
#include "stuList.c"


int main() { 
	LIST* stuList = (LIST*)malloc(sizeof(LIST));
	initList(stuList);
	int option;
menu:	
	showMenu();
	scanf("%d", &option);
	switch (option) {
	case 0:
		return 0;
	//*@����ѧ����¼����
	case 1:{
		system("cls");
		//���������Ѵ���ѧ����Ϣ�����ٿ��Ŵ˹���
		if (stuList->head) {
			printf("����������ѧ����Ϣ��\n");
			break;
		}
		//��ʾ�����˵�
		printf("0�����ϼ��˵�\n");
		printf("1ͷ�巨\n");
		printf("2β�巨\n");
		printf("3������ѧ����������\n");
		printf("4��ѧ����Ϣ�ļ���������\n");
		printf("**************************\n");
		printf("��������Ӧ������ִ�й��ܣ�\n");
		int option;
		scanf("%d", &option);
		//ͷ�巨
		if (option == 1)
			createStuList_head(stuList);
		//β�巨
		else if (option == 2)
			createStuList_tail(stuList);
		//��ѧ������������
		else if (option == 3)
			createStuList_order_id(stuList);
		//��ѧ����Ϣ�ļ���������
		else if (option == 4)
			createStuList_file(stuList);
		else
			goto menu;
		break;
	}
	//*@��ӡȫ��ѧ����¼
	case 2: {
		system("cls");
		printStuList(stuList);
		break;
	}
	//*@����һ���µ�ѧ����¼
	case 3: {
		system("cls");
		//��ʾ�����˵�
		printf("0�����ϼ��˵�\n");
		printf("1��ָ��λ�����\n");
		printf("2�����������в���\n");
		printf("************************\n");
		printf("��������Ӧ������ִ�й��ܣ�\n");
		int option;
		scanf("%d", &option);
		//��ָ��λ�����
		if (option == 1)
			addStuList_position(stuList);
		//�����������в���
		else if (option == 2)
			addStuList_order_id(stuList);
		else
			goto menu;
		break;
	}
	//*@������ɾ��һ��ѧ����¼
	case 4: {
		system("cls");
		//��ʾ�����˵�
		printf("0�����ϼ��˵�\n");
		printf("1ɾ��ָ��λ�õļ�¼\n");
		printf("2ɾ��ָ��ѧ�ŵļ�¼\n");
		printf("************************\n");
		printf("��������Ӧ������ִ�й��ܣ�\n");
		int option;
		scanf("%d", &option);
		//ɾ��ָ��λ�õļ�¼
		if (option == 1)
			deleteStu_position(stuList);
		//ɾ��ָ��ѧ�ŵļ�¼
		else if (option == 2)
			deleteStu_by_id(stuList);
		else
			goto menu;
		break;
	}
	//*@��ѧ�Ų���ѧ����¼
	case 5: {
		system("cls");
		searchStu(stuList);
		break;
	}
	//*@ͳ��ѧ����Ϣ
	case 6: {
		system("cls");
		statistics(stuList);
		break;
	}
	//*@��������
	case 7: {
		system("cls");
		destrList(stuList);
		printf("���ٳɹ���\n");
		break;
	}
	//*@��ѧ����Ϣд������ļ�
	case 8: {
		system("cls");
		printf("0�����ϼ��˵�\n");
		printf("1��дѧ���ļ�\n");
		printf("2׷��ѧ���ļ�\n");
		printf("3���ѧ���ļ�\n");
		printf("************************\n");
		printf("��������Ӧ������ִ�й��ܣ�\n");
		int option;
		scanf("%d", &option);
		if (option == 1)
			reWriteStuListFile(stuList);
		else if (option == 2)
			addStuListFile(stuList);
		else if (option == 3)
			clearStuListFile(stuList);
		break;
	}
	//*@��ѧ��������������
	case 9: {
		system("cls");
		LIST* p = rearrange(stuList);
		if (!p) 
			printf("���ȳ�ʼ������\n");
		else {
			stuList = p;
			puts("����ɹ���");
		}
		  }
	default:
		break;
	}
	system("pause");
	system("cls");
	goto menu;
}

