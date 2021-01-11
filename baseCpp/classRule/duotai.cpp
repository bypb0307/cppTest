/*
 * @Author: chenq
 * @Date: 2020-11-04 11:55:36
 * @LastEditTime: 2020-11-18 15:48:56
 * @Descripttion: 将派生类的地址 通过指针或引用的方式给父类
 */
#include <iostream>

using namespace std;

class Base
{
public:
    virtual void func(int val)
    {
        cout<<"Base func val: "<<val<<endl;
    }
};

class Derived : public Base
{
public:
    void func(int val)
    {
        cout<<"Derived func val: "<<val<<endl;
    }
    void func(string val)
    {
        cout<<"Derived func val: "<<val<<endl;
    }
};

int main()
{
    Derived de;
    de.func("abc");
    de.func(123);

    Base* ba1 = &de;
    ba1->func(456);
    Base& ba2 = de;
    ba2.func(789);

    return 0;
}