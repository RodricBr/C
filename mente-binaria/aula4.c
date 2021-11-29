#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

// Variáveis do tipo float
int main(void){
  // Indicando ao float o expoente de 3
  // Que é: 3 * 10 ^ 2
  //float f = 3e2;

  // 32 bits (precisão simples)
  // double (precisão dupla)
  // long double (precisão quadrupla)
  float f = 40.512321;
  long double d = 1;

  // O float tem limitações, se fizermos 10 / 3, o resultado
  // será 0.000000
  //printf("Valor de f: %f\n", 10 / 3);
  // Não é uma representação real, exata de um número real
  // é uma implementação que tem perdas e ganhos


  printf("O tamanho de f (float): %zu bytes / %zu bits\n", sizeof f, sizeof f * 8);

  printf("O tamanho de d (double): %zu bytes / %zu bits\n", sizeof d, sizeof d * 8);

  // .2 imprime somente duas casa decimais após o . do valor f
  // Ex: 2.0001 --> 2.00
  printf("Valor de f: %.2f\n", f / 3);
  // %Lg para long double
  printf("Valor de d: %.2Lg\n", d);
}

// Debugando o executável
// (Inspecionar, vê como ele funciona, etc)
// gdb -q executavel4

// disas == disassemblar (qual são as funções de máquina)
// Dentro do dbg-> disas main
// Pegando o valor hexadecimal da variável f
// 0xf8d(%rip),%rsi        # 0x2008
// E decodando em binário:
// echo 'obase=2; ibase=16; 6174204F' | bc
