#pragma once
void ShowMenu(void);				//0显示菜单
typedef struct systemParameter {	//系统参数结构体
	unsigned int arr_num;					//数组元素个数
	unsigned int num_per_row;				//每行显示个数
	unsigned int deci;						//保留小数点位数
}PARA;
void Config(PARA*);								//1配置系统参数
void PrintArray(PARA* para,float* array);		//2显示数组
void FillArray(PARA* para, float* array);		//3生成样本数据
void FillRandom(unsigned int arr_num, float* array,float min,float max);						//随机填充
void FillKeyboard(unsigned int arr_num, float* array);					//键盘输入
void FillSameVal(unsigned int arr_num, float* array,float val);			//同值填充
void FillArithSeq(unsigned int arr_num, float* array,float a0,float d);	//等差填充
void Delete(PARA* para, float* array);			//4删除
int DeleteIndex(PARA* para, float* array,unsigned int index);	//指定下标
int DeleteValue(PARA* para, float* array,float val);			//指定数值
void DeleteRange(PARA* para, float* array,unsigned int left, unsigned int right);	//指定下标区间
void Insert(PARA* para, float* array);			//5插入新元素
void InsertIndex(PARA* para, float* array,unsigned int index,float val);//指定下标
unsigned int InsertOrder(PARA* para, float* array,float val);			//有序数组中插入
void Statistics(PARA* para, float* array);		//6统计
float Max(unsigned int arr_num, float* array);				//最大值
float Min(unsigned int arr_num, float* array);				//最小值
float Average(unsigned int arr_num, float* array);			//平均值
float Variance(unsigned int arr_num, float* array);			//方差
float StdDev(unsigned int arr_num, float* array);			//均方差
void Search(PARA* para, float* array);			//7查找
unsigned int SeqSearch(unsigned int arr_num, float* array,float val);		//普通查找
unsigned int BiSearch(unsigned int arr_num, float* array,float val);		//二分查找
void Judge(PARA* para, float* array);			//8判断
int IsAsc(unsigned int arr_num, float* array);				//是否升序
int IsDesc(unsigned int arr_num, float* array);				//是否降序
int IsAllEqual(unsigned int arr_num, float* array);			//是否全等
void Arrange(PARA* para, float* array);		//9排列数组元素
void Sort(unsigned int arr_num, float* array);				//排序
void BubbleSort(unsigned int arr_num, float* array);			//冒泡排序
void SelectSort(unsigned int arr_num, float* array);			//选择排序
void InsertSort(unsigned int arr_num, float* array);			//插入排序
void ExchangeSort(unsigned int arr_num, float* array);			//交换排序
void Reverse(unsigned int arr_num, float* array);			//逆置
void RotateLeft(unsigned int arr_num, float* array,unsigned int delta);			//左旋
void RotateRight(unsigned int arr_num, float* array, unsigned int delta);		//右旋

void ShowMenu3(void);
void ShowMenu4(void);
void ShowMenu5(void);
void ShowMenu6(void);
void ShowMenu7(void);
void ShowMenu8(void);
void ShowMenu9(void);
void ShowMenu9_1(void);