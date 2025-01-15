struct no{
    
    int valorNaLista;
    struct no *anterior;
    struct no *proximo;

};typedef struct no NO;

NO* iniciar_lista();
NO* inserir_inicio(NO* n, int valor);
NO* inserir_fim(NO* n, int valor);
void imprimir(NO* n);
NO* liberar(NO* n);
int tamanho(NO* n);
int remove_lista(NO** li, int valor);
int insere_ordenado(NO* n, int valor);
