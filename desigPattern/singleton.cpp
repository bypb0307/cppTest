/*
 * @Author: chenq
 * @Date: 2021-04-25 23:35:55
 * @LastEditTime: 2021-04-26 17:19:50
 * @Descripttion: 懒汉模式。单例类只有一个实例对象，单例对象必须由单例类自行创建，单例类对外提供一个访问该单例的全局访问点
 *                  懒汉式：需要使用实例时才去创建并使用。（需要考虑线程安全）
 *                  饿汉式：系统一运行，就初始化实例，使用时直接调用。（线程安全）
 */
#include <iostream>
#include <memory>
using namespace std;

//懒汉模式
class LazySingleton
{
public:
    LazySingleton(const LazySingleton &) = delete;
    LazySingleton &operator=(const LazySingleton &) = delete;
    static LazySingleton &getInstance()
    {
        static LazySingleton instance;
        return instance;
    }

private:
    LazySingleton() { cout << "LazySingleton constructor" << endl; }
    ~LazySingleton() { cout << "LazySingleton destructor" << endl; }
};

//饿汉模式
class HungrySingleton
{
public:
    ~HungrySingleton() { cout << "HungrySingleton destructor" << endl; } //智能指针无法访问private的析构函数
    HungrySingleton(const HungrySingleton &) = delete;
    HungrySingleton &operator=(const HungrySingleton &) = delete;

    static std::shared_ptr<HungrySingleton> getInstance()
    {
        return instance;
    }

private:
    HungrySingleton() { cout << "HungrySingleton constructor" << endl; } //避免类在外部被实例化
    static std::shared_ptr<HungrySingleton> instance;
};

std::shared_ptr<HungrySingleton> HungrySingleton::instance(new HungrySingleton());

int main()
{
    LazySingleton &ls = LazySingleton::getInstance();
    auto hs = HungrySingleton::getInstance();
    cout << "main end" << endl;
    return 0;
}