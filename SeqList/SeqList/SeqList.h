#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDateType;

typedef struct SeqList
{
	SLDateType* p;
	int size;
	int capacity;
} SL;

void SeqListInit(SL* s);
void SeqListPrint(SL* s);
void SeqListDestory(SL* s);

void SeqListPushBack(SL* s, SLDateType x);
void SeqListPopBack(SL* s);
void SeqListCheackCapacity(SL* s);
void SeqListPushFront(SL* s ,SLDateType x);
void SeqListPopFront(SL* s);
void SeqListInsert(SL* s, int pos, SLDateType x);
int SeqListFind(SL* s, SLDateType x);
void SeqListErase(SL* s, int pos);