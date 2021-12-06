#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

// Operadores aritiméticos
// Um operador é um simbolo que faz alguma operação
// com um número, ou outra coisa

/*
  = : operador de atribuição
  + : operador unário (se só tiver um número é unário)
  + : operador binário com um número antes, (1 + 10) é adição/subtração
  * : operador de multiplicação (binário)
  / : operador de divisão (binário)
  % : operador de resto de divisão
  ++ : operador de incremento
  -- : operador de decremento
*/

int main(void){
  //float a;
  int a;

  // Lista de prioridade
  // Assim como na matemática, a multiplicação tem prioridade maior
  // doq a subtração
  // Podemos alterar a prioridade usando parênteses
  // Os unários tem prioridade acima dos binários, pois se eu botar
  // (4 + 2) * -3, o -3 terá de ser resolvido primeiro pois vai alterar o resultado
  a = (4 + 2) * 3; // (2 * 3) + 4 == 10
  printf("Pré: %d\n", a++); // a++ aqui só é incrementado depois, e não será usado
  printf("Pós: %d\n", a);
  // Operador de incremento/decremento tem dois tipos
  // Pós incremento/decremento: a++/a--
  // Pré incremento/decremento: ++a/--a

  // Quando não especificamos que um número é positivo
  // ou negativo, ele é positivo por padrão, mas podemos especificar
  // com um operador na frente (+10 || -10)

  // Um número float com um 'F' no final é um float real
  //a = 10 / 3.0F;
  // printf("%f\n", a);

  //a = 10 % 2;
  //printf("%d\n", a);

  // Incrementar número de 1 em 1 (somar)
  // Também podemos fazer isso com outros operadores
  //a -= 1;
  //a *= 8; // a = a * 8;

  //a = a + 1;

  // Mesmo significado
  //a += 1;

  // Operador especial de incremento
  //a ++ ; // Ou seja, 'a' vai ser incrementado em 1 unidade
  // 'a' tem 3 da conta da variável 'a' passada, que deixava um dividendo 3
  // esse 3 é somado com 1 e é atribuído ao 'a' (a = 4 no final)
  //printf("%d\n", a);

  return 0;
}
