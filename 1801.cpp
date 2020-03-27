// ������18��һ������O(1)ʱ��ɾ��������
// ��Ŀ���������������ͷָ���һ�����ָ�룬����һ��������O(1)ʱ��ɾ����
// ��㡣
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int       m_nValue;
	ListNode* m_pNext;
};

ListNode* CreateListNode(int value) {

	ListNode* pNode = new ListNode();
	pNode->m_nValue = value;
	pNode->m_pNext = nullptr;

	return pNode;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext) {

	if (pCurrent == nullptr) {
		printf("Error to connect two nodes.\n");
		exit(1);
	}
	pCurrent->m_pNext = pNext;
}

void PrintListNode(ListNode* pNode) {

	if (pNode == nullptr) {
		printf("The node is nullptr\n");
	}
	else {
		printf("The key in node is %d.\n", pNode->m_nValue);
	}
}

void PrintList(ListNode* pHead) {

	printf("PrintList starts.\n");
	ListNode* pNode = pHead;
	while (pNode != nullptr) {
		printf("%d\t", pNode->m_nValue);
		pNode = pNode->m_pNext;
	}
	printf("\nPrintList ends.\n");
}

void DestroyList(ListNode* pHead) {
	ListNode * pNode = pHead;
	while (pNode != nullptr) {
		pHead = pHead->m_pNext;
		delete pNode;
		pNode = pHead;
	}
}

void AddToTail(ListNode** pHead, int value) {

	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = nullptr;
	if (*pHead == nullptr) {
		*pHead = pNew;
	}
	else {
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != nullptr) {
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = pNew;
	}
}

void RemoveNode(ListNode** pHead, int value) {

	if (pHead == nullptr || *pHead == nullptr) {
		return;
	}
	ListNode* pToBeDeleted = nullptr;
	if ((*pHead)->m_nValue == value) {
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else {
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value) {
			pNode = pNode->m_pNext;
		}
		if (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value) {
			pToBeDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}
	if (pToBeDeleted != nullptr) {
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted) {

	if (!pListHead || !pToBeDeleted) {
		return;
	}
	//Ҫɾ���Ľڵ㲻��β�ڵ�
	if (pToBeDeleted->m_pNext != nullptr) {
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;
		delete pNext;
		pNext = nullptr;
	}
	//����ֻ��һ���ڵ㣬ɾ��ͷ�ڵ㣨Ҳ��β�ڵ㣩
	else if (*pListHead == pToBeDeleted) {
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		*pListHead = nullptr;
	}
	//�������ж���ڵ㣬ɾ��β�ڵ�
	else {
		ListNode* pNode = *pListHead;
		while (pNode->m_pNext != pToBeDeleted) {
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = nullptr;
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

// ====================���Դ���====================
void Test(ListNode* pListHead, ListNode* pNode)
{
	printf("The original list is: \n");
	PrintList(pListHead);

	printf("The node to be deleted is: \n");
	PrintListNode(pNode);

	DeleteNode(&pListHead, pNode);

	printf("The result list is: \n");
	PrintList(pListHead);
}

// �������ж����㣬ɾ���м�Ľ��
void Test1()
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

	Test(pNode1, pNode3);

	DestroyList(pNode1);
}

// �������ж����㣬ɾ��β���
void Test2()
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

	Test(pNode1, pNode5);

	DestroyList(pNode1);
}

// �������ж����㣬ɾ��ͷ���
void Test3()
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

	Test(pNode1, pNode1);

	DestroyList(pNode1);
}

// ������ֻ��һ����㣬ɾ��ͷ���
void Test4()
{
	ListNode* pNode1 = CreateListNode(1);

	Test(pNode1, pNode1);
}

// ����Ϊ��
void Test5()
{
	Test(nullptr, nullptr);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();

	return 0;
}

