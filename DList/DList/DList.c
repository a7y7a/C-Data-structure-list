#define _CRT_SECURE_NO_WARNINGS 1
#include"Dlist.h"

ListNode* BuyListNode(LTDateType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->data = x;
	return newnode;
}

ListNode* ListInit()
{
	ListNode* newnode = BuyListNode(0);
	newnode->next = newnode;
	newnode->prev = newnode;
	newnode->data = 0;
	return newnode;
}

void ListPushBack(ListNode *phead, LTDateType x)
{
	assert(phead);
	//ListNode* tail = phead->prev;
	//ListNode* newnode = BuyListNode(x);
	//tail->next = newnode;
	//newnode->prev = tail;
	//phead->prev = newnode;
	//newnode->next = phead;
	ListInsert(phead, x);
}

void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	/*ListNode* tail = phead->prev;
	ListNode* newtail = tail->prev;
	free(tail);
	newtail->next = phead;
	phead->prev = newtail;*/
	ListErase(phead->prev);
}

void ListPushFront(ListNode* phead, LTDateType x)
{
	assert(phead);
	//ListNode* head = phead->next;
	//ListNode* newnode = BuyListNode(x);
	//phead->next = newnode;
	//newnode->prev = phead;
	//head->prev = newnode;
	//newnode->next = head;
	ListInsert(phead->next, x);
}

void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	/*ListNode* head = phead->next;
	ListNode* newhead = head->next;
	free(head);
	newhead->prev = phead;
	phead->next = newhead;*/
	ListErase(phead->next);
}

void ListInsert(ListNode* pos, LTDateType x)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	pos->prev = newnode;
	newnode->next = pos;
	prev->next = newnode;
	newnode->prev = prev;
}

void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->prev, *next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}


void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

ListNode* ListFind(ListNode* phead, LTDateType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x) return cur;
		cur = cur->next;
	}
	return NULL;
}

void ListDestroy(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}