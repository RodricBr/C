/*
 Port scanner tcp syn
 Tutorial: binarytides.com/tcp-connect-port-scanner-c-code-linux-sockets/
*/
#include <stdio.h>
#include <sys/socket.h>
#include <errno.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <unistd.h>

int main(int argc , char **argv){
	struct hostent *host;
	int err, i , sock ,start , end;
	char hostname[100];
	struct sockaddr_in sa;
	
	// Pegando o hostname ou ip pelo stdin
  // + Entender o que é CIDR
	printf("Insira o HostName ou IP: ");
	gets(hostname);
	
	printf("Insira o número da porta inicial: ");
	scanf("%d" , &start);
	
	printf("Insira o número da porta final: ");
	scanf("%d" , &end);

	// Inicializando a estrutura sockaddr_in
	strncpy((char*)&sa , "" , sizeof sa);
	sa.sin_family = AF_INET;
	
	// Endereço de ip direto
	if (isdigit(hostname[0])){
		printf("Realizando o inet_addr...");
		sa.sin_addr.s_addr = inet_addr(hostname);
		printf("Feito\n");
	}
	// Resolve hostname para ip address
	else if ( (host = gethostbyname(hostname)) != 0){
		printf("Realizando o gethostbyname...");
		strncpy((char*)&sa.sin_addr , (char*)host->h_addr , sizeof sa.sin_addr);
		printf("Feito\n");
	}
	else{
		herror(hostname);
		exit(2);
	}
	
	// Inicia o loop do port scanner
	printf("Iniciando o loop do scanner\n");
	for ( i = start ; i <= end ; i++){
		sa.sin_port = htons(i);
		// Cria um socket do tipo endereço de internet e um socket, que fornece fluxos de bytes sequenciados e bidirecionais com um mecanismo de transmissão para dados de fluxo
		sock = socket(AF_INET, SOCK_STREAM , 0);
		
		// Verifica se o stdout do socket retornou erro (1)
		if (sock < 0){
			perror("\nSocket FALHOU");
			exit(1);
		}
		// Conecta usando o socket e o sockaddr structure
		err = connect(sock, (struct sockaddr*)&sa, sizeof sa);
		
		// Verifica se o socket e o sockaddr structure obtiveram erro
		if ( err < 0 ){
			fflush(stdout);
		}
		// Conexão realizada
		else{
			printf("%-5d ABERTO\n",  i);
		}
		close(sock);
	}
	
	printf("\r");
	fflush(stdout);
	return(0);
}
