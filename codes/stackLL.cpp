#include <iostream>
using namespace std;

struct SNode {
    int data;
    SNode *next;
};

SNode *top=NULL;
int numOfValues = 0;

bool isEmpty() {
    if (top==NULL) {
        return true;
    }
    return false;
}

void push(int value) {
    SNode *newTop = new SNode();
    newTop->data = value;
    newTop->next = top;
    top = newTop;
    numOfValues++;
}

int pop() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return -1;
    }

    SNode *temp = top;
    int value = temp->data;
    top = top->next;
    delete temp;
    numOfValues--;

    return value;
}

void display() {
    SNode *temp = top;
    cout << "Stack: ";
    while (temp!=NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

int count() {
    return numOfValues;
}


int main() {
    
    push(4);
    push(6);
    push(5);
    display();

    pop();
    display();

    push(9);
    display();

    pop();
    display();

    pop();
    display();

    pop();
    display();

    return 0;
}