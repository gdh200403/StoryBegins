#include <stdio.h>

int main() {
	int i, j, k;//ѭ������
	int bg;//��������
	int n;//��Ʒ����
	float x;//��������
	float value;//�ܼ�ֵ
	float weight_;//�����������е�����Сβ��
	float value_;//�����������еļ�ֵСβ��
	struct objct { //����ṹ�壬�����ڲ�ʹ��ģ�黯������Ƶ�����£���ʵ�Ͷ���������û������
		int no;//���
		float wt;//����
		float vl;//��ֵ
		float vlp;//��λ������ֵ
	};
	printf("���뱳����������");
	scanf("%d", &bg);
	printf("������Ʒ������(3~10)��");
	scanf("%d", &n);
	struct objct objct[n];//����n������
	printf("����%d����Ʒ�ı�ţ�", n);
	for (i = 0; i < n; i++)
		scanf("%d", &objct[i].no);
	printf("����%d����Ʒ��������", n);
	for (i = 0; i < n; i++)
		scanf("%f", &objct[i].wt);
	printf("����%d����Ʒ�ļ�ֵ��", n);
	for (i = 0; i < n; i++)
		scanf("%f", &objct[i].vl);
	for (i = 0; i < n; i++)
		objct[i].vlp = objct[i].vl / objct[i].wt;
//�洢������Ϣ���ṹ��
	printf("0-1��������İ���ֵ̰�ķ���⣺\n");
	for (i = 0; i < n; i++) {
		for (j = i; j > 0; j--) {
			if (objct[j].vl > objct[j - 1].vl)
				;
			else {
				objct[j].vl += objct[j - 1].vl;
				objct[j - 1].vl = objct[j].vl - objct[j - 1].vl;
				objct[j].vl = objct[j].vl - objct[j - 1].vl;
				objct[j].no += objct[j - 1].no;
				objct[j - 1].no = objct[j].no - objct[j - 1].no;
				objct[j].no = objct[j].no - objct[j - 1].no;
				objct[j].wt += objct[j - 1].wt;
				objct[j - 1].wt = objct[j].wt - objct[j - 1].wt;
				objct[j].wt = objct[j].wt - objct[j - 1].wt;
				objct[j].vlp += objct[j - 1].vlp;
				objct[j - 1].vlp = objct[j].vlp - objct[j - 1].vlp;
				objct[j].vlp = objct[j].vlp - objct[j - 1].vlp;
			}
		}
	}//���ݼ�ֵ��С����Ը�����������
	for (i = n - 1, x = 0; i >= 0; i--) {
		if (bg - x >= objct[i].wt) {
			x += objct[i].wt, value += objct[i].vl;
			printf("%d����Ʒ ������%.6f ��ֵ��%.6f װ�뱳��\n",
			       objct[i].no, objct[i].wt, objct[i].vl);
		}
	}
	printf("װ�뱳������Ʒ�ܼ�ֵΪ%.6f\n", value);
//0-1��������İ���ֵ̰�ķ����
	printf("0-1��������İ���λ��ֵ̰�ķ���⣺\n");
	for (i = 0; i < n; i++) {
		for (j = i; j > 0; j--) {
			if (objct[j].vlp > objct[j - 1].vlp)
				;
			else {
				objct[j].vl += objct[j - 1].vl;
				objct[j - 1].vl = objct[j].vl - objct[j - 1].vl;
				objct[j].vl = objct[j].vl - objct[j - 1].vl;
				objct[j].no += objct[j - 1].no;
				objct[j - 1].no = objct[j].no - objct[j - 1].no;
				objct[j].no = objct[j].no - objct[j - 1].no;
				objct[j].wt += objct[j - 1].wt;
				objct[j - 1].wt = objct[j].wt - objct[j - 1].wt;
				objct[j].wt = objct[j].wt - objct[j - 1].wt;
				objct[j].vlp += objct[j - 1].vlp;
				objct[j - 1].vlp = objct[j].vlp - objct[j - 1].vlp;
				objct[j].vlp = objct[j].vlp - objct[j - 1].vlp;
			}
		}
	}//���ݵ�λ��ֵ��С����Ը�����������
	for (i = n - 1, x = 0, value = 0; i >= 0; i--) {
		if (bg - x >= objct[i].wt) {
			x += objct[i].wt, value += objct[i].vl;
			printf("%d����Ʒ ������%.6f ��ֵ��%.6f,��λ��ֵ��%.6f,װ�뱳��\n",
			       objct[i].no, objct[i].wt, objct[i].vl, objct[i].vlp);
		}
	}
	printf("װ�뱳������Ʒ�ܼ�ֵΪ%.6f\n", value);
//0-1��������İ���λ��ֵ̰�ķ����
	printf("���ֱ�������İ���λ��ֵ̰�ķ���⣺\n");
	for (i = n - 1, x = 0, value = 0; i >= 0; i--) {
		if (bg - x > 0) {
			if (bg - x >= objct[i].wt) {
				x += objct[i].wt, value += objct[i].vl;
				printf("%d����Ʒ ������%.6f ��ֵ��%.6f,��λ��ֵ��%.6f,װ�뱳��\n",
				       objct[i].no, objct[i].vl, objct[i].vlp);
			} else {
				weight_ = bg - x;
				x = bg;
				value_ = weight_ * objct[i].vlp;
				value += value_;
				printf("%d����Ʒ ������%.2f ��ֵ��%.2f,��λ��ֵ��%.2f,����%.2f�ؼ�ֵ%.2fװ�뱳��\n",
				       objct[i].no, objct[i].wt, objct[i].vl, objct[i].vlp, weight_, value_);
			}
		}
	}
	printf("װ�뱳������Ʒ�ܼ�ֵΪ%.6f\n", value);
//���ֱ�������İ���λ��ֵ̰�ķ����
	return 0;
}