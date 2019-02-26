#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "saco.h"

saco_t *createbag(){
    saco_t *saco = (saco_t*)malloc(sizeof(saco_t));
    saco->head=NULL;
    saco->tail=NULL;
    saco->tamanho = 0;    
}
void adicionar_elemento_inicio(saco_t *saco,char letra){
    node_t *no_novo = (node_t*) malloc(sizeof(node_t));
    
    no_novo->letra = letra;
    no_novo->next = saco->head;
    saco->tamanho++;
    
    if (saco->head == NULL){
        saco->head=no_novo;
        saco->tail=no_novo;
    }
    else {
         no_novo -> next = saco->head;
        saco->head=no_novo;    
    }    
}
void adicionar_elemento_fim(saco_t *saco,char letra){
    
	node_t *no_novo = (node_t*) malloc(sizeof(node_t));
    node_t *tovisit = saco->head;
  
    no_novo->letra = letra;
    no_novo->next = NULL;
    saco->tamanho++;
    

    if (saco->head == NULL){
        saco->head = no_novo;
        saco->tail = no_novo;
		
    }
    else {
        saco->tail->next = no_novo;
        saco->tail = no_novo;	    
    }

}
void adicionar_elemento(saco_t *saco,char letra,int pos){
    int i=0;
        
    if (pos>0 && pos < saco->tamanho-1){
        node_t *tovisit=saco->head;
        for (i=0;i<pos-1;i++){
            tovisit=tovisit->next;
        }
        node_t *ultrapassado = tovisit->next;
        
		node_t *no_novo = (node_t*)malloc(sizeof(node_t));
        no_novo->letra = letra;
		
       
        tovisit->next = no_novo;
        no_novo->next=ultrapassado;
       
        saco->tamanho++;
    }
    else if (pos == 0)
        adicionar_elemento_inicio(saco,letra);
    else if (pos == saco->tamanho)
        adicionar_elemento_fim(saco,letra);
    else 
        printf("posicao nao permitida\n");
     
}
char retirar_elemento_inicio(saco_t *saco){
    
    node_t *tofree = saco->head;
    char toreturn = tofree->letra;
    saco->head=saco->head->next;
    saco->tamanho--;

    free(tofree);
    return toreturn;
}
char retirar_elemento_fim(saco_t *saco){
    
    node_t *previus = saco->head;
    while(previus->next != saco->tail)
        previus = previus->next;
    
    node_t *tofree = previus->next;
    char toreturn = tofree->letra;
    
    saco->tail = previus;
    previus->next = NULL;
    free(tofree);
    saco->tamanho--;
    return toreturn;
}
char retirar_elemento(saco_t *saco,int pos){
    char toreturn;
    if (pos>0 && pos < saco->tamanho - 1){
        node_t *tovisit =saco->head;
        node_t *tofree = NULL;
        int i;
        for (i=0;i < pos-1;i++)
            tovisit = tovisit->next;
        
        tofree = tovisit->next;
        toreturn =tofree->letra;
        tovisit->next = tofree->next;
        saco->tamanho--;
        free(tofree);
    }    
    else if (pos == 0)
        return retirar_elemento_inicio(saco);
    else if (pos == saco->tamanho - 1)
        return retirar_elemento_fim(saco);
    else   
        printf ("posicao inexistente ou nao permitida\n");
    return toreturn;
}
char retirar_especifico (saco_t *mao_jogador,char retirar){
	int pos = 0;
	node_t *atual= mao_jogador->head;
	int i = 0;
	if (mao_jogador->head==NULL){
		printf("Error, sem memoria!!");
    	exit(1);
	}
	while(atual->letra != retirar && atual->next != NULL){
		atual=atual->next;
		pos++;
	}
		
	if (atual->letra == retirar)
		return retirar_elemento(mao_jogador,pos);
		
	if (atual->next == NULL)
		return 0;

}
void imprimir_saco(saco_t *saco){
    if (saco->head != NULL){
        node_t *tovisit=saco->head;
        while (tovisit != NULL){
            printf("%c ",tovisit->letra);
            //printf("R==%d ",tovisit->repetido);
            tovisit = tovisit->next;
        }
        printf("\n");
    }
    else 
        printf("saco Vazio\n");    
}

