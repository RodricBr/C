#include <stdio.h>
#include <limits.h> // INT_MAX, INT_MIN, UINT_MAX, SHRT_MAX...
#include <stdint.h> // uint8, uint16, uint32, uint64...
#include <stdlib.h>

// Variáveis do tipo INT

int main(void){
  // INT_MAX é o tamanho máximo que pode ser colocado dentro de um inteiro
  // dentro de uma variável inteira nessa arquitetura
  // INT_MAX requer o header <limits.h> (locate limits.h)

  // Modificadores:
  //signed int i = INT_MAX;
  //unsigned int i = UINT_MAX;
  // Faz parte de uma coisa chamada 'stored glass'
  // É uma otimização pra quando uma variável vai ser uma contadora (loop..)
  register int i = 0;

  // Incluindo o header <stdint.h>, a gente garante que o int tenha 32 bits
  // Garantindo com exatidão o tamanho da variável
  // Contendo 8 bits, 16 bits, 32 bits, 64 bits (locate stdint.h)
  //uint16_t i = INT_MAX;
  //uint16_t i = USHRT_MAX;

  // Pra 8 bits:
  //uint8_t i = UCHAR_MAX;

  // short só serve pro int, não precisa declarar: short int i;
  // Pra 16 bits;
  //short i;

  // Pra 34 bits:
  //long i; //(printf %lu)

  // Pra 64 bits:
  //long long i; //(printf %llu)
  //long long i = LLONG_MAX;

  // Incluindo o header <stdlib.h> para usar o size_t
  // size_t (size-type) é o tipo de objeto devolvido pelo operador sizeof
  //size_t i = 1;

  // Quando declaramos: int i; estamos deixando implicito que é uma variável
  // com sinal (signed)

  // Quando vemos uma variável int i, é uma variável inteira com sinal (signed)
  // Ela tem esse valor INT_MAX, que não é o máximo que 32 bits pode armazenar
  // pq tem um range quebrado no meio pra abrigar tanto números negativos quanto
  // números positivos. (signed int i;)

  // i = i + 1; OU i += 1;
  // Se eu quisesse somar 2 a variável i,
  // teriamos que usar: i = i + 2 OU i += 2
  // Como ela é uma variável do tipo inteira com sinal (signed int) (-INT_MAX - 1)
  //i++;
  //i += 2;

  printf("O tamanho do i (int): %zu bytes / %zu bits\n", sizeof i, sizeof i * 8);

  // Printa o valor máximo que cabe em 32 bits (2^32 == 4294967296)
  // Só que como ele vai de 0 até 2^32, ele conta menos 1
  printf("O valor de i: %d\n", i);
  // %d OU %i são formatadores/modificador para signed int
  // %o, %u, %x OU %X são formatadores para unsigned int
  // %o == Octal
  // %u == Decimal
  // %x e %X == Hexadecimal
  // %zu == Imprimir o valor de size_t


  // Notas legais:
  // Percebi que o:
  // uint16_t i = USHRT_MAX;
  // printf("O valor de i: %u\n", i);
  // Retornam o mesmo valor de portas TCP que existem, -1

  // Variável não é simplismente declarar um tipo variante, na computação
  // de base, precisamos definir quanto de memória eu quero para uma variável
}
