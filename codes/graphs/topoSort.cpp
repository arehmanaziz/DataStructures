#include "adjMatFunctions.h"


bool allVisited(bool vertices[], int size) {
    for (int i=0; i<size; i++) {
        if (vertices[i]==false) 
            return false;
    }
    return true;
}

int* topologicalSort(int **matrix, int vertices) {
    int ID[vertices];

    for (int i=0; i<vertices; i++) 
        ID[i] = inDegree(matrix, vertices, i);
    
    bool visited[vertices] = {false};
    int *topSortList = new int[vertices], k=0; 

    bool allVis = false;
    while (!allVis) {
        int minVertex = 0;
        for (int i=0; i<vertices; i++) {
            // finding minimum value which is not visited
            if ( ID[i]<=ID[minVertex] && visited[i]==false ) 
                minVertex = i;
        }

        visited[minVertex] = true;
        topSortList[k++] = minVertex;

        for (int j=0; j<vertices; j++) {
            if (matrix[minVertex][j]!=0)
                ID[j]--; 
        }

        allVis = allVisited(visited, vertices);
    }
    
    return topSortList;
}



int main() {

    int vertices, edges, direction;
    AdjMatrix info = adjacencyMatrix("graph.txt");
    int **matrix = info.Matrix;
    vertices = info.vertices; 
    edges = info.edges;
    direction = info.direction;

    int *sortedVertices = topologicalSort(matrix, vertices);

    cout << "Sorted Vertices w.r.t Independence:" << endl; 
    for (int i=0; i<vertices; i++) {
        cout << sortedVertices[i] << " | ";
    }
    cout << endl;

    return 0;
}