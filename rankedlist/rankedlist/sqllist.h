#include<stdio.h>
typedef int DataType;//给予数据类型别名，给予程序更大的灵活性
typedef struct seqList
{
	DataType* _array;
   unsigned int _size;//无符号整形数据，可以直接用，元素个数
   size_t _size;
   size_t _capacity;
   unsigned int _capacity;//容量：当前可用空间
};