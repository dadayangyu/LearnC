#include<stdio.h>
typedef int DataType;//�����������ͱ���������������������
typedef struct seqList
{
	DataType* _array;
   unsigned int _size;//�޷����������ݣ�����ֱ���ã�Ԫ�ظ���
   size_t _size;
   size_t _capacity;
   unsigned int _capacity;//��������ǰ���ÿռ�
};