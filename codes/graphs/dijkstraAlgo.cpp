#include "adjMatFunctions.h"

struct Vertex {
    Vertex *previousVertex;
    int id;
    int distance;
    bool known;
    bool connected;
};

Vertex* createNewVertex(int id) {

    Vertex *newVertex = (Vertex*) malloc(sizeof(Vertex));
    newVertex->previousVertex = NULL;
    newVertex->known = false;
    newVertex->connected = false;
    newVertex->id = id;
    newVertex->distance = 2147483647;

    return newVertex;
}

bool allKnown(Vertex **vertices , int size) {
    for (int i=0; i<size; i++) {
        if (vertices[i]->known == false) 
            return false;
    }
    return true;
}

int *connectedVertices(int **Matrix, int numOfVertices, int vertex) {

    int out_degree = outDegree(Matrix, numOfVertices, vertex);
    int *connected_vertices = new int[out_degree];

    int j=0;
    for (int i=0; i<numOfVertices; i++)
        if (Matrix[vertex][i] != 0)
            connected_vertices[j++] = i;

    return connected_vertices; 

}

Vertex* nextVertex(Vertex **vertices, int size) {

    Vertex* next_vertex = vertices[0];

    int j;
    for (j=1; j<size; j++) {
        if (!vertices[j]->known) {
            next_vertex = vertices[j++];
            break;
        }
    }

    if (j==size) return NULL;

    for (int i=j; i<size; i++) {
        if (!vertices[i]->known) {
            if (vertices[i]->distance < next_vertex->distance) {
                next_vertex = vertices[i];
            }
        }
    }
    
    return next_vertex;
}

Vertex** dijkstraAlgorithm(int **matrix, int vertices) {

    Vertex **allVertices = (Vertex**) malloc(vertices * sizeof(Vertex*));

    for (int i=0; i<vertices; i++) 
        allVertices[i] = createNewVertex(i);   
    
    Vertex *current_vertex = allVertices[0];
    current_vertex->distance = 0;
    current_vertex->connected = true;
    current_vertex->previousVertex = NULL;


    bool visit = false;
    while (!visit) {

        int *connected_vertices = connectedVertices(matrix, vertices, current_vertex->id);
        int num_of_connected_vertices = outDegree(matrix, vertices, current_vertex->id);

        for (int i=0; i<num_of_connected_vertices; i++) {

            int conVert = connected_vertices[i];
            Vertex *connected_vertex = allVertices[conVert];

            int current_edge_weight = matrix[current_vertex->id][connected_vertex->id];
            int current_vertex_weight = current_vertex->distance;
            
            int totalWeight = current_vertex_weight + current_edge_weight;

            if (!connected_vertex->connected) {
                connected_vertex->connected = true;
                connected_vertex->previousVertex = current_vertex;
                connected_vertex->distance = totalWeight;
            }

            else if (totalWeight < connected_vertex->distance) {       
                connected_vertex->distance = totalWeight;
                connected_vertex->previousVertex = current_vertex;            
            }
        }
        current_vertex->known = true;
        visit = allKnown(allVertices, vertices);
        if (!visit) 
            current_vertex = nextVertex(allVertices, vertices);
    } 
    return allVertices;
}

void display(Vertex **vertices, int size) {
    cout << "(Vertex, Distance) <- Previous Vertex" << endl;
    for (int i=0; i<size; i++) {
        Vertex *current = vertices[i];
        while (current != NULL) {
            cout << "(" << current->id << ", " << current->distance << ") <- ";
            current = current->previousVertex;
        } cout << endl;
    }
}

int main() {

    int vertices, edges, direction;
    AdjMatrix info = adjacencyMatrix("graph.txt");
    int **matrix = info.Matrix;
    vertices = info.vertices; 
    edges = info.edges;
    direction = info.direction;

    Vertex **singlePathGraph = dijkstraAlgorithm(matrix, vertices);

    display(singlePathGraph, vertices);

    return 0;
}