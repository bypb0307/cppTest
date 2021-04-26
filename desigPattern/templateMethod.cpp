/*
 * @Author: chenq
 * @Date: 2021-04-25 22:18:41
 * @LastEditTime: 2021-04-26 17:22:33
 * @Descripttion: 模板方法模式。定义一个稳定的算法骨架，而将算法的一些步骤延迟到子类中，使得子类可以不改变该算法结构的情况下重定义该算法的某些特定步骤
 *                  抽象基类 + 具体子类
 */
#include <iostream>
using namespace std;

//抽象基类
class AbstractClass
{
public:
    AbstractClass() {}
    virtual ~AbstractClass() {}
    void templateMethod()
    {
        cout << "step1..." << endl;
        step2();
        cout << "step3..." << endl;
    }
    virtual void step2() = 0;
};

//具体子类
class ConcreteClass : public AbstractClass
{
public:
    void step2()
    {
        cout << "concrete step2..." << endl;
    }
};

int main()
{
    AbstractClass *tm = new ConcreteClass();
    tm->templateMethod();
    cout << "main end" << endl;
}