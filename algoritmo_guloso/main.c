/*
 * Diciplina : Grafos.
 * Aluno : Cleiton Piccini.
 * Trabalho : Desenvolver um algoritmo que percora dois grafos valorados,
 * com uma abordagem de algoritmo Guloso.
 * Obs : Programa construido para leitura de matrizes adjacentes de grafos
 * com ate 50 Vertices. 
 * Dados inseridos estaticamente nas funcoes :
 * - setValueGrafo_1 : grafo que deve percorrer todos os vertices.
 * - setValueGrafo_2 : grafo com origem e destino.
 * Dados para a movimentacao entre os vertices inseridos estaticamente nas funcoes :
 * - startMoveGrafo_1 : contempla o numero de vertices, vertice atual, vertice de destino 
 * e distancia percorida.
 * - startMoveGrafo_2 : contempla o numero de vertices, vertice atual, vertice de destino 
 * e distancia percorida.
*/
#include <stdio.h>
#include "fun.h"
#include "implement.c"

int main (void)
{
	moves moviment;
	int grafo_1[MAX][MAX];
	int grafo_2[MAX][MAX];
	
	moviment = startMoveGrafo_1(moviment);
	setValueGrafo_1 (grafo_1); 
	printf("Matriz Adjacente do Grafo 1\n");
	printArray (grafo_1, moviment);
	printf("\n");
	
	greedy (grafo_1, moviment);
	printf("\n");
	
	moviment = startMoveGrafo_2(moviment);
	setValueGrafo_2 (grafo_2);
	printf("Matriz Adjacente do Grafo 2\n");
	printArray (grafo_2, moviment);
	printf("\n");
	
	greedy (grafo_2, moviment);
	printf("\n");
	
	return 0;
}
