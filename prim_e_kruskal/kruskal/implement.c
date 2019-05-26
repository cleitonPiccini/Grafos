#include <stdio.h>
#include <stdlib.h>

//estrutura da matriz dos vertices para o algoritmo de Kruskal.
typedef struct _mat_vertice {
	int * ver;
	int * p;
} mat_vertice;

//estrutura da matriz das arrestas para o algoritmo de Kruskal.
typedef struct _mat_arresta {
	int * pe;
	int * vi;
	int * vj;
} mat_aresta;

//estrutura do algoritmo de Kruskal.
typedef struct _kruskal {
	int n_vert;
	int n_arrestas;
	int * menor_i;
	int * menor_j;
	mat_vertice vert;
	mat_aresta arrest;
}kruskal; 

//Atribui os valores iniciais das matrizes que o algoritmo usa como base.
kruskal start_kruskal (kruskal k){
	
	int i;
	
	k.n_vert = 8;
	k.n_arrestas = 	11;
	k.vert.ver = (int*) malloc (k.n_vert * sizeof (int));
	k.vert.p = (int*) malloc (k.n_vert * sizeof (int));
	
	k.arrest.pe = malloc (k.n_arrestas * sizeof (int));
	k.arrest.vi = malloc (k.n_arrestas * sizeof (int));
	k.arrest.vj = malloc (k.n_arrestas * sizeof (int));
	
	k.menor_i = malloc (2 * (k.n_arrestas * sizeof (int)));
	k.menor_j = malloc (2 * (k.n_arrestas * sizeof (int)));
	
	//nome dos vertices na matriz de vertices.
	for (i = 0; i < k.n_vert ; i++){
		k.vert.ver[i] = i;
	}
	//valor -1 para todos os vertices.
	for (i = 0; i < k.n_vert ; i++){
		k.vert.p[i] = -1;
	}
	
	//Atribuindo valores para o matriz das arrestas e a interligacao dos vertices.//Arresta 1.
	//Arresta 1.
	k.arrest.pe[0] = 2;
	k.arrest.vi[0] = 6;
	k.arrest.vj[0] = 7;
	//Arresta 2.
	k.arrest.pe[1] = 3;
	k.arrest.vi[1] = 0;
	k.arrest.vj[1] = 1;
	//Arresta 3.
	k.arrest.pe[2] = 3;
	k.arrest.vi[2] = 0;
	k.arrest.vj[2] = 3;
	//Arresta 4.
	k.arrest.pe[3] = 4;
	k.arrest.vi[3] = 0;
	k.arrest.vj[3] = 2;
	//Arresta 5.
	k.arrest.pe[4] = 4;
	k.arrest.vi[4] = 5;
	k.arrest.vj[4] = 6;
	//Arresta 6.
	k.arrest.pe[5] = 7;
	k.arrest.vi[5] = 4;
	k.arrest.vj[5] = 6;
	//Arresta 7.
	k.arrest.pe[6] = 7;
	k.arrest.vi[6] = 4;
	k.arrest.vj[6] = 7;
	//Arresta 8.
	k.arrest.pe[7] = 7;
	k.arrest.vi[7] = 5;
	k.arrest.vj[7] = 7;
	//Arresta 9.
	k.arrest.pe[8] = 8;
	k.arrest.vi[8] = 2;
	k.arrest.vj[8] = 4;
	//Arresta 10.
	k.arrest.pe[9] = 8;
	k.arrest.vi[9] = 2;
	k.arrest.vj[9] = 5;
	//Arresta 11.
	k.arrest.pe[10] = 8;
	k.arrest.vi[10] = 3;
	k.arrest.vj[10] = 5;
	
	return k;
}

//Atribui os valores para a matriz adjacente do grafo.
void start_adjacente (int *adj, int n_verts){
	
	int *aux = NULL;
	
	aux = (int *) malloc (n_verts * (n_verts * sizeof (int)));
	adj = aux;
	//Vertice 0 linha 1.
	adj[0] = 0;
	adj[1] = 3;
	adj[2] = 4;
	adj[3] = 3;
	adj[4] = 0;
	adj[5] = 0;
	adj[6] = 0;
	adj[7] = 0;
	//Vertice 1 linha 2.
	adj[8] = 3;
	adj[9] = 0;
	adj[10] = 0;
	adj[11] = 0;
	adj[12] = 0;
	adj[13] = 0;
	adj[14] = 0;
	adj[15] = 0;
	//Vertice 2 linha 3.
	adj[16] = 4;
	adj[17] = 0;
	adj[18] = 0;
	adj[19] = 0;
	adj[20] = 8;
	adj[21] = 8;
	adj[22] = 0;
	adj[23] = 0;
	//Vertice 3 linha 4.
	adj[24] = 3;
	adj[25] = 0;
	adj[26] = 0;
	adj[27] = 0;
	adj[28] = 0;
	adj[29] = 8;
	adj[30] = 0;
	adj[31] = 0;
	//Vertice 4 linha 5.
	adj[32] = 0;
	adj[33] = 0;
	adj[34] = 8;
	adj[35] = 0;
	adj[36] = 0;
	adj[37] = 0;
	adj[38] = 7;
	adj[39] = 7;
	//Vertice 5 linha 6.
	adj[40] = 0;
	adj[41] = 0;
	adj[42] = 8;
	adj[43] = 8;
	adj[44] = 0;
	adj[45] = 0;
	adj[46] = 4;
	adj[47] = 7;
	//Vertice 6 linha 7.
	adj[48] = 0;
	adj[49] = 0;
	adj[50] = 0;
	adj[51] = 0;
	adj[52] = 7;
	adj[53] = 4;
	adj[54] = 0;
	adj[55] = 2;
	//Vertice 7 linha 8.
	adj[56] = 0;
	adj[57] = 0;
	adj[58] = 0;
	adj[59] = 0;
	adj[60] = 7;
	adj[61] = 7;
	adj[62] = 2;
	adj[63] = 0;	
}

