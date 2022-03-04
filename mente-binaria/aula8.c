#include <stdio.h>
#include <stdlib.h>

// Operadores bit-a-bit
/*
 * & == AND
 * | == OR
 * ^ == OR exclusivo (xor)
 * ~ == Negação
 * ! == Negação lógica
 * << == Left Shift (pegar dígitos e mover para a esquerda) EX: int a = 0b1000; == 8, se eu fizer a << 1, é como se estivesse havendo uma multiplicação pela base, transformando o 8 em 16 (8 * 1 = 16, 8 * 2 = 32 etc...)
 * >> == Right Shift (pegar dígitos e mover para a direita) ao contrário do de cima, esse vai funcionar como divisão
*/

int main(void) {
  int a = 0b00000000000000000000000000000000;
  int b = 0b11111111111111111111111111111111; // Extensão 0b para digitar número em binário
  // A notação 0b para tipos literais em binários é uma extensão de alguns compiladores, não faz
  // parte de um padrão, prefirindo assim continuar usando a notação hexadecimal ou octal

  //int a = 2; // 10 == 2 em binário
  //int b = 3; // 11 == 3 em binário

  // Em operação lógica, 0 é falso e
  // qualquer coisa diferente de 0 é verdadeiro

  printf("O resultado é: %d\n", ~a);
  return 0;
}
