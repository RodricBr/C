#include <stdio.h>
#include <netdb.h> // <- pra utilizar a "gethostbyname" (man gethostbyname)
#include <arpa/inet.h>
// ^^ utilizando a função do header inet "inet_ntoa" que converte um host de internet em uma estrutura in_addr para uma string légivel em formato IPv4

int main(int argc, char *argv[]){
  if (argc <= 1){
    printf("Uso: %s <host>\n", argv[0]);
    return 0;
  } else {
    struct hostent *alvo = gethostbyname(argv[1]);
    if (alvo == NULL){
      printf("Host não encontrado!\n");
    } else {
      // A função inet_ntoa converte o endereço que vem para o in_addr em uma string legível
      printf("Host %s possui endereço %s\n", argv[1], inet_ntoa(*((struct in_addr *) alvo -> h_addr)));
    }
  }
}
