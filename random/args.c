#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
  // Criando uma variável chamada contador com valor int
  int contador;

  // Irá printar cada vez que houver um novo parâmetro.
  // Ex: ./args 122 4ede\;efr
  // Output:
  // 1º Parâmetro: 122
  // 2º Parâmetro: 4ede;efr   ... etc.
  for (contador=0; contador < argc; contador++)
    printf("%dº Parametro: %s\n", contador, argv[contador]);

  return 0;
}
