/*
 * @Author: chenq
 * @Date: 2021-01-07 21:55:33
 * @LastEditTime: 2021-01-07 23:13:30
 * @Descripttion: 
 */

#include <iostream>
#include <fstream>
#include <string>

#include "myStucture.pb.h"
#include "google/protobuf/text_format.h"
#include "google/protobuf/io/zero_copy_stream_impl.h"

using namespace std;

int main()
{
    protobuftest::MyStucture s1;
    s1.set_length(4);
    s1.set_width(5);
    s1.set_height(6);
    cout<<"s1 : "<<"length:"<<s1.length()<<", width:"<<s1.width()<<", height:"<<s1.height()<<endl;

    //序列化到字符串SerializeToString
    string str;
    s1.SerializeToString(&str);
    cout<<"str:"<<str<<endl;

    //反序列化
    protobuftest::MyStucture s2;
    s2.ParseFromString(str);
    cout<<"s2 : "<<"length:"<<s2.length()<<", width:"<<s2.width()<<", height:"<<s2.height()<<endl;

    return 0;
}








