/*
 * @Author: chenq
 * @Date: 2020-11-18 16:33:44
 * @LastEditTime: 2020-11-18 16:44:21
 * @Descripttion: 指针常量和常量指针
 */
#include <iostream>
using namespace std;

int main()
{
    char s1[] = "hello";
    char s2[] = "world";
    
    const char* p1;     //常量指针，指向的地址可以变，指向的内容不能变。

    p1 = s1;         //指向的地址可以变
    p1 = s2;         //指向的地址可以变
    // p1[0] = '1';  //指向的内容不能变


    char* const p2 = s1;     //指针常量，指向的地址不能变，指向的内容可以变。声明的时候就必须绑定一个地址，用法与引用类似
    
    // p2 = s2;        //指向的地址不能变
    p2[0] = '1';    //指向的内容可以变

    cout<<"s1:"<<s1<<", s2:"<<s2<<endl;
    return 0;
}
