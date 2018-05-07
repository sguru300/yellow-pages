#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#define PORT 8080
  
int main(int argc, char const *argv[])
{
struct sockaddr_in address;
int sock = 0, valread;
char sample[50];
int n1,n2;
char name[1024];
char ad[1024];
char word[256];
char words[256];
struct sockaddr_in serv_addr;
char *hello = "hello brps";
char buffer[1024] = {0};
char bufff[10024] = {0};
if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
{
printf("\n Socket creation error \n");
return -1;
}
  
memset(&serv_addr, '0', sizeof(serv_addr));
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
valread = read( sock , name, 1024);
    printf("%s\n",name );
printf("\n");
fgets(words, sizeof(words), stdin);
send(sock , words , strlen(words) , 0 );
valread = read( sock , ad, 1024);
    printf("%s\n",ad );
fgets(word, sizeof(word), stdin);
send(sock , word , strlen(word) , 0 );

valread = read( sock , buffer, 1024);
    printf("%s\n",buffer );
printf("Enter your choice : ");
scanf("%d",&n1);
int converted_number = htonl(n1);
    write(sock, &converted_number, sizeof(converted_number));
valread = read( sock , bufff, 10024);
printf("%s\n",bufff);
printf("Thank you for using Omega Elevators.Have a nice day!!\n");
    return 0;
}
