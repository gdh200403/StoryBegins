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
	int i, j, k, s, s1, s2, s3, s4, s5, n; // ѭ������i,j,k;ѡ�����s����ʼ����ϵ������n
	FILE *fp;
	char name[30], call[30], wx[30], qq[30]; // ���Ҽ�ɾ����ϵ��ʱ����
	int flag = 0, flag1;					 // flagΪ��ǰ��ϵ����������flag1Ϊĳ��ѭ���еĿ��ر���
	struct person psn[100];					 // ͨѶ¼����Ϊ100
	for (;;)
	{
	menu:
		flag1 = 0;
		printf("----------------\n"); // �ָ��ߣ��ÿ�
		printf(" �� �� ͨ Ѷ ¼ \n\n");
		printf("1--ͨѶ¼��ʼ��\n");
		printf("2----��ʾͨѶ¼\n");
		printf("3----�����ϵ��\n");
		printf("4----ɾ����ϵ��\n");
		printf("5----������ϵ��\n");
		printf("6----�洢ͨѶ¼\n");
		printf("----------------\n"); // �˵�
	loop:
		printf("��������Ӧ������ִ�в�����"); // ѡ�����
		scanf("%d", &s);
		switch (s)
		{
		case 1: // 1-ͨѶ¼��ʼ��
			printf("��������ϵ�˸�����1~100����");
			scanf("%d", &n);
			getchar(); // �Ե��س�����Ϊ����ĵ�һ��scanf�����س��Ͷ�ȡ����
			for (i = 0; i < n; i++)
			{
				printf("��ϵ��%d��\n", i + 1);
				printf("������");
				scanf("%[^\n]", psn[i].name); /*"%[^\n]"�ĸ�ʽ���������scanf�Ķ�ȡ�����س�
											 �Ͷ�ȡ�س�ǰ���������ݣ�����������ϵ�������д��ڿո�*/
				getchar();					  // �Ե��س����������еĲ���Ҳ���Եȼ���scanf("%[^\n]%*c",str)��ʽ������
				printf("�ֻ��ţ�");
				scanf("%s", psn[i].call);
				getchar();
				printf("QQ��");
				scanf("%s", psn[i].qq);
				getchar();
				printf("΢�ţ�");
				scanf("%s", psn[i].wx);
				getchar();
				printf("\n");
			}		  // ������ϵ��
			flag = i; // i����1��ѭ������ֵ����Ϊ��ʼ����ͨѶ¼����ϵ�˵�����������������ʣ���ֵ��flag
			printf("��ʼ��%d����ϵ�˳ɹ���\n", n);
			printf("����Enter��ȷ�ϲ����ز˵�����"); // ��ֱֹ��������һѭ���Ĳ˵������ÿ�
			getchar();							   // ���������������س���������break�󷵻ز˵�
			break;
		case 2:		   // 2-��ʾͨѶ¼
			getchar(); // �Ե��ڲ˵�ѡ��2ʱ����Ļس��������
			printf("\n");
			for (i = 0; i < flag; i++)
			{
				printf("%s\n", psn[i].name);
				printf("�ֻ��ţ�%s\n", psn[i].call);
				printf("QQ��%s\n", psn[i].qq);
				printf("΢�ţ�%s\n\n", psn[i].wx);
			}
			printf("����������ͨѶ¼������%d����ϵ��\n", flag);
			printf("����Enter��ȷ�ϲ����ز˵�����");
			getchar(); // ������س���������ֱ�ӱ��Ե�Ȼ�󷵻ز˵�
			break;
		case 3: // 3-�����ϵ��
			printf("��������Ҫ��ӵ���ϵ�˸�����");
			scanf("%d", &n); // ������Ҫ����n��ȥ����
			getchar();		 // ͬ1��getchar���Ե��س���Ϊ������"%[^\n]"�ĸ�ʽ������
			for (i = flag; i < flag + n; i++)
			{
				printf("�������ϵ��%d��\n", i - flag + 1);
				printf("������");
				scanf("%[^\n]", psn[i].name);
				getchar();
				printf("�ֻ��ţ�");
				scanf("%s", psn[i].call);
				getchar();
				printf("QQ��");
				scanf("%s", psn[i].qq);
				getchar();
				printf("΢�ţ�");
				scanf("%s", psn[i].wx);
				getchar();
				printf("\n");
			}		   // ��ϵ��˳����ӵ���ʼ������ϵ�˺�
			flag += n; // ������ϵ������flag
			printf("���%d����ϵ�˳ɹ��������ڹ���%d����ϵ�ˡ�\n\n", n, flag);
			printf("����Enter��ȷ�ϲ����ز˵�����");
			getchar();
			break;
		case 4: // 4-ɾ����ϵ��
		shanchu:
			printf("1-����\n2-�ֻ���\n3-QQ\n4-΢��\n��������Ҫɾ������ϵ�˵���Ϣ���ͣ�");
			scanf("%d", &s3);
			switch (s3)
			{ // �������
			case 1:
				getchar();
				printf("������������");
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
				printf("�������ֻ��ţ�");
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
				printf("������QQ��");
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
				printf("������΢�ţ�");
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
				goto shanchu; // ����Ƿ����ݣ���������
			}
			if (flag1 == 1)
			{
				printf("\n%s\n", psn[i].name);
				printf("�ֻ��ţ�%s\n", psn[i].call);
				printf("QQ��%s\n", psn[i].qq);
				printf("΢�ţ�%s\n\n", psn[i].wx);
				printf("��Ҫɾ������ϵ����Ϣ���ϣ�ȷ��ɾ����\n����1ɾ��������0���ز˵���"); // ������ϵ����ϣ�ѯ���Ƿ�ɾ��
				scanf("%d", &s5);
				getchar();
				switch (s5)
				{
				case 1: // ����1ɾ��
					for (j = i; j < flag - 1; j++)
					{
						for (k = 0; k < 30; k++)
						{
							psn[j].name[k] = psn[j + 1].name[k];
							psn[j].call[k] = psn[j + 1].call[k];
							psn[j].qq[k] = psn[j + 1].qq[k];
							psn[j].wx[k] = psn[j + 1].wx[k];
						}
					} // ɾ���������ݣ��������ݺ����������ǰ��һλ
					strcpy(psn[flag - 1].name, "");
					strcpy(psn[flag - 1].call, "");
					strcpy(psn[flag - 1].qq, "");
					strcpy(psn[flag - 1].wx, ""); /*����strcpy����(<string.h>)��ԭ���һ����������
													 ע���ַ���Ϊ���飬����ֱ�����������ֵ*/
					flag--;						  // ��ϵ��������һ
					printf("ɾ���ɹ���\n\n");
					printf("����Enter��ȷ�ϲ����ز˵�����");
					getchar();
					break;
				default: // Ϊ��ֹ�Ƿ����룬����1������������ز˵�
					goto menu;
				}
			}
			else
			{ // δ���ҵ��ķ�֧����
				printf("δ�ҵ�����ϵ�ˣ�\n����1���²��ң�����0���ز˵�\n");
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
		case 5: // 5-������ϵ��
		find:
			printf("1-����\n2-�ֻ���\n3-QQ\n4-΢��\n������������ͣ�");
			scanf("%d", &s1);
			switch (s1)
			{
			case 1:
				getchar();
				printf("������������");
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
				printf("�������ֻ��ţ�");
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
				printf("������QQ��");
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
				printf("������΢�ţ�");
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
			} // ͬ4��������ϵ��
			if (flag1 == 1)
			{
				printf("\n%s\n", psn[i].name);
				printf("�ֻ��ţ�%s\n", psn[i].call);
				printf("QQ��%s\n", psn[i].qq);
				printf("΢�ţ�%s\n\n", psn[i].wx);
				printf("���ҳɹ���\n����Enter��ȷ�ϲ����½���˵�����");
				getchar();
			}
			else
			{
				printf("δ�ҵ�����ϵ�ˣ�\n����1���²��ң�����0���ز˵�\n");
				scanf("%d", &s2);
				switch (s2)
				{
				case 1:
					goto find;
				default:
					goto menu;
				}
			}
			break; // ͬ4
		case 6:
			getchar();
			fp = fopen("ͨѶ¼.txt", "w+");
			for (i = 0; i < flag; i++)
			{
				fprintf(fp, "%s\n", psn[i].name);
				fprintf(fp, "�ֻ��ţ�%s\n", psn[i].call);
				fprintf(fp, "QQ��%s\n", psn[i].qq);
				fprintf(fp, "΢�ţ�%s\n\n", psn[i].wx);
			}
			fclose(fp);
			printf("ͨѶ¼�ѱ��浽ͬ�ļ�����\"ͨѶ¼.txt\"��������ǰ���鿴��\n");
			printf("����Enter��ȷ�ϲ����ز˵�����");
			getchar();
			break;
		default:
			goto loop; // �Ƿ����룬���¼���ѡ��
		}
		fp = fopen("ͨѶ¼.txt", "w+");
		for (i = 0; i < flag; i++)
		{
			fprintf(fp, "%s\n", psn[i].name);
			fprintf(fp, "�ֻ��ţ�%s\n", psn[i].call);
			fprintf(fp, "QQ��%s\n", psn[i].qq);
			fprintf(fp, "΢�ţ�%s\n\n", psn[i].wx);
		}
		fclose(fp); // ���벻�ף��Զ�����
	}
}
