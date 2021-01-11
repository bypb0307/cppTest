#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
using namespace std;

int main()
{
    struct sockaddr_in servaddr;    //填写地址结构
    //bzero(servaddr,sizeof(servaddr));
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(8081);
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);    //创建套接字
    if(sockfd == -1)
    {
	cout<<"socket error"<<endl;
	return -1;
    }
    
    if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0)
    {
	cout<<"connect error"<<endl;
	close(sockfd);
	return -1;
    }
    
    const char* buff = "hello, I am client";
    cout<<"strlen buff:"<<strlen(buff)<<endl;
    write(sockfd, buff, strlen(buff)+1);
    char res[1024];
    read(sockfd, res, 1024);
    close(sockfd);
    cout<<"read buf:"<<res<<endl;
    return 0;
}
