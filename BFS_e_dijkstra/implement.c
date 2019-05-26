#include <stdio.h>
#define MAX 50

typedef struct _matrix_d{
	char nome_vert;
	int dist;
	char nome_ant;
	int n_ant;
}matrix_d;

typedef struct _dijkstra{
	int n_vert;
	int vert_atual;
	int vert_livre[MAX];
	int n_livres;
	matrix_d matriz_d[MAX];
}dijkstra;

typedef struct _matrix_bfs{
	char nome_vert;
	int dist;
	
}matrix_bfs;

//Insert values in the adjacent array.
dijkstra setDijkstra (dijkstra dk)
{
	int i;
	
	dk.n_vert = 7;
	dk.vert_atual = 0;
	dk.n_livres = dk.n_vert;
	
	//Atribui valores para o vetor dos vertices livres.
	for (i = 0; i < dk.n_vert; i++) dk.vert_livre[i] = i;
	
	//Column 1
	dk.matriz_d[0].nome_vert = 'A';
	dk.matriz_d[0].dist = 0;
	dk.matriz_d[0].nome_ant = '0';
	dk.matriz_d[0].n_ant = 1000;
	//Column 2
	dk.matriz_d[1].nome_vert = 'B';
	dk.matriz_d[1].dist = 1000;
	dk.matriz_d[1].nome_ant = '0';
	dk.matriz_d[0].n_ant = 1000;
	//Column 3
	dk.matriz_d[2].nome_vert = 'C';
	dk.matriz_d[2].dist = 1000;
	dk.matriz_d[2].nome_ant = '0';
	dk.matriz_d[0].n_ant = 1000;
	//Column 4
	dk.matriz_d[3].nome_vert = 'D';
	dk.matriz_d[3].dist = 1000;
	dk.matriz_d[3].nome_ant = '0';
	dk.matriz_d[0].n_ant = 1000;
	//Column 5
	dk.matriz_d[4].nome_vert = 'E';
	dk.matriz_d[4].dist = 1000;
	dk.matriz_d[4].nome_ant = '0';
	dk.matriz_d[0].n_ant = 1000;
	//Column 6
	dk.matriz_d[5].nome_vert = 'F';
	dk.matriz_d[5].dist = 1000;
	dk.matriz_d[5].nome_ant = '0';
	dk.matriz_d[0].n_ant = 1000;
	//Column 7
	dk.matriz_d[6].nome_vert = 'G';
	dk.matriz_d[6].dist = 1000;
	dk.matriz_d[6].nome_ant = '0';
	dk.matriz_d[0].n_ant = 1000;
	
	return dk;	
}

//Insert values in the adjacent array.
void setValueGrafo_1 (int arrayAdjacent[MAX][MAX])
{
	//Line 1
	arrayAdjacent[0][0] = 0;
	arrayAdjacent[0][1] = 7;
	arrayAdjacent[0][2] = 0;
	arrayAdjacent[0][3] = 5;
	arrayAdjacent[0][4] = 0;
	arrayAdjacent[0][5] = 0;
	arrayAdjacent[0][6] = 0;
	//Line 2
	arrayAdjacent[1][0] = 7;
	arrayAdjacent[1][1] = 0;
	arrayAdjacent[1][2] = 8;
	arrayAdjacent[1][3] = 9;
	arrayAdjacent[1][4] = 7;
	arrayAdjacent[1][5] = 0;
	arrayAdjacent[1][6] = 0;
	//Line 3
	arrayAdjacent[2][0] = 0;
	arrayAdjacent[2][1] = 8;
	arrayAdjacent[2][2] = 0;
	arrayAdjacent[2][3] = 0;
	arrayAdjacent[2][4] = 5;
	arrayAdjacent[2][5] = 0;
	arrayAdjacent[2][6] = 0;
	//Line 4
	arrayAdjacent[3][0] = 5;
	arrayAdjacent[3][1] = 9;
	arrayAdjacent[3][2] = 0;
	arrayAdjacent[3][3] = 0;
	arrayAdjacent[3][4] = 15;
	arrayAdjacent[3][5] = 6;
	arrayAdjacent[3][6] = 0;
	//Line 5
	arrayAdjacent[4][0] = 0;
	arrayAdjacent[4][1] = 7;
	arrayAdjacent[4][2] = 5;
	arrayAdjacent[4][3] = 15;
	arrayAdjacent[4][4] = 0;
	arrayAdjacent[4][5] = 8;
	arrayAdjacent[4][6] = 9;
	//Line 6
	arrayAdjacent[5][0] = 0;
	arrayAdjacent[5][1] = 0;
	arrayAdjacent[5][2] = 0;
	arrayAdjacent[5][3] = 6;
	arrayAdjacent[5][4] = 8;
	arrayAdjacent[5][5] = 0;
	arrayAdjacent[5][6] = 11;
	//Line 7
	arrayAdjacent[6][0] = 0;
	arrayAdjacent[6][1] = 0;
	arrayAdjacent[6][2] = 0;
	arrayAdjacent[6][3] = 0;
	arrayAdjacent[6][4] = 9;
	arrayAdjacent[6][5] = 11;
	arrayAdjacent[6][6] = 0;
	
	return;	
}

