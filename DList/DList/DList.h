#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LTDateType;

typedef struct DListNode 
{
	struct DListNode* next;
	struct DListNode* prev;
	LTDateType data;
}ListNode;

ListNode* BuyListNode(LTDateType x);
ListNode* ListInit();
void ListPushBack(ListNode* phead, LTDateType x);
void ListPopBack(ListNode* phead);
void ListPushFront(ListNode* phead, LTDateType x);
void ListPopFront(ListNode* phead);
void ListInsert(ListNode* pos, LTDateType x);
void ListErase(ListNode* pos);
void ListPrint(ListNode* phead);
ListNode* ListFind(ListNode* phead, LTDateType x);
void ListDestroy(ListNode* phead);
