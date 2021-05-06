/*
 * @Author: chenq
 * @Date: 2020-12-03 23:33:00
 * @LastEditTime: 2021-05-06 15:38:53
 * @Descripttion: 链表反转，合并有序链表
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//链表结点
struct ListNode
{
	ListNode()
	{
		data = 0;
		next = nullptr;
	};
	int data;
    ListNode* next;
};

class List
{
public:
	ListNode* initList(int len);	//初始化链表
	
	ListNode* reverseList1(ListNode* head);		//反转链表，不改变原有链表，建立新空间。也可以利用stack
	ListNode* reverseList2(ListNode* head);		//反转链表，直接在原有链表上反转

	ListNode* mergeTwoList1(ListNode* head1, ListNode* head2);	//合并两个有序链表。循环方式。会破坏原来的两个list
	ListNode* mergeTwoList2(ListNode* head1, ListNode* head2);	//合并两个有序链表。递归方式。会破坏原来的两个list
	ListNode* mergeTwoList3(ListNode* head1, ListNode* head2);	//合并两个有序链表。循环方式。不会破坏原来的两个list
	ListNode* mergeTwoList4(ListNode* head1, ListNode* head2);	//合并两个有序链表。递归方式。不会破坏原来的两个list

	ListNode* merge(vector<ListNode*> vec);	//合并多个有序链表
	
	
	void bubbleSort(ListNode** head);	//链表排序
	void printList(ListNode* head);		//打印链表
};
