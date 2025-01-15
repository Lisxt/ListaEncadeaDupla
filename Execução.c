#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

NO* iniciar_lista(void){
    return NULL;
}

//liberar a Lista
NO* liberar(NO* n){
    NO* no;
    while(n !=NULL){
        no = n;//recebe o primeiro elemento
        n = n->proximo;//avança para o proximo
        free(no);//libera o elemento que ficou para traz
    }free(n);
}

//inserir no inicio
NO* inserir_inicio(NO* n, int valor){
        NO* novo = (NO*) malloc(sizeof(NO));//alocação de novo elemento na lista
        novo->valorNaLista = valor;
        novo->proximo = n;//proximo no aponta para conteudo n(inicio)
        novo->anterior = NULL;//nada antes do primeiro no.
        if(n){
        n->anterior = novo;//primeiro no da lista aponta para o novo no da lista;
        n = novo;//muda o primeiro elemento da lista
        }
        return novo;
}

//inserir no fim
NO* inserir_fim(NO* n, int valor)
{
        NO* novo = (NO*) malloc(sizeof(NO));
        novo->valorNaLista = valor;
        novo->proximo = NULL;

        //lista vazia  
        if(n==NULL){
            novo->anterior = NULL;
            n = novo;
            return novo;
        }else{//variavel auxiliar para andar na lista
            NO* aux = n;
            while(aux->proximo !=NULL)
            aux = aux->proximo;
            //chegou ao final da fila
            aux->proximo = novo;//auxiliar aponta para o proximo(novo elemento)
            novo->anterior = aux;//novo elemento aponta para o ultimo elemento antes dele;
            return n;
        }
}

//Remove no
int remove_lista(NO** li, int valor){
 
    if(li == NULL || *li == NULL){ // Verifica se a lista é nula
        return 0;
    }
    NO* no = *li;
    while(no != NULL && no->valorNaLista != valor){
        no = no->proximo;
    }

    if(no == NULL)
    {// Não encontrado
        printf("Elemento %d não encontrado.\n", valor);
        return 0;
    }

    if(no->anterior == NULL) // Remover o primeiro?
        *li = no->proximo;
    else
        no->anterior->proximo = no->proximo;

    if(no->proximo != NULL) // Não é o último?
        no->proximo->anterior = no->anterior;
    free(no);
    
    printf("Elemento %d removido com sucesso.\n", valor);

    return 1;
}

//Insere ordenado
int insere_ordenado(NO* n, int valor) {
    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL) return 0; 
    novo->valorNaLista = valor;

    if (n == NULL) { // Lista está vazia
        novo->proximo = NULL;
        novo->anterior = NULL;
        n = novo;
        return n;
    }

    NO* p = n;
    NO* ant = NULL;

    // Encontrar a posição correta para inserir o numero fornecido pelo usuario
    while (p != NULL && p->valorNaLista < valor) {
        ant = p;
        p = p->proximo;
    }

    if (ant == NULL) { // Insere no início da lista
        novo->proximo = n;
        novo->anterior = NULL;
        if (n != NULL) {
            (n)->anterior = novo;
        }
        n = novo;
    } else { // Insere no meio ou no final da lista
        novo->proximo = ant->proximo;
        novo->anterior = ant;
        if (ant->proximo != NULL) {
            ant->proximo->anterior = novo;
        }
        ant->proximo = novo;
    }

    return n;
}

//Imprimir
void imprimir(NO* n){
    NO* p;
    printf("Lista:\n");
    for(p = n; p != NULL;  p = p->proximo)
    {
       printf("%d\n", p->valorNaLista);
    }
 
}

//tamanho da lista
int tamanho(NO* n){
    int contar = 1;//contador
    NO* no;
    for(no = n; no != NULL; contar++){
        no = no->proximo;//anada para o proximo elemento, ate chegar a NULL
        printf("%d, ", contar);
    }return contar;
}
