#include <stdio.h>

// Operadores lógicos
/*
  == : operador de avaliação
  && : operador de conjunção
*/

/*
  # Conjunção (E, AND) &&
  Independente do número de entradas, a saída só será verdadeira
  quando todos as entradas forem verdadeiras
  0 0 = falso(0)
  0 1 = falso(0)
  1 0 = falso(0)
  1 1 = verdadeiro(1)

  # Disjunção (OU, OR) ||
  Basta ter qualquer entrada verdadeira, para o resultado ser verdadeiro
  0 0 = falso(0)
  0 1 = verdadeiro(1)
  1 0 = verdadeiro(1)
  1 1 = verdadeiro(1)
*/
int main(void){
  int a = 8;
  int b = 8;

  // 'a' é igual(==) a 'b' E 'b' é menor que 4?
  // Se o primeiro (a == b) for verdadeiro, e o (b > 4), e o (a < 9000)
  printf("AND: %d\n", a == b && b > 4 && a < 9000);

  // Se o primeiro (a == b) for verdadeiro, o resto também é verdadeiro
  printf("OR: %d\n", a == b || b < 4 || a < 2);

  // Negação : não é igual(a é igual a b)
  // Dando falso(0), pois 'a' é diferente de 'b' e 'a' é maior que nove
  // porém os parênteses dão prioridade
  printf("Negação: %d\n", !(a == b) && a > 9);

  // Também podemos usar números
  printf("Negação: %d\n", !( !(32 > 2) && 3 == 10) ); 

  // Condicionais
  //if (a != b)
  //  printf("IF O resultado é: %d\n", a == b);

  return 0;
}
