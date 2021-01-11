/*
 * @Author: chenq
 * @Date: 2020-11-01 10:35:11
 * @LastEditTime: 2020-11-01 10:51:29
 * @Descripttion: 如果一个派生类从多个基类派生，而这些基类又有共同的基类，那么对该基类中申明的名字进行访问时，可能产生二义性，使用虚继承解决
 */
#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
	Base():m_val(123)
	{
		cout<<"Base default constructor"<<endl;
	}
	Base(int val):m_val(val)
	{
		cout<<"Base int constructor"<<endl;
	}
public:
	int m_val;
};

// class Derived1 : public Base		//如果不用虚拟继承，会报错 ambiguous
class Derived1 :virtual public Base
{
public:
	Derived1()
	{
		cout<<"Derived1 constructor"<<endl;
	}
	Derived1(int val):Base(val)
	{
		cout<<"Derived1 int constructor"<<endl;
	}
};

// class Derived2 : public Base		//如果不用虚拟继承，会报错 ambiguous
class Derived2 : virtual public Base
{
public:
	Derived2()
	{
		cout<<"Derived2 constructor"<<endl;
	}
	Derived2(int val):Base(val)
	{
		cout<<"Derived2 int constructor"<<endl;
	}
};

class Child : public Derived1, public Derived2
{
public:
	Child():Derived1(111), Derived2(222)
	{
		cout<<"Child constructor"<<endl;
	}
	Child(int val):Derived1(val+1), Derived2(val+2)
	{
		cout<<"Child int constructor"<<endl;
	}
};

int main()
{
	Child ch(5);
	cout<<ch.m_val<<endl;
	return 0;
}