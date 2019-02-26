#ifndef SACO_H
#define SACO_H

typedef struct node{
	char letra;
	struct node *next;
} node_t;

typedef struct saco{
	int tamanho;
	node_t *head;
	node_t *tail;		
}saco_t;

saco_t *createbag();
void adicionar_elemento_inicio(saco_t *saco,char letra);
void adicionar_elemento_fim(saco_t *saco,char letra);
void adicionar_elemento(saco_t *saco,char letra,int pos);

char  retirar_elemento_inicio(saco_t *saco);
char  retirar_elemento_fim(saco_t *saco);
char  retirar_elemento(saco_t *saco,int pos);
char retirar_especifico (saco_t *mao_jogador,char retirar);


int busca_letra(saco_t *saco, char letra);
char busca_pos(saco_t *saco,int pos);

void destruir_saco(saco_t *saco);
void imprimir_saco(saco_t *saco);

void remove_duplicados(saco_t *saco);

saco_t *saco_ordenado();
saco_t *saco_aleatorio();

#endif
