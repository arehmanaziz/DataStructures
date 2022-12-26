#include "adjMatFunctions.h"

#define infinity 2147483647;

int** kruskalAlgorithm(int **Matrix, int num_of_vertices) {
    int **newMatrix = squareMatrix(num_of_vertices);
    int total_cost = 0;
    bool connected[num_of_vertices];
    connected[0] = true;

    for (int edgeNumber=0; edgeNumber < num_of_vertices-1; edgeNumber++) {
        int minimum = infinity;
        int x, y;

        for (int i = 0; i < num_of_vertices; i++) {
            // if (connected[i]) {
                for (int j=0; j<num_of_vertices; j++) {
                    if (!connected[j] && Matrix[i][j]!=0) {
                        if (Matrix[i][j]<minimum) {
                            minimum = Matrix[i][j];
                            x = i;
                            y = j;    
                        }
                    }
                }
            // }
        }

        newMatrix[x][y] = minimum;

        printf("%d - %d : %d\n", x, y, minimum);

        total_cost += minimum;
        connected[y] = true;
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

    int **newMatrix = kruskalAlgorithm(matrix, vertices);
    printMatrix(newMatrix, vertices, vertices);

    return 0;
}