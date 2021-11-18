#include <stdio.h>
#include <stdlib.h>
// Incluindo livrarias OU importando livrarias dentro do próprio sistema

int main(void){
  // Variável numero inteira recebendo valor de 1337
  int numero = 1337;

  // Printf == formatted string literal
  // Printando o valor int
  printf("Valor: %i\n", numero);

  // Operador pra pegar o endereço de uma variável
  // & == referência o seu endereço na memória
  printf("Endereço: %p\n", &numero);

  // Variável char de caractere recebendo o valor brasil1
  // Representando 1 byte character, guardado como um inteiro
  // Valor -128 até 127 ou 0 até 255
  char brasil1;

  // Uma string pode ser criada em um array de caracteres
  // Cada palávra tem seu endereço específico de memória,
  // e termina por um caractere nulo (\0)
  char brasil[] = "Ola, mundo";

  // Pointer
  // malloc == Allocate memory (4 bytes)
  // Alocando 4 bytes pra variável de caractere str
  char *str = malloc(4);

  // Agora assinando um caractere para cada index,
  // terminando com o caractere nulo para criar uma string (\0)
  str[0] = 'o';
  str[1] = 'l';
  str[2] = 'a';
  str[3] = '\0';

  // Liberando a memória alocada na ram do sistema
  free(str);


  // A linguagem C é procedural, e não suporta orientação a objetos (POO)
  // Apesar de poder-mos criar nosso próprio 'complex data type' usando struct
  struct Humano{
    char dna[50];
    int idade;
    float weight;
  };

  return 0;
}
