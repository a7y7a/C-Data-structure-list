#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void SeqListInit(SL* s)
{
	s->p = NULL;
	s->size = s->capacity = 0;
}

void SeqListPrint(SL* s)
{
	int i = 0;
	for (i = 0; i < s->size; i++)
	{
		printf("%d ", s->p[i]);
	}
	printf("\n");
}

void SeqListDestory(SL* s)
{
	free(s->p);
	SeqListInit(s);
}

void SeqListCheackCapacity(SL* s)
{
	if (s->size == s->capacity)
	{
		s->capacity = s->capacity ? 2 * s->capacity : 4;
		SLDateType* tmp = (SLDateType*)realloc(s->p, s->capacity * sizeof(SLDateType));
		if (tmp == NULL) exit(-1);
		s->p = tmp;
	}
}

void SeqListPushBack(SL* s, SLDateType x)
{
	SeqListCheackCapacity(s);
	s->p[s->size++] = x;
}

void SeqListPopBack(SL* s)
{
	assert(s->size > 0);
	s->size--;
}

void SeqListPushFront(SL* s, SLDateType x)
{
	SeqListCheackCapacity(s);
	int i = 0;
	for (i = s->size; i > 0; i--)
	{
		s->p[i] = s->p[i - 1];
	}
	s->p[0] = x;
	s->size++;
}

void SeqListPopFront(SL* s)
{
	assert(s->size > 0);
	int i = 0;
	for (i = 0; i < s->size - 1; i++)
	{
		s->p[i] = s->p[i + 1];
	}
	s->size--;
}

void SeqListInsert(SL* s, int pos, SLDateType x)
{
	assert(pos >= 0 && pos <= s->size);
	SeqListCheackCapacity(s);
	int i = 0;
	for (i = s->size; i > pos; i--)
	{
		s->p[i] = s->p[i - 1];
	}
	s->p[pos] = x;
	s->size++;
}

int SeqListFind(SL* s, SLDateType x)
{
	int i = 0;
	for (i = 0; i < s->size; i++)
	{
		if (s->p[i] == x)
		{
			return  i;
		}
	}
	return -1;
}

void SeqListErase(SL* s, int pos)
{
	assert(s->size > pos && pos >= 0);
	int i = 0;
	for (i = pos; i < s->size - 1; i++)
	{
		s->p[i] = s->p[i + 1];
	}
	s->size--;
}