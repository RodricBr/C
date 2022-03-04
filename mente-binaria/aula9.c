#include <stdio.h>
#include <stdlib.h>

// Condicional IF

int main(void) {
// Um bloco em C é definido por o que começa por { e termina por }.
// As variáveis de funções são locais, justamente por estarem
// dentro de um bloco, então, por exemplo, se criarmos o bloco
// {
//   int exe = 1337;
//   printf("O valor é: %d\n", exe);
// }
// tudo que está escrito alí em cima dentre as chaves são locais.
// Dessa forma, vai haver uma economia de memória bem grande, se
// for necessário a criação de vários blocos. Ou seja, o bloco
// sem nenhum IF, só o bloco puro, ele só vai ser executado normalmente,
// e o output do bloco acima será: O valor é: 1337

// IMPORTANTE!
// 0 em C é representado como FALSO
// e qualquer coisa posterior a zero é VERDADEIRO

// Porém, agora se botarmos um IF,
// o bloco dentro das chaves só será executado se
// a avaliação dentro dos parênteses for verdadeira

// Na condicional abaixo, setando b como um inteiro de número 32,
// perguntamos se b é igual a 1, ou seja, falso. O primeiro bloco
// deu falso, e logo após ele existe um outro bloco com uma condicional
// chamada else (senão), o segundo bloco só vai executar se o primeiro
// retornou como falso. Dentro desses parênteses podemos usar
// inclusive os operadores lógicos.
int b = 32;
  if (b == 1 && b < 33) { // Usando || (OR), se qualquer um for verdadeiro, o bloco inteiro será executado, se eu mudar para && (AND) ele fica VERDADEIRO
    int chave = 42;
    printf("O valor é: %d\n", chave);
    printf("Ou seja, a condicional deu \033[0;32mVERDADEIRO!\033[0m\n"); // Bônus: cor em C é o mesmo doq qualquer outra linguagem, usando o ASCII Escape Character \033

  } else if (b == 32) {
    // Se o IF for verdadeiro OK, do contrário (else if)
    // vai haver o teste se a == 32, que é VERDADEIRO
    // Podemos usar quantos else if quisermos em nosso código
    // Também podendo criar sub níveis
    if (b != 32) {
      puts("b é diferente de 32");
    }
    printf("A variável 'b' é de fato %d\n", b);

  } else {
    printf("A condicional deu \033[0;31mFALSO!\033[0m\n");
    puts("jooj"); // Não suporta formatador (%d...) e já adiciona um \n no final da string
  }

  // Avalização Ternária
  // : == else
  (b == 32) ? puts("Avaliação Ternária: 32") : puts("Não sei o valor de b");

  //printf("O resultado é: %d\n");
  return 0;
}
