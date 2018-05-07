#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080
int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread,valread2;
    struct sockaddr_in address;
    int opt = 1;
int flag=0;
int varia1=1,varia2=1,varia3=1,varia4=1,varia5=1,varia6=1;
char line[200];
int recieved_int = 0;
int recieve_int = 0;
char names2[1024];
char names[1024];
char ad[100];
char c1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Are you a new user ? Enter Y or N to continue ";
    char *hi = "1.bakeries\n2.banks\n3.schools\n4.theatres\n5.clinics\n6.hotel\n";
char *username = "enter username\n";
char *case2_1 = "welcome new user\n please enter login details\n name: ";
      
   
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
      
    
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
      
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, 
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                       (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
send(new_socket , hello , strlen(hello) , 0 );
    valread = read( new_socket , names2, 1024);
    
printf("choice recieved is %s",names2);
send(new_socket , username , strlen(username) , 0 );
valread2 = read( new_socket , names, 1024);
printf("%s",names);
switch(names2[0])
{
case 'Y':
{
FILE *fp2 = fopen("unames.txt","ab");
if(fp2==NULL)
        {
            printf("File open error");
            return 1;   
        }   
fprintf(fp2,"%s",names);
break;
}
case 'N':
{
FILE *fp3 = fopen("unames.txt","r");
if(fp3==NULL)
        {
            printf("File opern error");
            return 1;   
        }   
while ( fgets ( line, 200, fp3 ) != NULL )


        {

                if(strstr(line,names))

		flag =1;
                //printf("valid user");


        }
if(flag==1)
{
printf("valid user");
}
if(flag==0)
{
printf("invalid user");
exit(1);
}
break;
}
default:
exit(1);
}
send(new_socket , hi , strlen(hi) , 0 );
   valread = read( new_socket , &recieve_int, sizeof(recieve_int));
    int c = ntohl(recieve_int);
printf("choice recieved is %d\n",c);
switch(c){
case 1 : {
while(varia1)
    {
        //connfd = accept(listenfd, (struct sockaddr*)NULL ,NULL);
	printf("sending information regarding bakeries in mangalore\n");
        /* Open the file that we wish to transfer */
        FILE *fp = fopen("bakery.txt","rb");
        if(fp==NULL)
        {
            printf("File opern error");
            return 1;   
        }   

        /* Read data from file and send it */
        while(1)
        {
            /* First read file in chunks of 256 bytes */
            unsigned char buff[2560]={0};
            int nread = fread(buff,1,2560,fp);
            //printf("Bytes read %d \n", nread);        

            /* If read was success, send data. */
            if(nread > 0)
            {
                //printf("Sending \n");
                write(new_socket, buff, nread);
		//printf("%s",buff);
            }

            /*
             * There is something tricky going on with read .. 
             * Either there was error, or we reached end of file.
             */
            if (nread < 2560)
            {
                if (feof(fp))
                    printf("File has been sent\n");
                if (ferror(fp))
                    printf("Error reading\n");
                break;
            }


        }

        close(new_socket);
		varia1 = 0;
	break;
    }
break;
}
case 2 :
{
while(varia2)
    {
        //connfd = accept(listenfd, (struct sockaddr*)NULL ,NULL);
	printf("sending information regarding banks in mangalore\n");
        /* Open the file that we wish to transfer */
        FILE *fp = fopen("banks.txt","rb");
        if(fp==NULL)
        {
            printf("File opern error");
            return 1;   
        }   

        /* Read data from file and send it */
        while(1)
        {
            /* First read file in chunks of 256 bytes */
            unsigned char buff[2560]={0};
            int nread = fread(buff,1,2560,fp);
            //printf("Bytes read %d \n", nread);        

            /* If read was success, send data. */
            if(nread > 0)
            {
                //printf("Sending \n");
                write(new_socket, buff, nread);
		//printf("%s",buff);
            }

            /*
             * There is something tricky going on with read .. 
             * Either there was error, or we reached end of file.
             */
            if (nread < 2560)
            {
                if (feof(fp))
                    printf("File has been sent\n");
                if (ferror(fp))
                    printf("Error reading\n");
                break;
            }


        }

        close(new_socket);
		varia2 = 0;
	break;
    }
break;
}
case 3:
{
while(varia3)
    {
        //connfd = accept(listenfd, (struct sockaddr*)NULL ,NULL);
	printf("sending information regarding schools in mangalore\n");
        /* Open the file that we wish to transfer */
        FILE *fp = fopen("school.txt","rb");
        if(fp==NULL)
        {
            printf("File opern error");
            return 1;   
        }   

        /* Read data from file and send it */
        while(1)
        {
            /* First read file in chunks of 256 bytes */
            unsigned char buff[2560]={0};
            int nread = fread(buff,1,2560,fp);
            //printf("Bytes read %d \n", nread);        

            /* If read was success, send data. */
            if(nread > 0)
            {
                //printf("Sending \n");
                write(new_socket, buff, nread);
		//printf("%s",buff);
            }

            /*
             * There is something tricky going on with read .. 
             * Either there was error, or we reached end of file.
             */
            if (nread < 2560)
            {
                if (feof(fp))
                    printf("File has been sent\n");
                if (ferror(fp))
                    printf("Error reading\n");
                break;
            }


        }

        close(new_socket);
		varia3 = 0;
        break;
    }
break;
}
case 4:
{
while(varia4)
    {
        //connfd = accept(listenfd, (struct sockaddr*)NULL ,NULL);
	printf("sending information regarding theatres in mangalore\n");
        /* Open the file that we wish to transfer */
        FILE *fp = fopen("theatre.txt","rb");
        if(fp==NULL)
        {
            printf("File opern error");
            return 1;   
        }   

        /* Read data from file and send it */
        while(1)
        {
            /* First read file in chunks of 256 bytes */
            unsigned char buff[2560]={0};
            int nread = fread(buff,1,2560,fp);
            //printf("Bytes read %d \n", nread);        

            /* If read was success, send data. */
            if(nread > 0)
            {
                //printf("Sending \n");
                write(new_socket, buff, nread);
		//printf("%s",buff);
            }

            /*
             * There is something tricky going on with read .. 
             * Either there was error, or we reached end of file.
             */
            if (nread < 2560)
            {
                if (feof(fp))
                    printf("File has been sent\n");
                if (ferror(fp))
                    printf("Error reading\n");
                break;
            }


        }

        close(new_socket);
		varia4 = 0;
        break;
    }
break;
}
case 5:
{
while(varia5)
    {
        //connfd = accept(listenfd, (struct sockaddr*)NULL ,NULL);
	printf("sending information regarding clinics in mangalore\n");
        /* Open the file that we wish to transfer */
        FILE *fp = fopen("clinic.txt","rb");
        if(fp==NULL)
        {
            printf("File opern error");
            return 1;   
        }   

        /* Read data from file and send it */
        while(1)
        {
            /* First read file in chunks of 256 bytes */
            unsigned char buff[2560]={0};
            int nread = fread(buff,1,2560,fp);
            //printf("Bytes read %d \n", nread);        

            /* If read was success, send data. */
            if(nread > 0)
            {
                //printf("Sending \n");
                write(new_socket, buff, nread);
		//printf("%s",buff);
            }

            /*
             * There is something tricky going on with read .. 
             * Either there was error, or we reached end of file.
             */
            if (nread < 2560)
            {
                if (feof(fp))
                    printf("File has been sent\n");
                if (ferror(fp))
                    printf("Error reading\n");
                break;
            }


        }

        close(new_socket);
		varia5 = 0;
        break;
    }
break;
}
case 6:
{
while(varia6)
    {
        //connfd = accept(listenfd, (struct sockaddr*)NULL ,NULL);
	printf("sending information regarding hotels in mangalore\n");
        /* Open the file that we wish to transfer */
        FILE *fp = fopen("hotel.txt","rb");
        if(fp==NULL)
        {
            printf("File opern error");
            return 1;   
        }   

        /* Read data from file and send it */
        while(1)
        {
            /* First read file in chunks of 256 bytes */
            unsigned char buff[2560]={0};
            int nread = fread(buff,1,2560,fp);
            //printf("Bytes read %d \n", nread);        

            /* If read was success, send data. */
            if(nread > 0)
            {
                //printf("Sending \n");
                write(new_socket, buff, nread);
		//printf("%s",buff);
            }

            if (nread < 2560)
            {
                if (feof(fp))
                    printf("File has been sent\n");
                if (ferror(fp))
                    printf("Error reading\n");
                break;
            }


        }

        close(new_socket);
		varia6 = 0;
	break;
    }
break;
}
case 7:
{
exit(1);
}
default:
{
printf("invalid\n");
exit(1);
}
}

    return 0;
}
