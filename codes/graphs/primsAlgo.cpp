#include "adjMatFunctions.h"

#define infinity 2147483647;

int** primsAlgorithm(int **Matrix, int num_of_vertices) {
    int **newMatrix = squareMatrix(num_of_vertices);
    int total_cost = 0;
    bool selected[num_of_vertices];
    selected[0] = true;

    int edgeNumber;
    for (edgeNumber=0; edgeNumber < num_of_vertices-1; edgeNumber++) {
        int minimum = infinity;
        int x, y;

        for (int i = 0; i < num_of_vertices; i++) {
            if (selected[i]) {
                for (int j=0; j<num_of_vertices; j++) {
                    if (!selected[j] && Matrix[i][j]!=0) {
                        if (Matrix[i][j]<minimum) {
                            minimum = Matrix[i][j];
                            x = i;
                            y = j;    
                        }
                    }
                }
            }
        }

        newMatrix[x][y] = minimum;

        printf("%d - %d : %d\n", x, y, minimum);

        total_cost += minimum;
        selected[y] = true;
    }

    printf("Total Cost = %d",total_cost);
    cout << endl;
    return newMatrix;
}

int main() {

    int vertices, edges, direction;
    AdjMatrix info = adjacencyMatrix("graph.txt");
    int **matrix = info.Matrix;
    vertices = info.vertices; 
    edges = info.edges;
    direction = info.direction;

    int **newMatrix = primsAlgorithm(matrix, vertices);
    printMatrix(newMatrix, vertices, vertices);

    return 0;
}