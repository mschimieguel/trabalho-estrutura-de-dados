#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "saco.h"
#include "trie.h"
#include "jogo.h"	


int main (void){
	FILE *arquivo = fopen("palavras.txt","r");
	

	int i = 0,j = 0,n = 0 , ponto1, ponto2,pos,pontos = 0,l_c,pulos = 0;
	char direcao[7],sentido,palavras[30],jogada_v[14],*letras,*comprado,*troca_um;
	
	char **tabuleiro = matiz_strings (15,15);
	saco_t *SacoAleatorio  = saco_aleatorio();
	trie_t *palavras_validas = create_trie();
	char *clean_hand;
	
	while (fscanf(arquivo,"%s",palavras) !=  EOF )
		adicionar_palavra_trie (palavras_validas,palavras);
		
	
	printf("Digite o numero de jogadores(de 2 a 4 jogadores) : ");
	scanf("%d",&n);
	
	int escolhas[n];
	tabela_pontos_t tabela_pontos[n];
	for(j= 0;j < n;j++){
		tabela_pontos[j].jogador_i = j;
		tabela_pontos[j].pontos = 0;
	}
	printa_placar (tabela_pontos, n);
	jogador_t *jogadores = cria_jogadores(n);
	
	adicionar_elemento_inicio(jogadores[0].mao_jogador,'r');
	adicionar_elemento_inicio(jogadores[0].mao_jogador,'i');
	adicionar_elemento_inicio(jogadores[0].mao_jogador,'t');
	adicionar_elemento_inicio(jogadores[0].mao_jogador,'m');
	adicionar_elemento_inicio(jogadores[0].mao_jogador,'o');
	adicionar_elemento_inicio(jogadores[0].mao_jogador,'s');
	adicionar_elemento_inicio(jogadores[0].mao_jogador,'t');
		
	adicionar_elemento_inicio(jogadores[1].mao_jogador,'q');
	adicionar_elemento_inicio(jogadores[1].mao_jogador,'a');
	adicionar_elemento_inicio(jogadores[1].mao_jogador,'l');
	adicionar_elemento_inicio(jogadores[1].mao_jogador,'u');
	adicionar_elemento_inicio(jogadores[1].mao_jogador,'r');
	adicionar_elemento_inicio(jogadores[1].mao_jogador,'e');
	adicionar_elemento_inicio(jogadores[1].mao_jogador,'b');

	for(i = 2;i < n;i++)
		comprado = compra(&jogadores[i],SacoAleatorio);
	
	
	//printa_tabuleiro(tabuleiro);
	
	i = 0;
	while(SacoAleatorio->head != NULL && pulos < n*2){
		
		menu3(tabuleiro,i,&jogadores[i%n],n);
	
		menu1();
		scanf("%d",&escolhas[i%n]);
		//printf("Escolha %d",escolhas[i%n]);
		//printa_placar (tabela_pontos, n);
		
		if (escolhas[i%n] == 1){
				setbuf(stdin,NULL);
				menu3(tabuleiro,i,&jogadores[i%n],n);
				//printa_mao_jogador (&jogadores[i%n], i%n );
				printf("Escolha as letras :  \n");
				for(j = 0; j < 14;j++)
						jogada_v[j] = 0;
				
				fgets (jogada_v,14,stdin);
				//printf("jogada:  %s\n", jogada_v);
				setbuf(stdin,NULL);

				letras = jogada (&jogadores[i%n],jogada_v);
				//printf("letras %s\n", letras);
				//printf("Digite linha ou coluna para colocar a palavra na horizontal ou vertical respectivamente.\n  De um espaco e digite o numero da coluna ou linha onde sera colocada :\n");
				//scanf("%s %d",direcao,&l_c);
				menu3(tabuleiro,i,&jogadores[i%n],n);
				printf(" digite o sentido que vc quer colocar a sua palavra : \n D - Para a direita   B - para baixo \n E - para  esquerda  C - para cima \n");
				scanf("%c",&sentido);
				//printf("sentido %c\n",sentido);
				menu3(tabuleiro,i,&jogadores[i%n],n);
				setbuf(stdin,NULL);
				if ( sentido == 'D' || sentido == 'E' )
					printf(" Digite o numero da linha : "); 
				if ( sentido == 'B' || sentido == 'C' )
					printf(" Digite o numero da coluna : "); 
				 
				scanf("%d",&l_c);
				//printf("coluna %d\n",l_c);
				setbuf(stdin,NULL);
				printf("\n");
				//menu2();
				menu3(tabuleiro,i,&jogadores[i%n],n);
				printf("Agora digite posicao que vc quer colocar a primeira letra e a ultima letra : \n (lembre-se que vc deve contar as pecas do tabuleiro que estao entre elas).  \n");
				scanf(" %d %d",&ponto1,&ponto2);
				//printf("ponto 1 %d , ponto 2 %d\n",ponto1,ponto2);
				setbuf(stdin,NULL);
				pontos = put_palavra(palavras_validas,tabuleiro,letras, ponto1,ponto2,l_c,sentido);
				if (pontos > 0){
					jogadores[i%n].pontos += pontos;
					tabela_pontos[i%n].pontos  += pontos;
					clean_hand = limpar_mao(&jogadores[i%n],letras);
					printf("%s\n",clean_hand);
					
					comprado = compra(&jogadores[i%n],SacoAleatorio);
					printa_mao_jogador (&jogadores[i%n], i%n );
					pulos = 0;
				}
				else{
					printf("||||||||||||||||||||||||||||||||||||||||||Jogador %d errou na sua jogada|||||||||||||||||||||||||||||||||||||||||| \n",i%n);
					printf(":::::::::::::::::::::::::::::::::::::::::::::::TENTE NOVAMENTE::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
					i--;
				}			 
		}
		
		if(escolhas[i%n] == 2){
			printf("Digite a posicao da letra que  voce quer trocar :\n");
			scanf("%d",&pos);
			setbuf(stdin,NULL);
			troca_um =  troca1(&jogadores[i%n],SacoAleatorio,pos);

		}
		if(escolhas[i%n] == 3){
			troca(&jogadores[i%n],SacoAleatorio);
			pulos = 0;
		} 
			
		if(escolhas[i%n] == 4){
			printf("	|||||||Jogador %d pulou a sua jogada||||||| \n",i%n);
			pulos ++;
		}
		
		
		i++;
		
		free(letras);
		letras = NULL;
	}
	printf("------------------------------------------FIM DE JOGO----------------------------------------------- \n");
	//printf("o JOGADOR %d  foi o vencedor \n \n",tabela_pontos[]);
	printa_placar (tabela_pontos, n);
	fclose(arquivo);
    return 0;	

} 


