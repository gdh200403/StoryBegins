//p136 3.3.2.3-ģ�黯��������к������͡��������ͼ����������
#include <stdio.h>
extern int extern_num;//�䶨����main����֮������ڶ���֮ǰʹ��ʱ��Ҫ��extern����Ϊ�ⲿ����
static int static_num = 100;
int n = 10;

void func0() {
	printf("extern_num:%d\n", extern_num);
	printf("static_num:%d\n", static_num);
	extern_num = 2018;
	static_num++;
	printf("extern_num:%d\n", extern_num);
	printf("static_num:%d\n", static_num);
}

void func1() {
	int n = 20; //nΪ�����ڲ�����ľֲ�����
	printf("func1 n:%d\n", n);
}

void func2(int n) { //n��Ϊ�β�
	printf("func2 n:%d\n", n);
}

void func3() {
	printf("func3 n:%d\n", n); //n��ֵΪȫ�ֱ���n��ֵ10
}
void func4();
void func5(int);

int main() {
	func0();//����û���βεĺ���Ҫ������
	printf("extern_num:%d\n", extern_num);
	printf("static_num:%d\n", static_num);
	int n = 30;
	func1();
	func2(n);
	func3;
	//����Ϊ����飬һ���������{}��Χ
	{
		int n = 40;
		printf("block n:%d\n", n);
	}
	printf("main n:%d\n", n); //n��ֵΪmain�����ڲ�����ľֲ�����n��ֵ30
	//printf("global variable n1:%d\n",n1);
	func4();
	func5(n);//n=30
	//printf("n5=%d\n",n5);//��������ܷ�ͨ�����룿
	return 0;
}
int extern_num = 90;
int n1 = 50; //�ܽ���n1��Ϊn��

void func4() {
	printf("global variable n1:%d\n", n1);
	printf("global variable n:%d\n", n);
}

void func5(int n) {
	static int n5 = 10;
	n5++;
	printf("n5+n=%d\n", n5 + n);
	static_num++;
	printf("extern_num:%d\n", extern_num);
	printf("static_num:%d\n", static_num);
}