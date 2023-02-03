#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

int main()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 0);
	SLTInsert(&plist, SLTFind(plist, 0), 1);
	SLTInsert(&plist, SLTFind(plist, 0), 1);
	SLTInsert(&plist, SLTFind(plist, 0), 1);
	SLTInsertAfter(SLTFind(plist, 0), 2);
	SLTErase(&plist, SLTFind(plist, 1));
	SLTEraseAfter(SLTFind(plist, 0));
	SLTPrint(plist);
	SLTDestory(&plist);
	return 0;
}