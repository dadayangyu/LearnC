//typedef struct seqList   //˳���
//{
//	int _array[10000000];
//	int _size;
//}seqList;//�д�С��˳���һ�㲻��
//��̬˳���
//typedef int DataType;//�����������ͱ���������������������
//typedef struct seqList
//{
//	DataType* _array;
	//unsigned int _size;//�޷����������ݣ�����ֱ���ã�Ԫ�ظ���
	
	//unsigned int _capacity;//��������ǰ���ÿռ�
//};
#include<stdlib.h>
#include"sqlList.h"
void seqListInit(seqlist* sl){
	//��ʼ������
	s1->_array = (int *)malloc(sizeof(DataType)* 4);
	s1->_capacity = 4;
	s1->_size = 0;
}

//pushBack:β��
void seqListPushBack(seqList* sl, DataType value){
	s1->_array[s1->_size++] = value;//���һ���ŵ�ǰ��ֵ
}


//popBack:βɾ
//void seqListPopBack(seqList* s1);

//pushFront:ͷ��
//void seqListPopFront(seqList* s1, DataType value);

//popFront:ͷɾ
//void setListPopFront(seqList* s1);

//��posλ��ǰ�����һ������value
//void seqListInsert(seqList* s1, size_t pos, DataType value);

//ɾ��posλ�õ�����
//void seqListErace(seqList* s1, size_t pos);
void seqListPrint(seqList* s1){
	for (int i = 0; i < s1->_size; ++i){
		printf("%d", s1->_array[i]);
	}
}
