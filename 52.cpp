// ������52����������ĵ�һ���������
// ��Ŀ���������������ҳ����ǵĵ�һ��������㡣

#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int       m_nValue;
	ListNode* m_pNext;
};

ListNode* CreateListNode(int value)
{
	ListNode* pNode = new ListNode();
	pNode->m_nValue = value;
	pNode->m_pNext = nullptr;

	return pNode;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
	if (pCurrent == nullptr)
	{
		printf("Error to connect two nodes.\n");
		exit(1);
	}

	pCurrent->m_pNext = pNext;
}

void PrintListNode(ListNode* pNode)
{
	if (pNode == nullptr)
	{
		printf("The node is nullptr\n");
	}
	else
	{
		printf("The key in node is %d.\n", pNode->m_nValue);
	}
}

void PrintList(ListNode* pHead)
{
	printf("PrintList starts.\n");

	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		printf("%d\t", pNode->m_nValue);
		pNode = pNode->m_pNext;
	}

	printf("\nPrintList ends.\n");
}

void DestroyList(ListNode* pHead)
{
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		pHead = pHead->m_pNext;
		delete pNode;
		pNode = pHead;
	}
}

void AddToTail(ListNode** pHead, int value)
{
	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = nullptr;

	if (*pHead == nullptr)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != nullptr)
			pNode = pNode->m_pNext;

		pNode->m_pNext = pNew;
	}
}

void RemoveNode(ListNode** pHead, int value)
{
	if (pHead == nullptr || *pHead == nullptr)
		return;

	ListNode* pToBeDeleted = nullptr;
	if ((*pHead)->m_nValue == value)
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
			pNode = pNode->m_pNext;

		if (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value)
		{
			pToBeDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}

	if (pToBeDeleted != nullptr)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

unsigned int GetListLength(ListNode* pHead) {

	unsigned int nLength = 0;
	ListNode* pNode = pHead;
	while (pNode != nullptr) {

		nLength++;
		pNode = pNode->m_pNext;
	}
	return nLength;
}

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode *pHead2) {

	// �õ���������ĳ���
	unsigned int nLength1 = GetListLength(pHead1);
	unsigned int nLength2 = GetListLength(pHead2);
	int nLengthDif = nLength1 - nLength2;

	ListNode* pListHeadLong = pHead1;
	ListNode* pListHeadShort = pHead2;
	if (nLength2 > nLength1) {
		pListHeadLong = pHead2;
		pListHeadShort = pHead1;
		nLengthDif = nLength2 - nLength1;
	}
	for (int i = 0; i < nLengthDif; i ++) {
		pListHeadLong - pListHeadLong->m_pNext;
	}
	while ((pListHeadLong != nullptr) &&
		(pListHeadShort != nullptr) &&
		(pListHeadLong != pListHeadShort))
	{
		pListHeadLong = pListHeadLong->m_pNext;
		pListHeadShort = pListHeadShort->m_pNext;
	}

	// �õ���һ���������
	ListNode* pFisrtCommonNode = pListHeadLong;

	return pFisrtCommonNode;
}

void DestroyNode(ListNode* pNode);

void Test(char* testName, ListNode* pHead1, ListNode* pHead2, ListNode* pExpected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	ListNode* pResult = FindFirstCommonNode(pHead1, pHead2);
	if (pResult == pExpected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

// ��һ����������������м�
// 1 - 2 - 3 \
//            6 - 7
//     4 - 5 /
void Test1()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);
	ListNode* pNode6 = CreateListNode(6);
	ListNode* pNode7 = CreateListNode(7);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode6);
	ConnectListNodes(pNode4, pNode5);
	ConnectListNodes(pNode5, pNode6);
	ConnectListNodes(pNode6, pNode7);

	Test("Test1", pNode1, pNode4, pNode6);

	DestroyNode(pNode1);
	DestroyNode(pNode2);
	DestroyNode(pNode3);
	DestroyNode(pNode4);
	DestroyNode(pNode5);
	DestroyNode(pNode6);
	DestroyNode(pNode7);
}

// û�й������
// 1 - 2 - 3 - 4
//            
// 5 - 6 - 7
void Test2()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);
	ListNode* pNode6 = CreateListNode(6);
	ListNode* pNode7 = CreateListNode(7);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode5, pNode6);
	ConnectListNodes(pNode6, pNode7);

	Test("Test2", pNode1, pNode5, nullptr);

	DestroyList(pNode1);
	DestroyList(pNode5);
}

// ������������һ�����
// 1 - 2 - 3 - 4 \
//                7
//         5 - 6 /
void Test3()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);
	ListNode* pNode6 = CreateListNode(6);
	ListNode* pNode7 = CreateListNode(7);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode7);
	ConnectListNodes(pNode5, pNode6);
	ConnectListNodes(pNode6, pNode7);

	Test("Test3", pNode1, pNode5, pNode7);

	DestroyNode(pNode1);
	DestroyNode(pNode2);
	DestroyNode(pNode3);
	DestroyNode(pNode4);
	DestroyNode(pNode5);
	DestroyNode(pNode6);
	DestroyNode(pNode7);
}

// ��������ǵ�һ�����
// 1 - 2 - 3 - 4 - 5
// ����������ȫ�غ�   
void Test4()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test("Test4", pNode1, pNode1, pNode1);

	DestroyList(pNode1);
}

// ���������������һ��������
void Test5()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test("Test5", nullptr, pNode1, nullptr);

	DestroyList(pNode1);
}

// ���������������һ��������
void Test6()
{
	Test("Test6", nullptr, nullptr, nullptr);
}

void DestroyNode(ListNode* pNode)
{
	delete pNode;
	pNode = nullptr;
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();

	return 0;
}

