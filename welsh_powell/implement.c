#include <stdio.h>
#include <stdlib.h>

#define MAX 60

//Estrutura para a fila.
typedef struct _node {
	int vertice;
	struct _node *prox;
}node;
//Estrutura para vertice.
typedef struct _vetices {
	char nome_vertice;
	int grau_vertice;
	int cor;
	int indice;
} vertices;
//Estrutura para o algoritmo de Welsh Powell.
typedef struct _welsh {
	int n_verts;
	int n_arestas;
	int n_cores;
	node * p_inicio;
	node * p_fim;
	vertices * vert;
} welsh;
//EStrutura para ordenar de acordo com o mergeSort.
typedef struct _ordena{
	int grau_vertice;
	int indice;
}ordena;

//Adiciona um elemento na fila.
node* push (node *f, int vertice){
	
	node *auxiliar;
	
	auxiliar = (node*) malloc (sizeof (node));
	
	if (auxiliar == NULL){
		printf ("Nãp foi possivel alocar memoria.\n");
		return NULL;
	}
	if (f == NULL){
		f = auxiliar;
		f->vertice = vertice;
		return f;
	}
	auxiliar->vertice = vertice;
	f->prox = auxiliar;
	auxiliar->prox = NULL;
	return auxiliar;
}

//Retira um elemento da fila.
node* pop (node *f){
	
	node *auxiliar;
	auxiliar = f->prox;
	free (f);
	return auxiliar;
}

//Adiciona valores para o grafo a ser colorido por Welsh Powell;
welsh startWelshP (welsh w, int numero_vertices, int numero_arestas, int numero_cores)
{
	int i;
	
	w.n_verts = numero_vertices;
	w.n_arestas = numero_arestas;
	w.n_cores = numero_cores;
	w.p_inicio = NULL;
	w.p_fim = NULL;
	
	w.vert = (vertices*) malloc (w.n_verts * sizeof(vertices));
	
	//Line 1
	w.vert[0].nome_vertice = 'A';
	w.vert[0].grau_vertice = 0;
	w.vert[0].cor = 0;
	//Line 2
	w.vert[1].nome_vertice = 'B';
	w.vert[1].grau_vertice = 0;
	w.vert[1].cor = 0;
	//Line 3
	w.vert[2].nome_vertice = 'C';
	w.vert[2].grau_vertice = 0;
	w.vert[2].cor = 0;
	//Line 4
	w.vert[3].nome_vertice = 'D';
	w.vert[3].grau_vertice = 0;
	w.vert[3].cor = 0;
	//Line 5
	w.vert[4].nome_vertice = 'E';
	w.vert[4].grau_vertice = 0;
	w.vert[4].cor = 0;
	//Line 6
	w.vert[5].nome_vertice = 'F';
	w.vert[5].grau_vertice = 0;
	w.vert[5].cor = 0;
	//Line 7
	w.vert[6].nome_vertice = 'G';
	w.vert[6].grau_vertice = 0;
	w.vert[6].cor = 0;
	//Line 8
	w.vert[7].nome_vertice = 'H';
	w.vert[7].grau_vertice = 0;
	w.vert[7].cor = 0;
	//Line 9
	w.vert[8].nome_vertice = 'I';
	w.vert[8].grau_vertice = 0;
	w.vert[8].cor = 0;
	//Line 10
	w.vert[9].nome_vertice = 'J';
	w.vert[9].grau_vertice = 0;
	w.vert[9].cor = 0;
	//Line 11
	w.vert[10].nome_vertice = 'K';
	w.vert[10].grau_vertice = 0;
	w.vert[10].cor = 0;
	
	for (i = 0; i < w.n_verts; i++) w.vert[i].indice = i;
	
	return w;
}

