#include "list.h"
#include <ctime>
#include <stack>
using namespace std;

//初始化链表
ListNode *List::initList(int len)
{
	if (len < 1) //如果初始化链表长度小于1，则为空链表
	{
		return nullptr;
	}

	static int s = 0; //防止在同一秒调用多次生成一样的随机链表
	srand(time(0) + s);
	s++;

	int tmp;
	tmp = rand() % 100 + 1;			 //生成一个1-99的随机数作为结点数据
	ListNode *head = new ListNode(); //初始化头结点
	head->data = tmp;
	head->next = nullptr;
	ListNode *p = head;

	for (int i = 0; i < len - 1; i++) //循环初始化剩余结点
	{
		tmp = rand() % 100 + 1;
		ListNode *node = new ListNode();
		node->data = tmp;
		node->next = nullptr;
		p->next = node;
		p = node;
	}
	return head;
}

//反转链表，不改变原有链表，建立新空间。也可以利用stack
ListNode *List::reverseList1(ListNode *head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return nullptr;
	}
	ListNode *ret = nullptr;
	while (head != nullptr)
	{
		ListNode *node = new ListNode();
		node->data = head->data;
		node->next = ret;
		ret = node;
		head = head->next;
	}
	return ret;
}

//反转链表，直接在原有链表上反转
ListNode *List::reverseList2(ListNode *head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return nullptr;
	}
	ListNode *pre = nullptr;
	ListNode *cur = head;
	ListNode *tmp = nullptr;
	while (cur != nullptr)
	{
		tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}
	return pre;
}

//合并两个有序链表。循环方式。会破坏原来的两个list
ListNode *List::mergeTwoList1(ListNode *head1, ListNode *head2)
{
	if (head1 == nullptr)
		return head2;
	if (head2 == nullptr)
		return head1;

	ListNode *newHead = new ListNode(); //创建一个头结点，返回的时候返回头结点的下一个结点，并且释放该头结点
	ListNode *p = newHead;

	while (head1 && head2)
	{
		if (head1->data > head2->data)
		{
			p->next = head2;
			head2 = head2->next;
		}
		else
		{
			p->next = head1;
			head1 = head1->next;
		}
		p = p->next;
	}
	if (head1 == nullptr)
	{
		p->next = head2;
	}
	else
	{
		p->next = head1;
	}
	ListNode *h = newHead;
	newHead = newHead->next;
	delete h;
	return newHead;
}

//合并两个有序链表。递归方式。会破坏原来的两个list
ListNode *List::mergeTwoList2(ListNode *head1, ListNode *head2)
{
	if (head1 == nullptr)
		return head2;
	if (head2 == nullptr)
		return head1;

	if (head1->data > head2->data)
	{
		head2->next = mergeTwoList2(head1, head2->next);
		return head2;
	}
	else
	{
		head1->next = mergeTwoList2(head1->next, head2);
		return head1;
	}
}

//合并两个有序链表。循环方式。不会破坏原来的两个list
ListNode *List::mergeTwoList3(ListNode *head1, ListNode *head2)
{
	if (head1 == nullptr)
	{
		return head2;
	}
	else if (head2 == nullptr)
	{
		return head1;
	}
	ListNode *newHead = new ListNode();
	ListNode *p = newHead;
	ListNode *tmp;

	while (head1 && head2)
	{
		if (head1->data > head2->data)
		{
			tmp = new ListNode();
			tmp->data = head2->data;
			p->next = tmp;
			head2 = head2->next;
		}
		else
		{
			tmp = new ListNode();
			tmp->data = head1->data;
			p->next = tmp;
			head1 = head1->next;
		}
		p = p->next;
	}
	while (head1)
	{
		tmp = new ListNode();
		tmp->data = head1->data;
		p->next = tmp;
		p = p->next;
		head1 = head1->next;
	}
	while (head2)
	{
		tmp = new ListNode();
		tmp->data = head2->data;
		p->next = tmp;
		p = p->next;
		head2 = head2->next;
	}
	ListNode *h = newHead;
	newHead = newHead->next;
	delete h;
	return newHead;
}

//合并两个有序链表。循环方式。不会破坏原来的两个list
ListNode *List::mergeTwoList4(ListNode *head1, ListNode *head2)
{
	return nullptr;
}

//合并多个有序链表
ListNode *List::merge(vector<ListNode *> vec)
{
	return nullptr;
}

//链表排序
void List::bubbleSort(ListNode *head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return;
	}

	ListNode *p;
	ListNode *q;
	ListNode *tail = nullptr;
	bool sorted; //用于判断是否提前完成冒泡过程
	int i = 1;	 //计数，冒泡的次数

	while (true)
	{
		sorted = true;
		p = head;
		while (p->next != tail)
		{
			if (p->data > p->next->data)
			{
				int tmp = p->next->data;
				p->next->data = p->data;
				p->data = tmp;
				sorted = false;
			}
			p = p->next;
		}
		cout << "第" << i++ << "次冒泡结果:" << endl;
		printList(head);

		tail = p;
		if (p == head || sorted) //完成冒泡排序，tail指针指向头指针，或者提前完成排序，sorted=true
		{
			break;
		}
	}
}

//打印链表
void List::printList(ListNode *head)
{
	if (head == nullptr)
	{
		return;
	}
	while (head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	List li;
	ListNode *head1 = li.initList(10); //初始化一个列表head1
	cout << "print head1:" << endl;
	li.printList(head1);
	li.bubbleSort(head1); //对列表head1进行冒泡排序
	cout << "print bubble sorted head1:" << endl;
	li.printList(head1);

	// ListNode *head1Rev1 = li.reverseList1(head1); //逆转链表head1，不改变原有链表
	// cout << "print head1 reverseList1:" << endl;
	// li.printList(head1);
	// cout << "print head1Rev1 after reverseList1:" << endl;
	// li.printList(head1Rev1);

	// ListNode *head1Rev2 = li.reverseList2(head1); //直接在原有链表基础上逆转链表head1，会改变head1的原有结构
	// cout << "print head1 reverseList2:" << endl;
	// li.printList(head1);
	// cout << "print head1Rev1 after reverseList2:" << endl;
	// li.printList(head1Rev2);

	// cout << "merge two list............................." << endl
	// 	 << endl;

	// ListNode *head2 = li.initList(10); //初始化一个列表head2
	// li.bubbleSort(&head2);			   //对列表head2进行冒泡排序
	// cout << "print sorted list head2:" << endl;
	// li.printList(head2);

	// ListNode *head3 = li.initList(10); //初始化一个列表head3
	// li.bubbleSort(&head3);			   //对列表head3进行冒泡排序
	// cout << "print sorted list head3:" << endl;
	// li.printList(head3);

	// ListNode *head23 = li.mergeTwoList4(head2, head3); //测试合并两个有序链表 mergeTwoList1 mergeTwoList2 mergeTwoList3
	// cout << "print merged list head23:" << endl;
	// li.printList(head23);
	// cout << "print merged head2:" << endl;
	// li.printList(head2);
	// cout << "print merged head3:" << endl;
	// li.printList(head3);

	return 0;
}
