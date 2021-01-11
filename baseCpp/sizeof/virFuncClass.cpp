/*
 * @Author: chenq
 * @Date: 2020-11-18 16:57:38
 * @LastEditTime: 2020-11-18 17:05:01
 * @Descripttion: 计算有虚函数时类大小
 */


#include <iostream>
using namespace std;

class Base    //16
{
public:
    Base(){}
    virtual void print1(){cout<<"base print1 "<<endl;}
    virtual void print2(){cout<<"base print2"<<endl;}
    
private:
    int x;
    char s1;
};
class Derived : public Base
{
public:
    Derived(){}
    void print1(){cout<<"Derived print1"<<endl;}

private:
    // int y;
    char s2;
};

int main()
{
    cout<<"sizeof(Base):"<<sizeof(Base)<<endl;
    cout<<"sizeof(Derived):"<<sizeof(Derived)<<endl;

    return 0;
}