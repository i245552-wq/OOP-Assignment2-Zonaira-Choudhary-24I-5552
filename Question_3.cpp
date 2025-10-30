#include <iostream>
using namespace std;

struct Node {
    int BookID;
    string Title;
    string Author;
    Node* next;
    Node* prev;
};

class Library {
private:
    Node* head;
    Node* tail;

public:
    Library() {
        head = nullptr;
        tail = nullptr;
    }

    // Add at beginning
    void addAtBeginning(int id, string title, string author) {
        Node* newNode = new Node{id, title, author, head, nullptr};
        if (head != nullptr)
            head->prev = newNode;
        else
            tail = newNode;
        head = newNode;
    }


    // Add at end
   void addAtEnd(int id, string title, string author) {
    Node* newNode = new Node{id, title, author, nullptr, tail};
    if (tail != nullptr)
        tail->next = newNode;
    else
        head = newNode;  // if list was empty
    tail = newNode;
}

    // Add at specific position (1-based)
   void addAtPosition(int pos, int id, string title, string author) {
    if (pos <= 1 || head == nullptr) {
        addAtBeginning(id, title, author);
        return;
    }

    Node* current = head;
    int count = 1;

    while (current->next && count < pos - 1) {
        current = current->next;
        count++;
    }

    Node* newNode = new Node{id, title, author, current->next, current};

    if (current->next)
        current->next->prev = newNode;
    else
        tail = newNode;

    current->next = newNode;
}

    // Delete by ID
    void deleteBook(int id) {
        Node* temp = head;
        while (temp && temp->BookID != id)
            temp = temp->next;

        if (!temp) {
            cout<<"Book not found.\n";
            return;
        }

        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;

        if (temp->next) temp->next->prev = temp->prev;
        else tail = temp->prev;

        delete temp;
        cout<<"Book deleted.\n";
    }

    // Display forward
    void displayForward() {
        Node* temp = head;
        cout<<"\nBooks (Forward):\n";
        while (temp!= nullptr) {
            cout<<temp->BookID<<" - "<<temp->Title<<" by "<<temp->Author<<endl;
            temp = temp->next;
        }
    }

    // Display backward
    void displayBackward() {
        Node* temp = tail;
        cout<<"\nBooks (Reverse):\n";
        while (temp != nullptr) {
            cout<<temp->BookID<<" - "<<temp->Title<<" by "<<temp->Author<<endl;
            temp = temp->prev;
        }
    }
};

int main() {
    Library lib;

    lib.addAtEnd(101, "Pride and Prejudice", "Jane Austen");
    lib.addAtBeginning(102, "Animal Farm", "George Orwell");
    lib.addAtEnd(103, "War and Peace", "Leo Tolstoy");
    lib.addAtPosition(2, 104, "To Kill a Mockingbird", "Harper Lee");

    lib.displayForward();
    lib.displayBackward();

    lib.deleteBook(103);
    lib.displayForward();

    return 0;
}

