#include <iostream>
using namespace std;

int stack[20], top=0, numOfValues=0;

bool isEmpty() {
    if (numOfValues==0) {
        return true;
    }
    return false;
}

bool isFull() {
    if (numOfValues==20) {
        return true;
    }
    return false;
}

void push(int value) {
    if (isFull()) {
        cout << "Stack Overflow" << endl;
        return;
    }
    
    stack[top++] = value;
    numOfValues++;
}

int pop() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return -1;
    }

    int value = stack[top];
    stack[top--] = -1;
    numOfValues--;
    return value;
}

int count() {
    return numOfValues;
}

void display() {
    cout << "Stack: ";
    for (int i=top-1; i>=0; i--) {
        cout << stack[i] << "->";
    }
    cout << endl;
}

int main() {
    for (int i=0; i<20; i++) {
        stack[i] = -1;
    }

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