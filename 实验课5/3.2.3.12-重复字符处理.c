#include <stdio.h>
#include <string.h>

struct biaoji {
	int weizhi;
	int geshu;
};
struct biaoji bj[100];


void string_filter(char s[]) {
	int i, j, k, c;
	bj[0].weizhi = 0;
	bj[0].geshu = 0;
	for (i = 0, k = 1; s[i] != '\0'; ) {//ɨ���ַ���
		c = 1;
		for (j = i; s[j + 1] == s[i]; j++) { //��ÿһ���ַ���ɨ�������֮����ַ�����Ǻ�����ͬ���ַ��������ڴˡ�==��������
			c++;//������
		}
		if (c > 1) {
			bj[k].weizhi = i;//�洢��ʼ�ظ����ַ���ԭ�ַ�����λ��
			bj[k].geshu = c;//�洢���ַ��ظ�����
			i += c; //�������ظ��ַ���ɨ��֮����ַ���
			k++;//���ַ��ظ���Ϣ����ṹ�����飨��ѭ��ʱk����1��
		} else
			i++;
	}//ɨ��ԭ�ַ�����ɲ����ַ��ظ���Ϣ����ṹ������
	for (i = 0; i < k - 1; i++) {//���ظ��ַ���λ�òü�ԭ�ַ����ֶ����
		for (j = bj[i].weizhi + bj[i].geshu; j < bj[i + 1].weizhi; j++) {
			printf("%c", s[j]);//���ÿ��Ƭ�Σ���������֮����ظ��ַ���
		}
		printf("%d", bj[i + 1].geshu);//�����Ƭ�κ���ظ��ַ����ظ�����
		printf("%c", s[bj[i + 1].weizhi]);//���һ����Ƭ�κ���ظ��ַ�
	}//��������һ���ַ��ظ�����ɶ����һ���ظ��ַ��Ĵ���
	for (i = bj[k - 1].weizhi + bj[k - 1].geshu; s[i] != '\0'; i++)
		printf("%c", s[i]);//������һ��Ƭ��
	return;
}

int main() {
	char a[100];
	printf("�������ַ�����\n");
	scanf("%s", a);
	printf("ȥ���ظ��ַ��������ظ��ַ�ǰ�����ظ�����������ַ���Ϊ��\n");
	string_filter(a);
	return 0;
}