/* Atualiza o vetor dos vertices livres.
 * Controle dos vetores ainda livres. 
*/
dijkstra livres (dijkstra dk)
{
	int i = 0,j = 0;
	
	//Percore o vetor dos livres e elimina o valor do vertice atual dos livres.
	while (i <= dk.n_livres)
	{
		if (dk.vert_livre[i] == dk.vert_atual) i++;
		dk.vert_livre[j] = dk.vert_livre[i];
		j++;
		i++;
	}
	
	dk.n_livres--;//Decrementa o numero de vertices livres.

	return dk; 
}

/* Faz uma busca na matriz dijkstra (somente nos vertices ainda livres) e 
 * encontra o vertice com o menor valor de distancia.*/
int searchLess (dijkstra dk)
{
	int i=0, menor, retorno;
	
	menor = dk.matriz_d[dk.vert_livre[i]].dist;
	retorno = dk.vert_livre[i];
	
	//Percore a matriz dijkstra para achar o vertice com a menor distancia para ser o vertice atual 
	//Percore somente os vertices livres.
	for (i=1; i < dk.n_livres; i++)
	{
		if(menor > dk.matriz_d[dk.vert_livre[i]].dist ) 
		{
			menor = dk.matriz_d[dk.vert_livre[i]].dist;
			retorno = dk.vert_livre[i];
		}
	}
	return retorno;
}

/* Busca na tabela adjacente os valores das arestas interligadas ao vertice atual
 * caso o valor da aresta interligada ao vertice atual seja menor ai troca o valor na matriz do dijkstra.*/ 
dijkstra searchAdj (dijkstra dk, int arrayAdj[MAX][MAX])
{
	int i;
	
	for (i = 0; i < dk.n_livres; i++) //Incrementa apenas a quantidade de vertices livres.
	{
		
		if(arrayAdj[dk.vert_atual][dk.vert_livre[i]] != 0)//Desconsidera os valores zero.
		{
			/* Se o valor na matriz adjacente mais a distancia do vertice atual for menor que a distancia atual do vertice
			 * entao subistitui seus valores. */
			if (arrayAdj[dk.vert_atual][dk.vert_livre[i]] + dk.matriz_d[dk.vert_atual].dist < dk.matriz_d[dk.vert_livre[i]].dist)
			{
				//Atualiza o nome do vertice anterior
				dk.matriz_d[dk.vert_livre[i]].nome_ant = dk.matriz_d[dk.vert_atual].nome_vert;
				//Atualiza o endereco do vertice anterior.
				dk.matriz_d[dk.vert_livre[i]].n_ant = dk.vert_atual;
				//Atualiza a distancia na matriz dijkstra.
				dk.matriz_d[dk.vert_livre[i]].dist = arrayAdj[dk.vert_atual][dk.vert_livre[i]] + dk.matriz_d[dk.vert_atual].dist;
			}
		}
	}
	return dk;
}

// Faz print na tela do vertice atual, vertices livres e a matriz dijkstra.
void printDk (dijkstra dk)
{
	int i;
	
	//printf("Vertice Atual : %c \n", dk.matriz_d[dk.vert_atual].nome_vert);	
	//printf("Vertices Livres : ");
	
	for (i = 0; i < dk.n_livres; i++) printf("%c,", dk.matriz_d[dk.vert_livre[i]].nome_vert);
	printf("\n");
	printf("\n");	
	printf("|");
	for (i = 0; i < dk.n_vert; i++) printf("%c ", dk.matriz_d[i].nome_vert);
	printf("|");
	printf("\n");
	printf("|");
	for (i = 0; i < dk.n_vert; i++) printf("%d ", dk.matriz_d[i].dist);
	printf("|");
	printf("\n");
	printf("|");
	for (i = 0; i < dk.n_vert; i++) printf("%c ", dk.matriz_d[i].nome_ant);
	printf("|");
	printf("\n");
	printf("\n");
	
}

