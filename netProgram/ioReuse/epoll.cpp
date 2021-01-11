#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/fcntl.h>
#include <sys/epoll.h>
using namespace std;

#define MAXEVENTS  100

int setNoBlocking(int sockFd)
{
	if(fcntl(sockFd, F_SETFL, fcntl(sockFd, F_GETFD, 0)|O_NONBLOCK) == -1)
	{
		return -1;
	}
	return 0;
}

int initServer(int port)
{
    struct sockaddr_in servaddr;    //填写地址结构
    //bzero(servaddr,sizeof(servaddr));
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    //servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(port);

    int sockFd = socket(AF_INET, SOCK_STREAM, 0);
    
    //setsockopt(sockFd,);
    bind(sockFd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    listen(sockFd, 20);
    return sockFd;
}

int main()
{
    int listenSock = initServer(8081);
    if(listenSock<0)
    {
		cout<<"initServer error"<<endl;
    }
	cout<<"listenSock:"<<listenSock<<endl;

    int epollFd;
	epollFd = epoll_create(1);	//创建一个描述符
	
	//添加监听描述事件
	struct epoll_event ev;
	ev.data.fd = listenSock;
	ev.events = EPOLLIN;
	epoll_ctl(epollFd, EPOLL_CTL_ADD, listenSock, &ev);
    
    while(true)
    {
		struct epoll_event events[MAXEVENTS];	//存放有事件发生的结构数组
		
		int infds = epoll_wait(epollFd, events, MAXEVENTS, -1);

		if(infds < 0)
		{
			cout<<"epoll fail"<<endl;
			break;
		}
		if(infds == 0)
		{
			cout<<"poll timeout"<<endl;
			continue;
		}
		
		for(int i=0;i<infds;i++)		//遍历有事件发生的结构数组
		{
			if((events[i].data.fd == listenSock)&&(events[i].events & EPOLLIN))	//新客户端连接
			{
				struct sockaddr_in clientaddr;
				socklen_t clnt_addr_size;
				int clientSock = accept(listenSock, (struct sockaddr*)&clientaddr, &clnt_addr_size);
				if(clientSock < 0)
				{
					cout<<"accept fail"<<endl;
					continue;
				}
				
				memset(&ev, 0, sizeof(struct epoll_event));
				ev.data.fd = clientSock;
				ev.events = EPOLLIN;
				epoll_ctl(epollFd, EPOLL_CTL_ADD, clientSock, &ev);
				cout<<"new client connected"<<endl;
				continue;
			}
			else if(events[i].events & EPOLLIN)	//现有客户端发送数据或连接断开
			{
				char buff[1024];
				memset(buff, 0, 1024);
				size_t size = read(events[i].data.fd, buff, sizeof(buff));
				if(size <= 0)  //发生错误或连接断开
				{
					cout<<"client disconnect, sockFd:"<<events[i].data.fd<<endl;
					memset(&ev, 0, sizeof(struct epoll_event));
					ev.events = EPOLLIN;
					ev.data.fd = events[i].data.fd;
					epoll_ctl(epollFd, EPOLL_CTL_DEL, events[i].data.fd, &ev);
					close(events[i].data.fd);
					continue;
				}
				
				cout<<"sockFd:"<<events[i].data.fd<<", recv buf:"<<buff<<", size:"<<size<<endl;
				string res = "get it";
				write(events[i].data.fd, res.c_str(), res.length());
			}
		}
    }
	close(epollFd);
	return 0;
}
