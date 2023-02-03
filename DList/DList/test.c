#define _CRT_SECURE_NO_WARNINGS 1
#include"Dlist.h"

int main()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 1);
	ListPushBack(plist, 5);
	ListPrint(plist);
	ListDestroy(plist);
	plist - NULL;
	return 0;
}