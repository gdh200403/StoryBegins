#include <stdio.h>

int main() {
	char a[100];
	int result[6] = {0};
	int i;
	printf("���룺");
	for (i = 0; i < 100; i++) {
		a[i] = getchar();
		if (a[i] == EOF)
			break;
	}
	for (i = 0; i < 100; i++) {
		if (65 <= a[i] && a[i] <= 90)
			result[0]++;
		else if (97 <= a[i] && a[i] <= 122)
			result[1]++;
		else if (48 <= a[i] && a[i] <= 57)
			result[2]++;
		else if (a[i] == 32)
			result[3]++;
		else if (1 <= a[i] && a[i] <= 31)
			result[4]++;
		else if (a[i] == '\0')
			break;
		else
			result[5]++;

	}
	printf("\n�����");
	printf("%d����д��ĸ��", result[0]);
	printf("%d��Сд��ĸ��", result[1]);
	printf("%d�����֣�", result[2]);
	printf("%d���ո�", result[3]);
	printf("%d���Ʊ����", result[4]);
	printf("%d�������ַ�", result[5]);
	return 0;
}