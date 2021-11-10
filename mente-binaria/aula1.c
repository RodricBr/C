#include <stdio.h>  // Comando pré processador que importa a biblioteca da função printf
// Podemos importar coisas usando esse comando: #include "arquivo.sh"

int main(void){
  // variável retorno recebe um valor inteiro = 0
  int retorno = 0;

  // int == função que retorna algo(int == número inteiro de 32bits) 
  // main == nome da função(função principal obrigatória)
  // () == argumentos
  // void == a função main não vai receber argumento
  // {} == bloco da função onde os códigos serão executados

	retorno = printf("Olá, mundo!\n");
  printf("Retorno da printf anterior: %d\n", retorno); // retorna valor 13, 13 caracteres contando com o \n
  // formato do printf %d é pra número decimal/número inteiro
  // %d vai ser substituido pelo próximo argumento (retorno)
  // return 0; == retorna o valor 0 (exit code true) 
  return 0;
}

// Diga: CTRL + A == Aumenta valor de número selecionado no VIM
// Dica: CTRL + X == Diminui valor de número selecionado no VIM
// Dica: Apertando o == Identa na linha de baixo e já bota o insert
// Dica: Apertando dd == Recorta/apaga toda a linha selecionada
// Dica: Apertando p == Cola toda a linha recortada com o dd
// Dica: Apertando yy == Copia toda a linha recortada com o dd 
// Dica: Apertando r em cima de um caractere == replace/substituir

