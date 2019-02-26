#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "saco.h"
#include "trie.h"
#include "jogo.h"	


void printa_mao_jogador (saco_t *jogador_atual ,int n ){
	printf ("jogador %d: ",n	);
	imprimir_saco(jogador_atual);
	int i = 0;
	printf("            ");
	for (i = 0;i < jogador_atual->tamanho;i++)
		printf ("%d ",i);
	printf("\n");
				
}
char *jogada (saco_t *jogador_atual ,int n){
	printf("Digite uma jogada:");
	char *string = (char*) malloc(9*sizeof(char));
	fgets(string,9,stdin);
	 
	return string;
}
/*
void pular_jogada(void){
}


void colocar_no_tabuleiro(char **tabuleiro,char* string){
	//v^<>
	int tamanho = strlen(string);
	int letras_do_tabuleiro;
	scanf("")
	 
	if (direcao == 'v');
	if (direcao == '^');
	if (direcao == '<');
	if (direcao == '>');
	
	
}

void opcao(saco_t *jogador_atual ,saco_t *SacoAleatorio,int n){
	printf("Escolha uma opcao :\n");
	printf("1-fazer uma jogada \n");
	printf("2-trocar letras");
	printf("3-pular jogada");
	int opcao;
	scanf ("%d",&opcao);
	if (opcao == 1 )
		jogada (jogador_atual , n);
	else if(opcao == 2)
		troca(jogador_atual,SacoAleatorio);
	else if (opcao == 3)
		pular_jogada();
	else {
		printf("Escolha invalida");	
		opcao(jogador_atual , SacoAleatorio, n);
	}
	
}
*/
int main (void){
	
	int i = 0,j = 0;
	FILE *arquivo = fopen("palavras.txt","r");
	char palavras[50];
	char *ptr_char;
	int tam;
	char **tabuleiro =(char**)malloc(15*sizeof(char*));
	for (i = 0;i< 15;i++){
		tabuleiro[i] = (char*)malloc(15*sizeof(char));
	}
	for (i = 0 ;i < 15;i++)
		for(j = 0;j < 15 ;j++)
			tabuleiro[i][j] = ' ';

	trie_t *palavras_validas = create_trie();
	while (fscanf(arquivo,"%s",palavras) !=  EOF )
		adicionar_palavra_trie (palavras_validas,palavras);

	//put_palavra(tabuleiro,"abaca",3,7,3,'C',palavras_validas);

	tabuleiro[2][1] = 'b';
	tabuleiro[2][3] = 'c';
	printa_tabuleiro (tabuleiro);
	system("clear");
	//printa_tabuleiro (tabuleiro);
	
	put_palavra(palavras_validas ,tabuleiro,"aaaxi",0,6,2,'D');
	put_palavra(palavras_validas ,tabuleiro,"casl",5,1,4,'C');
	put_palavra(palavras_validas ,tabuleiro,"otar",0,4,1,'E');
	put_palavra(palavras_validas ,tabuleiro,"auco",0,5,0,'B');
	put_palavra(palavras_validas ,tabuleiro,"nhoa",0,5,5,'D');
	put_palavra(palavras_validas ,tabuleiro,"emiso",5,10,2,'B');


	//system("clear");h

	printa_tabuleiro(tabuleiro);

	//int NUM_L  = conta_letras(s,inicio, fim);
	/*
	char *s =  copy_l_c(tabuleiro,'D',2);
	printf("%s\n",s);	
	char *p = preenche(s,"aaaxi",'D',0,6);
	printf("preenchido %s\n",p);
	char *v = to_verify(p,'D',0,6);
	printf("to_verify : %s\n",v);
	if (verifica(palavras_validas,v) == 1){
		printf("aeeeeeee caraleoofidfkdxmkio \n");	
		


	}

	saco_t *sacoordenado = saco_ordenado();
	imprimir_saco (sacoordenado);
	//printf("%d \n", sacoordenado->tamanho);	
	saco_t *SacoAleatorio  = saco_aleatorio(sacoordenado);
	destruir_saco(sacoordenado);
	printf("saco inteiro \n");
	imprimir_saco(SacoAleatorio);
	saco_t *mao_jogador1 = createbag();
	saco_t *mao_jogador2 = createbag();
	saco_t *jogador_atual;//ponteiro que aponta para o jogador atual 
	char tabuleiro[15][15]={' '};
	char **strings;
	
	compra(mao_jogador1,SacoAleatorio);
	printf("mao_jogador1 \n");
	imprimir_saco(mao_jogador1);
	printf("saco atual \n");
	//imprimir_saco(SacoAleatorio);
	
	compra(mao_jogador2,SacoAleatorio);
	printf("mao_jogador2 \n");
	imprimir_saco(mao_jogador2);
	printf("saco atual \n");
	imprimir_saco(SacoAleatorio);
	printf("troca\n");
	strings = troca(mao_jogador2,SacoAleatorio);
	printf("mao_jogador2 \n");
	imprimir_saco(mao_jogador2);
	printf("saco atual \n");
	imprimir_saco(SacoAleatorio);

	printf (" string mao : %s \n string nova :s %s\n ",strings[0],strings[1]);
	printa_mao_jogador(mao_jogador2,2);
	*/



	
	
	//adicionar_palavra_trie (palavras_validas,"ab");
	//adicionar_palavra_trie (palavras_validas,"abc");
	//adicionar_palavra_trie (palavras_validas,"abcd");
	//adicionar_palavra_trie (palavras_validas,"dba");
	/*

	

	}
	*/

	//nodetrie_t *tovisit = palavras_validas->raiz;
	
	//if(tovisit != NULL){
	//	while (tovisit->letras[i].id == 0){i++;}
	//}
	//int k=0;
	//while(tovisit != NULL){
	//	printf(" ciclo:::: %d\n",k++);
	//	printf(" id : %d e i(%d)",tovisit->letras[i].id,i);
	//	printf("%c \n",97+i);
	//	tovisit = tovisit->letras[i].next ;
	//	i++;
	//}
/*
int a =0;
	//printf("\n");
	i = 0;
	while(scanf("%s",palavras) != EOF){
	
		 a = verifica(palavras_validas,palavras);
		  printf("%d\n",a);
		if( a != 1 ){
			printf(" valor de a == %d",a);
			//printf("%d\n",i);
			printf("deu ruim\n");
		}
		i++;
	}
*/

	//printf("%d\n",palavras_validas->n_nodes);

	//printf ("%d\n",verifica(palavras_validas,"abcd"));
	//printf ("%d\n",verifica(palavras_validas,"abcde"));

	//nodetrie_t *ptr = palavras_validas->raiz;
	//ptr = ptr->letras[0].next;
	//ptr = ptr->letras[1].next;
	//printf ("%c adaa ad",ptr->letras[23].letra);

	 


	fclose(arquivo);
    return 0;	
} 


