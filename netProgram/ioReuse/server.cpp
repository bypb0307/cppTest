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
    //servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    //servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(8028);
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    listen(sockfd, 20);

    struct sockaddr_in clientaddr;
    socklen_t clnt_addr_size;
    int c_fd = accept(sockfd, (struct sockaddr*)&clientaddr, &clnt_addr_size);
    char buff[1024];
    auto n = read(c_fd, buff, 1024);
    cout<<"recf buff:"<<buff<<endl;
    close(c_fd);
    close(sockfd);
    return 0;
}
