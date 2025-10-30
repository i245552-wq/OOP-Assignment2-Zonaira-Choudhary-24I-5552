#include <iostream>
#include <string>
using namespace std;

class Feature {
public:
    string Name;

    Feature(string n){
        Name = n;
    }
    virtual void analyze() = 0;  // Pure virtual function
    virtual ~Feature() {}        // Virtual destructor
};

class LandFeature : public Feature {
public:
    LandFeature(string n) : Feature(n) {}
    void analyze() override {
        cout<<"Land Feature: "<< Name <<" ==> Land area detected.\n";
    }
};

class WaterFeature : public Feature {
public:
    WaterFeature(string n) : Feature(n) {}
    void analyze() override {
        cout<<"Water Feature: "<<Name<<" ==> Water body detected.\n";
    }
};


class Node {
public:
    int FeatureID;
    Feature* feature;
    Node* next;

    Node(int id, Feature* f) : FeatureID(id), feature(f), next(nullptr) {}
    ~Node() {
        delete feature;  // Delete dynamically allocated feature
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList(){
        head = nullptr;
    }

    void insertAtEnd(int featureID, Feature* f) {
        Node* newNode = new Node(featureID, f);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next)
            current = current->next;

        current->next = newNode;
    }

    void deleteByID(int featureID) {
        if (head == nullptr){ 
            return;
        }

        if (head->FeatureID == featureID) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout<<"Feature with ID "<<featureID<<" deleted.\n";
            return;
        }

        // Traverse to find node before the one to delete
        Node* current = head;
        while (current->next && current->next->FeatureID != featureID){
            current = current->next;
        }

        if (current->next) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            cout<<"Feature with ID "<<featureID<<" deleted.\n";
        } else {
            cout<<"Feature ID was not found.\n";
        }
    }

    void displayAll() const {
        Node* current = head;
        if (current == nullptr) {
            cout<<"There are no features to display.\n";
            return;
        }

        cout<<"\n=== Feature List ===\n";
        while (current != nullptr) {
            cout<<"Feature ID: "<<current->FeatureID<<" ==> ";
            current->feature->analyze();
            current = current->next;
        }
    }

    void reverseList() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    ~SinglyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkedList list;

    list.insertAtEnd(1, new LandFeature("Forest"));
    list.insertAtEnd(2, new WaterFeature("River"));
    list.insertAtEnd(3, new LandFeature("Mountain"));
    list.insertAtEnd(4, new WaterFeature("Lake"));

    list.displayAll();

    cout<<"\nDeleting feature\n";
    list.deleteByID(2);
    list.displayAll();

    list.reverseList();
    list.displayAll();

    return 0;
}

