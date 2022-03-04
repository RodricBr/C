#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

/*
 * [##] Usando a função getaddrinfo para o nome do host para o endereço de IP em C [##]
 *
 * getaddrinfo faz parte das facilidades de programação de rede UNIX e pode
 * converter informações de host de rede para endereço de IP, e vice-versa.
 * getaddrinfo também é uma chamada de função compatível com POSIX e pode
 * fazer a conversão independente dos protocolos submjacentes.

 * getaddrinfo leva 4 argumentos:
 * 1- O primeiro pode ser o ponteiro para o nome do host ou string de endereço formatado IPv4/v6
 * 2- O segundo argumento pode ser um nome de serviço ou um número de porta representado com o número inteiro decimal.
 * 3- Os próximos dois argumentos são ponteiros para estruturas addrinfo. O primeiro é hints que especifica os requisitos
 * para filtrar as estruturas de socket recuperadas, enquanto o segundo é o ponteiro, onde a função irá alocar
 * dinamicamente uma lista vinculada de estruturas addrinfo.
 * 
 * Observe que a estrutura hints deve ser definida com zeros e, em seguida, seus membros devem ser atribuídos.
 * O membro ai_family indica a família do endereço, por exemplo, IPv4 ou IPv6 como AF_INET e AF_INET6, respectivamente.
 * Nesse caso, não estamos interessados na conversão do nome do serviço e especificamos NULL como o segundo argumento da função.
 * Finalmente, chamamos getnameinfo para traduzir as estruturas sockaddr fornecidas para a forma imprimível.
  
 gcc programa.c -o exec -O2
 ./exec localhost
*/

int main(int argc, char const *argv[]) {
  struct addrinfo hints;
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

  int ret = getaddrinfo(argv[1], NULL, &hints, &res);
  if (ret != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
    exit(EXIT_FAILURE);
  }

  for (tmp = res; tmp != NULL; tmp = tmp->ai_next) {
    getnameinfo(tmp->ai_addr, tmp->ai_addrlen, host, sizeof(host), NULL, 0, NI_NUMERICHOST);
    puts(host);
  }

  freeaddrinfo(res);
  exit(EXIT_FAILURE);

}
