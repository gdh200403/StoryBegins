#include <stdio.h>
#include <string.h>

struct person
{
	char name[20];
	char call[20];
	char wx[20];
	char qq[20];
};

int main()
{
	int i, j, k, s, s1, s2, s3, s4, s5, n; // 循环变量i,j,k;选择变量s；初始化联系人数量n
	FILE *fp;
	char name[30], call[30], wx[30], qq[30]; // 查找及删除联系人时备用
	int flag = 0, flag1;					 // flag为当前联系人总数量，flag1为某个循环中的开关变量
	struct person psn[100];					 // 通讯录容量为100
	for (;;)
	{
	menu:
		flag1 = 0;
		printf("----------------\n"); // 分割线，好看
		printf(" 简 易 通 讯 录 \n\n");
		printf("1--通讯录初始化\n");
		printf("2----显示通讯录\n");
		printf("3----添加联系人\n");
		printf("4----删除联系人\n");
		printf("5----查找联系人\n");
		printf("6----存储通讯录\n");
		printf("----------------\n"); // 菜单
	loop:
		printf("请输入相应数字以执行操作："); // 选择操作
		scanf("%d", &s);
		switch (s)
		{
		case 1: // 1-通讯录初始化
			printf("请输入联系人个数（1~100）：");
			scanf("%d", &n);
			getchar(); // 吃掉回车，因为下面的第一个scanf见到回车就读取数据
			for (i = 0; i < n; i++)
			{
				printf("联系人%d：\n", i + 1);
				printf("姓名：");
				scanf("%[^\n]", psn[i].name); /*"%[^\n]"的格式化输入代表scanf的读取见到回车
											 就读取回车前的所有内容，它允许了联系人姓名中存在空格*/
				getchar();					  // 吃掉回车，上面两行的操作也可以等价于scanf("%[^\n]%*c",str)格式化输入
				printf("手机号：");
				scanf("%s", psn[i].call);
				getchar();
				printf("QQ：");
				scanf("%s", psn[i].qq);
				getchar();
				printf("微信：");
				scanf("%s", psn[i].wx);
				getchar();
				printf("\n");
			}		  // 输入联系人
			flag = i; // i自增1出循环，其值正好为初始化的通讯录中联系人的数量。利用这个性质，赋值给flag
			printf("初始化%d个联系人成功！\n", n);
			printf("按下Enter以确认并返回菜单……"); // 防止直接跳出下一循环的菜单，不好看
			getchar();							   // 挡在这里，等你输入回车放行让你break后返回菜单
			break;
		case 2:		   // 2-显示通讯录
			getchar(); // 吃掉在菜单选择2时输入的回车，否则↓
			printf("\n");
			for (i = 0; i < flag; i++)
			{
				printf("%s\n", psn[i].name);
				printf("手机号：%s\n", psn[i].call);
				printf("QQ：%s\n", psn[i].qq);
				printf("微信：%s\n\n", psn[i].wx);
			}
			printf("以上是您的通讯录，共有%d个联系人\n", flag);
			printf("按下Enter以确认并返回菜单……");
			getchar(); // ↑否则回车会在这里直接被吃掉然后返回菜单
			break;
		case 3: // 3-添加联系人
			printf("请输入你要添加的联系人个数：");
			scanf("%d", &n); // 哪里需要变量n就去哪里
			getchar();		 // 同1中getchar，吃掉回车因为下面有"%[^\n]"的格式化输入
			for (i = flag; i < flag + n; i++)
			{
				printf("待添加联系人%d：\n", i - flag + 1);
				printf("姓名：");
				scanf("%[^\n]", psn[i].name);
				getchar();
				printf("手机号：");
				scanf("%s", psn[i].call);
				getchar();
				printf("QQ：");
				scanf("%s", psn[i].qq);
				getchar();
				printf("微信：");
				scanf("%s", psn[i].wx);
				getchar();
				printf("\n");
			}		   // 联系人顺次添加到初始化的联系人后
			flag += n; // 更新联系人总数flag
			printf("添加%d个联系人成功！您现在共有%d个联系人。\n\n", n, flag);
			printf("按下Enter以确认并返回菜单……");
			getchar();
			break;
		case 4: // 4-删除联系人
		shanchu:
			printf("1-姓名\n2-手机号\n3-QQ\n4-微信\n请输入您要删除的联系人的信息类型：");
			scanf("%d", &s3);
			switch (s3)
			{ // 分类查找
			case 1:
				getchar();
				printf("请输入姓名：");
				scanf("%[^\n]", name);
				getchar();
				for (i = 0; i < flag; i++)
				{
					if (strcmp(name, psn[i].name) == 0)
					{
						flag1 = 1;
						break;
					}
				}
				break;
			case 2:
				printf("请输入手机号：");
				scanf("%s", call);
				getchar();
				for (i = 0; i < flag; i++)
				{
					if (strcmp(call, psn[i].call) == 0)
					{
						flag1 = 1;
						break;
					}
				}
				break;
			case 3:
				printf("请输入QQ：");
				scanf("%s", qq);
				getchar();
				for (i = 0; i < flag; i++)
				{
					if (strcmp(qq, psn[i].qq) == 0)
					{
						flag1 = 1;
						break;
					}
				}
				break;
			case 4:
				printf("请输入微信：");
				scanf("%s", wx);
				getchar();
				for (i = 0; i < flag; i++)
				{
					if (strcmp(wx, psn[i].wx) == 0)
					{
						flag1 = 1;
						break;
					}
				}
				break;
			default:
				goto shanchu; // 输入非法数据，重新输入
			}
			if (flag1 == 1)
			{
				printf("\n%s\n", psn[i].name);
				printf("手机号：%s\n", psn[i].call);
				printf("QQ：%s\n", psn[i].qq);
				printf("微信：%s\n\n", psn[i].wx);
				printf("您要删除的联系人信息如上，确认删除吗？\n键入1删除，键入0返回菜单："); // 查找联系人完毕，询问是否删除
				scanf("%d", &s5);
				getchar();
				switch (s5)
				{
				case 1: // 键入1删除
					for (j = i; j < flag - 1; j++)
					{
						for (k = 0; k < 30; k++)
						{
							psn[j].name[k] = psn[j + 1].name[k];
							psn[j].call[k] = psn[j + 1].call[k];
							psn[j].qq[k] = psn[j + 1].qq[k];
							psn[j].wx[k] = psn[j + 1].wx[k];
						}
					} // 删除本条数据，本条数据后的所有数据前移一位
					strcpy(psn[flag - 1].name, "");
					strcpy(psn[flag - 1].call, "");
					strcpy(psn[flag - 1].qq, "");
					strcpy(psn[flag - 1].wx, ""); /*利用strcpy函数(<string.h>)将原最后一条数据清零
													 注：字符串为数组，难以直接用运算符赋值*/
					flag--;						  // 联系人总数减一
					printf("删除成功！\n\n");
					printf("按下Enter以确认并返回菜单……");
					getchar();
					break;
				default: // 为防止非法输入，键入1以外的数均返回菜单
					goto menu;
				}
			}
			else
			{ // 未查找到的分支处理
				printf("未找到该联系人！\n键入1重新查找，键入0返回菜单\n");
				scanf("%d", &s4);
				switch (s4)
				{
				case 1:
					goto shanchu;
				default:
					goto menu;
				}
			}
			break;
		case 5: // 5-查找联系人
		find:
			printf("1-姓名\n2-手机号\n3-QQ\n4-微信\n请输入查找类型：");
			scanf("%d", &s1);
			switch (s1)
			{
			case 1:
				getchar();
				printf("请输入姓名：");
				scanf("%[^\n]", name);
				getchar();
				for (i = 0; i < flag; i++)
				{
					if (strcmp(name, psn[i].name) == 0)
					{
						flag1 = 1;
						break;
					}
				}
				break;
			case 2:
				printf("请输入手机号：");
				scanf("%s", call);
				getchar();
				for (i = 0; i < flag; i++)
				{
					if (strcmp(call, psn[i].call) == 0)
					{
						flag1 = 1;
						break;
					}
				}
				break;
			case 3:
				printf("请输入QQ：");
				scanf("%s", qq);
				getchar();
				for (i = 0; i < flag; i++)
				{
					if (strcmp(qq, psn[i].qq) == 0)
					{
						flag1 = 1;
						break;
					}
				}
				break;
			case 4:
				printf("请输入微信：");
				scanf("%s", wx);
				getchar();
				for (i = 0; i < flag; i++)
				{
					if (strcmp(wx, psn[i].wx) == 0)
					{
						flag1 = 1;
						break;
					}
				}
				break;
			default:
				goto find;
			} // 同4，查找联系人
			if (flag1 == 1)
			{
				printf("\n%s\n", psn[i].name);
				printf("手机号：%s\n", psn[i].call);
				printf("QQ：%s\n", psn[i].qq);
				printf("微信：%s\n\n", psn[i].wx);
				printf("查找成功！\n按下Enter以确认并重新进入菜单……");
				getchar();
			}
			else
			{
				printf("未找到该联系人！\n键入1重新查找，键入0返回菜单\n");
				scanf("%d", &s2);
				switch (s2)
				{
				case 1:
					goto find;
				default:
					goto menu;
				}
			}
			break; // 同4
		case 6:
			getchar();
			fp = fopen("通讯录.txt", "w+");
			for (i = 0; i < flag; i++)
			{
				fprintf(fp, "%s\n", psn[i].name);
				fprintf(fp, "手机号：%s\n", psn[i].call);
				fprintf(fp, "QQ：%s\n", psn[i].qq);
				fprintf(fp, "微信：%s\n\n", psn[i].wx);
			}
			fclose(fp);
			printf("通讯录已保存到同文件夹下\"通讯录.txt\"，您可以前往查看！\n");
			printf("按下Enter以确认并返回菜单……");
			getchar();
			break;
		default:
			goto loop; // 非法输入，重新键入选项
		}
		fp = fopen("通讯录.txt", "w+");
		for (i = 0; i < flag; i++)
		{
			fprintf(fp, "%s\n", psn[i].name);
			fprintf(fp, "手机号：%s\n", psn[i].call);
			fprintf(fp, "QQ：%s\n", psn[i].qq);
			fprintf(fp, "微信：%s\n\n", psn[i].wx);
		}
		fclose(fp); // 输入不易，自动保存
	}
}
