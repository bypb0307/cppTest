/*
 * @Author: chenq
 * @Date: 2021-04-25 22:37:09
 * @LastEditTime: 2021-04-26 17:22:49
 * @Descripttion: 观察者模式。定义对象间的一种一对多的依赖关系，以便当一个对象的状态发生改变时，所有依赖于它的对象都得到通知并自动更新
 *                  观察者抽象基类 + 具体观察者类 + 发布者类
 */
#include <iostream>
#include <list>
using namespace std;

//观察者抽象基类
class Observer
{
public:
    Observer() {}
    virtual ~Observer() {}
    virtual void response() = 0;
};

//发布者类
class Publisher
{
public:
    void addObserver(Observer *ob)
    {
        obs.emplace_back(ob);
    }
    void removeObserver(Observer *ob)
    {
        obs.remove(ob);
    }
    void notifyObserver()
    {
        for (auto ob : obs)
        {
            ob->response();
        }
    }

private:
    list<Observer *> obs;
};

//具体观察者1
class ConcreteObserver1 : public Observer
{
public:
    void response()
    {
        cout << "this is ConcreteObserver1 response" << endl;
    }
};
//具体观察者2
class ConcreteObserver2 : public Observer
{
public:
    void response()
    {
        cout << "this is ConcreteObserver2 response" << endl;
    }
};

int main()
{
    Observer *ob1 = new ConcreteObserver1();
    Observer *ob2 = new ConcreteObserver2();
    Publisher pub;
    pub.addObserver(ob1);
    pub.addObserver(ob2);
    pub.notifyObserver();
    cout << "main end" << endl;
}