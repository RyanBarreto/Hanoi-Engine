#include <stdio.h>
#include <stdlib.h>
#include "hanoi.h"

/* Complete somente as funcoes abaixo. Nao use vetor para representar as torres. */

int push(No **topo,int disco){
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) {
    return 0;
}
int pop(No **topo){
    /* TODO 2: remover do inicio, usar free(), retornar disco ou -1. */
    return -1;
}
int peek(No *topo){
    /* TODO 3: consultar topo sem remover. */
    return -1;
}
int torreVazia(No *topo){
    /* TODO 4 */
    return 1;
}
int registrarMovimento(Movimento **historico,char origem,char destino,int disco){
    /* TODO 5: historico em lista encadeada, mantendo ordem cronologica. */
    return 0;
}
int contarMovimentos(Movimento *historico){
    /* TODO 6 */
    return 0;
}
int moverDisco(Torre *origem,Torre *destino,Movimento **historico){
    /* TODO 7:
       - origem nao vazia;
       - maior nunca sobre menor;
       - invalido nao altera estrutura;
       - valido usa pop + push e registra historico;
       retorno: 1 sucesso, 0 invalido, -1 erro memoria.
    */
    return 0;
}
int verificarVitoria(Torre *destino,int quantidadeDiscos){
    /* TODO 8 */
    return 0;
}
void liberarTorre(No **topo){
    /* TODO 9 */
}
void liberarHistorico(Movimento **historico){
    /* TODO 10 */
}
int inicializarJogo(Torre *a,Torre *b,Torre *c,int quantidadeDiscos){
    /* TODO 11: 3 a 8 discos; A com 1 no topo; B/C vazias. */
    (void)a;(void)b;(void)c;(void)quantidadeDiscos;
    return 0;
}
void reiniciarJogo(Torre *a,Torre *b,Torre *c,Movimento **historico,int quantidadeDiscos){
    /* TODO 12 */
    (void)a;(void)b;(void)c;(void)historico;(void)quantidadeDiscos;
}