//Printa as matrizes que o algoritmo usa como base.
void printKruskal (kruskal k)
{
	int i;
	
	printf("pe | ");
	for (i = 0; i < k.n_arrestas; i++)
	{
		printf ("%d ", k.arrest.pe[i]);
	}
	printf("\n");
	
	printf("vi | ");
	for (i = 0; i < k.n_arrestas; i++)
	{
		printf ("%d ", k.arrest.vi[i]);
	}
	printf("\n");
	
	printf("vj | ");
	for (i = 0; i < k.n_arrestas; i++)
	{
		printf ("%d ", k.arrest.vj[i]);
	}
	printf("\n\n");
	printf("ver | ");
	for (i = 0; i < k.n_vert; i++)
	{
		printf (" %d ", k.vert.ver[i]);
	}
	printf("\n");
	
	printf("p   | ");
	for (i = 0; i < k.n_vert; i++)
	{
		printf ("%d ", k.vert.p[i]);
	}
	printf("\n\n");
	return;
}

//Printa na tela o resultado do algoritmo de Kruskal.
void printGrafo (kruskal k, int novo_vert)
{
	int i;
	for (i = 0; i < novo_vert; i++)
	{
		printf("(%d,%d) ", k.menor_i[i],k.menor_j[i]);
	}
	printf ("\n");
	return;
}

//Retorna o vertice pai de acordo como vertice de origem (atributo origem).
int vertPai (kruskal k, int origem)
{
	if (k.vert.p[origem] < 0) return k.vert.ver[origem];
	return vertPai(k,k.vert.p[origem]);
}

// Roda o algoritmo de Kruskal.
kruskal runKruskal (kruskal k)
{
	int arresta, i, j, novo_vert;
	
	printKruskal(k);
	
	for (arresta = 0, novo_vert = 0 ; arresta < k.n_arrestas && novo_vert < k.n_vert-1; arresta++)
	{
		//Encrontra o vertice vi pai da arvore.
		i = vertPai(k,k.vert.ver[k.arrest.vi[arresta]]);
		//Encrontra o vertice vj pai da arvore.
		j = vertPai(k,k.vert.ver[k.arrest.vj[arresta]]);
		
		//Descarta as arrestas se os vertices pais forem iguais.
		if (k.vert.ver[i] == k.vert.ver[j])continue;
		
		//Se o vertice vi tiver uma arvore maior que o vertice vj (quanto menor o numero no p maior a arvore).
		if (k.vert.p[i] < k.vert.p[j])
		{
			// vertice vi recebe a arvore contida em vj e se torna pai da arvore de vi e vj.
			k.vert.p[i] = k.vert.p[i] + k.vert.p[j];
			// vertice vj recebe como pai o vertice pai da arvore vi.
			k.vert.p[j] = k.vert.ver[i]; 
			// atribui os vertices ao novo grafo com a menor arvore geradora.
			k.menor_i[novo_vert] = k.vert.ver[k.arrest.vi[arresta]];
			k.menor_j[novo_vert] = k.vert.ver[k.arrest.vj[arresta]];
			novo_vert++;
			continue;
		}
		//Se o vertice vj tiver uma arvore maior que o vertice vi (quanto menor o numero no p maior a arvore).
		if (k.vert.p[j] < k.vert.p[i])
		{
			// vertice vj recebe a arvore contida em vi e se torna pai da arvore de vi e vj.
			k.vert.p[j] = k.vert.p[j] + k.vert.p[i];
			// vertice vi recebe como pai o vertice pai da arvore vj.
			k.vert.p[i] = k.vert.ver[j]; 
			// atribui os vertices ao novo grafo com a menor arvore geradora.
			k.menor_i[novo_vert] = k.vert.ver[k.arrest.vi[arresta]];
			k.menor_j[novo_vert] = k.vert.ver[k.arrest.vj[arresta]];
			novo_vert++;
			continue;
		}
		//Se o vertice vj tiver a arvore igual o vertice vi.
		if (k.vert.p[j] == k.vert.p[i])
		{
			// vertice vj recebe a arvore contida em vi e se torna pai da arvore de vi e vj.
			k.vert.p[j] = k.vert.p[j] + k.vert.p[i];
			// vertice vi recebe como pai o vertice pai da arvore vj.
			k.vert.p[i] = k.vert.ver[j];
			// atribui os vertices ao novo grafo com a menor arvore geradora.
			k.menor_i[novo_vert] = k.vert.ver[k.arrest.vi[arresta]];
			k.menor_j[novo_vert] = k.vert.ver[k.arrest.vj[arresta]];
			novo_vert++;
			continue;
		}
	}
	printKruskal(k);
	printGrafo (k,novo_vert);
	
	return k;
}

