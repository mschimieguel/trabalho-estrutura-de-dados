#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "saco.h"
#include "trie.h"
#include "jogo.h"

jogador_t *cria_jogadores(int n){
    int i = 0;
   // printf("Digite o numero de jogadores: \n");
    jogador_t *toreturn  = (jogador_t*)malloc(n*sizeof(jogador_t));
    for (i = 0 ;i < n;i++){
    	toreturn[i].pontos = 0;
    	toreturn[i].mao_jogador = createbag();
    }
    return toreturn;
}
void inverter(char *linha){
    int n = strlen(linha);
    int i = 0,j = 0;
    char *aux = (char *)malloc(n*sizeof(char));
   
    for(i = n - 1 ; i >= 0 ; i--){
        aux[i] = linha[j];
        j++;
    }
    j = 0;
    for(i = 0 ; i < n ; i++){
        linha[i] = aux[j];
        j++;
    }
    puts(linha);
    free(aux);
}
void p_linha(void){
     int i = 0;
    for (i = 0;i < 91;i++){
            printf("-");
        }
        printf("\n");
}
void p_espaco(void){
    int i = 0;
    for (i = 0;i < 10;i++)
        printf(" ");       
}
void printa_tabuleiro (char **tabuleiro){
    int i = 0,j = 0,k = 0;
   
    //_ -\\||==
    for(i = 0; i < 15;i++){
        p_espaco();
        if(i == 0){
            p_espaco();
            printf("   ");
            printf("0     1     2     3     4     5     6     7     8     9    10     11    12     13    14" );
            printf("\n");
            p_espaco();
        }
            p_espaco();
            p_linha();
            p_espaco();
            if(i < 10)
                printf("        %d ",i);
            else
                printf("       %d ",i);
            //p_espaco();
            for (j = 0;j < 15;j++){
                if(j ==  0 )
                    printf("|");
                printf("  %c  |",tabuleiro[i][j]);   
        }
        printf("\n");   
    }
    p_espaco();
    p_espaco();
    p_linha();
    printf("\n");
}
void menu1(void){

    printf("	escolha uma opcao ,digite um numero:    \n");
    printf("	-----------------------------------------  \n");
    printf("	||	1: Para fazer uma jogada        ||  \n");
    printf("	||	2: para trocar uma pedra        ||  \n");
    printf("	||	3: para trocar todas as pedras  ||  \n");
    printf("	||	4: passar a vez                 ||  \n");
    printf("	-----------------------------------------  \n");

   
}
void menu2(void){

    printf("Digite os seguintes caracterespara \nescolher o sentido que voce quer colocar a palavra\n");
    printf("                                  D :->\n\n");
    printf("                                  E : <-\n\n");
    printf("                                  B : |\n                                      V\n");
    printf("                                  C : ^\n                                      |\n");
    //printf("D : l e t r a  \n");
    //printf("E : a r t e l \n");
   // printf("C : a\nr\nt\ne\nl \n");
   // printf("B : l\ne\nt\nr\na \n");   


}
char* copy_l_c(char **tabuleiro,char sentido,int l_c){
    char *toreturn = (char*)malloc(15*sizeof(char));
    int i = 0;

    if (sentido == 'D' || sentido == 'E'){
        for(i =  0;i < 15;i++){
            toreturn[i] = tabuleiro[l_c][i];
        }
    }
    //linha fixa

    if (sentido == 'C' || sentido == 'B'){
        for(i =  0;i < 15;i++){
            toreturn[i] = tabuleiro[i][l_c];
        }
    }

    //coluna fixa
    return toreturn;
}
int conta_letras(char *copiada_l_c,int inicio,int fim){
    int i = 0,add = 0;
    for(i = inicio;i <= fim;i++ ){
        if(copiada_l_c[i] >='a' && copiada_l_c[i] <='z')
            add++;

    }
    return add;
}
char *preenche(char *copiada_l_c,char *palavra,char sentido,int inicio,int fim){
    int i = 0, dif = 0,tamanho = 0,add = 0;
    dif = fim - inicio + 1;
    int num_l = conta_letras(copiada_l_c,inicio,fim);
    tamanho = strlen(palavra);
    /*if (num_l == 0 && )
        ret return "ERRO";
        */
//tamanho sao a quantidade de letras que o jogador colocou
    if(tamanho + num_l != dif)
        return "ERRO";

    char *toreturn = (char*)malloc(15*sizeof(char));
    for (i =0;i <15 ;i++)
        toreturn[i] = copiada_l_c[i];
    if (sentido == 'D' || sentido == 'B'){
        for(i = inicio;i <=fim ;i++){
            if(copiada_l_c[i] >= 'a' && copiada_l_c[i] <= 'z'){
                toreturn[i] = copiada_l_c[i];
            }
            else{
                toreturn[i] = palavra[add];
                add++;
            }
        }
    }
    //linha fixa
    if (sentido == 'C' || sentido == 'E'){
        for(i = fim;i >=inicio ;i--){
            if(copiada_l_c[i] >= 'a' && copiada_l_c[i] <= 'z'){
                toreturn[i] = copiada_l_c[i];
            }
            else{
                toreturn[i] = palavra[add];
                add++;
            }
        }
    }
   // printf("toreturn %s\n",toreturn );
    return toreturn;

}
char *to_verify(char *preenchido,char sentido,int inicio,int fim ){
    int i = 0,r_i =inicio,r_f = fim;
   // printf("enrntfefduhfushfueshfuiods\n");
       
        i = inicio - 1;
        while(preenchido[i] != ' ' && i > 0){
           // printf("entrou1\n");
            r_i--;
            i--;
        }
       
        i = fim + 1;
        while(preenchido[i] != ' ' && i < 15){
           // printf("entrou2\n");
            r_f++;
            i++;
        }
        char *toreturn = (char*)malloc((r_f - r_i + 1)*sizeof(char));

        for (i = r_i;i <= r_f ; i++){
            toreturn[i - r_i] = preenchido[i];
        }
       
    if (sentido == 'D' || sentido == 'B'){}
    if (sentido == 'C' || sentido == 'E'){
        inverter(toreturn);
    }
    return toreturn;   
}

 int put_palavra(trie_t * palavras_validas ,char **tabuleiro,char *letras,int ponto1,int ponto2,int l_c,char sentido){
     int i = 0;
     char *copia =  copy_l_c(tabuleiro,sentido,l_c);
     int pts = 0;
     //printf("copia %s\n",copia);
    if (ponto1 > 14 || ponto1 < 0 || ponto2 > 14 || ponto2 < 0)
    	return -3;
    int aux = 0;
    if (ponto1 > ponto2){
        aux = ponto1;
        ponto1 = ponto2;
        ponto2 = aux;

    }
   
    //printf("%s\n",s);
    //int NUM_L  = conta_letras(s,inicio, fim);
    char *preenchida = preenche(copia,letras,sentido,ponto1,ponto2);
    if (strcmp(preenchida,"ERRO") == 0)
        return -1;
    //printf("preenchido %s\n",preenchida);
    char *verificar = to_verify(preenchida,sentido,ponto1,ponto2);
    //printf("verificar %s\n",verificar);
    if (verifica(palavras_validas,verificar) == 1){
        if (sentido == 'D' || sentido == 'E'){
            for(i = 0;i < 15;i++)
                tabuleiro[l_c][i] = preenchida[i];
        }
        if (sentido == 'C' || sentido == 'B'){
            for(i = 0;i < 15;i++)
                tabuleiro[i][l_c] = preenchida[i];
        }
        pts = pontopalavra (verificar);
        
        return pts;
    }

    return -2;
 }

 char **matiz_strings (int l,int c){
    char **matriz = (char**) malloc(l*sizeof(char*));
    int i = 0,j = 0;
    for (j = 0;j < l;j++)
        matriz[j] = (char *)malloc(c*sizeof(char));

    for (i = 0 ;i < l;i++)
        for(j = 0;j < c ;j++)
            matriz[i][j] = ' ';
   
    return matriz;
}
char *jogada (jogador_t *jogador,char *retirar){
    //retorna as letras referentes as posicoes digitadas

    int tamanho  = strlen(retirar);
   	int caractere ; 
    int i = 0 ,pos = 0,t = 0,add = 0;
    t = tamanho/2 +1;
    	t++;
    char *toreturn =(char*) malloc(t*sizeof(char));
    for(i = 0 ; i < t;i++)
    	toreturn[i] = 0;
  
    for(i = 0 ; i < tamanho;i++){
        
        if (retirar[i] == '0' ||retirar[i] == '1' ||retirar[i] == '2' ||retirar[i] == '3' ||retirar[i] == '4' ||retirar[i] == '5' ||retirar[i] == '6'){
           caractere = retirar[i] - 48;
           //printf("caractere : %d\n", caractere);
           // pos = caractere;
            //printf("teste2\n");
            toreturn[add] = busca_pos (jogador->mao_jogador,caractere);
            //printf("toreturn[add] =: %c \n", toreturn[add]);
            add++;
        }
    }
    toreturn[add] = 0;
    //printf("*toretrun ----- %s\n",toreturn);
    
 
     return toreturn;   
}
int pt_letra(char l){
    if(l =='a' || l =='e'|| l == 'i'|| l =='o'|| l =='s'|| l =='u'|| l =='m'|| l =='r'|| l =='t')
         return 1;
    if(l =='d' || l =='l' ||l =='c' ||l =='p')
        return 2;
     if(l =='n' || l =='b')
         return 3;
     if(l =='f' || l =='g' || l =='h' || l =='v')
         return 4;
     if (l =='j')
         return 5;
     if(l =='q')
         return 6;
     if( l =='x'|| l =='z')
         return 8;
}
int pontopalavra (char *total){
    int tamanho =strlen(total);
    int i = 0;
    int soma = 0;
    for (i = 0;i <tamanho;i++){
        soma += pt_letra(total[i]);
    }
    return soma;
}
char *compra(jogador_t *jogador,saco_t *SacoAleatorio){
    char *toreturn =  (char*) malloc(8*sizeof(char));
    int i = 0;
    while(jogador->mao_jogador->tamanho < 7 && SacoAleatorio->head != NULL){
        toreturn[i] = retirar_elemento_inicio(SacoAleatorio);
        adicionar_elemento_inicio(jogador->mao_jogador,toreturn[i]);
        i++;
    }
    toreturn[i] = 0;

    return toreturn;
 }
 char **troca(jogador_t *jogador,saco_t *SacoAleatorio){
     // a funcao retorna a string  que estava na mao do jogador e que ele recebeu ao trocar
    char **toreturn = matiz_strings (2,8);
    srand((unsigned)time(NULL));
    int i = 0;
    while(jogador->mao_jogador->head != NULL ){
         toreturn[0][i] = retirar_elemento_inicio(jogador->mao_jogador);
        adicionar_elemento(SacoAleatorio,toreturn[0][i],rand()%SacoAleatorio->tamanho);
        i++;
    }
    toreturn[0][i] = 0;
      toreturn[1]  = compra(jogador,SacoAleatorio);
     //toreturn[0][] e a string que estava na mao do jogador.
     //toreturn[1][] e a string que ele recebeu(tirou do saco) .
    
     return toreturn;
 }
