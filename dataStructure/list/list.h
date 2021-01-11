/*
 * @Author: chenq
 * @Date: 2020-12-03 23:33:00
 * @LastEditTime: 2020-12-05 22:52:46
 * @Descripttion: 
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


struct ListNode
{	
    int val;
    ListNode* next;
	ListNode(){};
    ListNode(int x):val(x),next(nullptr){}
};

class List
{
public:
	void initList(ListNode* head, int size);	//初始化链表
	ListNode* reverseList1(ListNode* head);		//反转链表，直接在原有链表上反转
	ListNode* reverseList2(ListNode* head);		//反转链表，不改变原有链表，建立新空间，利用stack
	ListNode* mergeTwoList(ListNode* head1, ListNode* head2);	//合并两个有序链表
	ListNode* merge(vector<ListNode*> vec);	//合并多个有序链表,分治
	
	
	void bubbleSort(ListNode** head);	//链表排序
	void printList(ListNode* head);		//打印链表
};
