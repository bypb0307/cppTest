/*
 * @Author: chenq
 * @Date: 2020-11-01 12:02:16
 * @LastEditTime: 2020-11-18 15:52:20
 * @Descripttion: 继承子类对父类成员的访问权限
 */
#include <iostream>
using namespace std;

class Base
{
public:
    void func1()
    {
        cout<<"Base func1"<<endl;
    }
protected:
    void func2()
    {
        cout<<"Base func2"<<endl;
    }
private:
    void func3()
    {
        cout<<"Base func3"<<endl;
    }
};

class Derived1 : public Base
{
public:
    void derived1() //public继承可以在子类函数中访问父类的public跟protected函数
    {
        cout<<"Derived1 derived1"<<endl;
        func1();
        func2();
        // func3();
    }    
};

class Derived2 : protected Base
{
public:
    void derived2() //protected继承可以在子类函数中访问父类的public跟protected函数
    {
        cout<<"Derived2 derived2"<<endl;
        func1();
        func2();
        // func3();
    }  
};

class Derived3 : private Base
{
public:
    void derived3() //private继承无法在子类函数中访问父类的public跟protected函数
    {
        cout<<"Derived3 derived3"<<endl;
        // func1();
        // func2();
        // func3();
    }
};

int main()
{
    Base b;         //类的对象可以直接访问public成员，无法访问protected跟private成员
    b.func1();
    
    Derived1 d1;     //public继承，子类对象可以直接访问子类跟父类的public成员，无法访问protected跟private成员
    d1.derived1();
    d1.func1();

    Derived2 d2;    //protected继承，父类中public跟protected方法在子类中变为protected，private不变，因此均无法通过类对象直接访问
    d2.derived2();

    Derived3 d3;    //private继承，父类中public跟protected跟private方法在子类中均变为private，均无法通过类对象直接访问
    d3.derived3();
    
    return 0;
}