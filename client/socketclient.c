#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {

    int Status;
    int socket_client = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in server;
    int port = atoi(argv[2]);

    printf("Trying %s...\n", argv[1]);
    
    if(socket_client < 0) {
        perror("Erro ao conectar, verifique se os dados estao corretos.\n");
        close(socket_client);        
        exit(1);
    }
    server.sin_family = AF_INET;                         
    server.sin_port = htons(port);                       // Argument two (port)
    server.sin_addr.s_addr = inet_addr(argv[1]); // Argument one 
    bzero(&(server.sin_zero),8);                         // Limpa estrutura(IP)
    
    // Estabelece a conexão com o socket
    Status = connect(socket_client,(struct sockaddr *)&server, sizeof(server)); 
    if(Status < 0)  {  
        perror("Erro ao conectar\n");
        close(socket_client);        
        exit(1);
    } 
    printf("Conected to %s.\n", argv[1]);
    puts("Escape character is \'^C\'");
    
        
    char type[5];
    char path[12];
    char protocol[9];
    char host[30];
    scanf("%s%s%s", type, path, protocol);
    getchar();
    scanf("%*s%s", host);
    getchar();
    do{}while(getchar() != '\n');
    
    //Request
    char req_get[50];
    sprintf(req_get,"%s %s %s \r\nHost:%s\r\n", type, path, protocol, host);
    Status = send(socket_client,req_get,strlen(req_get),0);
    if(Status < 0) {
        perror("Erro ao enviar!\n");
        close(socket_client);        
        exit(1);
    }

    char buffer[0x200]; 
    int bytes = 1;                                   
    while(bytes > 0) {                               
        memset(buffer,0x0,0x200);                    
        bytes = recv(socket_client,buffer,0x200,0);
        printf("%s",buffer);
    }
    
    close(socket_client);
    return 0;
}
