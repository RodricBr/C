#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

// Arrays
// Arrays são onde vamos armazenar
// mais de um valor
int main(void){
  // Array de 3 posições
  // Esse é o número de elementos do array
  // char tem 1 byte, dando 1 * 3 == 3
  unsigned char c[3];

  //long int c[3];

  // int tem 4 bytes, dando 3 * 4 == 12
  //int i[3];

  printf("O tamanho de c é: %zu\n", sizeof c);

  // O array em c é de variáveis do mesmo tipo, sempre
  // logo, o tamanho de c[0] vai ser 4, que é um inteiro
  // (Lembrando que o array começa a contagem em 0)
  //printf("O número de elementos de i é: %zu\n", sizeof i / sizeof i[0]);

  // Normalmente a gente declara um array, e depois itera(faz um loop) através
  // dele, com esses elementos do array. Em C, a gente não usa o sizeof para
  // pegar o tamanho do array pronto, só vai funcionar se for char.
  // Então pra pegar o número de elementos de array a gente pega o tamanho
  // total, que é o tamanho em bytes, e divide por um elemento dele mesmo,
  // ou pelo tamanho do tipo

  // Definindo valor para cada posição do array
  c[0] = 'A'; // 'A' em char
  c[1] = 0x42; // 'B' em hex ascii
  c[2] = 67; // 'C' em dec ascii
  // man ascii

  printf("O elemento 0 de c é: %c\n", c[0]);
  printf("O elemento 1 de c é: %c\n", c[1]);
  printf("O elemento 2 de c é: %c\n", c[2]);

  // Pegando elementos não setados na array, que estão armazenados na memória,
  // e acaba que nós pegamos valores aleatórios da memória do sistema,
  // podendo ser até lixos
  printf("O elemento 5 de c é: %c\n", c[5]);
  printf("O elemento 10 de c é: %c\n", c[10]);
  printf("O elemento 11 de c é: %c\n", c[11]);
  printf("O elemento 12 de c é: %c\n", c[12]);

  // A principal diferença de um array pra um ponteiro é,
  // o array aponta pra endereços fixos de memória, enquanto
  // o ponteiro aponta pra endereços variáveis de memória

  // %p == pointer
  // & == pega o endereço
  printf("O endereço do array c em memória: %p\n", c);
  printf("O endereço do array &c em memória: %p\n", &c);
  printf("O endereço do primeiro elemento do array c em memória: %p\n", &c[0]);
  printf("O endereço do primeiro elemento do array c em memória: %p\n", &c[1]);

  // Muitas linguagens tratam o tamanho do array como número de elementos,
  // em C o tamanho do array é o tamanho total em bytes que todas as posições
  // dele ocupam

  return 0;
}
