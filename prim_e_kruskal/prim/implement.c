#include <stdio.h>
#define MAX 50

typedef struct _matrix_p{
	int nome_vert;
	int dist;
	int nome_ant;
}matrix_p;

typedef struct _prim{
	int n_vert;
	int vert_atual;
	int vert_livre[MAX];
	int n_livres;
	matrix_p matriz_d[MAX];
}prim;

//Insert values in the prim.
prim setPrim (prim p)
{
	int i;
	
	p.n_vert = 8;
	p.vert_atual = 0;
	p.n_livres = p.n_vert;
	
	//Atribui valores para o vetor dos vertices livres.
	for (i = 0; i < p.n_vert; i++) p.vert_livre[i] = i;
	
	//Column 1
	p.matriz_d[0].nome_vert = 0;
	p.matriz_d[0].dist = 0;
	p.matriz_d[0].nome_ant = -1;
	//Column 2
	p.matriz_d[1].nome_vert = 1;
	p.matriz_d[1].dist = 1000;
	p.matriz_d[1].nome_ant = -1;
	//Column 3
	p.matriz_d[2].nome_vert = 2;
	p.matriz_d[2].dist = 1000;
	p.matriz_d[2].nome_ant = -1;
	//Column 4
	p.matriz_d[3].nome_vert = 3;
	p.matriz_d[3].dist = 1000;
	p.matriz_d[3].nome_ant = -1;
	//Column 5
	p.matriz_d[4].nome_vert = 4;
	p.matriz_d[4].dist = 1000;
	p.matriz_d[4].nome_ant = -1;
	//Column 6
	p.matriz_d[5].nome_vert = 5;
	p.matriz_d[5].dist = 1000;
	p.matriz_d[5].nome_ant = -1;
	//Column 7
	p.matriz_d[6].nome_vert = 6;
	p.matriz_d[6].dist = 1000;
	p.matriz_d[6].nome_ant = -1;
	//Column 7
	p.matriz_d[7].nome_vert = 7;
	p.matriz_d[7].dist = 1000;
	p.matriz_d[7].nome_ant = -1;
	
	return p;	
}

//Insert values in the adjacent array.
void setValueGrafo_1 (int arrayAdjacent[MAX][MAX])
{
	//Line 1
	arrayAdjacent[0][0] = 0;
	arrayAdjacent[0][1] = 2;
	arrayAdjacent[0][2] = 0;
	arrayAdjacent[0][3] = 6;
	arrayAdjacent[0][4] = 5;
	arrayAdjacent[0][5] = 0;
	arrayAdjacent[0][6] = 0;
	arrayAdjacent[0][7] = 0;
	//Line 2
	arrayAdjacent[1][0] = 2;
	arrayAdjacent[1][1] = 0;
	arrayAdjacent[1][2] = 7;
	arrayAdjacent[1][3] = 7;
	arrayAdjacent[1][4] = 0;
	arrayAdjacent[1][5] = 0;
	arrayAdjacent[1][6] = 0;
	arrayAdjacent[1][7] = 0;
	//Line 3
	arrayAdjacent[2][0] = 0;
	arrayAdjacent[2][1] = 7;
	arrayAdjacent[2][2] = 0;
	arrayAdjacent[2][3] = 0;
	arrayAdjacent[2][4] = 6;
	arrayAdjacent[2][5] = 2;
	arrayAdjacent[2][6] = 0;
	arrayAdjacent[2][7] = 0;
	//Line 4
	arrayAdjacent[3][0] = 6;
	arrayAdjacent[3][1] = 7;
	arrayAdjacent[3][2] = 0;
	arrayAdjacent[3][3] = 0;
	arrayAdjacent[3][4] = 0;
	arrayAdjacent[3][5] = 0;
	arrayAdjacent[3][6] = 0;
	arrayAdjacent[3][7] = 0;
	//Line 5
	arrayAdjacent[4][0] = 5;
	arrayAdjacent[4][1] = 0;
	arrayAdjacent[4][2] = 6;
	arrayAdjacent[4][3] = 0;
	arrayAdjacent[4][4] = 0;
	arrayAdjacent[4][5] = 0;
	arrayAdjacent[4][6] = 4;
	arrayAdjacent[4][7] = 5;
	//Line 6
	arrayAdjacent[5][0] = 0;
	arrayAdjacent[5][1] = 0;
	arrayAdjacent[5][2] = 2;
	arrayAdjacent[5][3] = 0;
	arrayAdjacent[5][4] = 0;
	arrayAdjacent[5][5] = 0;
	arrayAdjacent[5][6] = 4;
	arrayAdjacent[5][7] = 6;
	//Line 7
	arrayAdjacent[6][0] = 0;
	arrayAdjacent[6][1] = 0;
	arrayAdjacent[6][2] = 0;
	arrayAdjacent[6][3] = 0;
	arrayAdjacent[6][4] = 4;
	arrayAdjacent[6][5] = 4;
	arrayAdjacent[6][6] = 0;
	arrayAdjacent[6][7] = 1;
	//Line 8
	arrayAdjacent[7][0] = 0;
	arrayAdjacent[7][1] = 0;
	arrayAdjacent[7][2] = 0;
	arrayAdjacent[7][3] = 0;
	arrayAdjacent[7][4] = 5;
	arrayAdjacent[7][5] = 6;
	arrayAdjacent[7][6] = 1;
	arrayAdjacent[7][7] = 0;
	
	return;	
}

