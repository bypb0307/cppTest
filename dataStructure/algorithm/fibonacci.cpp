/*
 * @Author: chenq
 * @Date: 2020-11-18 17:28:30
 * @LastEditTime: 2020-12-08 22:15:45
 * @Descripttion: 动态规划跟递归计算fibonacci数列
 */
#include <iostream>
using namespace std;

//Recursion
int Fibonacci1(int n) //输入n，输出第n个斐波那契数  0、1、1、2、3、5、8、13...  F(0) = 0, F(1) = 1, F(2) = 1, F(3) = 2 ...
{
    if(n == 0 || n == 1)
    {
        return n;
    }

    return Fibonacci1(n-1) + Fibonacci1(n-2);
}

//dynamic programming
int Fibonacci2(int n) //输入n，输出第n个斐波那契数  0、1、1、2、3、5、8、13... F(0) = 0, F(1) = 1, F(2) = 1, F(3) = 2 ...
{
    if(n == 0 || n == 1)
    {
        return n;
    }
    int a = 0;
    int b = 1;
    int s;
    for(int i = 2;i<=n;i++)
    {
        s = a + b;
        a = b;
        b = s;
    }
    return s;
}

int main()
{
    int n;
    cout<<"input n:";
    cin>>n;
    cout<<"fibonacci1 "<<n<<", : "<<fibonacci1(n)<<endl;
    cout<<"fibonacci2 "<<n<<", : "<<fibonacci2(n)<<endl;

    return 0;
}