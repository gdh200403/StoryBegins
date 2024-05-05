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

//创建一条学生记录
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

//打印一条学生记录
void printStu(STU* stu) {
	printf("%llu\t", stu->id);
	printf("%s\t", stu->name);
	printf("%s\t", stu->sex ? "男" : "女");
	printf("%u\t", stu->age);
	printf("%.2f\n", stu->score);
	return;
}

//向二进制文件中写入一条学生记录
void writeStu(STU* stu, FILE* fp) {
	fwrite(stu, sizeof(STU), 1, fp);
	return;
}

//打印表头
void printHeader(void) {
	printf("学号\t\t姓名\t性别\t年龄\t成绩\n");
	return;
}

//显示主菜单
void showMenu(void) {
	printf("****学生信息管理系统****\n");
	printf("0退出程序\n");
	printf("1创建学生记录链表\n");
	printf("2打印全部学生记录\n");
	printf("3插入一条新的学生记录\n");
	printf("4按条件删除一条学生记录\n");
	printf("5按学号查找学生记录\n");
	printf("6统计\n");
	printf("7销毁学生链表\n");
	printf("8将学生信息写入磁盘文件\n");
	printf("9按学号升序排列\n");
	printf("************************\n");
	printf("请输入相应数字以执行功能：\n");
	return;
}

