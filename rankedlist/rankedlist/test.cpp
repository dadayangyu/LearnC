#include"seqList.h"
void test()
{
	seqList* s1;
	seqListInit(&s1);
	seqListPushBack(&s1, 1);
	seqListPushBack(&s1, 2);
	seqListPushBack(&s1, 3);
	seqListPrint(&s1);
}
int main(){
	test();
	return 0;
}