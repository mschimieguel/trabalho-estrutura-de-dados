#ifndef TRIE_H
#define TRIE_H

typedef struct elemento{
    char letra;
    int id;
    //id == 0 no adicionado equivalente a uma letra "null"
    //id == 1 no pertencente a uma palavra 
    //id == -1 no representa o final de uma palavra 
    struct nodetrie *next;
    
}element_trie_t;

typedef struct nodetrie{
     
     element_trie_t letras[26];
}nodetrie_t;

typedef struct trie{
    nodetrie_t *raiz;
    int n_nodes;       
}trie_t;

trie_t *create_trie();
void inicializar_elements(nodetrie_t *no_novotrie);
void adicionar_palavra_trie (trie_t *trie,char *palavra);

int verifica(trie_t *trie,char *palavra);
#endif
