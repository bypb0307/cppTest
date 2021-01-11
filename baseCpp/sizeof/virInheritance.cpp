/*
 * @Author: chenq
 * @Date: 2020-11-01 23:20:43
 * @LastEditTime: 2020-11-02 21:24:20
 * @Descripttion: 计算虚拟继承时类大小
 */
#include <iostream>
using namespace std;

class A
{
public:
    void func(){cout<<"A func"<<endl;}
private:
    // char a[2];
};

class B1: virtual public A
{
public:
    void funcb1(){cout<<"B funcb1"<<endl;}
private:
    // char b1[5];
};

class B2: virtual public A
{
public:
    void funcb2(){cout<<"B funcb2"<<endl;}
private:
    // char b2[5];
};

class C : public B1, public B2
{
public:
    void funcc(){cout<<"C funcc"<<endl;}
private:
    // char c[1];
};

int main()
{
    cout<<"sizeof(A):"<<sizeof(A)<<endl;
    cout<<"sizeof(B1):"<<sizeof(B1)<<endl;
    cout<<"sizeof(B2):"<<sizeof(B2)<<endl;
    cout<<"sizeof(C):"<<sizeof(C)<<endl;
 
    return 0;
}