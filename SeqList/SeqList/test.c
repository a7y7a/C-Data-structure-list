#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

int main()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 0);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 3);
	SeqListPopBack(&s1);
	SeqListPrint(&s1);
	SeqListPushFront(&s1, 7);
	SeqListPushFront(&s1, 7);
	SeqListPushFront(&s1, 7);
	SeqListPopFront(&s1);
	SeqListPrint(&s1);
	SeqListInsert(&s1, 2, 8);
	printf("%d\n",SeqListFind(&s1, 7));
	SeqListErase(&s1, 1);
	SeqListPrint(&s1);
	SeqListDestory(&s1);
	return 0;
}
