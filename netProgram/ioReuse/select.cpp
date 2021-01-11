#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/fcntl.h>
using namespace std;

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

    fd_set readfdset;
    int maxfd;
    FD_ZERO(&readfdset);
    FD_SET(listenSock, &readfdset);
    maxfd = listenSock;
    
    while(true)
    {
		fd_set tmpfdset = readfdset;
		struct timeval tm;
		tm.tv_sec =5;
		tm.tv_usec=0;
		int infds = select(maxfd+1, &tmpfdset, NULL, NULL, &tm);
		// int infds = select(maxfd+1, &tmpfdset, NULL, NULL, NULL);
		if(infds < 0)
		{
			cout<<"select fail"<<endl;
			break;
		}
		if(infds == 0)	//select最后一个参数为空时，不存在超时情况
		{
			cout<<"select timeout"<<endl;
			continue;
		}
		for(int eventFd=0;eventFd<=maxfd;eventFd++)
		{
			if(FD_ISSET(eventFd,&tmpfdset)<=0)
			{
				cout<<"FD_ISSET <= 0"<<endl;
				continue;
			}
			if(eventFd == listenSock)		//新客户端连接
			{
				cout<<"new client connect"<<endl;
				struct sockaddr_in clientaddr;
				socklen_t clnt_addr_size;
				int clientSock = accept(listenSock, (struct sockaddr*)&clientaddr, &clnt_addr_size);
				FD_SET(clientSock, &readfdset);
				if(maxfd < clientSock)
				{
					maxfd = clientSock;
				}
			}
			else	//现有客户端发送数据或连接断开
			{
				char buff[1024];
				memset(buff, 0, 1024);
				size_t size = read(eventFd, buff, sizeof(buff));
				if(size <= 0)  //发生错误或连接断开
				{
					cout<<"client disconnect, sockFd:"<<eventFd<<endl;
					close(eventFd);
					FD_CLR(eventFd, &readfdset);
					
					// 重新计算maxfd的值，注意，只有当eventfd==maxfd时才需要计算。
					if (eventFd == maxfd)
					{
						for (int i=maxfd;i>0;i--)
						{
							if (FD_ISSET(i, &readfdset))
							{
								maxfd = i; break;
							}
						}
						cout<<"max fd:"<<maxfd<<endl;
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
