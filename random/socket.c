#include <stdio.h>
#include <sys/socket.h> // (man 7 ip)
                        // no manual vemos que para fazermos conexão tcp utilizamos o af_inet e sock_stream
                        // pra udp o sock_dgram
                        // (man socket) para mais informações sobre o que é af_inet, sock_stream, sock_dgram e etc
#include <netdb.h>

int main(int argc, char *argv[]){
  int socket1;
  int connecta;

  // Estrutura para realizar conexões tcp(SOCK_STREAM) ipv4(AF_INET)
  struct sockaddr_in alvo;
  socket1 = socket(AF_INET, SOCK_STREAM, 0); // O "0" é o protocolo, 0 sendo o protocolo ip (cat /etc/protocols)

  // No (man 7 ip) vemos que o formato sin_family é sempre definindo como AF_INET.
  // Como o endereço e a porta são sempre guardados em ordem de bytes de rede, precisamos chamar a função htons() na função sin_port que será assinada para porta
  // sin_addr é o endereço de host IP. s_addr é o membro da estrutura in_addr que contém o endereço da interface do host na ordem de bytes da rede
  alvo.sin_family = AF_INET;
  alvo.sin_port = htons(81);
  alvo.sin_addr.s_addr = inet_addr("10.0.0.1");

  // Realizando a conexão (man connect)
  connecta = connect(socket1, (struct sockaddr *)&alvo, sizeof alvo);

  if (connecta == 0){
    printf("Porta 81 aberta para o host 10.0.0.1\n");
    close(socket1); // Encerrando a conexão do socket
    close(connecta);
  } else {
    printf("Porta 81 fechada\n");
  }
}
