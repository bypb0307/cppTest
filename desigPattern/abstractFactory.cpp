/*
 * @Author: chenq
 * @Date: 2021-04-26 16:36:05
 * @LastEditTime: 2021-04-26 16:49:42
 * @Descripttion: 抽象工厂模式。在工厂模式的基础上扩展了工厂的功能，使其可以生产多个大类（手机 + 电脑），如果只有一个产品体系就会退化为工厂模式
 *                  抽象产品类（手机 + 电脑） + 具体产品类（华为手机 + 小米手机 + 华为电脑 + 小米电脑） + 抽象工厂类（工厂）+ 具体工厂类（华为工厂 + 小米工厂）
 */
#include <iostream>
using namespace std;

//抽象产品类A（手机）
class Phone
{
public:
    Phone() {}
    virtual ~Phone() {}
    virtual void showPhoneInfo() = 0;
};
//抽象产品类B（电脑）
class Computer
{
public:
    Computer() {}
    virtual ~Computer() {}
    virtual void showComputerInfo() = 0;
};

//抽象工厂，定义生产多个品类的接口
class Factory
{
public:
    Factory() {}
    virtual ~Factory() {}
    virtual Phone *createPhone() = 0;
    virtual Computer *createComputer() = 0;
};

//抽象产品类A的具体产品类1（华为手机）
class HuaweiPhone : public Phone
{
public:
    void showPhoneInfo()
    {
        cout << "this is HuaweiPhone" << endl;
    }
};
//抽象产品类A的具体产品类2（小米手机）
class XiaomiPhone : public Phone
{
public:
    void showPhoneInfo()
    {
        cout << "this is XiaomiPhone" << endl;
    }
};

//抽象产品类B的具体产品类1（华为电脑）
class HuaweiComputer : public Computer
{
public:
    void showComputerInfo()
    {
        cout << "this is HuaweiComputer" << endl;
    }
};
//抽象产品类B的具体产品类2（小米电脑）
class XiaomiComputer : public Computer
{
public:
    void showComputerInfo()
    {
        cout << "this is XiaomiComputer" << endl;
    }
};

//具体工厂类1（华为工厂）
class HuaweiFactory : public Factory
{
public:
    Phone *createPhone()
    {
        return new HuaweiPhone();
    }
    Computer *createComputer()
    {
        return new HuaweiComputer();
    }
};
//具体工厂类2（小米工厂）
class XiaomiFactory : public Factory
{
public:
    Phone *createPhone()
    {
        return new XiaomiPhone();
    }
    Computer *createComputer()
    {
        return new XiaomiComputer();
    }
};

int main()
{
    Factory *fact1 = new HuaweiFactory();
    Phone *ph1 = fact1->createPhone();
    Computer *comp1 = fact1->createComputer();
    ph1->showPhoneInfo();
    comp1->showComputerInfo();

    Factory *fact2 = new XiaomiFactory();
    Phone *ph2 = fact2->createPhone();
    Computer *comp2 = fact2->createComputer();
    ph2->showPhoneInfo();
    comp2->showComputerInfo();

    cout << "main end" << endl;
}