/*
 * @Author: chenq
 * @Date: 2020-11-04 11:08:54
 * @LastEditTime: 2020-11-18 15:51:04
 * @Descripttion: 只要函数名相同，不管参数和返回值是否相同，基类函数都会被隐藏
 */
#include <iostream>

using namespace std;

class Base
{
public:
    void func(int val)
    {
        cout<<"Base func val: "<<val<<endl;
    }
};

class Derived : public Base
{
public:
    void func(string str)
    {
        cout<<"Derived func str: "<<str<<endl;
    }
};

int main()
{
    Derived de;
    int val = 123;
    string str = "abc";
    // de.func(val);   //被隐藏了，不能调用父类的同名函数，即时参数不同
    de.func(str);

    return 0;
}