char* troca1(jogador_t *jogador,saco_t *SacoAleatorio,int pos){
    char retirada  = retirar_elemento(jogador->mao_jogador,pos);
    srand((unsigned)time(NULL));
    adicionar_elemento(SacoAleatorio,retirada,rand()%SacoAleatorio->tamanho);
    char *toreturn = compra(jogador,SacoAleatorio);
    return toreturn;
}
char* limpar_mao(jogador_t *jogador,char *letras){
	int tamanho  = strlen(letras);
	char *toreturn  = (char*)malloc(tamanho*sizeof(char));
	int i =0;
	for(i = 0;i < tamanho;i++){
		toreturn[i] = retirar_especifico (jogador->mao_jogador,letras[i]);
	}
	return toreturn;
}
void printa_mao_jogador (jogador_t *jogador ,int n ){
    printf ("	jogador %d: \n\n",n);
    printf("	pontuacao : %d\n",jogador->pontos);
    printf("	mao:      \n");
    printf("	          ");
    imprimir_saco(jogador->mao_jogador);
    int i = 0;
    printf("	         ");
    for (i = 0;i < jogador->mao_jogador->tamanho;i++)
        printf (" %d",i);
    printf("\n");
               
}
void menu3(char **tabuleiro,int i,jogador_t *jogador,int n){
		system("clear");
		printa_tabuleiro(tabuleiro);

		printf("      |||Rodada %d |||\n\n",i);
		printa_mao_jogador (jogador,i%n);
		printf("\n");
}


