/*
 * @Author: chenq
 * @Date: 2021-04-25 23:39:12
 * @LastEditTime: 2021-04-26 17:22:02
 * @Descripttion: 责任链模式。使多个对象都有机会处理请求，从而避免请求的发送者和接收者之间的耦合关系。将判定条件的部分放到处理类中。相当于更灵活的if else
 *                  抽象处理类（处理请求接口 + 设置下一级处理者 + 获取下一级处理者） +  具体处理类（处理请求）
 */
#include <iostream>
using namespace std;

//抽象处理类
class Leader
{
public:
    Leader() {}
    virtual ~Leader() {}

    void setNextLeader(Leader *next)
    {
        nextLeader = next;
    }
    Leader *getNextLeader()
    {
        return nextLeader;
    }
    virtual void handleRequest(int LeaveDays) = 0;

private:
    Leader *nextLeader;
};

//具体处理类1
class ClassTeacher : public Leader
{
public:
    void handleRequest(int LeaveDays)
    {
        if (LeaveDays <= 2)
        {
            cout << "class teacher approves leave" << endl;
        }
        else
        {
            if (getNextLeader() != nullptr)
            {
                getNextLeader()->handleRequest(LeaveDays);
            }
            else
            {
                cout << "Asking for leave is too long and no one approved 1" << endl;
            }
        }
    }
};
//具体处理类2
class DepartmentHead : public Leader
{
public:
    void handleRequest(int LeaveDays)
    {
        if (LeaveDays <= 7)
        {
            cout << "department head aproves leave" << endl;
        }
        else
        {
            if (getNextLeader() != nullptr)
            {
                getNextLeader()->handleRequest(LeaveDays);
            }
            else
            {
                cout << "Asking for leave is too long and no one approved 2" << endl;
            }
        }
    }
};
//具体处理类3
class Dean : public Leader
{
public:
    void handleRequest(int LeaveDays)
    {
        if (LeaveDays <= 10)
        {
            cout << "dean approves leave" << endl;
        }
        else
        {
            if (getNextLeader() != nullptr)
            {
                getNextLeader()->handleRequest(LeaveDays);
            }
            else
            {
                cout << "Asking for leave is too long and no one approved 3" << endl;
            }
        }
    }
};

int main()
{
    Leader *classteacher = new ClassTeacher();
    Leader *departmenthead = new DepartmentHead();
    Leader *dean = new Dean();
    classteacher->setNextLeader(departmenthead);
    departmenthead->setNextLeader(dean);

    int leavedays = 8;
    classteacher->handleRequest(leavedays);

    cout << "main end" << endl;
    return 0;
}