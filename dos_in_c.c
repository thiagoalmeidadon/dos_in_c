#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    
    int meuSocket;
    int conecta;

    struct sockaddr_in alvo;
    // resolvendo dns
    struct hostent *host = gethostbyname(argv[1]);
    // socket
    meuSocket = socket(AF_INET, SOCK_STREAM, 0);
    alvo.sin_family = AF_INET;
    alvo.sin_port = htons(21);
    // inet_ntoa escrever ip legivel
    alvo.sin_addr.s_addr = inet_addr( inet_ntoa( *((struct in_addr * ) host->h_addr) ) );

    printf(" %s resolvido: %s \n ", argv[1] ,inet_ntoa( *((struct in_addr * ) host->h_addr) ) );

    conecta = connect(meuSocket, (struct sockaddr *)&alvo, sizeof alvo);

    if ( conecta == 0 ) {
        printf("Aberta \n");
        close(meuSocket);
        close(conecta);
    } else {
         printf("Fechado \n ");
    }

   

}