#pragma once
void ShowMenu(void);				//0��ʾ�˵�
typedef struct systemParameter {	//ϵͳ�����ṹ��
	unsigned int arr_num;					//����Ԫ�ظ���
	unsigned int num_per_row;				//ÿ����ʾ����
	unsigned int deci;						//����С����λ��
}PARA;
void Config(PARA*);								//1����ϵͳ����
void PrintArray(PARA* para,float* array);		//2��ʾ����
void FillArray(PARA* para, float* array);		//3������������
void FillRandom(unsigned int arr_num, float* array,float min,float max);						//������
void FillKeyboard(unsigned int arr_num, float* array);					//��������
void FillSameVal(unsigned int arr_num, float* array,float val);			//ֵͬ���
void FillArithSeq(unsigned int arr_num, float* array,float a0,float d);	//�Ȳ����
void Delete(PARA* para, float* array);			//4ɾ��
int DeleteIndex(PARA* para, float* array,unsigned int index);	//ָ���±�
int DeleteValue(PARA* para, float* array,float val);			//ָ����ֵ
void DeleteRange(PARA* para, float* array,unsigned int left, unsigned int right);	//ָ���±�����
void Insert(PARA* para, float* array);			//5������Ԫ��
void InsertIndex(PARA* para, float* array,unsigned int index,float val);//ָ���±�
unsigned int InsertOrder(PARA* para, float* array,float val);			//���������в���
void Statistics(PARA* para, float* array);		//6ͳ��
float Max(unsigned int arr_num, float* array);				//���ֵ
float Min(unsigned int arr_num, float* array);				//��Сֵ
float Average(unsigned int arr_num, float* array);			//ƽ��ֵ
float Variance(unsigned int arr_num, float* array);			//����
float StdDev(unsigned int arr_num, float* array);			//������
void Search(PARA* para, float* array);			//7����
unsigned int SeqSearch(unsigned int arr_num, float* array,float val);		//��ͨ����
unsigned int BiSearch(unsigned int arr_num, float* array,float val);		//���ֲ���
void Judge(PARA* para, float* array);			//8�ж�
int IsAsc(unsigned int arr_num, float* array);				//�Ƿ�����
int IsDesc(unsigned int arr_num, float* array);				//�Ƿ���
int IsAllEqual(unsigned int arr_num, float* array);			//�Ƿ�ȫ��
void Arrange(PARA* para, float* array);		//9��������Ԫ��
void Sort(unsigned int arr_num, float* array);				//����
void BubbleSort(unsigned int arr_num, float* array);			//ð������
void SelectSort(unsigned int arr_num, float* array);			//ѡ������
void InsertSort(unsigned int arr_num, float* array);			//��������
void ExchangeSort(unsigned int arr_num, float* array);			//��������
void Reverse(unsigned int arr_num, float* array);			//����
void RotateLeft(unsigned int arr_num, float* array,unsigned int delta);			//����
void RotateRight(unsigned int arr_num, float* array, unsigned int delta);		//����

void ShowMenu3(void);
void ShowMenu4(void);
void ShowMenu5(void);
void ShowMenu6(void);
void ShowMenu7(void);
void ShowMenu8(void);
void ShowMenu9(void);
void ShowMenu9_1(void);