/*
 * @Author: chenq
 * @Date: 2021-01-06 14:33:29
 * @LastEditTime: 2021-01-07 16:09:34
 * @Descripttion: 
 */
#include <string>
#include <fstream>
#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using namespace std;

struct MyStruct
{
    int length;
    int width;
    int height;
    MyStruct() : length(0), height(0), width(0) {}
    template <class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar &length;
        ar &height;
        ar &width;
    };
    void myPrint()
    {
        cout<<"length:"<<length<<", height:"<<height<<", width:"<<width<<endl;
    }

    static string to_string(const MyStruct& s);
    static MyStruct from_strint(const string& str);
};

string MyStruct::to_string(const MyStruct& s)
{
    ostringstream oss;
    boost::archive::text_oarchive oa(oss);
    oa << s;
    return oss.str();
}

MyStruct MyStruct::from_strint(const string& str)
{
    MyStruct s;
    std::istringstream iss(str);
    boost::archive::text_iarchive ia(iss);
    ia >> s;
    return s;

}

int main()
{
    MyStruct s1;
    s1.length = 1;
    s1.width = 2; 
    s1.height = 3;
    s1.myPrint();

    string str = MyStruct::to_string(s1);
    cout<<"str: "<<str<<endl;

    MyStruct s2;
    s2.myPrint();
    s2 = MyStruct::from_strint(str);
    s2.myPrint();

    return 0;
}