//按学号顺序插入
void addList_order_id(NODE* newNode, LIST* stuList) {
	STU* newData = newNode->data;
	if (stuList->head == NULL ) {
		newNode->next = stuList->head;
		stuList->head = newNode;
	}
	else {
		STU* headData = stuList->head->data;
	//头文件中使用了void*类型的指针data，要访问data被赋以STU*类型的值后内部的id的值，必须新建STU*类型的指针
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

//判断链表是否按学号顺序排列
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

//删除指定学号的记录
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

//查找指定学号的记录
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

//学号查重，返回1重复，返回0无重复
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

//统计平均分
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

//统计最高分
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

//统计不及格人数
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

//排序链表
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
	//创建学生记录链表
	case 1:{
		system("cls");
		if (stuList->head) {
			printf("链表中已有学生信息！\n");
			break;
		}
		//定义变量接收输入信息
		uint64 id;
		char name[10];
		byte sex;
		unsigned age;
		float score;
		//显示二级菜单
		printf("0返回上级菜单\n");
		printf("1头插法\n");
		printf("2尾插法\n");
		printf("3创建按学号有序链表\n");
		printf("4打开学生信息文件创建链表\n");
		printf("**************************\n");
		printf("请输入相应数字以执行功能：\n");
		int option;
		scanf("%d", &option);
		//头插法
		if (option == 1) {
			system("cls");
			printf("请输入学生学号（输入0以终止录入）:");
			scanf("%llu", &id);
			while (id)
			{
				printf("请输入学生姓名：");
				scanf("%s", name);  getchar();
				printf("请输入学生性别（男1女0）：");
				scanf("%d", &sex);
				printf("请输入学生年龄：");
				scanf("%u", &age);
				printf("请输入学生成绩：");
				scanf("%f", &score);
				STU* stu = createStu(id, name, sex, age, score);
				addList_h(stuList, stu);
				printf("输入成功！\n\n请输入下一位学生学号（输入0以终止录入）:");
			loop_7:
				scanf("%llu", &id);
				if (checkID(stuList, id)) {
					if (checkID(stuList, id)) {
						printf("学号重复！请检查后重新输入学号：");
						goto loop_7;
					}
				}
			}
			printf("录入结束！\n");
		}
		//尾插法
		else if (option == 2) {
			system("cls");
			printf("请输入学生学号（输入0以终止录入）:");
			scanf("%llu", &id);
			while (id)
			{
				//输入数据
				printf("请输入学生姓名：");
				scanf("%s", name);  getchar();
				printf("请输入学生性别（男1女0）：");
				scanf("%d", &sex);
				printf("请输入学生年龄：");
				scanf("%u", &age);
				printf("请输入学生成绩：");
				scanf("%f", &score);
				STU* stu = createStu(id, name, sex, age, score);
				//尾插插入
				addList_t(stuList, stu);
				printf("输入成功！\n\n请输入下一位学生学号（输入0以终止录入）:");
			loop_5:
				scanf("%llu", &id);
				if (checkID(stuList, id)) {
					printf("学号重复！请检查后重新输入学号：");
					goto loop_5;
				}
			}
			printf("录入结束！\n");
		}
		//按学号有序建立链表
		else if (option == 3) {
			system("cls");
			printf("请输入学生学号（输入0以终止录入）:");
			scanf("%llu", &id);
			while (id)
			{
				//输入数据
				printf("请输入学生姓名：");
				scanf("%s", name); getchar();
				printf("请输入学生性别（男1女0）：");
				scanf("%d", &sex);
				printf("请输入学生年龄：");
				scanf("%u", &age);
				printf("请输入学生成绩：");
				scanf("%f", &score);
				STU* stu = createStu(id, name, sex, age, score);
				NODE* newNode = createNode(stu);
				//按学号顺序插入
				addList_order_id(newNode, stuList);
				printf("输入成功！\n\n请输入下一位学生学号（输入0以终止录入）:");
			loop_4:
				scanf("%llu", &id);
				if (checkID(stuList, id)) {
					printf("学号重复！请检查后重新输入学号：");
					goto loop_4;
				}
			}
			printf("录入结束！\n");
		}
		//打开学生信息文件创建链表
		else if (option == 4) {
			FILE* fp;
			fp = fopen("stuList.dat", "rb");
			while (!feof(fp)) {
				STU* stu = (STU*)malloc(sizeof(STU));
				fread(stu, sizeof(STU), 1, fp);
				addList_t(stuList, stu);
			}

			if (ferror(fp)) {
				puts("读取错误！");
				destrList(stuList);
			}
			else if (feof(fp)) {
				puts("文件读取结束！链表创建成功！");
				deleteNode_pos(stuList, stuList->size);
			}
			fclose(fp);
		}
		else
			goto menu;
		break;
	}
	//打印全部学生记录
	case 2: {
		system("cls");
		printHeader();
		foreach(stuList, printStu);
		break;
	}
	//插入一条新的学生记录
	case 3: {
		system("cls");
		//定义变量接收输入信息
		unsigned pos;
		uint64 id;
		char name[10];
		byte sex;
		unsigned age;
		float score;
		//显示二级菜单
		printf("0返回上级菜单\n");
		printf("1在指定位序插入\n");
		printf("2在有序链表中插入\n");
		printf("************************\n");
		printf("请输入相应数字以执行功能：\n");
		int option;
		scanf("%d", &option);
		//在指定位序插入
		if (option == 1) {
			system("cls");
			//输入数据
		loop_1:
			printf("请输入学生在链表中的位序（输入0以终止录入）：");
			scanf("%u", &pos);
			if (pos == 0)
				break;
			if (pos > stuList->size + 1) {//合法性检查
				printf("当前学生个数为%d，您输入的位序过大，请重新输入！\n", stuList->size); system("pause");
				goto loop_1;
			}
			printf("请输入学生学号:");
		loop_3:
			scanf("%llu", &id);
			if (checkID(stuList, id)) {
				printf("学号重复！请检查后重新输入学号：");
				goto loop_3;
			}
			printf("请输入学生姓名：");
			scanf("%s", name);  getchar();
			printf("请输入学生性别（男1女0）：");
			scanf("%d", &sex);
			printf("请输入学生年龄：");
			scanf("%u", &age);
			printf("请输入学生成绩：");
			scanf("%f", &score);
			//创建学生
			STU* stu = createStu(id, name, sex, age, score);
			//插入链表
			addList_pos(stuList, stu, pos);
			printf("插入成功！\n");
		}
		//在有序链表中插入
		else if (option == 2) {
			system("cls");
			//输入数据
			if (!IsInOrder(stuList)) {
				printf("链表未按照学号升序排列！请排序后再进行此操作！\n");
				break;
			}
			printf("请输入学生学号（输入0以终止录入）:");
		loop_6:
			scanf("%llu", &id);
			if (!id)
				break;
			if (checkID(stuList, id)) {
				printf("学号重复！请检查后重新输入学号：");
				goto loop_6;
			}
			printf("请输入学生姓名：");
			scanf("%s", name);  getchar();
			printf("请输入学生性别（男1女0）：");
			scanf("%d", &sex);
			printf("请输入学生年龄：");
			scanf("%u", &age);
			printf("请输入学生成绩：");
			scanf("%f", &score);
			//创建学生
			STU* stu = createStu(id, name, sex, age, score);
			NODE* newNode = createNode(stu);
			//插入链表
			addList_order_id(newNode, stuList);
			printf("插入成功！\n");
		}
		else
			goto menu;
		break;
	}
	//按条件删除一条学生记录
	case 4: {
		system("cls");
		//定义变量接收输入信息
		unsigned pos;
		uint64 id;
		//显示二级菜单
		printf("0返回上级菜单\n");
		printf("1删除指定位置的记录\n");
		printf("2删除指定学号的记录\n");
		printf("************************\n");
		printf("请输入相应数字以执行功能：\n");
		int option;
		scanf("%d", &option);
		//删除指定位置的记录
		if (option == 1) {
			system("cls");
			//输入数据
		loop_2:
			printf("请输入学生在链表中的位序（输入0以终止录入）：\n");
			scanf("%u", &pos);
			if (pos == 0)
				break;
			//合法性检查
			if (pos > stuList->size) {
				printf("当前学生个数为%d，您输入的位序过大，请重新输入！\n",stuList->size);
				goto loop_2;
			}
			deleteNode_pos(stuList, pos);
			printf("删除成功！\n");
		}
		//删除指定学号的记录
		else if (option == 2) {
			printf("请输入学生学号:\n");
			scanf("%llu", &id);
			int flag = deleteStu_id(stuList, id);
			if(flag==-1)
				printf("未找到该学生！\n");
			else if (flag > -1)
				printf("删除成功！\n");
		}
		else
			goto menu;
		break;
	}
	//按学号查找学生记录
	case 5: {
		uint64 id;
		system("cls");
		printf("请输入学生学号:\n");
		scanf("%llu", &id);
		NODE* found = findStu(stuList, id);
		if (!found)
			printf("未找到该学生！\n");
		else{
			STU* stu = found->data;
			printHeader();
			printStu(stu);
		}
		break;
	}
	//统计学生信息
	case 6: {
		system("cls");
		if (!stuList->head) {
			printf("统计失败！请先创建链表初始化学生信息！\n");
			break;
		}
		printf("学生人数：%d\n",stuList->size);
		printf("平均成绩：%.2f\n", scoreAve(stuList));
		printf("最高分：%.2f\n", scoreMax(stuList->head));
		printf("不及格人数：%d\n", failedNum(stuList->head)); 
		printf("************************\n");
		break;
	}
	//销毁链表
	case 7: {
		system("cls");
		destrList(stuList);
		printf("销毁成功！\n");
		break;
	}
	//将学生信息写入磁盘文件
	case 8: {
		system("cls");
		printf("0返回上级菜单\n");
		printf("1重写学生文件\n");
		printf("2追加学生文件\n");
		printf("3清空学生文件\n");
		printf("************************\n");
		printf("请输入相应数字以执行功能：\n");
		FILE* fp;
		int option;
		scanf("%d", &option);
		if (option == 1) {
			if (!stuList->head) {
				printf("没有可以写入的学生信息！\n");
				break;
			}
			fp = fopen("stuList.dat", "wb");
			if (!fp) {
				printf("发生未知错误导致打开文件失败！\n");
				break;
			}
			foreach_fp(stuList, fp, writeStu);
			fclose(fp);
			printf("重写成功！保存学生信息的二进制文件\"stuList.dat\"位于程序所在同一目录下！\n");
		}
		else if (option == 2) {
			if (!stuList->head) {
				printf("没有可以追加的学生信息！\n");
				break;
			}
			fp = fopen("stuList.dat", "ab");
			if (!fp) {
				printf("发生未知错误导致打开文件失败！\n");
				break;
			}
			foreach_fp(stuList, fp, writeStu);
			fclose(fp);
			printf("追加成功！保存学生信息的二进制文件\"stuList.dat\"位于程序所在同一目录下！\n");
		}
		else if (option == 3) {
			fp = fopen("stuList.dat", "wb");
			if (!fp) {
				printf("发生未知错误导致打开文件失败！\n");
				break;
			}
			fclose(fp);
			printf("清空学生文件成功！\n");
		}
		break;
	}
	//按学号升序排列链表
	case 9: {
		system("cls");
		LIST* p = rearrange(stuList);
		if (!p) 
			printf("请先初始化链表！\n");
		else {
			stuList = p;
			puts("排序成功！");
		}
		  }
	default:
		break;
	}
	system("pause");
	goto menu;
}