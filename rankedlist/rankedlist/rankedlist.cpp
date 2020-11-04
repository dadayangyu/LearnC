//typedef struct seqList   //顺序表
//{
//	int _array[10000000];
//	int _size;
//}seqList;//有大小的顺序表，一般不用
//动态顺序表
//typedef int DataType;//给予数据类型别名，给予程序更大的灵活性
//typedef struct seqList
//{
//	DataType* _array;
	//unsigned int _size;//无符号整形数据，可以直接用，元素个数
	
	//unsigned int _capacity;//容量：当前可用空间
//};
#include<stdlib.h>
#include"sqlList.h"
void seqListInit(seqlist* sl){
	//初始化数组
	s1->_array = (int *)malloc(sizeof(DataType)* 4);
	s1->_capacity = 4;
	s1->_size = 0;
}

//pushBack:尾插
void seqListPushBack(seqList* sl, DataType value){
	s1->_array[s1->_size++] = value;//最后一个放当前的值
}


//popBack:尾删
//void seqListPopBack(seqList* s1);

//pushFront:头插
//void seqListPopFront(seqList* s1, DataType value);

//popFront:头删
//void setListPopFront(seqList* s1);

//在pos位置前面插入一个数据value
//void seqListInsert(seqList* s1, size_t pos, DataType value);

//删除pos位置的数据
//void seqListErace(seqList* s1, size_t pos);
void seqListPrint(seqList* s1){
	for (int i = 0; i < s1->_size; ++i){
		printf("%d", s1->_array[i]);
	}
}
