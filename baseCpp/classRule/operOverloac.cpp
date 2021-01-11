/*
 * @Author: chenq
 * @Date: 2020-11-01 16:13:46
 * @LastEditTime: 2020-11-18 16:28:29
 * @Descripttion: 运算符重载的相关知识
 */

#include <iostream>
using namespace std;

class Box
{
public:
    Box():length(0),breadth(0),high(0){}
    Box(int l, int b, int h):length(l),breadth(b),high(h){}
    Box operator+(const Box& other)     //a+b等价于a.operator+(b)
    {
        Box box;
        box.length = this->length + other.length;
        box.breadth = this->breadth + other.breadth;
        box.high = this->high + other.high;
        return box;
    }
    Box operator++()        //前置单目运算符重载为类的成员函数时，不需要显式说明参数，即函数没有形参
    {
        this->length++;
        this->breadth++;
        this->high++;
        return *this;
    }
    Box operator++(int)       //后置单目运算符重载为类的成员函数时，函数要带有一个整型形参
    {
        Box box = *this;
        this->length++;
        this->breadth++;
        this->high++;
        return box;
    }
    void printBox()
    {
        cout<<"length:"<<this->length<<", breadth:"<<this->breadth<<", high:"<<this->high<<endl;
    }

private:
    int length;     //长
    int high;      //宽
    int breadth;    //高
};

int main()
{
    Box b1(1,2,3);
    Box b2(2,3,4);
    Box b3;
    Box b4;
    Box b5;
    b3 = b1 + b2;
    b1.printBox();  //1, 2, 3
    b2.printBox();  //2, 3, 4
    b3.printBox();  //3, 5, 7
    
    cout<<endl;

    b4 = b1++;
    b5 = ++b2;
    b4.printBox();  //1, 2, 3
    b5.printBox();  //3, 4, 5

    return 0;
}


