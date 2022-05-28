// Aluns compiladores vão interpretar só
// se estiver escrito como "__asm__" ou "asm"

// Invocando código assembly dentro de um programa
// C. PS: as instruções devem ficar dentro de aspas e
//        o \n(quebra de linha) é importante.

__asm (
  "xor %rdx, %rdx\n" // Terceiro argumento do execve é envp, setado para nulo (NULL)
  "push %rdx\n" // Terminador zero (zero terminator)

  "sub $14, %rsp\n" // Espaço para a string
  "movb $0x2f, 7(%rsp)\n" // "/" em hexadecimal
  "movl $0x2f6e6962, 8(%rsp)\n" // "bin/" em hexadecimal
                                // Nota: o valor hexadecimal está ao contrário devido ao "Little Endianess"
                                // echo -e "\x2f\x6e\x69\x62"
  "movw $0x736c, 12(%rsp)\n" // "ls" em hexadecimal
  "leaq 7(%rsp), %rdi\n" // Primeiro argumento para o execve é o nome do arquivo

  "pushq %rdx\n" // Pushando(push) valor nulo(NULL) para a pilha(stack), terminador do argv.
  "push %rdi\n" // "argv[0]"

  "mov %rsp, %rsi\n" // Segundo argumento para o execve é argv
  
  // Copiando 59 para o rax, definindo número da syscall para o execve
  // Evitando byte zero
  "xor %eax, %eax\n"
  "movb $59, %al\n"
  "syscall"
);
