#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/fcntl.h>
#include <poll.h>
using namespace std;

#define MAXNFDS  1024

int initServer(int port)
{
    struct sockaddr_in servaddr;    //填写地址结构
    //bzero(servaddr,sizeof(servaddr));
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    //servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(port);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    //setsockopt(sockfd,);
    bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    listen(sockfd, 20);
    return sockfd;
}

int main()
{
    int listenSock = initServer(8081);
    if(listenSock<0)
    {
		cout<<"initServer error"<<endl;
    }
	cout<<"listenSock:"<<listenSock<<endl;

    int maxfd;
	maxfd = listenSock;
	
	struct pollfd fds[MAXNFDS];  // fds存放需要监视的socket
	for (int i=0;i<MAXNFDS;i++) 
	{
		fds[i].fd=-1; // 初始化数组，把全部的fd设置为-1。
	}
	
    // 把listensock添加到数组中
	fds[listenSock].fd=listenSock;
	fds[listenSock].events=POLLIN;  // 有数据可读事件，包括新客户端的连接、客户端socket有数据可读和客户端socket断开三种情况。
    
    while(true)
    {
		int infds = poll(fds, maxfd+1, -1);
		cout<<"poll ..."<<endl;
		if(infds < 0)
		{
			cout<<"poll fail"<<endl;
			break;
		}
		if(infds == 0)
		{
			cout<<"poll timeout"<<endl;
			continue;
		}
		for(int eventFd=0;eventFd<=maxfd;eventFd++)
		{
			if(fds[eventFd].fd < 0)
			{
				continue;
			}
			if((fds[eventFd].revents & POLLIN) == 0)
			{
				cout<<"eventFd:"<<eventFd<<endl;
				continue;
			}
			fds[eventFd].revents = 0;
			if(fds[eventFd].fd == listenSock)		//新客户端连接
			{
				cout<<"new client connect"<<endl;
				struct sockaddr_in clientaddr;
				socklen_t clnt_addr_size;
				int clientSock = accept(listenSock, (struct sockaddr*)&clientaddr, &clnt_addr_size);
				if(clientSock < 0)
				{
					cout<<"accept fail"<<endl;
					continue;
				}
				if(clientSock > MAXNFDS)
				{
					cout<<"clientSock > MAXNFDS"<<endl;
					close(clientSock);
					continue;
				}
				cout<<"clientSock:"<<clientSock<<endl;
				fds[clientSock].fd=clientSock;
				fds[clientSock].events=POLLIN; 
				fds[clientSock].revents=0;
				if(maxfd < clientSock)
				{
					maxfd = clientSock;
					cout<<"maxfd change to:"<<clientSock;
				}
				continue;
			}
			else	//现有客户端发送数据或连接断开
			{
				cout<<"recv data, eventFd:"<<eventFd<<endl;
				char buff[1024];
				memset(buff, 0, 1024);
				size_t size = read(eventFd, buff, sizeof(buff));
				if(size <= 0)  //发生错误或连接断开
				{
					cout<<"client disconnect, sockFd:"<<eventFd<<endl;
					close(eventFd);
					fds[eventFd].fd = -1;
					
					// 重新计算maxfd的值，注意，只有当eventfd==maxfd时才需要计算。
					if (eventFd == maxfd)
					{
						for (int i=maxfd;i>0;i--)
						{
							if (fds[i].fd != -1)
							{
								maxfd = i; 
								break;
							}
						}
						cout<<"change max fd:"<<maxfd<<endl;
					}
					continue;
				}
				
				cout<<"sockFd:"<<eventFd<<", recv buf:"<<buff<<", size:"<<size<<endl;
				string res = "get it";
				write(eventFd, res.c_str(), res.length());
			}
		}
    }
}
