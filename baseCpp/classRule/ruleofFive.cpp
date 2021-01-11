/*
 * @Author: chenq
 * @Date: 2020-11-01 15:18:14
 * @LastEditTime: 2020-11-01 15:31:40
 * @Descripttion: 类的构造跟析构函数的一些规则。当类成员里面有需要自己管理的资源，对应的析构函数，拷贝构造函数，拷贝等号要明确地重写，否则可能会出新问题
 */
#include <iostream>
#include <cstring>
using namespace std;

class RuleOfFive
{
public:
    RuleOfFive(const char* str)  //constructor 构造函数
    {
        cout<<"RuleOfFive constructor"<<endl;
        if(str == nullptr)
        {
            m_str = new char[1];
            *m_str = '\0';
        }
        else
        {
            m_str = new char[strlen(str)+1];
            strcpy(m_str, str);
        }
    }
    ~RuleOfFive()  //destructor 析构函数 手动释放资源
    {
        cout<<"RuleOfFive destructor"<<endl;
        delete[] m_str;
    }
    RuleOfFive(const RuleOfFive& other)  //copy constructor 拷贝构造函数
    {
        cout<<"RuleOfFive copy constructor"<<endl;
        m_str = new char[strlen(other.m_str)+1];
        strcpy(m_str, other.m_str);
    }
    RuleOfFive& operator=(const RuleOfFive& other)  //copy assignment 
    {
        cout<<"RuleOfFive copy assignment"<<endl;
        if(this == &other)
        {
            return *this;
        }
        if(m_str != nullptr)
        {
            delete[] m_str;
            m_str = nullptr;
        }
        m_str = new char[strlen(other.m_str)+1];
        strcpy(m_str, other.m_str);
        return* this;
    }
    RuleOfFive(RuleOfFive&& other)  //std::move() copy constructor 
    {
        cout<<"std::move copy constructor"<<endl;
        m_str = other.m_str;
        other.m_str = nullptr;
    }
    RuleOfFive& operator=(RuleOfFive&& other)  //std::move() copy assignment
    {
        cout<<"std::move copy assignment"<<endl;
        if(m_str != nullptr)
        {
            delete[] m_str;
            m_str = nullptr;
        }
        m_str = other.m_str;
        other.m_str = nullptr;
        return* this;
    } 

private:
    char* m_str;
};

int main()
{
    RuleOfFive a("abc");    //constructor

    RuleOfFive b(a);    //copy constructor

    b = a;              //copy assignment

    return 0;   
}