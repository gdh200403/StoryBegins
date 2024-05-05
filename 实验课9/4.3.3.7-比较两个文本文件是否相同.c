//p192 4.3.3.7-�Ƚ������ı��ļ��Ƿ���ͬ
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc < 3) {
		// ���������������ӡ�÷���Ϣ���˳�
		printf("Usage: %s file1 file2\n", argv[0]);
		return 1;
	}

	// �������ļ�
	FILE *file1 = fopen(argv[1], "r");
	FILE *file2 = fopen(argv[2], "r");
	if (file1 == NULL || file2 == NULL) {
		// ������ļ���ʧ�ܣ���ӡ������Ϣ���˳�
		printf("Failed to open file(s)!\n");
		return 1;
	}

	int pos = 0; // ��¼��ǰ�Ƚϵ��˵ڼ����ַ�
	int c1, c2; // ��¼�����ļ���ǰ��ȡ���ַ�
	while ((c1 = fgetc(file1)) != EOF && (c2 = fgetc(file2)) != EOF) {
// ����Ƚϵ��˵ڼ����ַ�
		pos++;
// ����ȽϽ����ͬ�������һ����ͬ�ַ����ֽ�λ�ò��˳�
		if (c1 != c2) {
			printf("Different at position %d!\n", pos);
			break;
		}
	}

// ��������ļ�������ȫ��ͬ����� "��ͬ"
	if (c1 == EOF && c2 == EOF) {
		printf("��ͬ\n");
	}

// �ر��ļ�
	fclose(file1);
	fclose(file2);
	return 0;
}
