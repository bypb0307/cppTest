#include "sort.h"

//冒泡排序
void Sort::bubbleSort(int *a, int len)
{
	bool sorted = true;
	for (int i = len - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				swapVal(a[j], a[j + 1]);
				sorted = false;
			}
		}
		if (sorted)
		{
			break;
		}
	}

	printArray(a, len);
	cout << "bubbleSort end ..." << endl;
}
//选择排序
void Sort::selectSort(int *a, int len)
{
	int max_idx;
	for (int i = len - 1; i > 0; i--)
	{
		max_idx = 0;
		for (int j = 1; j <= i; j++)
		{
			if (a[j] > a[max_idx])
			{
				max_idx = j;
			}
		}
		swapVal(a[max_idx], a[i]);
	}

	printArray(a, len);
	cout << "selectSort end ..." << endl;
}
//插入排序
void Sort::insertSort(int *a, int len)
{
	int i, j, tmp;
	for (i = 1; i < len; i++)
	{
		tmp = a[i];
		for (j = i; j > 0 && a[j - 1] > tmp; j--)
		{
			a[j] = a[j - 1];
		}
		a[j] = tmp;
	}

	printArray(a, len);
	cout << "insertSort end ..." << endl;
}
//快速排序
void Sort::quickSort(int *a, int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int pivot = a[start];
	int low = start;
	int high = end;
	while (low < high)
	{
		while ((low < high) && (a[high] >= pivot))
		{
			high--;
		}
		if (low < high)
		{
			a[low] = a[high];
		}
		while ((low < high) && (a[low] < pivot))
		{
			low++;
		}
		if (low < high)
		{
			a[high] = a[low];
		}
		if (low == high)
		{
			a[low] = pivot;
		}
	}
	quickSort(a, start, low - 1);
	quickSort(a, low + 1, end);

	printArray(a, start, end);
	cout << "quickSort end ..." << endl;
}
//希尔排序
void Sort::hellSort(int *a, int len)
{
	if (len < 2)
	{
		return;
	}
	int i, j, tmp;
	int gap = len / 2;
	while (gap > 0)
	{
		for (i = gap; i <= len - gap; i += gap)
		{
			tmp = a[i];
			for (j = i; j >= gap && a[j - gap] > tmp; j -= gap)
			{
				a[j] = a[j - gap];
			}
			a[j] = tmp;
		}
		gap = gap / 2;
	}

	printArray(a, len);
	cout << "hellSort end ..." << endl;
}
//归并排序
void Sort::mergeSort(int *a, int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int mid = (start + end) / 2;
	mergeSort(a, start, mid);
	mergeSort(a, mid + 1, end);
	merge(a, start, mid, end);
}
void Sort::merge(int *a, int start, int mid, int end)
{
	int n = end - start + 1;
	int *tmp = new int[n];
	int left = start;
	int right = mid + 1;
	int i = 0;
	while (left <= mid && right <= end)
	{
		tmp[i++] = a[left] < a[right] ? a[left++] : a[right++];
	}
	while (left <= mid)
	{
		tmp[i++] = a[left++];
	}
	while (right <= end)
	{
		tmp[i++] = a[right++];
	}

	for (int j = 0; j < n; j++)
	{
		a[start + j] = tmp[j];
	}
	delete[] tmp;
}
//堆排序，大顶堆
void Sort::maxHeapSort(int *a, int len)
{
	//构建大顶堆，从最后一个父节点开始
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		maxHeapify(a, i, len);
	}

	//取大顶堆的根节点，即最大的数，放在数组最后的位置
	for (int j = len - 1; j > 0; j--)
	{
		swapVal(a[j], a[0]);
		maxHeapify(a, 0, j); //去除最后位置的元素，重新建堆，只需要从根节点开始，后面的都是已经有序的
	}

	printArray(a, len);
	cout << "maxHeapSort end ..." << endl;
}
void Sort::maxHeapify(int *a, int root, int len)
{
	int lchild = 2 * root + 1;
	if (lchild >= len)
	{
		return;
	}
	int max_child = lchild;
	int rchild = lchild + 1;
	if (rchild < len && a[rchild] > a[max_child])
	{
		max_child = rchild;
	}
	if (a[root] < a[max_child])
	{
		swapVal(a[root], a[max_child]);
		maxHeapify(a, max_child, len);
	}
}

//交换两个整数的值
void Sort::swapVal(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void Sort::printArray(int *a, int len)
{
	for (auto i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void Sort::printArray(int *a, int start, int end)
{
	for (auto i = start; i <= end; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void initArray(int *a, int len)
{
	srand(time(0));
	for (int i = 0; i < len; i++)
	{
		a[i] = rand() % 100 + 1;
	}
}

int main()
{
	int a[10];
	initArray(a, 10);
	Sort st;
	cout << "print original array: ";
	st.printArray(a, 10);

	cout << " print after sorting: ";
	// st.bubbleSort(a, 10);
	st.selectSort(a, 10);
	// st.insertSort(a, 10);
	// st.quickSort(a, 0, 9);
	// st.hellSort(a, 10);

	// st.mergeSort(a, 0, 9);
	// st.printArray(a, 0, 9);
	// cout<<"mergeSort end ..."<<endl;

	// st.maxHeapSort(a, 10);

	return 0;
}