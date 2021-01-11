/*
 * @Author: chenq
 * @Date: 2020-11-18 16:56:19
 * @LastEditTime: 2020-11-18 17:09:27
 * @Descripttion: 计算普通类大小
 */
#include <iostream>
#include <string>

using namespace std;

class N
{
    
};

class A
{
public:
    int a;
};

class B
{
public:
    char ch;
};

class C
{
public:
    int i;
    short j;
};

class D
{
public:
    int i;
    short j;
    char ch;
};

class E
{
public:
    int i1;
    int i2;
    short j;
    char ch1;
    char ch2;
};

class F
{
public:
    int i1;
    int i2;
    int i3;
    double d;
    short j;
    char ch1;
    char ch2;
};

 void main()
 {
    char str[] = "hello";
    cout<<"sizeof(str):"<<sizeof(str)<<endl;    //6，还有一个\0

    char *p = str;
    cout<<"sizeof(p):"<<sizeof(p)<<endl;        //64位系统prt: 8 

    int n =10;
    cout<<"sizeof(n):"<<sizeof(n)<<endl;        //4

    cout<<"sizeof(N):"<<sizeof(N)<<endl;           //1
    cout<<"sizeof(A):"<<sizeof(A)<<endl;           //4
    cout<<"sizeof(B):"<<sizeof(B)<<endl;           //1
    cout<<"sizeof(C):"<<sizeof(C)<<endl;           //8
    cout<<"sizeof(D):"<<sizeof(D)<<endl;           //8
    cout<<"sizeof(E):"<<sizeof(E)<<endl;           //12
    cout<<"sizeof(F):"<<sizeof(F)<<endl;           //32
 }