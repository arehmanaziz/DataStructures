#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *next;
};


void insert(Node *hn, int value) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->key = value;
    newNode->next = hn;
    hn = newNode;
}


void deleteNode(Node *hn, int value) {
    Node *current;
    Node *previous;

    while (current->next != NULL) {
        if (current->key==value) {
            previous->next = current->next;
            free(current);
            return;
        }

        previous = current;
        current = current->next;
    }

    cout << value << " not found." << endl;
}

void display(Node* hn) {
    Node *temp = hn;
    while (temp!=NULL) {
        cout << temp->key << "->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {
    int values[] = {4, 7, 1, 5, 9, 0, 1, 3, 77};
    int len = sizeof(values)/sizeof(values[0]);
    Node *HeadNode;
    
    for (int i=0; i<len; i++) {
        insert(HeadNode, values[i]);
        display(HeadNode);
    }

    deleteNode(HeadNode, 9);
    display(HeadNode);
    deleteNode(HeadNode, 999);
    display(HeadNode);
    
    return 0;
}