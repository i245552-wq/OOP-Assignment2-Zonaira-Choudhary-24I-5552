#include <iostream>
using namespace std;


struct Customer {
    int ID;
    string Name;
    int Tickets;
};

// Queue class
class Queue {
private:
    Customer* queArr;
    int front, rear, sizeOfQueue;

public:
    Queue(int size) {
        sizeOfQueue = size;
        queArr = new Customer[sizeOfQueue];
        front = -1;
        rear = -1;
    }

    ~Queue() {
        delete[] queArr;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return (rear == sizeOfQueue - 1);
    }

    void enqueue(int id, string name, int tickets) {
        if (isFull()) {
            cout<<"The queue is full! Cannot add more customers.\n";
            return;
        }

        Customer c = {id, name, tickets};
        queArr[++rear] = c;
        if (front == -1)
            front = 0;

        cout<<"Customer "<<name<<" added to the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout<<"The queue is empty! No customer to serve.\n";
            return;
        }

        cout<<"Customer "<<queArr[front].Name<<" served and removed from queue.\n";
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout<<"The queue is empty.\n";
            return;
        }

        cout<<"\nCurrent Queue:\n";
        for (int i = front; i <= rear; i++) {
            cout<<"Customer ID: "<<queArr[i].ID
                <<", Name: "<<queArr[i].Name
                <<", Tickets: "<<queArr[i].Tickets<<endl;
        }
    }
};

int main() {
    Queue q(5); // Queue with capacity 5

    q.enqueue(101, "Ali", 2);
    q.enqueue(102, "Sara", 4);
    q.enqueue(103, "Hassan", 1);

    q.display();

    q.dequeue();
    q.display();

    q.enqueue(104, "Ayesha", 3);
    q.enqueue(105, "Usman", 2);
    q.enqueue(106, "Fatima", 1); // will show queue full

    q.display();

    return 0;
}

