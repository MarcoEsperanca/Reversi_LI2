/**
@file bot.h
Definição das funções relativas ao bot
*/


#ifndef ___BOT_H___
#define ___BOT_H___

#include "dados.h"
#include "listas.h"


/**
\brief Verifica as posições livres em torno de uma dada casa.
Esta função varre todas as posições vizinhas da peça branca que estejam livres e armazena-las numa lista ligada de posições.
@param e Apontador para o estado
@param c A coordenada a ser inserida
@returns A lista com as coordenadas inseridas
*/
LISTA vizinhos(ESTADO *e, COORDENADA c);


/**
\brief Calcula o mínimo.
Esta função compara dois inteiros e verifica qual é o menor.
@param a O primeiro inteiro
@param b O segundo inteiro
@returns O menor inteiro
*/
int min(int a, int b);


/**
\brief Calcula o máximo.
Esta função compara dois inteiros e verifica qual é o maior.
@param a O primeiro inteiro
@param b O segundo inteiro
@returns O maior inteiro
*/
int max(int a, int b);


/**
\brief Seleciona um valor da matriz.
Esta função atribui valores a cada uma das posições do tabuleiro, selecionando a melhor jogada possível com esses valores.
@param e Apontador para o estado
@param peca O valor da casa a ser atribuído.
@returns O valor da casa selecionada
*/
int valor(ESTADO *e, CASA peca);


/**
\brief Escolha aleatória da jogada. 
Esta função utiliza a heurística que simplesmente escolhe uma das hipóteses possíveis.
@param e Apontador para o estado
@returns A coordenada selecionada
*/
COORDENADA pesquisa_aleatoria(ESTADO *e);


/**
\brief Algoritmo de procura minimax.  
Esta função utiliza a heurística minimax, que avalia cada posição, experimentando todas as jogadas possíveis de cada um 
dos jogadores, até uma dada profundidade, bem como avaliando a posição final em cada caso e escolhendo a jogada mais 
proveitosa para o jogador atual. O bot maximiza a sua posição, diminuindo o proveito do adversário. Nesta heurística
utiliza-se alpha beta pruning.
@param node O estado do jogo
@param depth A profundidade da árvore (o nível de recursão). Caso seja 0 calcula o valor atual do estado (node).
@param alpha Valor auxiliar que verifica se existe um melhor valor para o max
@param beta Valor auxiliar que verifica se existe um melhor valor para o min
@param maximizing_player A casa que o jogador selecionou para esta função
@returns O valor do estado node de forma a ser comparado com outros
*/
int minimax(ESTADO node, int depth, int alpha, int beta, CASA maximizing_player);


/**
\brief Determina a posição onde o bot vai jogar
Esta função usa a heurística minimax para determinar onde o bot vai jogar.
@param e Apontador para o estado
*/
void jogada_bot(ESTADO *e);


#endif