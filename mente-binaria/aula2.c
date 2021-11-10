#include <stdio.h>

// Variáveis boolean e do tipo char

int main(void){
    int retorno = 0;

    // Imprimindo \n em hex usando a formatação character do printf
    printf("Olá, novamente%c", 10); // 10 == 0xa == \n
    printf("Decimal: %d - %d - %d - %d\n", retorno, 10, 0xa, 'A');
    printf("Hex:     %x - %x - %x - %x\n", retorno, 10, 0xa, 'A');
    printf("Char:    %d - %d - %d - %c\n", retorno, 10, 0xa, 'A');

    // Impressões printf ('man 3 printf' na parte de Flag Characters)
    // %d == decimal
    // %x == hexadecimal
    // %c == caractere

    // Output do printf:
    // O primeiro recebe o valor da variável retorno (0)
    // O segundo recebe um valor 10
    // O terceiro recebe um valor 10 em hex
    // O quarto recebe um valor ASCII que é igual a 65 

    //char nome;
    puts("Isso é o puts");

    // Input, mas não funciona no WSL
    //scanf("%c", &nome); 
    //printf("%c", nome);
    return 0;
}
