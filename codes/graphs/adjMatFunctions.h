#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;


// -------ADJACENCY MATRIX--------

int** squareMatrix(int n) {
    int **matrix = new int*[n];
    for (int i=0; i<n; i++) {
        matrix[i] = new int[n];
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            matrix[i][j] = 0;
        }
    }

    return matrix;
}

void printMatrix(int **matrix, int rows, int columns) {
    cout << "Adjacency Matrix" << endl << endl;
    
    cout << "  \t";
    for (int k=0; k<columns; k++) {
        cout << k << "\t";
    }
    cout << endl << endl;

    for (int i=0; i<rows; i++) {
        cout << i << ":\t";
        for (int j = 0; j < columns; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int inDegree(int **Matrix, int vertices, int vertex) {

    int degree = 0;
    for (int i=0; i<vertices; i++) {
        if (Matrix[i][vertex] != 0) {
            degree += 1;
        }
    }

    return degree;
}

int outDegree(int **Matrix, int vertices, int vertex) {
    int degree = 0;
    for (int i=0; i<vertices; i++) {
        if (Matrix[vertex][i] != 0) {
            degree += 1;
        }
    }

    return degree;
}

struct AdjMatrix {
    int **Matrix;
    int vertices, edges, direction;
};

AdjMatrix adjacencyMatrix(string filename) {
    int vertices, edges, direction;

    ifstream file;
    file.open(filename);

    string graphInfo;
    getline(file, graphInfo);
    stringstream ved(graphInfo);
    
    string n;
    getline(ved, n, ',');
    vertices = stoi(n);

    getline(ved, n, ',');
    edges = stoi(n);

    getline(ved, n, ',');
    direction = stoi(n);

    AdjMatrix info;
    info.vertices = vertices;
    info.edges = edges;
    info.direction = direction;

    int **Matrix = squareMatrix(vertices);

    for (int i=0; i<edges; i++) {
        int v1, v2, weight;
        getline(file, graphInfo);
        stringstream data(graphInfo);
        string value;

        getline(data, value, ',');
        v1 = stoi(value);

        getline(data, value, ',');
        v2 = stoi(value);

        getline(data, value, ',');
        weight = stoi(value);
        
        Matrix[v1][v2] = weight;
        if (direction==0) {
            Matrix[v2][v1] = weight;
        } 
    }

    file.close();
    info.Matrix = Matrix;

    return info;
}