// Roda as funcoes do algoritmo de Dijkstra :
dijkstra runDijkstra (dijkstra dk, int arrayAdj[MAX][MAX])
{
	int i;
	
	for(i = 0; i < dk.n_vert; i++)
	{
		dk = searchAdj(dk, arrayAdj);//
		//printDk(dk);//mostra a matriz no terminal.
		dk=livres(dk);//Atualiza os vetores livres
		dk.vert_atual = searchLess(dk);//Atualiza o novo vertice.
	} 
	printDk(dk);//mostra a matriz no terminal.
	return dk;
} 

void buscaCaminho (dijkstra dk, int end)
{
	if (dk.matriz_d[end].nome_ant == '0')
	 {
		 printf("%c :",dk.matriz_d[end].nome_vert);
		 printf(" %d",dk.matriz_d[end].dist);	
		 return;
	 }
	buscaCaminho(dk, dk.matriz_d[end].n_ant);
	printf(" -> %c : %d",dk.matriz_d[end].nome_vert, dk.matriz_d[end].dist);	
}

/* Mostra o menor caminho entre um vertice e outro. */
void caminho (dijkstra dk, char end )
{
	int n_end;
	
	//encontra posicao do vertice destino na matriz dijkstra.
	for (n_end = 0; n_end < dk.n_vert; n_end++)
	{
		if (dk.matriz_d[n_end].nome_vert == end) break;
	}
	
	buscaCaminho(dk, n_end);
	printf("\n");
	
} 

//

