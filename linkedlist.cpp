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

    void insertAtEnd() {
        Node* newNode = CreateNode();
        if (!start) {
            start = newNode;
        } else {
            Node* temp = start;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertAtBeginning() {
        Node* newNode = CreateNode();
        newNode->next = start;
        start = newNode;
    }

// Inside the LinkedList class

void insertAfter() {
    if (!start) {
        cout << "List is empty. Cannot insert after.\n";
        return;
    }

    int key;
    cout << "Enter the data value after which you want to insert: ";
    cin >> key;

    Node* newNode = CreateNode();
    Node* temp = start;

    while (temp && temp->data != key) {
        temp = temp->next;
    }

    if (!temp) {
        cout << "Key not found in the list.\n";
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertAfterPosition() {
    // Check if the list is empty
    if (!start) {
        cout << "List is empty. Cannot insert after position.\n";
        return;
    }

    // Prompt user to enter the position
    int position;
    cout << "Enter the position after which you want to insert: ";
    cin >> position;

    // Create a new node
    Node* newNode = CreateNode();

    // Initialize a temporary pointer to traverse the list
    Node* temp = start;

    // Traverse the list until the specified position or the end of the list
    for (int i = 1; i < position && temp; ++i) {
        temp = temp->next;
    }

    // Check if the position exceeds the size of the list
    if (!temp) {
        cout << "Position exceeds the size of the list.\n";
    } else {
        // Insert the new node after the specified position
        newNode->next = temp->next;
        temp->next = newNode;
    }
}


void insertBefore() {
    if (!start) {
        cout << "List is empty. Cannot insert before.\n";
        return;
    }

    int key;
    cout << "Enter the data value before which you want to insert: ";
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
        if (prev) {
            prev->next = newNode;
        } else {
            start = newNode;
        }

        newNode->next = temp;
    }
}

void insertBeforePosition() {
    if (!start) {
        cout << "List is empty. Cannot insert before position.\n";
        return;
    }

    int position;
    cout << "Enter the position before which you want to insert: ";
    cin >> position;

    Node* newNode = CreateNode();
    Node* temp = start;
    Node* prev = nullptr;

    for (int i = 1; i < position && temp; ++i) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp || !prev) {
        cout << "Position exceeds the size of the list.\n";
    } else {
        newNode->next = temp;
        prev->next = newNode;
    }
}


void deleteAtEnd() {
    if (!start) {
        cout << "List is empty. Cannot delete from the end.\n";
        return;
    }

    Node* temp = start;
    Node* prev = nullptr;

    while (temp->next) {
        prev = temp;
        temp = temp->next;
    }

    if (prev) {
        prev->next = nullptr;
        delete temp;
    } else {
        // Only one node in the list
        delete start;
        start = nullptr;
    }
}

void deleteAtBeginning() {
    if (!start) {
        cout << "List is empty. Cannot delete from the beginning.\n";
        return;
    }

    Node* temp = start;
    start = start->next;
    delete temp;
}


// Inside the LinkedList class

void deleteAfter() {
    if (!start) {
        cout << "List is empty. Cannot delete after.\n";
        return;
    }

    int key;
    cout << "Enter the data value after which you want to delete: ";
    cin >> key;

    Node* temp = start;

    while (temp && temp->data != key) {
        temp = temp->next;
    }

    if (!temp || !temp->next) {
        cout << "Key not found or no node to delete after.\n";
    } else {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
}


void deleteAfterPosition() {
    if (!start || !start->next) {
        cout << "List is empty or has only one node. Cannot delete after position.\n";
        return;
    }

    int position;
    cout << "Enter the position after which you want to delete: ";
    cin >> position;

    Node* temp = start;

    for (int i = 1; i < position && temp; ++i) {
        temp = temp->next;
    }

    if (!temp || !temp->next) {
        cout << "Position exceeds the size of the list or no node to delete after.\n";
    } else {
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
        cout << "Node deleted successfully.\n";
    }
}


void deleteBefore() {
    if (!start || !start->next) {
        cout << "List is empty or has only one element. Cannot delete before.\n";
        return;
    }

    int key;
    cout << "Enter the data value before which you want to delete: ";
    cin >> key;

    Node* temp = start;

    if (temp->data == key) {
        cout << "No element before the first node to delete.\n";
    } else {
        Node* prev = nullptr;

        while (temp && temp->next && temp->next->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (!temp || !temp->next || !prev) {
            cout << "Key not found or no node to delete before.\n";
        } else {
            Node* nodeToDelete = prev->next;
            prev->next = nodeToDelete->next;
            delete nodeToDelete;
        }
    }
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
        cout << "7. Delete After\n8. Delete Before\n9. Display\n10.InsertafterPosition\n11.InsertBeforePosition\n12.DeleteafterPosition\n13/DeleteBeforePosition\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                list.insertAtEnd();
                list.display();

                break;

            case 2:
                list.insertAtBeginning();
                list.display();

                break;

            case 3:
                list.insertAfter();
                list.display();

                break;

            case 4:
                list.insertBefore();
                list.display();

                break;

            case 5:
                list.deleteAtEnd();
                list.display();

                break;

            case 6:
                list.deleteAtBeginning();
                list.display();

                break;

            case 7:
                list.deleteAfter();
                list.display();

                break;

            case 8:
                list.deleteBefore();
                list.display();

                break;

            case 9:
                list.display();
                list.display();

                break;

            case 10:
                list.insertAfterPosition();
                list.display();

                break;
            case 11:
                list.insertBeforePosition();
                list.display();

                break;
            case 12:
                list.deleteAfterPosition();
                list.display();

                break;
            case 13:
                list.deleteBeforePosition();
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
