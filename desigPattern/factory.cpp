/*
 * @Author: chenq
 * @Date: 2021-04-26 16:26:22
 * @LastEditTime: 2021-04-26 16:51:14
 * @Descripttion: 工厂模式。定义一个创建对象的接口，让子类决定实例化哪个类。
 *                  符合开闭原则，新增具体产品类时，只需要添加相应的具体工厂和具体产品类，不需要修改现有工厂
 *                  抽象工厂类 + 具体工厂（华为工厂 +小米工厂） + 抽象产品类（手机） + 具体产品类（华为手机 + 小米手机）
 */
#include <iostream>
using namespace std;

//抽象产品类（手机）
class Phone
{
public:
    Phone() {}
    virtual ~Phone() {}
    virtual void showInfo() = 0;
};

//抽象工厂，定义生 产品类的接口
class Factory
{
public:
    Factory() {}
    virtual ~Factory() {}
    virtual Phone *createPhone() = 0;
};

//具体产品类1（华为手机）
class HuaweiPhone : public Phone
{
public:
    void showInfo()
    {
        cout << "this is HuaweiPhone" << endl;
    }
};
//具体产品类2（小米手机）
class XiaomiPhone : public Phone
{
public:
    void showInfo()
    {
        cout << "this is XiaomiPhone" << endl;
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
};
//具体工厂类2（小米工厂）
class XiaomiFactory : public Factory
{
public:
    Phone *createPhone()
    {
        return new XiaomiPhone();
    }
};

int main()
{
    Factory *fact1 = new HuaweiFactory();
    Phone *ph1 = fact1->createPhone();
    ph1->showInfo();

    Factory *fact2 = new XiaomiFactory();
    Phone *ph2 = fact2->createPhone();
    ph2->showInfo();

    cout << "main end" << endl;
}