#include <stdio.h>

// Extended Stack Pointer finder
// Útil para a construção de um stack overflow e de shell codes

unsigned long procurar_(void){
  __asm__("movl %esp, %eax");
}

int main(void){
  printf("ESP: 0x%x\n", procurar_);
}
