/*
 * @Author: chenq
 * @Date: 2020-11-01 14:53:29
 * @LastEditTime: 2020-11-18 15:50:15
 * @Descripttion: 友元函数和友元类
 */
#include <iostream>
using namespace std;

class MyClass
{
public:
    friend void Print(MyClass mc);
    friend class MyFriend;
    void myFunc1()
    {
        cout<<"MyClass myFunc1"<<endl;
    }
protected:
    void myFunc2()
    {
        cout<<"MyClass myFunc2"<<endl;
    }
private:
    void myFunc3()
    {
        cout<<"MyClass myFunc3"<<endl;
    }
};

class MyFriend
{
public:
    void friendFun()    //被声明为友元的类的成员函数可以访问类的public、protected跟private成员
    {
        m_mc.myFunc1();
        m_mc.myFunc2();
        m_mc.myFunc3();
    }
private:
    MyClass m_mc;
};

void Print(MyClass mc)  //被声明为友元的函数可以访问类的public、protected跟private成员
{
    mc.myFunc1();
    mc.myFunc2();
    mc.myFunc3();
}

int main()
{
    MyClass mc;
    Print(mc);
    MyFriend mf;
    mf.friendFun();
    return 0;
}