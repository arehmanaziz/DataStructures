#include <iostream>
using namespace std;


struct QNode {
    int data;
    QNode* next;
    QNode(int d) {
        data = d;
        next = NULL;
    }
};

QNode *front=NULL, *rear=NULL;

void enqueue(int value) {
    QNode *newNode = new QNode(value);
    if (rear==NULL) {
        front = newNode;
        rear = newNode;
    }

    rear->next = newNode;
    rear = newNode;
}

int dequeue() {
    if (front==NULL) {
        return 0;
    }

    QNode *temp = front;

    front = front->next;
    if (front==NULL) {
        rear = NULL;
    }

    int value = temp->data;
    delete temp;

    return value;
}

void display() {
    QNode *temp = front;
    while (temp!=NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


int main() {

    enqueue(10);
    enqueue(20);
    display();

    dequeue();
    display();

    dequeue();
    display();

    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();

    dequeue();
    display();
    
    return 0;
}