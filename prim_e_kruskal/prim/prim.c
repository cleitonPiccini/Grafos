#include <stdio.h>
#include "implement.c"


int main ()
{
	prim matrix_prim;
	int adjacente[MAX][MAX];
	
	matrix_prim = setPrim (matrix_prim);
	setValueGrafo_1(adjacente);
	matrix_prim = runPrim (matrix_prim, adjacente);
	
	/*caminho(matrix_dj, 1);
	caminho(matrix_dj, 2);
	caminho(matrix_dj, 3);
	caminho(matrix_dj, 4);
	caminho(matrix_dj, 5);
	caminho(matrix_dj, 6);*/
	printArvore(matrix_prim);
	return 0;
}
