#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

// --------ADJACENCY LIST----------


struct AdjNode {
    int vertex, weight;
    AdjNode *next;
    AdjNode(int ver, int w) {
        this->vertex = ver;
        this->weight = w;
        this->next = NULL;
    }
};

struct AdjList {
    AdjNode **List;
    int vertices, edges, direction;
};

void addNode(AdjNode **List, int v1, int v2, int weight, int direction) {
    AdjNode *node = new AdjNode(v2, weight); 

    if(List[v1]==NULL) {
        List[v1] = node;
    }
    else {
        AdjNode *temp = List[v1];
        List[v1] = node;
        node->next = temp;
    }

    if (direction==0) {
        node = new AdjNode(v1, weight);
        if(List[v2]==NULL) {
            List[v2] = node;
        }
        else {
            AdjNode *temp = List[v2];
            List[v2] = node;
            node->next = temp;
        }
    }
}

AdjList adjacencyList(string filename) {
    
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

    AdjList info;
    info.vertices = vertices;
    info.edges = edges;
    info.direction = direction;

    AdjNode **List = (AdjNode**) malloc(vertices*sizeof(AdjNode*));

    for (int i=0; i<vertices; i++) 
        List[i] = NULL;


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
        
        addNode(List, v1, v2, weight, direction);
    }

    file.close();
    info.List = List;

    return info;
}

int outDegree(AdjNode **List, int vertex) {
    int degree = 0;
    AdjNode *temp = List[vertex];
    while (temp!=NULL) {
        degree++;
        temp = temp->next;
    }
    
    return degree;
}

int inDegree(AdjNode **List, int vertex, int vertices) {
    int degree = 0;
    for (int i=0; i<vertices; i++) {
        AdjNode *temp = List[i];
        while (temp!=NULL) {
            if (temp->vertex==vertex) 
                degree++;

            temp = temp->next;
        }
    }

    return degree;
}

void printList(AdjNode **List, int vertices) {
    cout << "Adjacency List:" << endl << endl;
    for (int i=0; i<vertices; i++) {
        cout << "Vertex " << i << ": ";
        AdjNode *temp = List[i];
        while (temp!=NULL) {
            cout << temp->vertex << "->";
            temp = temp->next;
        }
        
        cout << endl;
    }
    cout << endl;
}

