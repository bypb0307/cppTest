#include "list.h"
#include <ctime>
#include <stack>
using namespace std;

//初始化链表
void List::initList(ListNode *head, int size)
{
	static int s = 0;
	srand(time(0) + s);
	s++;
	int tmp;
	tmp = rand() % 100 + 1;
	head->val = tmp;
	head->next = nullptr;
	ListNode *p = head;

	for (int i = 0; i < size - 1; i++)
	{
		tmp = rand() % 100 + 1;
		ListNode *q = new ListNode(tmp);
		p->next = q;
		p = q;
	}
}
//反转链表，直接在原有链表上反转
ListNode *List::reverseList1(ListNode *head)
{
	ListNode *pre = nullptr;
	ListNode *cur = head;
	ListNode *tmp;

	while (cur != nullptr)
	{
		tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}
	return pre;
}
//反转链表，不改变原有链表，建立新空间，利用stack
ListNode *reverseList2(const ListNode *head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return head;
	}
	stack<int> datas;
	ListNode *p = head;
	while (p != nullptr)
	{
		datas.push(p->val);
		p = p->next;
	}

	int tmp = datas.pop();
	ListNode *q = new ListNode(tmp);
	ListNode *t = q;
	while(!datas.empty())
	{
		
	}
}

//合并两个有序链表
ListNode *List::mergeTwoList(ListNode *head1, ListNode *head2)
{
	if (head1 == nullptr)
		return head2;
	if (head2 == nullptr)
		return head1;
	return nullptr;

	/*
	// 这种会破坏原来的两个list
	ListNode* head;
	if(head1->val > head2->val)
	{
		head = head2;
		head->next = mergeTwoList(head1, head2->next);
	}
	else
	{
		head = head1;
		head->next = mergeTwoList(head1->next, head2);
	}
	return head;
	*/

	// ListNode* head;
	// if(head1->val > head2->val)
	// {
	// head = new ListNode(head2->val);
	// ListNode* tmp = mergeTwoList(head1, head2->next);
	// head->next = new ListNode(tmp->val);
	// }
	// else
	// {
	// head = new ListNode(head1->val);
	// ListNode* tmp = mergeTwoList(head2, head1->next);
	// head->next = new ListNode(tmp->val);
	// }
	// return head;
}

//合并多个有序链表,分治
ListNode *List::merge(vector<ListNode *> vec)
{
	return nullptr;
}

//链表排序
void List::bubbleSort(ListNode **head)
{
	ListNode *p;
	ListNode *q;
	ListNode *r;
	if ((*head) == nullptr || (*head)->next == nullptr)
	{
		return;
	}
	bool sorted = true;
	for (p = *head; p != nullptr; p = p->next)
	{
		for (q = *head; q->next != nullptr; q = q->next)
		{
			if (q->val > q->next->val)
			{
				int tmp = q->val;
				q->val = q->next->val;
				q->next->val = tmp;
				sorted = false;
			}
		}
		if (sorted)
		{
			break;
		}
	}
	cout << "after bubbleSort" << endl;
	printList(*head);
}
//打印链表
void List::printList(ListNode *head)
{
	cout << "print list: ";
	if (head == nullptr)
	{
		return;
	}
	while (head != nullptr)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	List li;
	ListNode *head1 = new ListNode();
	li.initList(head1, 10);
	li.printList(head1);

	li.bubbleSort(&head1);

	head1 = li.reverseList1(head1);

	// ListNode *head2 = new ListNode();
	// li.initList(head2, 10);
	// li.printList(head2);
	// li.bubbleSort(&head2);

	// cout << endl;

	// ListNode *head1_r = li.reverseList(head1);
	// li.printList(head1_r);
	// li.printList(head1);

	// ListNode* head = li.mergeTwoList(head1, head2);
	// li.printList(head);
	// cout<<"mergeTwoList end"<<endl;
	// li.printList(head1);
	// li.printList(head2);

	return 0;
}
