#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SLTNode;

void SLTPrint(SLTNode* phead);

SLTNode* BuySlistNode(SLTDateType x);

void SLTPushBack(SLTNode** pphead, SLTDateType x);

void SLTPushFront(SLTNode** pphead, SLTDateType x);

void SLTPopBack(SLTNode** pphead);

void SLTPopFront(SLTNode** pphead);

SLTNode* SLTFind(SLTNode* pphead, SLTDateType x);

void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x);

void SLTInsertAfter(SLTNode* pos, SLTDateType x);

void SLTErase(SLTNode** pphead, SLTNode* pos);

void SLTEraseAfter(SLTNode* pos);

void SLTDestory(SLTNode** pphead);