void setValueGrafo_2(int array[MAX][MAX])
{
	//Linha 1
	array[0][0] = 0;//a
	array[0][1] = 1;//b
	array[0][2] = 0;//c
	array[0][3] = 0;//d
	array[0][4] = 0;//e
	array[0][5] = 0;//f
	array[0][6] = 0;//g
	array[0][7] = 0;//h
	array[0][8] = 0;//i
	array[0][9] = 0;//j
	array[0][10] = 1;//k
	array[0][11] = 0;//l
	array[0][12] = 0;//m
	array[0][13] = 0;//n
	array[0][14] = 0;//o
	array[0][15] = 0;//p
	array[0][16] = 0;//q
	array[0][17] = 0;//r
	array[0][18] = 0;//s
	array[0][19] = 0;//t
	array[0][20] = 0;//z
	//Linha 2
	array[1][0] = 1;//a
	array[1][1] = 0;//b
	array[1][2] = 1;//c
	array[1][3] = 1;//d
	array[1][4] = 0;//e
	array[1][5] = 0;//f
	array[1][6] = 0;//g
	array[1][7] = 0;//h
	array[1][8] = 0;//i
	array[1][9] = 0;//j
	array[1][10] = 0;//k
	array[1][11] = 0;//l
	array[1][12] = 0;//m
	array[1][13] = 0;//n
	array[1][14] = 0;//o
	array[1][15] = 0;//p
	array[1][16] = 0;//q
	array[1][17] = 0;//r
	array[1][18] = 0;//s
	array[1][19] = 0;//t
	array[1][20] = 0;//z
	//Linha 3
	array[2][0] = 0;//a
	array[2][1] = 1;//b
	array[2][2] = 0;//c
	array[2][3] = 0;//d
	array[2][4] = 1;//e
	array[2][5] = 0;//f
	array[2][6] = 0;//g
	array[2][7] = 0;//h
	array[2][8] = 0;//i
	array[2][9] = 0;//j
	array[2][10] = 0;//k
	array[2][11] = 0;//l
	array[2][12] = 0;//m
	array[2][13] = 0;//n
	array[2][14] = 0;//o
	array[2][15] = 0;//p
	array[2][16] = 0;//q
	array[2][17] = 0;//r
	array[2][18] = 0;//s
	array[2][19] = 0;//t
	array[2][20] = 0;//z
	//Linha 4
	array[3][0] = 0;//a
	array[3][1] = 1;//b
	array[3][2] = 0;//c
	array[3][3] = 0;//d
	array[3][4] = 1;//e
	array[3][5] = 0;//f
	array[3][6] = 0;//g
	array[3][7] = 0;//h
	array[3][8] = 0;//i
	array[3][9] = 0;//j
	array[3][10] = 0;//k
	array[3][11] = 1;//l
	array[3][12] = 0;//m
	array[3][13] = 0;//n
	array[3][14] = 0;//o
	array[3][15] = 0;//p
	array[3][16] = 0;//q
	array[3][17] = 0;//r
	array[3][18] = 0;//s
	array[3][19] = 0;//t
	array[3][20] = 0;//z
	//Linha 5
	array[4][0] = 0;//a
	array[4][1] = 0;//b
	array[4][2] = 1;//c
	array[4][3] = 1;//d
	array[4][4] = 0;//e
	array[4][5] = 1;//f
	array[4][6] = 1;//g
	array[4][7] = 0;//h
	array[4][8] = 0;//i
	array[4][9] = 0;//j
	array[4][10] = 0;//k
	array[4][11] = 0;//l
	array[4][12] = 0;//m
	array[4][13] = 0;//n
	array[4][14] = 0;//o
	array[4][15] = 0;//p
	array[4][16] = 0;//q
	array[4][17] = 0;//r
	array[4][18] = 0;//s
	array[4][19] = 0;//t
	array[4][20] = 0;//z
	//Linha 6 f
	array[5][0] = 0;//a
	array[5][1] = 0;//b
	array[5][2] = 0;//c
	array[5][3] = 0;//d
	array[5][4] = 1;//e
	array[5][5] = 0;//f
	array[5][6] = 0;//g
	array[5][7] = 1;//h
	array[5][8] = 0;//i
	array[5][9] = 0;//j
	array[5][10] = 0;//k
	array[5][11] = 0;//l
	array[5][12] = 0;//m
	array[5][13] = 0;//n
	array[5][14] = 0;//o
	array[5][15] = 0;//p
	array[5][16] = 0;//q
	array[5][17] = 0;//r
	array[5][18] = 0;//s
	array[5][19] = 0;//t
	array[5][20] = 0;//z
	//Linha 7 g
	array[6][0] = 0;//a
	array[6][1] = 0;//b
	array[6][2] = 0;//c
	array[6][3] = 0;//d
	array[6][4] = 1;//e
	array[6][5] = 0;//f
	array[6][6] = 0;//g
	array[6][7] = 0;//h
	array[6][8] = 1;//i
	array[6][9] = 0;//j
	array[6][10] = 0;//k
	array[6][11] = 0;//l
	array[6][12] = 0;//m
	array[6][13] = 0;//n
	array[6][14] = 0;//o
	array[6][15] = 0;//p
	array[6][16] = 0;//q
	array[6][17] = 0;//r
	array[6][18] = 0;//s
	array[6][19] = 0;//t
	array[6][20] = 0;//z
	//Linha 8 h
	array[7][0] = 0;//a
	array[7][1] = 0;//b
	array[7][2] = 0;//c
	array[7][3] = 0;//d
	array[7][4] = 0;//e
	array[7][5] = 1;//f
	array[7][6] = 0;//g
	array[7][7] = 0;//h
	array[7][8] = 1;//i
	array[7][9] = 1;//j
	array[7][10] = 0;//k
	array[7][11] = 0;//l
	array[7][12] = 0;//m
	array[7][13] = 0;//n
	array[7][14] = 0;//o
	array[7][15] = 0;//p
	array[7][16] = 0;//q
	array[7][17] = 0;//r
	array[7][18] = 0;//s
	array[7][19] = 0;//t
	array[7][20] = 0;//z
	//Linha 9 i
	array[8][0] = 0;//a
	array[8][1] = 0;//b
	array[8][2] = 0;//c
	array[8][3] = 0;//d
	array[8][4] = 0;//e
	array[8][5] = 0;//f
	array[8][6] = 1;//g
	array[8][7] = 1;//h
	array[8][8] = 0;//i
	array[8][9] = 1;//j
	array[8][10] = 0;//k
	array[8][11] = 0;//l
	array[8][12] = 0;//m
	array[8][13] = 0;//n
	array[8][14] = 0;//o
	array[8][15] = 0;//p
	array[8][16] = 0;//q
	array[8][17] = 0;//r
	array[8][18] = 0;//s
	array[8][19] = 0;//t
	array[8][20] = 0;//z
	//Linha 10 j
	array[9][0] = 0;//a
	array[9][1] = 0;//b
	array[9][2] = 0;//c
	array[9][3] = 0;//d
	array[9][4] = 0;//e
	array[9][5] = 0;//f
	array[9][6] = 0;//g
	array[9][7] = 1;//h
	array[9][8] = 1;//i
	array[9][9] = 0;//j
	array[9][10] = 0;//k
	array[9][11] = 0;//l
	array[9][12] = 0;//m
	array[9][13] = 0;//n
	array[9][14] = 0;//o
	array[9][15] = 0;//p
	array[9][16] = 0;//q
	array[9][17] = 0;//r
	array[9][18] = 0;//s
	array[9][19] = 0;//t
	array[9][20] = 1;//z
	//Linha 11 k
	array[10][0] = 1;//a
	array[10][1] = 0;//b
	array[10][2] = 0;//c
	array[10][3] = 0;//d
	array[10][4] = 0;//e
	array[10][5] = 0;//f
	array[10][6] = 0;//g
	array[10][7] = 0;//h
	array[10][8] = 0;//i
	array[10][9] = 0;//j
	array[10][10] = 0;//k
	array[10][11] = 1;//l
	array[10][12] = 1;//m
	array[10][13] = 1;//n
	array[10][14] = 0;//o
	array[10][15] = 0;//p
	array[10][16] = 0;//q
	array[10][17] = 0;//r
	array[10][18] = 0;//s
	array[10][19] = 0;//t
	array[10][20] = 0;//z
	//Linha 12 l
	array[11][0] = 0;//a
	array[11][1] = 0;//b
	array[11][2] = 0;//c
	array[11][3] = 1;//d
	array[11][4] = 0;//e
	array[11][5] = 0;//f
	array[11][6] = 0;//g
	array[11][7] = 0;//h
	array[11][8] = 0;//i
	array[11][9] = 0;//j
	array[11][10] = 1;//k
	array[11][11] = 0;//l
	array[11][12] = 0;//m
	array[11][13] = 0;//n
	array[11][14] = 1;//o
	array[11][15] = 0;//p
	array[11][16] = 0;//q
	array[11][17] = 0;//r
	array[11][18] = 0;//s
	array[11][19] = 0;//t
	array[11][20] = 0;//z
	//Linha 13 m
	array[12][0] = 0;//a
	array[12][1] = 0;//b
	array[12][2] = 0;//c
	array[12][3] = 0;//d
	array[12][4] = 0;//e
	array[12][5] = 0;//f
	array[12][6] = 0;//g
	array[12][7] = 0;//h
	array[12][8] = 0;//i
	array[12][9] = 0;//j
	array[12][10] = 1;//k
	array[12][11] = 0;//l
	array[12][12] = 0;//m
	array[12][13] = 0;//n
	array[12][14] = 1;//o
	array[12][15] = 0;//p
	array[12][16] = 0;//q
	array[12][17] = 0;//r
	array[12][18] = 0;//s
	array[12][19] = 0;//t
	array[12][20] = 0;//z
	//Linha 14 n
	array[13][0] = 0;//a
	array[13][1] = 0;//b
	array[13][2] = 0;//c
	array[13][3] = 0;//d
	array[13][4] = 0;//e
	array[13][5] = 0;//f
	array[13][6] = 0;//g
	array[13][7] = 0;//h
	array[13][8] = 0;//i
	array[13][9] = 0;//j
	array[13][10] = 1;//k
	array[13][11] = 0;//l
	array[13][12] = 0;//m
	array[13][13] = 0;//n
	array[13][14] = 1;//o
	array[13][15] = 0;//p
	array[13][16] = 0;//q
	array[13][17] = 0;//r
	array[13][18] = 0;//s
	array[13][19] = 0;//t
	array[13][20] = 0;//z
	//Linha 15 o
	array[14][0] = 0;//a
	array[14][1] = 0;//b
	array[14][2] = 0;//c
	array[14][3] = 0;//d
	array[14][4] = 0;//e
	array[14][5] = 0;//f
	array[14][6] = 0;//g
	array[14][7] = 0;//h
	array[14][8] = 0;//i
	array[14][9] = 0;//j
	array[14][10] = 0;//k
	array[14][11] = 1;//l
	array[14][12] = 1;//m
	array[14][13] = 1;//n
	array[14][14] = 0;//o
	array[14][15] = 1;//p
	array[14][16] = 0;//q
	array[14][17] = 1;//r
	array[14][18] = 0;//s
	array[14][19] = 0;//t
	array[14][20] = 0;//z
	//Linha 16 p
	array[15][0] = 0;//a
	array[15][1] = 0;//b
	array[15][2] = 0;//c
	array[15][3] = 0;//d
	array[15][4] = 0;//e
	array[15][5] = 0;//f
	array[15][6] = 0;//g
	array[15][7] = 0;//h
	array[15][8] = 0;//i
	array[15][9] = 0;//j
	array[15][10] = 0;//k
	array[15][11] = 0;//l
	array[15][12] = 0;//m
	array[15][13] = 0;//n
	array[15][14] = 1;//o
	array[15][15] = 0;//p
	array[15][16] = 1;//q
	array[15][17] = 0;//r
	array[15][18] = 0;//s
	array[15][19] = 0;//t
	array[15][20] = 0;//z
	//Linha 17 q
	array[16][0] = 0;//a
	array[16][1] = 0;//b
	array[16][2] = 0;//c
	array[16][3] = 0;//d
	array[16][4] = 0;//e
	array[16][5] = 0;//f
	array[16][6] = 0;//g
	array[16][7] = 0;//h
	array[16][8] = 0;//i
	array[16][9] = 0;//j
	array[16][10] = 0;//k
	array[16][11] = 0;//l
	array[16][12] = 0;//m
	array[16][13] = 0;//n
	array[16][14] = 0;//o
	array[16][15] = 1;//p
	array[16][16] = 0;//q
	array[16][17] = 1;//r
	array[16][18] = 1;//s
	array[16][19] = 1;//t
	array[16][20] = 0;//z
	//Linha 18 r
	array[17][0] = 0;//a
	array[17][1] = 0;//b
	array[17][2] = 0;//c
	array[17][3] = 0;//d
	array[17][4] = 0;//e
	array[17][5] = 0;//f
	array[17][6] = 0;//g
	array[17][7] = 0;//h
	array[17][8] = 0;//i
	array[17][9] = 0;//j
	array[17][10] = 0;//k
	array[17][11] = 0;//l
	array[17][12] = 0;//m
	array[17][13] = 0;//n
	array[17][14] = 1;//o
	array[17][15] = 0;//p
	array[17][16] = 1;//q
	array[17][17] = 0;//r
	array[17][18] = 0;//s
	array[17][19] = 0;//t
	array[17][20] = 0;//z
	//Linha 19 s
	array[18][0] = 0;//a
	array[18][1] = 0;//b
	array[18][2] = 0;//c
	array[18][3] = 0;//d
	array[18][4] = 0;//e
	array[18][5] = 0;//f
	array[18][6] = 0;//g
	array[18][7] = 0;//h
	array[18][8] = 0;//i
	array[18][9] = 0;//j
	array[18][10] = 0;//k
	array[18][11] = 0;//l
	array[18][12] = 0;//m
	array[18][13] = 0;//n
	array[18][14] = 0;//o
	array[18][15] = 0;//p
	array[18][16] = 1;//q
	array[18][17] = 0;//r
	array[18][18] = 0;//s
	array[18][19] = 1;//t
	array[18][20] = 1;//z
	//Linha 20 t
	array[19][0] = 0;//a
	array[19][1] = 0;//b
	array[19][2] = 0;//c
	array[19][3] = 0;//d
	array[19][4] = 0;//e
	array[19][5] = 0;//f
	array[19][6] = 0;//g
	array[19][7] = 0;//h
	array[19][8] = 0;//i
	array[19][9] = 0;//j
	array[19][10] = 0;//k
	array[19][11] = 0;//l
	array[19][12] = 0;//m
	array[19][13] = 0;//n
	array[19][14] = 0;//o
	array[19][15] = 0;//p
	array[19][16] = 1;//q
	array[19][17] = 0;//r
	array[19][18] = 1;//s
	array[19][19] = 0;//t
	array[19][20] = 1;//z
	//Linha 21 z
	array[20][0] = 0;//a
	array[20][1] = 0;//b
	array[20][2] = 0;//c
	array[20][3] = 0;//d
	array[20][4] = 0;//e
	array[20][5] = 0;//f
	array[20][6] = 0;//g
	array[20][7] = 0;//h
	array[20][8] = 0;//i
	array[20][9] = 1;//j
	array[20][10] = 0;//k
	array[20][11] = 0;//l
	array[20][12] = 0;//m
	array[20][13] = 0;//n
	array[20][14] = 0;//o
	array[20][15] = 0;//p
	array[20][16] = 0;//q
	array[20][17] = 0;//r
	array[20][18] = 1;//s
	array[20][19] = 1;//t
	array[20][20] = 0;//z
	
}
