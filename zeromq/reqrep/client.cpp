/*
 * @Author: chenq
 * @Date: 2020-12-12 14:08:03
 * @LastEditTime: 2020-12-13 21:53:59
 * @Descripttion: 
 */

#include <iostream>
#include <cstring>
#include <cassert>
#include <unistd.h>
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
    void *cli_sock = zmq_socket (ctx, ZMQ_REQ); //ZMQ_REP ZMQ_REQ ZMQ_ROUTER
    assert(cli_sock);
    int ret = zmq_connect(cli_sock, "tcp://127.0.0.1:8081");  // transport ://   transport:tcp, ipc, inproc, pgm, epgm vmci
    assert (ret == 0);
    
    int i = 1;
    char recv_msg[1024];
    char send_msg[1024];
    
    while(true)
    {
        sprintf(send_msg, "req msg %d", i++);
        memset(recv_msg, 0, strlen(recv_msg));

        my_send(cli_sock, send_msg);
        cout<<"send_msg size:"<<strlen(send_msg)<<", "<<send_msg<<endl;
        my_recv(cli_sock, recv_msg);
        cout<<"recv_msg size:"<<strlen(recv_msg)<<", "<<recv_msg<<endl;
        sleep(1);
    }

    zmq_close (cli_sock);
    zmq_ctx_destroy (ctx);
    return 0;
}
