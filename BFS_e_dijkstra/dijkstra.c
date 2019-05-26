#include <stdio.h>
#include "implement.c"


int main ()
{
	dijkstra matrix_dj;
	int adjacente[MAX][MAX];
	
	matrix_dj = setDijkstra(matrix_dj);
	setValueGrafo_1(adjacente);
	matrix_dj = runDijkstra(matrix_dj, adjacente);
	
	caminho(matrix_dj, 'B');
	caminho(matrix_dj, 'C');
	caminho(matrix_dj, 'D');
	caminho(matrix_dj, 'E');
	caminho(matrix_dj, 'F');
	caminho(matrix_dj, 'G');
	return 0;
}
