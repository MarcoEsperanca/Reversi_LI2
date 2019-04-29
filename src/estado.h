//
// Created by pja on 27/02/2019.
//



#ifndef PROJ_ESTADO_H
#define PROJ_ESTADO_H



/**
estado.h
Definição do estado i.e. tabuleiro. Representação matricial do tabuleiro.
*/


// definição de valores possiveis no tabuleiro
typedef enum {VAZIA, VALOR_X, VALOR_O} VALOR;

/**
Estrutura que armazena o estado do jogo
*/
typedef struct estado {
    VALOR peca; // peça do jogador que vai jogar!
    VALOR grelha[8][8];
    char modo; // modo em que se está a jogar! 0-> manual, 1-> contra computador
    char dif; // dificuldade do jogo (quando em modo automático), entre 1 e 3.
} ESTADO;

typedef struct estadosh {
    ESTADO e;
    struct estadosh * prox;
} *ESTADOSH;

// Armazena uma posição da grelha.
typedef struct posicao {
    char lin;
    char col;
    char dest;
} POSICAO;

void printa(ESTADO e, int* pVal, int nPos, POSICAO pos[]);

void newBoard(ESTADO* e, VALOR peca, char modo);

void limpaHist(ESTADOSH* hist);

#endif //PROJ_ESTADO_H