#include<stdio.h> 
#include<stdlib.h> 
#include<sys/types.h> 
#include<sys/socket.h> 
#include<netinet/in.h>
#include<unistd.h>
#include <arpa/inet.h>
#include <sys/msg.h>

struct msg
{ 
int a;
char b;
float c; 
};

int main() 
{
int server_socket;
int error_check;
char ping[10];
struct msg server_msg;
struct sockaddr_in client_address;
socklen_t client_len;
client_len = sizeof(client_address);
server_socket = socket(AF_INET, SOCK_DGRAM, 0);
struct sockaddr_in server_address; 
server_address.sin_family = AF_INET;
server_address.sin_port = htons(9002);
//server_address.sin_client_address.s_client_address = inet_network("192.168.1.71");
error_check = bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

if(error_check == -1)
{
	printf("Error while binding\n");
	exit(1); 
}

// get message from client 1
error_check = recvfrom(server_socket,&server_msg,sizeof(server_msg),0, (struct sockaddr *) &client_address, &client_len);
if(error_check == -1) 
{
	printf("error receiving message from client.\n");
	exit(1); 
}
printf("Client sent integer: %d\n", server_msg.a); 
printf("Client sent character: %c\n", server_msg.b);
printf("Client sent float: %f\n", server_msg.c);

// process the message and double the integer sent by client 1 server_msg.a*=2;
// process the message and increment the float sent by client 1 server_msg.c+=1.0;
// process the message and increment the character sent by client 1 
if(server_msg.b !='z')
{
server_msg.b+=1;
}
else
{
server_msg.b='a';
}
// client 2 pings so that its ip address and port can be known and response can be sent.
error_check = recvfrom(server_socket,ping,sizeof(ping),0, (struct sockaddr *) &client_address, &client_len);

if(error_check == -1) 
{
printf("error receiving message from client.\n"); exit(1);
}

// sends the updated struct to client 2
error_check = sendto(server_socket, &server_msg, sizeof(server_msg), 0, (struct sockaddr *) &client_address, client_len);

if(error_check == -1)
{
	printf("Error while sending message.\n");
	exit(1); 
}
printf("Server says I am done.\n");
close(server_socket);
return 0; 
}