//Atribui valores a matriz adjacente referente ao grafo.
void setAdjacent (int adj[MAX][MAX])
{	
	//Vertice A linha 1.
	adj[0][0] = 0;
	adj[0][1] = 1;
	adj[0][2] = 0;
	adj[0][3] = 0;
	adj[0][4] = 0;
	adj[0][5] = 0;
	adj[0][6] = 0;
	adj[0][7] = 1;
	adj[0][8] = 0;
	adj[0][9] = 0;
	adj[0][10] = 0;
	//Vertice B linha 2.
	adj[1][0] = 1;
	adj[1][1] = 0;
	adj[1][2] = 0;
	adj[1][3] = 1;
	adj[1][4] = 0;
	adj[1][5] = 0;
	adj[1][6] = 0;
	adj[1][7] = 0;
	adj[1][8] = 0;
	adj[1][9] = 0;
	adj[1][10] = 0;
	//Vertice C linha 3.
	adj[2][0] = 0;
	adj[2][1] = 0;
	adj[2][2] = 0;
	adj[2][3] = 1;
	adj[2][4] = 0;
	adj[2][5] = 0;
	adj[2][6] = 0;
	adj[2][7] = 0;
	adj[2][8] = 0;
	adj[2][9] = 0;
	adj[2][10] = 0;
	//Vertice D linha 4.
	adj[3][0] = 0;
	adj[3][1] = 1;
	adj[3][2] = 1;
	adj[3][3] = 0;
	adj[3][4] = 0;
	adj[3][5] = 0;
	adj[3][6] = 0;
	adj[3][7] = 0;
	adj[3][8] = 1;
	adj[3][9] = 0;
	adj[3][10] = 1;
	//Vertice E linha 5.
	adj[4][0] = 0;
	adj[4][1] = 0;
	adj[4][2] = 0;
	adj[4][3] = 0;
	adj[4][4] = 0;
	adj[4][5] = 1;
	adj[4][6] = 0;
	adj[4][7] = 0;
	adj[4][8] = 0;
	adj[4][9] = 0;
	adj[4][10] = 1;
	//Vertice F linha 6.
	adj[5][0] = 0;
	adj[5][1] = 0;
	adj[5][2] = 0;
	adj[5][3] = 0;
	adj[5][4] = 1;
	adj[5][5] = 0;
	adj[5][6] = 1;
	adj[5][7] = 0;
	adj[5][8] = 0;
	adj[5][9] = 0;
	adj[5][10] = 0;
	//Vertice G linha 7.
	adj[6][0] = 0;
	adj[6][1] = 0;
	adj[6][2] = 0;
	adj[6][3] = 0;
	adj[6][4] = 0;
	adj[6][5] = 1;
	adj[6][6] = 0;
	adj[6][7] = 1;
	adj[6][8] = 0;
	adj[6][9] = 0;
	adj[6][10] = 1;
	//Vertice H linha 8.
	adj[7][0] = 1;
	adj[7][1] = 0;
	adj[7][2] = 0;
	adj[7][3] = 0;
	adj[7][4] = 0;
	adj[7][5] = 0;
	adj[7][6] = 1;
	adj[7][7] = 0;
	adj[7][8] = 1;
	adj[7][9] = 1;
	adj[7][10] = 1;
	//Vertice I linha 9.
	adj[8][0] = 0;
	adj[8][1] = 0;
	adj[8][2] = 0;
	adj[8][3] = 1;
	adj[8][4] = 0;
	adj[8][5] = 0;
	adj[8][6] = 0;
	adj[8][7] = 1;
	adj[8][8] = 0;
	adj[8][9] = 1;
	adj[8][10] = 0;
	//Vertice J linha 10.
	adj[9][0] = 0;
	adj[9][1] = 0;
	adj[9][2] = 0;
	adj[9][3] = 0;
	adj[9][4] = 0;
	adj[9][5] = 0;
	adj[9][6] = 0;
	adj[9][7] = 1;
	adj[9][8] = 1;
	adj[9][9] = 0;
	adj[9][10] = 1;
	//Vertice K linha 11.
	adj[10][0] = 0;
	adj[10][1] = 0;
	adj[10][2] = 0;
	adj[10][3] = 1;
	adj[10][4] = 1;
	adj[10][5] = 0;
	adj[10][6] = 1;
	adj[10][7] = 1;
	adj[10][8] = 0;
	adj[10][9] = 1;
	adj[10][10] = 0;
	
	return;
}

//Merge da Funcao MergeSort.
void merge (ordena *v, int inicio, int medium, int tam)
{
	ordena aux[tam+1];
	int i, j, k;

	i = inicio;
	j = medium+1;
	k = 0;
	
	while(i <= medium && j <= tam)
	{
		if( v[j].grau_vertice <= v[i].grau_vertice)
		{
			aux[k].grau_vertice = v[i].grau_vertice;
			aux[k].indice = v[i].indice;
			i++;
		}else{								
			aux[k].grau_vertice = v[j].grau_vertice;
			aux[k].indice = v[j].indice;
			j++;
		}
		k++;
	}
	while (i <= medium)
	{
		aux[k].grau_vertice = v[i].grau_vertice;
		aux[k].indice = v[i].indice;
		i++;
		k++;
	}
	while (j <= tam)
	{
		aux[k].grau_vertice = v[j].grau_vertice;
		aux[k].indice = v[j].indice;
		j++;
		k++;
	}	
	for (i = 0; i < k; i++)
	{
		v[i+inicio].grau_vertice = aux[i].grau_vertice;
		v[i+inicio].indice = aux[i].indice;
	}
}

//Funcao de mergeSort (Ordenacao dos vertices apartir do seu grau)
void mergeSort (ordena * v, int start, int end)
{
	int medium = (start + end) /2;
		
	if (start < end)
	{
		mergeSort(v, start,medium);
		mergeSort(v, (medium+1),end);
		merge(v, start, medium, end);
	}
}

//Define o grau de cada vertice, atraves da matriz adjacente.
welsh setGrau (welsh w, int adj[MAX][MAX])
{
	int vertice, indice;
	
	for (indice = 0; indice < w.n_verts; indice++)
	{
		for (vertice = 0; vertice < w.n_verts; vertice++)
		{
			if (adj[indice][vertice] > 0) w.vert[indice].grau_vertice++;
		}
	}
	return w;
}

