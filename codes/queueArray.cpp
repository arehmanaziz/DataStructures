#include <iostream>
using namespace std;

int queue[20]={0}, rear = -1, front = -1, capacity = 20, count = 0;

bool isFull() {
    if (capacity == count) {
        return true;
    }

    return false;
}

bool isEmpty() {
    if (front==-1 && rear==-1) {
        return true;
    }

    return false;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow" << endl;
    } 

    else {
        if (front == - 1) front++;
        queue[rear++] = value;
        count++;
    }
}

int dequeue() {
    int val;
    if (front == - 1 || front > rear) {
        cout << "Queue Underflow " << endl;
    }

    else {
        val = queue[front];
        queue[front] = -1;

        if(front==rear) {
            front = -1, rear = -1;
        }
        else {
            front++;
        }

        count--;
    }

    return val;
}


int top() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return -1;
    }

    else {
        return queue[front];
    }
}

void display() {
    if (front == - 1) {
        cout << "Queue is empty." << endl;
    }

    else {
        cout << "Queue elements are: ";
        for (int i=front; i<=rear; i++) {
            cout << queue[i] << ", ";
        }
        cout << endl;
    }
}

int main() {

    int choice;
    cout << "1) Insert an element" << endl;
    cout << "2) Delete first element" << endl;
    cout << "3) Display all the elements" << endl;
    cout << "4) Get top element" << endl;
    cout << "5) Exit" << endl;

    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                int value;
                cout << "Enter value: " << endl;
                cin >> value;
                enqueue(value);
                break;
            case 2: 
                dequeue();
                break;
            case 3: 
                display();
                break;
            case 4:
                cout << "Top value: " << top() << endl;
                break;
            case 5: 
                cout << "Exit" << endl;
                break;
            default:
                 cout << "Invalid choice" << endl;
        }
    }
    while(choice!=5);

    return 0;
}