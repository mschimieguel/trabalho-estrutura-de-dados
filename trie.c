#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

/*int char_to_int(char letra){
    int i =0;
     char aux ='a';
     for (i= 0; i < 26;i++)
     	if(letra == aux + i)
     		return i;

}*/

trie_t *create_trie(){
    trie_t *trie = (trie_t *) malloc(sizeof(trie_t));
    //trie->raiz = NULL;
    nodetrie_t *no_novo = (nodetrie_t*)malloc(sizeof(nodetrie_t));
    inicializar_elements(no_novo);
    trie->raiz  = no_novo;       
    trie->n_nodes = 1;
    return trie;
}
void inicializar_elements(nodetrie_t *no_novotrie){
    int i = 0;
    for(i = 0;i < 26;i++){
        no_novotrie->letras[i].letra = 97 + i;
        no_novotrie->letras[i].next = NULL;
        no_novotrie->letras[i].id = 0;           
    }
}       
void adicionar_palavra_trie (trie_t *trie,char *palavra){

    int i = 0;
    int tamanho  = strlen (palavra);
    //printf(" tamanho %d\n",tamanho);
    char atual;
    int charactere;
    if (trie->raiz == NULL){
        nodetrie_t *no_novo1 = (nodetrie_t*)malloc(sizeof(nodetrie_t));
        inicializar_elements(no_novo1);
        trie->raiz  = no_novo1;         
    }
    
    nodetrie_t *tovisit = trie->raiz;
    for (i = 0;i < tamanho ;i++){
        atual = palavra[i];
        //printf("%c cilco: %d \n",atual,i);
        charactere = atual - 97;
       
        if (tovisit->letras[charactere].next == NULL ){
            
            if (tovisit->letras[charactere].id == 0)
            	tovisit->letras[charactere].id = 1;

            if(i != tamanho - 1){
	            nodetrie_t *no_novo2 = (nodetrie_t*)malloc(sizeof(nodetrie_t));
	            inicializar_elements(no_novo2);
	            tovisit->letras[charactere].next = no_novo2;
                trie->n_nodes++;
	        }               
        }
        if(i != tamanho - 1)
   			tovisit = tovisit->letras[charactere].next;
   			
   }
   	tovisit->letras[charactere].id = -1;	
}
int verifica(trie_t *trie,char *palavra){
	 int i = 0;
     int tamanho  = strlen (palavra);
     //printf(" tam =     %d\n",tamanho );
     int charactere;
     char atual;
     if (trie->raiz == NULL){
     	printf("trie vazia");
     	return -30;
     }	
     
     nodetrie_t *tovisit = trie->raiz;
     
     for(i = 0; i < tamanho;i++){
     	atual = palavra[i];
     	 charactere = atual - 97;
     	//printf(" char :%c \n",atual);
       // printf("id :%d \n",tovisit->letras[charactere].id);
       	//printf("%d\n",i);
     	if (tovisit->letras[charactere].id == 0)
     		return -1;
        if(tovisit->letras[charactere].id == -1 && i == tamanho-1)
            return 1;
 
     	if (tovisit->letras[charactere].next == NULL )
     		return -15;
     	tovisit = tovisit->letras[charactere].next;	
     }
     

     return -2;
}