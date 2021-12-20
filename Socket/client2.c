#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include <sys/msg.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>


// we defined a structure as per the question
struct msg{
int a;
char b;
float c;
};
int main() 
{
int client_socket;
int error_check;
struct sockaddr_in client_address; 
socklen_t server_len;
struct msg client_msg;
server_len = sizeof(client_address);

// Creating socket file descriptor
client_socket = socket(AF_INET, SOCK_DGRAM, 0); 
if(client_socket == -1)
{
	printf("Error creating socket\n");
	exit(1); 
}

client_address.sin_family = AF_INET; 
client_address.sin_port = htons(9002); 
client_address.sin_addr.s_addr = INADDR_ANY;

// connection request to server
error_check = sendto(client_socket, &client_msg, sizeof(client_msg),0, (struct sockaddr *) &client_address, server_len);

if(error_check == -1)
{
	printf("Error sending message\n");
	exit(1); 
}

// receives message from server
error_check = recvfrom(client_socket, &client_msg, sizeof(client_msg), 0, (struct sockaddr *) &client_address, &server_len);

if(error_check == -1) 
{
	printf("Error receiving message\n");
	exit(1);
}

printf("Server sent following integer:\n"); printf("%d\n", client_msg.a);
printf("Server sent following character:\n"); printf("%c\n", client_msg.b);
printf("Server sent following float:\n"); printf("%f\n", client_msg.c);
close(client_socket);
return 0; 
}