int busca_letra(saco_t *saco, char letra){
	
	int pos=0;
	node_t *atual= saco->head;
	int i;
	if (saco->head==NULL){
		printf("Error, sem memoria!!");
    	exit(1);
	}
	while(atual->letra != letra && atual->next != NULL){
		atual=atual->next;
		pos++;
	}
		
	if (atual->letra == letra)
		return pos;
		
	if (atual->next==NULL)
		return -1;
}
char busca_pos(saco_t *saco,int pos){
	if (pos <  0 && pos >= saco->tamanho )
		return -1;
	int i = 0;
	node_t *atual = saco->head;
	for(i = 0;i < pos;i++){
		atual=atual->next;
	}
	char toreturn = atual->letra;
	return toreturn;

}
void destruir_saco(saco_t *saco){
    while (saco->head != NULL){
         retirar_elemento_inicio(saco);
    }
    free(saco);    
}
saco_t *saco_ordenado(){
    saco_t *toreturn = createbag();
    int i = 0;
   for (i = 0;i < 0;i++)
       adicionar_elemento_fim(toreturn,' ');
   for (i = 0;i < 14;i++)
        adicionar_elemento_fim(toreturn,'a');
   for (i = 0;i < 3;i++)
        adicionar_elemento_fim(toreturn,'b');
   for (i = 0;i < 6;i++)
       adicionar_elemento_fim(toreturn,'c');
   for (i = 0;i < 5;i++)
       adicionar_elemento_fim(toreturn,'d');
   for (i = 0;i < 11;i++)
       adicionar_elemento_fim(toreturn,'e');
   for (i = 0;i < 2;i++)
       adicionar_elemento_fim(toreturn,'f');
   for (i = 0;i < 2;i++)
       adicionar_elemento_fim(toreturn,'g');
   for (i = 0;i < 2;i++)
       adicionar_elemento_fim(toreturn,'h');
   for (i = 0;i < 10;i++)
       adicionar_elemento_fim(toreturn,'i');
   for (i = 0;i < 2;i++)
       adicionar_elemento_fim(toreturn,'j');
   for (i = 0;i < 0;i++)
       adicionar_elemento_fim(toreturn,'k');
   for (i = 0;i < 5;i++)
       adicionar_elemento_fim(toreturn,'l');
   for (i = 0;i < 6;i++)
       adicionar_elemento_fim(toreturn,'m');
   for (i = 0;i < 4;i++)
       adicionar_elemento_fim(toreturn,'n');
   for (i = 0;i < 10;i++)
       adicionar_elemento_fim(toreturn,'o');
   for (i = 0;i < 4;i++)
       adicionar_elemento_fim(toreturn,'p');
   for (i = 0;i < 1;i++)
       adicionar_elemento_fim(toreturn,'q');
   for (i = 0;i < 6;i++)
       adicionar_elemento_fim(toreturn,'r');
   for (i = 0;i < 8;i++)
       adicionar_elemento_fim(toreturn,'s');
   for (i = 0;i < 5;i++)
       adicionar_elemento_fim(toreturn,'t');
   for (i = 0;i < 7;i++)
       adicionar_elemento_fim(toreturn,'u');
   for (i = 0;i < 2;i++)
       adicionar_elemento_fim(toreturn,'v');
   for (i = 0;i < 0;i++)
       adicionar_elemento_fim(toreturn,'w');
   for (i = 0;i < 1;i++)
       adicionar_elemento_fim(toreturn,'x');
   for (i = 0;i < 0;i++)
       adicionar_elemento_fim(toreturn,'y');
   for (i = 0;i < 1;i++)
       adicionar_elemento_fim(toreturn,'z');


    return toreturn;
}
 saco_t *saco_aleatorio(){
    
 	saco_t *sacoordenado = saco_ordenado();

    saco_t *toreturn = createbag();
    srand( (unsigned)time(NULL) );
    char retirada;

    while (sacoordenado->head != NULL){
        retirada = retirar_elemento(sacoordenado,rand()%sacoordenado->tamanho);
        adicionar_elemento_fim(toreturn,retirada);    
    }
    destruir_saco(sacoordenado);
    return toreturn;
 }  
