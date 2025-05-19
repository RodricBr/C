#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  int socket1;
  int connecta;

  int porta;
  int inicio = 0;
  int final = 65535;
  char *destino;
  destino = argv[1];

  if (argc <= 1){
    printf("Uso: %s [IPv4] [PORTA]", argv[0]);
  } else {
    printf("[+] Escaneando o host %s...\n\n", destino);
    // Estrutura para realizar conexões tcp(SOCK_STREAM) ipv4(AF_INET)
    struct sockaddr_in alvo;

    for (porta = inicio; porta < final; porta++){
      socket1 = socket(AF_INET, SOCK_STREAM, 0); // O "0" é o protocolo, 0 sendo o protocolo ip (cat /etc/protocols)

      alvo.sin_family = AF_INET;
      alvo.sin_port = htons(porta);
      alvo.sin_addr.s_addr = inet_addr(destino);

      // Realizando a conexão (man connect)
      connecta = connect(socket1, (struct sockaddr *)&alvo, sizeof alvo);

      if (connecta == 0){
        printf("[ OPEN ] Porta '%d'\n", porta);
        close(socket1); // Encerrando a conexão do socket
      } else {
        //printf("[CLOSED] Porta '%d'\n", porta);
        close(socket1);
      }
    }
  }
}
