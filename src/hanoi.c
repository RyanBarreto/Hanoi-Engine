#include <stdio.h>
#include <stdlib.h>
#include "hanoi.h"


int push(No **topo,int disco){
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) {
    return 0;
    }
    novo->disco = disco;
        novo->proximo = *topo;
        *topo = novo;
        return 1;
}
int pop(No **topo) {
    if (torreVazia(*topo)) {
        return -1;
    }
    No *temp = *topo;
    int disco = temp->disco;
    *topo = temp->proximo;
    free(temp);
    return disco;
}

int peek(No *topo) {
    if (torreVazia(topo)) {
        return -1;
    }
    return topo->disco;
}

int torreVazia(No *topo) {
    return topo == NULL ? 1 : 0;
}

int registrarMovimento(Movimento **historico, char origem, char destino, int disco) {
    Movimento *novo = (Movimento *)malloc(sizeof(Movimento));
    if (novo == NULL) {
        return 0; 
    }
    novo->disco = disco;
    novo->origem = origem;
    novo->destino = destino;
    novo->proximo = NULL;

    if (*historico == NULL) {
        *historico = novo;
    } else {
        Movimento *atual = *historico;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    return 1;
}

int contarMovimentos(Movimento *historico) {
    int count = 0;
    Movimento *atual = historico;
    while (atual != NULL) {
        count++;
        atual = atual->proximo;
    }
    return count;
}

int moverDisco(Torre *origem, Torre *destino, Movimento **historico) {
    if (torreVazia(origem->topo)) {
        return 0;
    }

    int discoOrigem = peek(origem->topo);

    if (!torreVazia(destino->topo)) {
        int discoDestino = peek(destino->topo);
        if (discoOrigem > discoDestino) {
            return 0;
        }
    }

    int disco = pop(&(origem->topo));
    if (!push(&(destino->topo), disco)) {
        push(&(origem->topo), disco);
        return -1;
    }

    if (!registrarMovimento(historico, origem->nome, destino->nome, disco)) {
        pop(&(destino->topo));
        push(&(origem->topo), disco);
        return -1;
    }

    return 1; 
}

int verificarVitoria(Torre *destino, int quantidadeDiscos) {
    No *atual = destino->topo;
    for (int i = 1; i <= quantidadeDiscos; i++) {
        if (atual == NULL || atual->disco != i) {
            return 0;
        }
        atual = atual->proximo;
    }
    return atual == NULL ? 1 : 0;
}

void liberarTorre(No **topo) {
    No *atual = *topo;
    while (atual != NULL) {
        No *prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    *topo = NULL;
}

void liberarHistorico(Movimento **historico) {
    Movimento *atual = *historico;
    while (atual != NULL) {
        Movimento *prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    *historico = NULL;
}

int inicializarJogo(Torre *a, Torre *b, Torre *c, int quantidadeDiscos) {
    liberarTorre(&(a->topo));
    liberarTorre(&(b->topo));
    liberarTorre(&(c->topo));

    for (int i = quantidadeDiscos; i >= 1; i--) {
        if (!push(&(a->topo), i)) {
            return 0;
        }
    }
    return 1;
}

void reiniciarJogo(Torre *a, Torre *b, Torre *c, Movimento **historico, int quantidadeDiscos) {
    liberarTorre(&(a->topo));
    liberarTorre(&(b->topo));
    liberarTorre(&(c->topo));
    liberarHistorico(historico);
    inicializarJogo(a, b, c, quantidadeDiscos);
}
