#include <stdio.h>
#include <string.h>

struct candidate {
	int id;//���
	char name[30];//����
	char gender;//�Ա�
	unsigned votes;//��Ʊ��
};

int main() {
	int n, i, mode, id;
	char name[30];
	printf("�м�λ��ѡ�ˣ�");
	scanf("%d", &n);
	struct candidate can[n];
	printf("����%dλ��ѡ����Ϣ(���,����,�Ա�)��\n", n);
	for (i = 0; i < n; i++) {
		scanf("%d%s", &can[i].id, can[i].name);
		getchar();
		can[i].gender = getchar();
		can[i].votes = 0;
	}
	printf("��ʼͶƱ��\n");
	for (;;) {
		printf("ͶƱ��0��ţ�1������10��������\n");
		scanf("%d", &mode);
		switch (mode) {
			case 0:
				scanf("%d", &id);
				for (i = 0; i < n; i++) {
					if (id == can[i].id) {//��ѵ
						can[i].votes++;
						break;
					}

				}
				break;
			case 1:
				scanf("%s", name);
				for (i = 0; i < n; i++) {
					if (strcmp(name, can[i].name) == 0) {
						can[i].votes++;
						break;
					}
				}
				break;
			case 10:
				goto result;
		}
	}
result:
	printf("ͶƱ�����\n");
	for (i = 0; i < n; i++) {
		printf("%d,%s,%c:%dƱ\n", can[i].id, can[i].name, can[i].gender, can[i].votes);
	}
	return 0;
}
