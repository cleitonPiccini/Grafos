#include <stdio.h>
#include "implement.c"

int main ()
{
	welsh w;
	int adj[MAX][MAX];
	
	w = startWelshP(w, 11, 0, 0);
	
	setAdjacent(adj);
	
	w = runWelshP(w,adj);
	
	printWelshP(w);

	return 0;
}
