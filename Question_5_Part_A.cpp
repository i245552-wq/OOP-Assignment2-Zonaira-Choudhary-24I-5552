#include <iostream>
using namespace std;

class StackArray {
    int top;
    int arr[100];
public:
    StackArray() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == 99; }

    void push(int val) {
        if (!isFull()) arr[++top] = val;
    }

    int pop() {
        if (!isEmpty()) return arr[top--];
        else return -1;
    }

    int peek() {
        if (!isEmpty()) return arr[top];
        else return -1;
    }
};

void ChangeLocation_Iterative_Array(char* Array, int b1, int b2) {
    StackArray s1, s2;

    for (int i = b1; i <= b2; i++)
        s1.push(Array[i]);

    while (!s1.isEmpty())
        s2.push(s1.pop());

    for (int i = b1; i <= b2; i++)
        Array[i] = s2.pop();
}

void PrintPattern_Iterative_Array(int n) {
    StackArray s;
    int temp = n;

    while (temp > 0) {
        s.push(temp);
        temp--;
    }

    while (!s.isEmpty()) {
        int value = s.pop();
        for (int i = 0; i < n - value + 1; i++)
            cout<<value<<" ";
        cout<<endl;
    }
}

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class StackLinkedList {
    Node* top;
public:
    StackLinkedList() { top = NULL; }

    bool isEmpty() { return top == NULL; }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) return -1;
        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    int peek() {
        if (isEmpty()) return -1;
        return top->data;
    }
};

void ChangeLocation_Iterative_Linked(char* Array, int b1, int b2) {
    StackLinkedList s1, s2;

    for (int i = b1; i <= b2; i++)
        s1.push(Array[i]);

    while (!s1.isEmpty())
        s2.push(s1.pop());

    for (int i = b1; i <= b2; i++)
        Array[i] = s2.pop();
}

void PrintPattern_Iterative_Linked(int n) {
    StackLinkedList s;
    int temp = n;

    while (temp > 0) {
        s.push(temp);
        temp--;
    }

    while (!s.isEmpty()) {
        int value = s.pop();
        for (int i = 0; i < n - value + 1; i++)
            cout<<value<<" ";
        cout<<endl;
    }
}

// ----- MAIN FUNCTION -----
int main() {
    cout<<"----- ARRAY BASED STACK OUTPUT -----\n";
    char arr1[] = {'A', 'B', 'C', 'D', 'E', 'F', '\0'};
    cout<<"Original Array: ";
    for (int i = 0; i < 6; i++) cout<<arr1[i]<<" ";
    cout<<endl;

    ChangeLocation_Iterative_Array(arr1, 1, 4);
    cout<<"After ChangeLocation (Array Stack): ";
    for (int i = 0; i < 6; i++) cout<<arr1[i]<<" ";
    cout<<"\n\nPrintPattern (n = 5):\n";
    PrintPattern_Iterative_Array(5);

    cout<<"\n\n----- LINKED LIST BASED STACK OUTPUT -----\n";
    char arr2[] = {'A', 'B', 'C', 'D', 'E', 'F', '\0'};
    cout<<"Original Array: ";
    for (int i = 0; i < 6; i++) cout<<arr2[i]<<" ";
    cout<<endl;

    ChangeLocation_Iterative_Linked(arr2, 1, 4);
    cout<<"After ChangeLocation (Linked Stack): ";
    for (int i = 0; i < 6; i++) cout<<arr2[i]<<" ";
    cout<<"\n\nPrintPattern (n = 5):\n";
    PrintPattern_Iterative_Linked(5);

    return 0;
}
