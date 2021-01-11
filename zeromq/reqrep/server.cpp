/*
 * @Author: chenq
 * @Date: 2020-12-12 14:08:00
 * @LastEditTime: 2020-12-13 21:53:46
 * @Descripttion: 
 */

#include <iostream>
#include <cstring>
#include <cassert>
#include <zeromq/zmq.h>

using namespace std;

void my_recv(void *socket, char *recv_msg)
{
    zmq_msg_t msg;
    zmq_msg_init(&msg);
    int rc = zmq_msg_recv(&msg, socket, 0);  //如果使用zmq_recv，只能接收指定的长度
    assert(rc != -1);
    memcpy(recv_msg, zmq_msg_data(&msg), rc);
}

void my_send(void *socket, const char *send_msg)
{
    auto len = strlen(send_msg);
    zmq_msg_t msg;
    zmq_msg_init_size(&msg, len);
    memcpy(zmq_msg_data(&msg), send_msg, len);

    int sd = zmq_msg_send(&msg, socket, 0);
    assert(sd == len);
}

int main()
{
    void *ctx = zmq_ctx_new ();
    assert(ctx);
    void *serv_sock = zmq_socket (ctx, ZMQ_REP); //ZMQ_REP ZMQ_REQ ZMQ_ROUTER
    assert(serv_sock);
    int ret = zmq_bind(serv_sock, "tcp://*:8081");  // transport ://   transport:tcp, ipc, inproc, pgm, epgm vmci
    assert (ret == 0);
    
    int i = 1;
    char recv_msg[1024];
    char send_msg[1024];
    
    while(true)
    {
        memset(recv_msg, 0, strlen(recv_msg));
        my_recv(serv_sock, recv_msg);
        cout<<"recv_msg size:"<<strlen(recv_msg)<<", "<<recv_msg<<endl;

        sprintf(send_msg, "rep msg %d", i++);
        my_send(serv_sock, send_msg);
        cout<<"send_msg size:"<<strlen(send_msg)<<", "<<send_msg<<endl; 
    }

    zmq_close (serv_sock);
    zmq_ctx_destroy (ctx);
    return 0;
}
