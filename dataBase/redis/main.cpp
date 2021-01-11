/*
 * @Author: chenq
 * @Date: 2020-12-03 15:41:28
 * @LastEditTime: 2020-12-03 17:20:11
 * @Descripttion: 测试使用hiredis连接Redis服务  g++ main.cpp -o test -I/home/chenq/include -L/home/chenq/lib -lhiredis
 */
#include <iostream>
#include <string>
#include <hiredis/hiredis.h>
using namespace std;

int main()
{
    redisContext *context = redisConnect("49.234.96.166", 6379);
	if (context->err)
	{
		cout << "can not connect to redisserver: 49.234.96.166, port:6379, "<<context->errstr << endl;
		redisFree(context);
		context = nullptr;
		return 0;
	}

    string k_name = "name";
    redisReply *reply = (redisReply *)redisCommand(context, "get %s", k_name.c_str());
    if(reply == nullptr)
    {
        cout<<"redisCommand error1, "<<reply->str<<endl;
        return -1;
    }
    if(reply->type == REDIS_REPLY_ERROR)
    {
        cout<<"redisCommand error2, "<<reply->str<<endl;
        return -1;
    }
    cout<<"name: "<<reply->str<<endl;
    freeReplyObject(reply);
    
    /* Disconnects and frees the context */
    redisFree(context);
    return 0;
}