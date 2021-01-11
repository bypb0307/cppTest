/*
 * @Author: chenq
 * @Date: 2020-11-16 15:03:02
 * @LastEditTime: 2020-11-26 22:40:11
 * @Descripttion: 二分查找法
 */
#include <iostream>
using namespace std;

//冒泡排序
void bubbleSort(int* a, int n)
{
    int tmp;
    bool sorted = true;
    for(int i=n-1;i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j] > a[j+1])
            {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                sorted = false;
            }
        }
        if(sorted)
        {
            return;
        }
    }
}

//初始化一个随机数组
void initArray(int* a, int n)
{
	srand(time(0));
	for(int i=0;i<n;i++)
	{
		a[i] = rand()%100 + 1; 
	}
}

void printArray(const int* a, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

//二分查找，非递归实现
int binSearch1(int target, const int* a, int n)
{
    int begin = 0;
    int end = n;
    int mid;

    while (begin < end)
    {
        mid = (begin + end)/2;
        if(target == a[mid])
        {
            return mid;
        }
        else if(target > a[mid])
        {
            begin = mid+1;
        }
        else
        {
            end = mid;
        }
    }
    cout<<"not found target:"<<target<<endl;
    return -1;
}

//二分查找，递归实现
int binSearch2(int target, const int* a, int begin, int end)
{
    if(begin > end)
    {
        return -1;
    }
    int mid = (begin + end)/2;
    if(target == a[mid])
    {
        return mid;
    }
    else if(target > a[mid])
    {
        return binSearch2(target, a, mid+1, end);
    }
    else
    {
        return binSearch2(target, a, begin, mid-1);
    }
}


int main()
{
    //init array
    int a[20] = {0};
    initArray(a, 20);
    cout<<"print origin array:"<<endl;
    printArray(a, 20);

    //bubbleSort
    bubbleSort(a, 20);
    cout<<"print array after bubbleSort:"<<endl;
    printArray(a, 20);

    int target;
    cout<<"input a target: ";
    cin>>target;
    // int ret = binSearch1(target, a, 20);
    int ret = binSearch2(target, a, 0, 19);
    if(ret != -1)
    {
        cout<<"find target:"<<target<<", index is:"<<ret<<endl;
    }

    return 0;
}
