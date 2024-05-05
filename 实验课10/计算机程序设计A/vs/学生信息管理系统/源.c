#define _CRT_SECURE_NO_WARNINGS 1
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
	if (stuList->head == NULL ) {
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
				if(p_next_data->id < newData->id){
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
		if (curData->id> nextData->id)
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
	while (p->next != NULL ) {
		STU* p_next_data = p->next->data;
		if(p_next_data->id != id){
			p = p->next;
		}else
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
	NODE* curNode=stuList->head;
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
	float sum=0;
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
	float max=0;
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
	for(int i=0;i<n;i++){
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

int main() { 
	LIST* stuList = (LIST*)malloc(sizeof(LIST));
	initList(stuList);
	int option;
menu:	
	system("cls");
	showMenu();
	scanf("%d", &option);
	switch (option) {
	case 0:
		return 0;
	//����ѧ����¼����
	case 1:{
		system("cls");
		if (stuList->head) {
			printf("����������ѧ����Ϣ��\n");
			break;
		}
		//�����������������Ϣ
		uint64 id;
		char name[10];
		byte sex;
		unsigned age;
		float score;
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
		if (option == 1) {
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
		}
		//β�巨
		else if (option == 2) {
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
		}
		//��ѧ������������
		else if (option == 3) {
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
		}
		//��ѧ����Ϣ�ļ���������
		else if (option == 4) {
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
		}
		else
			goto menu;
		break;
	}
	//��ӡȫ��ѧ����¼
	case 2: {
		system("cls");
		printHeader();
		foreach(stuList, printStu);
		break;
	}
	//����һ���µ�ѧ����¼
	case 3: {
		system("cls");
		//�����������������Ϣ
		unsigned pos;
		uint64 id;
		char name[10];
		byte sex;
		unsigned age;
		float score;
		//��ʾ�����˵�
		printf("0�����ϼ��˵�\n");
		printf("1��ָ��λ�����\n");
		printf("2�����������в���\n");
		printf("************************\n");
		printf("��������Ӧ������ִ�й��ܣ�\n");
		int option;
		scanf("%d", &option);
		//��ָ��λ�����
		if (option == 1) {
			system("cls");
			//��������
		loop_1:
			printf("������ѧ���������е�λ������0����ֹ¼�룩��");
			scanf("%u", &pos);
			if (pos == 0)
				break;
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
		}
		//�����������в���
		else if (option == 2) {
			system("cls");
			//��������
			if (!IsInOrder(stuList)) {
				printf("����δ����ѧ���������У���������ٽ��д˲�����\n");
				break;
			}
			printf("������ѧ��ѧ�ţ�����0����ֹ¼�룩:");
		loop_6:
			scanf("%llu", &id);
			if (!id)
				break;
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
		}
		else
			goto menu;
		break;
	}
	//������ɾ��һ��ѧ����¼
	case 4: {
		system("cls");
		//�����������������Ϣ
		unsigned pos;
		uint64 id;
		//��ʾ�����˵�
		printf("0�����ϼ��˵�\n");
		printf("1ɾ��ָ��λ�õļ�¼\n");
		printf("2ɾ��ָ��ѧ�ŵļ�¼\n");
		printf("************************\n");
		printf("��������Ӧ������ִ�й��ܣ�\n");
		int option;
		scanf("%d", &option);
		//ɾ��ָ��λ�õļ�¼
		if (option == 1) {
			system("cls");
			//��������
		loop_2:
			printf("������ѧ���������е�λ������0����ֹ¼�룩��\n");
			scanf("%u", &pos);
			if (pos == 0)
				break;
			//�Ϸ��Լ��
			if (pos > stuList->size) {
				printf("��ǰѧ������Ϊ%d���������λ��������������룡\n",stuList->size);
				goto loop_2;
			}
			deleteNode_pos(stuList, pos);
			printf("ɾ���ɹ���\n");
		}
		//ɾ��ָ��ѧ�ŵļ�¼
		else if (option == 2) {
			printf("������ѧ��ѧ��:\n");
			scanf("%llu", &id);
			int flag = deleteStu_id(stuList, id);
			if(flag==-1)
				printf("δ�ҵ���ѧ����\n");
			else if (flag > -1)
				printf("ɾ���ɹ���\n");
		}
		else
			goto menu;
		break;
	}
	//��ѧ�Ų���ѧ����¼
	case 5: {
		uint64 id;
		system("cls");
		printf("������ѧ��ѧ��:\n");
		scanf("%llu", &id);
		NODE* found = findStu(stuList, id);
		if (!found)
			printf("δ�ҵ���ѧ����\n");
		else{
			STU* stu = found->data;
			printHeader();
			printStu(stu);
		}
		break;
	}
	//ͳ��ѧ����Ϣ
	case 6: {
		system("cls");
		if (!stuList->head) {
			printf("ͳ��ʧ�ܣ����ȴ��������ʼ��ѧ����Ϣ��\n");
			break;
		}
		printf("ѧ��������%d\n",stuList->size);
		printf("ƽ���ɼ���%.2f\n", scoreAve(stuList));
		printf("��߷֣�%.2f\n", scoreMax(stuList->head));
		printf("������������%d\n", failedNum(stuList->head)); 
		printf("************************\n");
		break;
	}
	//��������
	case 7: {
		system("cls");
		destrList(stuList);
		printf("���ٳɹ���\n");
		break;
	}
	//��ѧ����Ϣд������ļ�
	case 8: {
		system("cls");
		printf("0�����ϼ��˵�\n");
		printf("1��дѧ���ļ�\n");
		printf("2׷��ѧ���ļ�\n");
		printf("3���ѧ���ļ�\n");
		printf("************************\n");
		printf("��������Ӧ������ִ�й��ܣ�\n");
		FILE* fp;
		int option;
		scanf("%d", &option);
		if (option == 1) {
			if (!stuList->head) {
				printf("û�п���д���ѧ����Ϣ��\n");
				break;
			}
			fp = fopen("stuList.dat", "wb");
			if (!fp) {
				printf("����δ֪�����´��ļ�ʧ�ܣ�\n");
				break;
			}
			foreach_fp(stuList, fp, writeStu);
			fclose(fp);
			printf("��д�ɹ�������ѧ����Ϣ�Ķ������ļ�\"stuList.dat\"λ�ڳ�������ͬһĿ¼�£�\n");
		}
		else if (option == 2) {
			if (!stuList->head) {
				printf("û�п���׷�ӵ�ѧ����Ϣ��\n");
				break;
			}
			fp = fopen("stuList.dat", "ab");
			if (!fp) {
				printf("����δ֪�����´��ļ�ʧ�ܣ�\n");
				break;
			}
			foreach_fp(stuList, fp, writeStu);
			fclose(fp);
			printf("׷�ӳɹ�������ѧ����Ϣ�Ķ������ļ�\"stuList.dat\"λ�ڳ�������ͬһĿ¼�£�\n");
		}
		else if (option == 3) {
			fp = fopen("stuList.dat", "wb");
			if (!fp) {
				printf("����δ֪�����´��ļ�ʧ�ܣ�\n");
				break;
			}
			fclose(fp);
			printf("���ѧ���ļ��ɹ���\n");
		}
		break;
	}
	//��ѧ��������������
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
	goto menu;
}