/* Atualiza o vetor dos vertices livres.
 * Controle dos vetores ainda livres. 
*/
prim livres (prim p)
{
	int i = 0,j = 0;
	
	//Percore o vetor dos livres e elimina o valor do vertice atual dos livres.
	while (i <= p.n_livres)
	{
		if (p.vert_livre[i] == p.vert_atual) i++;
		p.vert_livre[j] = p.vert_livre[i];
		j++;
		i++;
	}
	
	p.n_livres--;//Decrementa o numero de vertices livres.

	return p; 
}

/* Faz uma busca na matriz prim (somente nos vertices ainda livres) e 
 * encontra o vertice com o menor valor de distancia.*/
int searchLess (prim p)
{
	int i=0, menor, retorno;
	
	menor = p.matriz_d[p.vert_livre[i]].dist;
	retorno = p.vert_livre[i];
	
	//Percore a matriz prim para achar o vertice com a menor distancia para ser o vertice atual 
	//Percore somente os vertices livres.
	for (i=1; i < p.n_livres; i++)
	{
		if(menor > p.matriz_d[p.vert_livre[i]].dist ) 
		{
			menor = p.matriz_d[p.vert_livre[i]].dist;
			retorno = p.vert_livre[i];
		}
	}
	return retorno;
}

/* Busca na tabela adjacente os valores das arestas interligadas ao vertice atual
 * caso o valor da aresta interligada ao vertice atual seja menor ai troca o valor na matriz do prim.*/ 
prim searchAdj (prim p, int arrayAdj[MAX][MAX])
{
	int i;
	
	for (i = 0; i < p.n_livres; i++) //Incrementa apenas a quantidade de vertices livres.
	{
		
		if(arrayAdj[p.vert_atual][p.vert_livre[i]] != 0)//Desconsidera os valores zero.
		{
			/* Se o valor na matriz adjacente for menor que a distancia atual do vertice
			 * entao subistitui seus valores. */
			if (arrayAdj[p.vert_atual][p.vert_livre[i]] < p.matriz_d[p.vert_livre[i]].dist)
			{
				//Atualiza o nome do vertice anterior
				p.matriz_d[p.vert_livre[i]].nome_ant = p.matriz_d[p.vert_atual].nome_vert;
				//Atualiza a distancia na matriz prim.
				p.matriz_d[p.vert_livre[i]].dist = arrayAdj[p.vert_atual][p.vert_livre[i]];// + p.matriz_d[p.vert_atual].dist;
			}
		}
	}
	return p;
}

// Faz print na tela do vertice atual, vertices livres e a matriz prim.
void printP (prim p)
{
	int i;
	
	for (i = 0; i < p.n_livres; i++) printf("%d,", p.matriz_d[p.vert_livre[i]].nome_vert);
	printf("\n");
	printf("\n");	
	printf("|");
	for (i = 0; i < p.n_vert; i++) printf("%d ", p.matriz_d[i].nome_vert);
	printf("|");
	printf("\n");
	printf("|");
	for (i = 0; i < p.n_vert; i++) printf("%d ", p.matriz_d[i].dist);
	printf("|");
	printf("\n");
	printf("|");
	for (i = 0; i < p.n_vert; i++) printf("%d ", p.matriz_d[i].nome_ant);
	printf("|");
	printf("\n");
	printf("\n");
	
}

// Roda as funcoes do algoritmo Prim :
prim runPrim (prim p, int arrayAdj[MAX][MAX])
{
	int i;
	
	for(i = 0; i < p.n_vert; i++)
	{
		p = searchAdj(p, arrayAdj);//
		p=livres(p);//Atualiza os vetores livres
		p.vert_atual = searchLess(p);//Atualiza o novo vertice.
	} 
	printP(p);//mostra a matriz no terminal.
	return p;
} 

/* Mostra a arvore de  menor caminho do grafo. */
void printArvore (prim p)
{
	int indice;
	
	for (indice = 0; indice < p.n_vert; indice++) 
	{
		if (p.matriz_d[indice].nome_ant >= 0 ) printf("(%d, %d) ", p.matriz_d[indice].nome_ant, p.matriz_d[indice].nome_vert);
	}
	printf("\n");
}

