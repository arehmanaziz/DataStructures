#include<iostream>
using namespace std;

class BinaryHeap {
    private:
        int* PQ;
        int count;
        int capacity;
        int n;

    public:
        BinaryHeap() {
            capacity = 5;
            PQ = (int*) malloc(capacity*sizeof(int));
            count = 0;
            n = 1;
        }

        void display(){
            cout << "count = " << count << ": ";
            for (int i=1; i<count+1; i++) {
                cout << PQ[i] << " ";
            }
            cout << endl;
        }

        void heapify() {

            int i = count;

            while (i!=1) {   
                int k = int(i/2);
                if (PQ[i]<PQ[k]) {

                    int temp = PQ[k];
                    PQ[k] = PQ[i];
                    PQ[i] = temp;
                    i = k;
                }

                else break;
            }
        }

        void enqueue(int data) {   
            if (count == capacity) {

                capacity *= 2;
                int *temp = (int*) malloc(capacity*sizeof(int));

                for (int i=1; i<count+1; i++) {
                    temp[i] = PQ[i];
                }

                free(PQ);
                PQ = temp;
            }      

            PQ[++count] = data;
            heapify();
        }

        void dequeue() {
            if ((2*n <= count) && ((2*n)+1 <= count)) {

                if (PQ[2*n] < PQ[(2*n)+1]) {
                    PQ[n] = PQ[2*n];
                    n *= 2;
                }

                else {
                    PQ[n] = PQ[(2*n)+1];
                    n = (2*n)+1;
                }

                dequeue();
            }
            
            else {
                PQ[n] = PQ[count];
                count--;
            }
            n = 1;
        }
};


int main() {
    BinaryHeap PriorityQueue;

    PriorityQueue.enqueue(8);
    PriorityQueue.enqueue(13);
    PriorityQueue.enqueue(5);
    PriorityQueue.enqueue(10);
    PriorityQueue.enqueue(3);
    PriorityQueue.enqueue(9);
    PriorityQueue.enqueue(2);
    PriorityQueue.enqueue(-1);
    PriorityQueue.enqueue(6);
    PriorityQueue.enqueue(4);

    PriorityQueue.display();

    PriorityQueue.dequeue();
    PriorityQueue.display();

    PriorityQueue.dequeue();
    PriorityQueue.display();

    PriorityQueue.dequeue();
    PriorityQueue.display();
    return 0;
}
