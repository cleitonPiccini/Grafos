#include <stdio.h>
#include "fun.h"

//Insert values in the adjacent array.
void setValueGrafo_1 (int arrayAdjacent[MAX][MAX])
{
	//Line 1
	arrayAdjacent[0][0] = 0;
	arrayAdjacent[0][1] = 30;
	arrayAdjacent[0][2] = -15;
	arrayAdjacent[0][3] = 0;
	arrayAdjacent[0][4] = 20;
	//Line 2
	arrayAdjacent[1][0] = -30;
	arrayAdjacent[1][1] = 0;
	arrayAdjacent[1][2] = -10;
	arrayAdjacent[1][3] = 50;
	arrayAdjacent[1][4] = 0;
	//Line 3
	arrayAdjacent[2][0] = 15;
	arrayAdjacent[2][1] = 10;
	arrayAdjacent[2][2] = 0;
	arrayAdjacent[2][3] = 5;
	arrayAdjacent[2][4] = -10;
	//Line 4
	arrayAdjacent[3][0] = 0;
	arrayAdjacent[3][1] = 50;
	arrayAdjacent[3][2] = -5;
	arrayAdjacent[3][3] = 0;
	arrayAdjacent[3][4] = -30;
	//Line 5
	arrayAdjacent[4][0] = -20;
	arrayAdjacent[4][1] = 0;
	arrayAdjacent[4][2] = 10;
	arrayAdjacent[4][3] = 30;
	arrayAdjacent[4][4] = 0;
	
	return;	
}

//Insert values in the adjacent array.
void setValueGrafo_2 (int arrayAdjacent[MAX][MAX])
{
	//Line 1
	arrayAdjacent[0][0] = 0;
	arrayAdjacent[0][1] = 2;
	arrayAdjacent[0][2] = 0;
	arrayAdjacent[0][3] = 6;
	arrayAdjacent[0][4] = 12;
	arrayAdjacent[0][5] = 0;
	arrayAdjacent[0][6] = 0;
	//Line 2
	arrayAdjacent[1][0] = -2;
	arrayAdjacent[1][1] = 0;
	arrayAdjacent[1][2] = 1;
	arrayAdjacent[1][3] = 0;
	arrayAdjacent[1][4] = 0;
	arrayAdjacent[1][5] = 5;
	arrayAdjacent[1][6] = 0;
	//Line 3
	arrayAdjacent[2][0] = 0;
	arrayAdjacent[2][1] = -1;
	arrayAdjacent[2][2] = 0;
	arrayAdjacent[2][3] = 0;
	arrayAdjacent[2][4] = 0;
	arrayAdjacent[2][5] = 0;
	arrayAdjacent[2][6] = 40;
	//Line 4
	arrayAdjacent[3][0] = -6;
	arrayAdjacent[3][1] = 0;
	arrayAdjacent[3][2] = 0;
	arrayAdjacent[3][3] = 0;
	arrayAdjacent[3][4] = 0;
	arrayAdjacent[3][5] = 4;
	arrayAdjacent[3][6] = 0;
	//Line 5
	arrayAdjacent[4][0] = -12;
	arrayAdjacent[4][1] = 0;
	arrayAdjacent[4][2] = 0;
	arrayAdjacent[4][3] = 0;
	arrayAdjacent[4][4] = 0;
	arrayAdjacent[4][5] = 0;
	arrayAdjacent[4][6] = 30;
	//Line 6
	arrayAdjacent[5][0] = 0;
	arrayAdjacent[5][1] = -5;
	arrayAdjacent[5][2] = 0;
	arrayAdjacent[5][3] = -4;
	arrayAdjacent[5][4] = 0;
	arrayAdjacent[5][5] = 0;
	arrayAdjacent[5][6] = 8;
	//Line 7
	arrayAdjacent[6][0] = 0;
	arrayAdjacent[6][1] = 0;
	arrayAdjacent[6][2] = -40;
	arrayAdjacent[6][3] = 0;
	arrayAdjacent[6][4] = -30;
	arrayAdjacent[6][5] = -8;
	arrayAdjacent[6][6] = 0;
	return;	
}

//Search the smallest path
moves searchLess (int array[MAX][MAX], moves moviment)
{
	int i, less = 0, temp;
	
	temp = moviment.vertActual;
	
	for (i=0; i < moviment.nVert; i++)
	{
		if (array[temp][i] > 0){
			less = array[temp][i];
			moviment.vertActual = i;
			break;
		}
	}
	
	for (i=0; i < moviment.nVert; i++)
	{
		if (array[temp][i] > 0 && array[temp][i] < less)
		{
			less = array[temp][i];
			moviment.vertActual = i;
		}
	}
	if (less == 0) printf("erro\n");
	moviment.valueMoves = less + moviment.valueMoves;
	return moviment;
}

//Next Vertex
moves nextVert (int array[MAX][MAX], moves moviment)
{
	//int vert;
	moves teste;
	teste = searchLess(array, moviment);
	return teste;
}

//Greedy
void greedy (int array[MAX][MAX], moves moviment)
{
	int i;
	
	for (i=0; i < (moviment.nVert-1); i++)
	{
		printf("Vertice = %d ->", moviment.vertActual + 1);
		moviment =  nextVert(array, moviment);
		printf(" Vertice = %d", moviment.vertActual + 1);
		printf(" / Percorido = %d\n", moviment.valueMoves);
		if (moviment.end == moviment.vertActual)
		{
			break;
		}
	}
	printf("Fim\n");
}

//Print Values Array
void printArray (int array[MAX][MAX], moves moviment)
{
	int i, j;
	
	for (i = 0; i< moviment.nVert ;i++)
	{
		for (j = 0; j < moviment.nVert; j++)
		{
			printf ("%d  ", array[i][j]);
		}
		printf("\n");
	}
	return;
}

//start Values of Stract the moviment.
moves startMoveGrafo_1 (moves moviment)
{
	moviment.valueMoves = 0;
	moviment.vertActual = 0;
	moviment.nVert = 5;
	moviment.end = -1;
	return moviment;
}

//start Values of Stract the moviment.
moves startMoveGrafo_2 (moves moviment)
{
	moviment.valueMoves = 0;
	moviment.vertActual = 0;
	moviment.nVert = 7;
	moviment.end = 6;
	return moviment;
}
