/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>

int main() {

  char c;
  int init, palavra, ehletra, ehpont, ehnum, pontoflutuante;

  c = 1;
  init = 0;
  palavra =0;
  ehletra=0; 
  ehpont=0;
  ehnum=0;
  pontoflutuante=0;

  while (c != '\n') { 
  
    scanf("%c", &c);
    
    if ((65 <= c && c <= 90) || (97 <= c && c <= 122)) {	//Se o caractere lido for uma letra
    
       	if (init==0) {	//Se não estiver lendo uma palavra
    		init=1;	   //Flag é setada para indicar o começo da leitura de uma palavra
    		palavra++;	//Quando uma palavra começa a ser lida, o contador é incrementado
		} 
		if(ehnum==1) {  //Se logo depois de um número vier uma letra
			init=1;
			palavra++;	//O contador é incrementado
			ehnum=0;
		}
		if (ehpont==1 && init==1 && pontoflutuante==1) {  //Caso em que o caractere anterior a letra é um ponto precedido de um número
			init=1;
			palavra++;  //A letra após ao ponto dá início a uma nova palavra
		}
		ehletra=1;
		ehnum=0;
		ehpont=0;
	
	}
	
	else if (!((97 <= c && c <= 122) || (65 <= c && c <= 90) || (48 <= c && c <= 57)))  {	//Se o caractere lido for uma pontuação
		
		if (ehletra==1) {  //Se o caractere anterior à pontuação é uma letra
			ehletra=0;
			init=0;		  //Flag sinaliza o fim de uma palavra de letras
		}
		if (ehnum==1 && ((c=='.') || (c==','))) {  
			pontoflutuante=1;  //Flag indica que pode ser ponto flutuante
		} else {  			  //Os demais casos não são pontos flutuantes
			pontoflutuante=0;  //Fim da palavra, não é ponto flutuante
			init=0;
		}
		
		if (ehpont==1) {  //Caso em que antes da pontuação há outro caractere de pontuação
			init=0;		 
			pontoflutuante=0;  
		}
		ehpont=1;
		ehletra=0;
		ehnum=0;	
	}
	
	else if (48 <= c && c <= 57) { //Se o caractere lido for um número
		
		if (pontoflutuante==1) {   //Se for um ponto flutuante	
			pontoflutuante=0;
		} else if (pontoflutuante==0 && ehnum==0) {  //Se não for ponto flutuante
			init=1;	     //Dá-se início a leitura de uma nova palavra
			palavra++;
		}
		if (ehletra==1) { //Se a flag da letra estiver setada
			init=1;	     //Indica o início da leitura de uma nova palavra
			ehletra=0;
			palavra++;    //O contador de palvras é incrementado
		}
		ehnum=1;
		ehletra=0;
		ehpont=0;
	}
  }

  printf("%d\n", palavra);
  return 0;
}
