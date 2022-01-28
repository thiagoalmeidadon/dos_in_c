#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int meuSocket;
    int conecta;

    struct sockaddr_in alvo;
    struct hostent *host = gethostbyname(argv[1]);

    meuSocket = socket(AF_INET, SOCK_STREAM, 0);
    

    alvo.sin_family = AF_INET;
    alvo.sin_port = htons(21);
    alvo.sin_addr.s_addr = inet_addr(host);

    conecta = connect(meuSocket, (struct sockaddr *)&alvo, sizeof alvo);

    if ( conecta == 0 ) {
        printf("Aberta");
        close(meuSocket);
        close(conecta);
    } else {
         printf("Fechado");
    }

   

}