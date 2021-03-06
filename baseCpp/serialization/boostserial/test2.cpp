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
    void myPrint()
    {
        cout<<"length:"<<length<<", height:"<<height<<", width:"<<width<<endl;
    }
};

string to_string(const MyStruct& s)
{
    ostringstream oss;
    boost::archive::text_oarchive oa(oss);
    oa << s;
    return oss.str();
}

MyStruct from_strint(const string& str)
{
    MyStruct s;
    std::istringstream iss(str);
    boost::archive::text_iarchive ia(iss);
    ia >> s;
    return s;
}

template <class Archive>
void serialize(Archive &ar, MyStruct& s, const unsigned int version)
{
    ar &s.length;
    ar &s.height;
    ar &s.width;
};

int main()
{
    MyStruct s1;
    s1.length = 7;
    s1.width = 8; 
    s1.height = 9;
    s1.myPrint();

    string str = to_string(s1);
    cout<<"str: "<<str<<endl;

    MyStruct s2;
    s2.myPrint();
    s2 = from_strint(str);
    s2.myPrint();

    return 0;
}

