#include "adjMatFunctions.h"
#include "adjListFunctions.h"


int main() {
    // ----------MATRIX------------
    int vertices, edges, direction;

    AdjMatrix info = adjacencyMatrix("graph.txt");
    int **matrix = info.Matrix;
    vertices = info.vertices; 
    edges = info.edges;
    direction = info.direction;

    printMatrix(matrix, vertices, vertices);

    for (int i=0; i<vertices; i++) {
        cout << "Indegree of Vertex " << i << ": " << inDegree(matrix, vertices, i) << endl;
        cout << "Outdegree of Vertex " << i << ": " << outDegree(matrix, vertices, i) << endl;
        cout << endl;
    }

    // --------LIST--------------
    int vertices1, edges1, direction1;

    AdjList info1 = adjacencyList("graph.txt");

    AdjNode **list = info1.List;
    vertices1 = info1.vertices; 
    edges1 = info1.edges;
    direction1 = info1.direction;

    printList(list, vertices1);
    for (int i=0; i<vertices; i++) {
        cout << "Indegree of Vertex " << i << ": " << inDegree(list, i, vertices1) << endl;
        cout << "Outdegree of Vertex " << i << ": " << outDegree(list, i) << endl;
        cout << endl;
    }

    return 0;
}