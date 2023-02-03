#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

void SLTPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

SLTNode* BuySlistNode(SLTDateType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	newnode->data = x;
	newnode->next = NULL;
}

void SLTPushBack(SLTNode** pphead, SLTDateType x)
{
	assert(pphead);
	SLTNode* newnode = BuySlistNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SLTPushFront(SLTNode** pphead, SLTDateType x)
{
	assert(pphead);
	SLTNode* newnode = BuySlistNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SLTPopBack(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	if (!(*pphead)->next)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		/*SLTNode* tail = *pphead;
		SLTNode* pre = NULL;
		while (tail->next)
		{
			pre = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		pre->next = NULL;*/

		SLTNode* tail = *pphead;
		while (tail->next->next)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}

void SLTPopFront(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

SLTNode* SLTFind(SLTNode* phead, SLTDateType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return  cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x)
{
	assert(pphead);
	if (*pphead == pos)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode* newnode = BuySlistNode(x);
		SLTNode* pre = *pphead;
		while (pre->next != pos)
		{
			pre = pre->next;
		}
		pre->next = newnode;
		newnode->next = pos;
	}
}

void SLTInsertAfter(SLTNode* pos, SLTDateType x)
{
	SLTNode* newnode = BuySlistNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	assert(*pphead);
	if (*pphead == pos)
	{
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* pre = *pphead;
		while (pre->next != pos)
		{
			pre = pre->next;
		}
		pre->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void SLTEraseAfter(SLTNode* pos)
{
	assert(pos->next);
	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
	next = NULL;
}

void SLTDestory(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* cur = *pphead;
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}