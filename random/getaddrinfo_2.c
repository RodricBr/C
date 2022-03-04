#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

/*
 * [##] Usando a função getaddrinfo para o endereço IP do nome do host em C [##]
 *
 * A função getnameinfo é usada em conjunto com getaddrinfo neste caso,
 * e recupera os nomes de host para os endereços IP correspondentes.
 * Observe que processamos a entrada do usuário a partir do primeiro argumento
 * da linha de comando e o passamos como o argumento getaddrinfo para recuperar as estruturas socketaddr.
 * Finalmente, cada estrutura pode ser traduzida para a string do nome do host.
 * Uma vez que getaddrinfo aloca memória dinâmica para armazenar a lista vinculada
 * no quarto argumento, este ponteiro deve ser liberado pelo usuário com a chamada de função freeaddrinfo.
 
 gcc programa2.c -o exec2 -O2
 ./exec2 127.0.0.1
*/

int main(int argc, char const *argv[]) {
  struct addrinfo hints;
  // Lembrando que * e & são modificadores de tipo (type modifiers)
  struct addrinfo *res, *tmp;
  char host[256];

  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET;

  // Se o argumento 2 estiver vazio
  if (argc != 2) {
    fprintf(stderr, "%s string\n", argv[0]);
    // Função exit(), onde EXIT_FAILURE é o mesmo do que saindo com exit code 1
    exit(EXIT_FAILURE);
  }

  // & como um operador para hints e res, ele pega o
  // endereço do hints e do res e joga numa variável int chamada ret,
  // e o segundo argumento da função setado para nulo
  int ret = getaddrinfo(argv[1], NULL, &hints, &res);
  if (ret != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
    exit(EXIT_FAILURE);
  }

  for (tmp = res; tmp != NULL; tmp = tmp->ai_next) {
    getnameinfo(tmp->ai_addr, tmp->ai_addrlen, host, sizeof(host), NULL, 0, 0);
  }
  freeaddrinfo(res);
  exit(EXIT_FAILURE);
}