//Roda o algoritmo de Welsh Powell. 
welsh runWelshP (welsh w, int adj[MAX][MAX])
{
	int i, cor, j;
	int vertice_atual, vertice_adj;
	ordena *vert_ordenados;
	
	vert_ordenados = (ordena*) malloc (w.n_verts * sizeof(ordena));
	cor = 0;
	
	w = setGrau (w, adj);
	
	//Passa os valores para o vetor de vertices, para que o mergeSort possa ordenalos de acordo com a Grau de cada vetice.
	for (i = 0; i < w.n_verts; i++)
	{
		vert_ordenados[i].grau_vertice = w.vert[i].grau_vertice;
		vert_ordenados[i].indice = w.vert[i].indice;
	}
	mergeSort(vert_ordenados,0,w.n_verts-1);
	
	//Verifica todos os vertices, para colorir todos.
	for (i = 0; i < w.n_verts; i++)
	{
		vertice_atual = vert_ordenados[i].indice;//Passa o vertice de acordo com a ordenacao do mergeSort.
		//Passa para o proximo vertice caso o vertice atual ja possua cor.
		if (w.vert[vertice_atual].cor != 0) continue;
		//Caso o vertica atual nao possua cor, adiciona uma nova cor e o pinta com esta cor.
		if (w.vert[vertice_atual].cor == 0) 
		{
			cor++;
			w.vert[vertice_atual].cor = cor;
		}
		/* Vare a linha da matriz adjacente referente ao vertice atual
		 * procurando de modo a verificar a coloracao de todos os vertices 
		 * nao interligados ao vertice atual.*/
		for (j = 0 ; j < w.n_verts; j++)
		{
			vertice_adj = vert_ordenados[j].indice;//Passa o vertice de acordo com a ordenacao do mergeSort.
			/*Descarta o vertice atual, pois ja foi atribuido cor a ele. 
			 *E vertices ja coloridos.Caso if verdadeiro passa para a proxima
			 *ligacao da matriz adjacente*/
			if (vertice_atual == vertice_adj || w.vert[vertice_adj].cor != 0) continue;
			/*Pinta vertices que nao possuem ligacao com o vertice atual e que ainda nao estao pintados.
			 * Atribui os vertices pintados para uma fila, para verificacao de validade da cor para o vertice*/
			if (adj[vertice_atual][vertice_adj] == 0 && w.vert[vertice_adj].cor == 0)
			{
				w.vert[vertice_adj].cor = cor;
				if (w.p_fim == NULL)
				{
					w.p_fim = push (w.p_fim, w.vert[vertice_adj].indice);
					w.p_inicio = w.p_fim;
				}else {
					w.p_fim = push (w.p_fim, w.vert[vertice_adj].indice);
				}
			}
		}
		//Verifica fila vazia, e atribui como vertice atual(para validar a cor) o primeiro vertice da fila.
		if (w.p_inicio != NULL) vertice_atual = w.p_inicio->vertice;
		/*Enquanto a fila nao estiver vazia vai percorendo todos os vertices nela contidos
		 * para validar a cor atribuida ao vertice*/
		while (w.p_inicio != NULL)
		{
			//Percorre a matriz adjacente para verificar possiveis ilegalidades a cor atribuida ao vertice atual.
			for (j = 0 ; j < w.n_verts && w.vert[vertice_atual].cor != 0 ; j++)
			{
				vertice_adj = vert_ordenados[j].indice;//Passa o vertice de acordo com a ordenacao do mergeSort.
				
				//Descarta o vertice atual das comparacoes na matriz adjacente.
				if (vertice_atual == vertice_adj)continue;
				
				/*Caso exista um vertice interligado ao vertice atual, e que possua a mesma cor
				 * que o vertice atual, pela ordem de estabelecida pela mergeSort, o vertice atual tem
				 * controle para mudar a cor do vertice interligado que possu cor igual a dele.
				 * Volta a cor para zero no vertice causador do comflito*/
				if (adj[vertice_atual][vertice_adj] == 1 && w.vert[vertice_atual].cor == w.vert[vertice_adj].cor) w.vert[vertice_adj].cor = 0;
			}
			w.p_inicio = pop (w.p_inicio);//Retira o vertice atual da fila, pois ja foi validada sua cor.
			//Caso ainda nao esteja vazia a fila, atribuimos o novo vertice atual (proximo a ser validada a sua cor).
			if (w.p_inicio != NULL) vertice_atual = w.p_inicio->vertice;
			else continue;
			
		}
		w.p_fim = NULL;
	}
	return w;
}

//Imprime o grafo de Welsh Powell.
void printWelshP (welsh w)
{
	int i;
	
	//Imprime o nome dos vertices
	printf("Nome : ");
	for (i = 0; i < w.n_verts; i++) printf("%c |",w.vert[i].nome_vertice);
	printf("\n");
	//Imprime o grau dos vertices
	printf("Grau : ");
	for (i = 0; i < w.n_verts; i++) printf("%d |",w.vert[i].grau_vertice);
	printf("\n");
	//Imprime a cor dos vertices
	printf("Cor  : ");
	for (i = 0; i < w.n_verts; i++) printf("%d |",w.vert[i].cor);
	printf("\n");

}
