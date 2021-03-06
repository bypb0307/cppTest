/*
 * @Author: chenq
 * @Date: 2021-05-10 21:39:54
 * @LastEditTime: 2021-05-10 21:42:32
 * @Descripttion: 
 */
#include <iostream>
using namespace std;

class Sort
{
public:
	Sort(){}
	~Sort(){}
	
	void bubbleSort(int* a, int len);	//冒泡排序
	void selectSort(int* a, int len);	//选择排序
	void insertSort(int* a, int len);	//插入排序
	void quickSort(int* a, int start, int end);	//快速排序
	void hellSort(int* a, int len);		//希尔排序
	void mergeSort(int* a, int start, int end);		//归并排序
	void merge(int* a, int start, int mid, int end);
	void maxHeapSort(int* a, int len);	//堆排序
	void maxHeapify(int* a, int root, int len);	//构建大根堆
	
	void printArray(int* a, int len);	//打印数组
	void printArray(int* a, int start, int end);	//打印数组
	void swapVal(int& a, int& b);		//交换两个整数的值
};