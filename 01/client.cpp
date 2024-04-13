#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main () {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    bzero(&serv_addr, sizeof(serv_addr));




    // 设置地址族、IP地址和端口：
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.01");
    serv_addr.sin_port = htons(8888);


    // 然后将socket地址与文件描述符绑定：
    // bind(sockfd, (sockaddr*)&serv_addr, sizeof(serv_addr));  客户端不进行bind操作


    
    connect(sockfd, (sockaddr*)&serv_addr, sizeof(serv_addr));
    return 0;
}