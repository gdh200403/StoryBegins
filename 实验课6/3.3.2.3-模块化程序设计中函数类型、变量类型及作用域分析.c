//p136 3.3.2.3-模块化程序设计中函数类型、变量类型及作用域分析
#include <stdio.h>
extern int extern_num;//其定义在main函数之后，因此在定义之前使用时需要用extern声明为外部变量
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
	int n = 20; //n为函数内部定义的局部变量
	printf("func1 n:%d\n", n);
}

void func2(int n) { //n作为形参
	printf("func2 n:%d\n", n);
}

void func3() {
	printf("func3 n:%d\n", n); //n的值为全局变量n的值10
}
void func4();
void func5(int);

int main() {
	func0();//调用没有形参的函数要加括号
	printf("extern_num:%d\n", extern_num);
	printf("static_num:%d\n", static_num);
	int n = 30;
	func1();
	func2(n);
	func3;
	//以下为代码块，一个代码块由{}包围
	{
		int n = 40;
		printf("block n:%d\n", n);
	}
	printf("main n:%d\n", n); //n的值为main函数内部定义的局部变量n的值30
	//printf("global variable n1:%d\n",n1);
	func4();
	func5(n);//n=30
	//printf("n5=%d\n",n5);//此条语句能否通过编译？
	return 0;
}
int extern_num = 90;
int n1 = 50; //能将吗n1改为n吗？

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