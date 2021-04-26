/*
 * @Author: chenq
 * @Date: 2021-04-26 16:15:14
 * @LastEditTime: 2021-04-26 16:53:30
 * @Descripttion: 简单工厂模式。定义一个工厂类来负责创建其他类的实例，被创建的类通常有共同的父类。根据参数的不同返回不同的类的实例
 *                  不符合开闭原则，每次新增具体产品类，需要修改简单工厂类中生成具体类的接口
 *                  简单工厂类 + 抽象产品类（手机） + 具体产品类（华为手机 + 小米手机）
 */
#include <iostream>
#include <string>
using namespace std;

//抽象产品类（手机）
class Phone
{
public:
    Phone() {}
    virtual ~Phone() {}
    virtual void showInfo() = 0;
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

//简单工厂类，定义生产品类的接口，根据参数的不同返回不同的类的实例
class SimpleFactory
{
public:
    Phone *createPhone(const string &str)
    {
        if (str == "huawei")
        {
            return new HuaweiPhone();
        }
        else if (str == "xiaomi")
        {
            return new XiaomiPhone();
        }
        else
        {
            return nullptr;
        }
    }
};

int main()
{
    SimpleFactory fact;
    Phone *ph1 = fact.createPhone("huawei");
    ph1->showInfo();

    Phone *ph2 = fact.createPhone("xiaomi");
    ph2->showInfo();
    cout << "main end" << endl;
}