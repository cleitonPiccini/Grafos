#ifndef Fun_h
#define Fun_h
#define MAX  50

typedef struct _moves{
    int vertActual;
    int valueMoves;
    int start;
    int end;
    int nVert;
}moves;

//Insert values in the adjacent array.
void setValueGrafo_1 (int arrayAdjacent[MAX][MAX]);

//Insert values in the adjacent array.
void setValueGrafo_2 (int arrayAdjacent[MAX][MAX]);

//Search the smallest path
moves searchLess (int array[MAX][MAX], moves moviment);

//Greedy
void greedy (int array[MAX][MAX], moves moviment);

//Next Vertex
moves nextVert (int array[MAX][MAX], moves moviment);

// Print Values the move Vertex
void printVert (moves vert);

// Print Values in Array Adjacent
void printArray (int array[MAX][MAX], moves moviment);

//start Values of Stract the moviment.
moves startMoveGrafo_1 (moves moviment);

//start Values of Stract the moviment.
moves startMoveGrafo_2 (moves moviment);

#endif
