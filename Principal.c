#include <stdio.h>
#include "Execucao.c"

int main(){
 
    NO *n;
    
    n = iniciar_lista();
      /*
      n = inserir_inicio(n, 9);
      n = inserir_inicio(n, 8);
      n = inserir_fim(n, 14);
      n = inserir_inicio(n, 21);
      n = inserir_fim(n, 13);
      
      printf("\n----------------\n");

      imprimir(n);
      tamanho(n);

      printf("\n----------------\n");
    
      remove_lista(&n, 62);
      imprimir(n);
      tamanho(n);

      printf("\n----------------\n");
      */

      n = insere_ordenado(n, 12);
      n = insere_ordenado(n, 18);
      n = insere_ordenado(n, 62);
      n = insere_ordenado(n, 45);
      n = insere_ordenado(n, 20);

      printf("\n----------------\n");

      imprimir(n);
      tamanho(n);

      printf("\n----------------\n");

      remove_lista(&n, 62);
      imprimir(n);
      tamanho(n);

      printf("\n----------------\n");

      liberar(n);
}