void selectionSort(tabela_pontos_t *tabela_pontos, int i, int n){
    int j=0,maior=0,pos=0,cont=0;
    tabela_pontos_t aux;
    maior=tabela_pontos[i].pontos;
    pos=i;
    if (i==n)
        return;
    for (j=i;j< n;j++){
        if (tabela_pontos[j].pontos > maior){
            maior=tabela_pontos[j].pontos;
            pos=j;
        }
    }
    aux.pontos = tabela_pontos[pos].pontos;
    aux.jogador_i = tabela_pontos[pos].jogador_i;
    //aux=array[pos];
    tabela_pontos[pos].pontos = tabela_pontos[i].pontos;
    tabela_pontos[pos].jogador_i = tabela_pontos[i].jogador_i;

    //array[pos]=array[i];
    tabela_pontos[i].pontos = aux.pontos;
    tabela_pontos[i].jogador_i = aux.jogador_i;
    //array[i]=aux;
    return selectionSort(tabela_pontos,i+1,n);
   

}
void printa_placar (tabela_pontos_t tabela_pontos[],int n){
    selectionSort(tabela_pontos,0,n);
    printf("        Pontuacao Geral :\n");
    int i = 0;
    for(i = 0;i < n;i++){
        printf("    Jogador %d : ",tabela_pontos[i].jogador_i);
        printf("    %d pontos \n",tabela_pontos[i].pontos);
    }
}