#include <stdio.h>
#include <time.h>

int main() {
	FILE *fpi, *fpo; //��������ָ��������ڶ�ȡ���ݺͱ�����
	time_t seconds;//��1970��1��1�յ����ڵ�����
	char days_mons[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}},
	leap  = 0;
	int year, month, day, hour, minute, second;
	int a[100];
	int n;
	int i, j, t;
	printf("�м�������1~100����");
	scanf("%d", &n);
	fpi = fopen("data.txt", "r");
	if (fpi == NULL) {
		fpi = fopen("data.txt", "w+"); //�ɶ�д��ʽ�򿪣������ھ��½������ھ�����ļ�����
		printf("����%d������", n);
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			fprintf(fpi, "%d ", a[i]);
		}
		rewind(fpi);//�������ļ���ͷ���Ա���������ͷ��ʼ��ȡ�ļ��е�����
	}
	//
	fpo = fopen("result.txt", "a"); //��׷�ӵķ�ʽ�򿪵�ǰ�ļ����е��ı��ļ��������ھ��½������ھ����ļ���β�������
	for (i = 0; i < n; i++)
		fscanf(fpi, "%d", &a[i]);
	fclose(fpi);//��ȡ���ݽ���
	/*�Դ��ļ���ȡ�����ݴ����ֺ��ԣ��������ȡ��ǰϵͳ��ʱ�䣬���ȡ������һ��д�롰result.txt���ļ���*/
	seconds = time(NULL) + 8 * 60 * 60; //��ȡϵͳ��1970��1��1�յ����ڵ�����������ʱ����������
	second = seconds % 60;
	seconds /= 60;
	minute = seconds % 60;
	seconds /= 60;
	hour = seconds % 24;
	seconds /= 24;
	year = 1970;
	leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
	while (seconds > 365) {
		if (leap)
			seconds -= 366;
		else
			seconds -= 365;
		year++;
		leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
	}
	month == 1;
	for (i = 0; seconds >= days_mons[leap][i]; i++, month++)
		seconds -= days_mons[leap][i];
	day = seconds + 1;
	fprintf(fpo, "%d-%02d-%02d,%02d:%02d:%02d\n", year, month, day, hour, minute, second); //дʱ������ļ�
	for (i = 0; i < n; i++)
		fprintf(fpo, "%d ", a[i]); //�������е�����д���ļ�
	fprintf(fpo, "\n"); //���дһ�����е��ļ�
	fclose(fpo);
	return 0;


}