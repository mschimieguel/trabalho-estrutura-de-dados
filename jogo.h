#ifndef JOGO_H
#define JOGO_H

typedef struct jogador{
	int pontos;
	saco_t *mao_jogador;
}jogador_t;
typedef struct tabela_pontos{
	int jogador_i;
	int pontos;
}tabela_pontos_t;


jogador_t *cria_jogadores(int n);
void inverter(char *linha);
void p_linha(void);
void p_espaco(void);
void printa_tabuleiro (char **tabuleiro);
void menu1(void);
void menu2(void);
char* copy_l_c(char **tabuleiro,char sentido,int l_c);
int conta_letras(char *copiada_l_c,int inicio,int fim);
char *preenche(char *copiada_l_c,char *palavra,char sentido,int inicio,int fim);
char *to_verify(char *preenchido,char sentido,int inicio,int fim);
int put_palavra(trie_t * palavras_validas ,char **tabuleiro,char *letras,int ponto1,int ponto2,int l_c,char sentido);
char **matiz_strings (int l,int c);
char *jogada (jogador_t *jogador,char *retirar);
int pt_letra(char l);
int pontopalavra (char *total);

char *compra(jogador_t *jogador,saco_t *SacoAleatorio);
char **troca(jogador_t *jogador,saco_t *SacoAleatorio);
char *	troca1(jogador_t *jogador,saco_t *SacoAleatorio,int pos);
char *limpar_mao(jogador_t *jogador,char *letras);

void printa_mao_jogador (jogador_t *jogador ,int n );
void menu3(char **tabuleiro,int i,jogador_t *jogador,int n);
void selectionSort(tabela_pontos_t *tabela_pontos, int i, int n);
void printa_placar (tabela_pontos_t tabela_pontos[],int n);

#endif