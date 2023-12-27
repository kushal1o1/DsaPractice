#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* start;

public:
    LinkedList() : start(nullptr) {}

    Node* CreateNode() {
        int data;
        cout << "Enter data to be inserted: ";
        cin >> data;

        Node* temp = new Node();
        temp->data = data;
        temp->next = nullptr;
        return temp;
    }

    // Combine common insertion logic into a single function
    void insert(Node* newNode, Node*& position) {
        if (!position) {
            start = newNode;
        } else {
            newNode->next = position;
            position = newNode;
        }
    }

    void insertAtEnd() {
        Node* newNode = CreateNode();
        Node* temp = start;

        while (temp->next) {
            temp = temp->next;
        }

        // Use the common insert function
        insert(newNode, temp->next);
    }

    void insertAtBeginning() {
        Node* newNode = CreateNode();
        // Use the common insert function
        insert(newNode, start);
    }

    // Combine insertion functions into a single function
    void insertAtPosition(bool after) {
        if (!start) {
            cout << "List is empty. Cannot insert.\n";
            return;
        }

        int key;
        cout << "Enter the data value " << (after ? "after" : "before") << " which you want to insert: ";
        cin >> key;

        Node* newNode = CreateNode();
        Node* temp = start;
        Node* prev = nullptr;

        while (temp && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (!temp) {
            cout << "Key not found in the list.\n";
        } else {
            newNode->next = (after ? temp->next : temp);
            if (after) {
                temp->next = newNode;
            } else {
                if (prev) {
                    prev->next = newNode;
                } else {
                    start = newNode;
                }
            }
        }
    }

    // Combine deletion functions into a single function
    void deleteAtPosition(bool after) {
        if (!start) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }

        int key;
        cout << "Enter the data value " << (after ? "after" : "before") << " which you want to delete: ";
        cin >> key;

        Node* temp = start;
        Node* prev = nullptr;

        while (temp && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (!temp || (after && !temp->next) || (!after && !prev)) {
            cout << "Key not found or no node to delete " << (after ? "after" : "before") << ".\n";
        } else {
            if (after) {
                Node* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
            } else {
                Node* nodeToDelete = (prev ? prev->next : start);
                if (prev) {
                    prev->next = nodeToDelete->next;
                } else {
                    start = nodeToDelete->next;
                }
                delete nodeToDelete;
            }
        }
    }

    // Use the common delete function
    void deleteAtEnd() {
        deleteAtPosition(true);
    }

    // Use the common delete function
    void deleteAtBeginning() {
        deleteAtPosition(false);
    }

    void display() {
        if (!start) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = start;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int choice;

    do {
        cout << "1. Insert at End\n2. Insert at Beginning\n3. Insert After\n";
        cout << "4. Insert Before\n5. Delete at End\n6. Delete at Beginning\n";
        cout << "7. Delete After\n8. Delete Before\n9. Display\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                list.insertAtEnd();
                break;

            case 2:
                list.insertAtBeginning();
                break;

            case 3:
                list.insertAtPosition(true);
                break;

            case 4:
                list.insertAtPosition(false);
                break;

            case 5:
                list.deleteAtEnd();
                break;

            case 6:
                list.deleteAtBeginning();
                break;

            case 7:
                list.deleteAtPosition(true);
                break;

            case 8:
                list.deleteAtPosition(false);
                break;

            case 9:
                list.display();
                break;

            case 0:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
