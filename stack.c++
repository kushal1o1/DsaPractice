#include<iostream>

using namespace std;

class Stack {
private:
    
    int size;
    char* arr;
    
public:
int top;
    Stack(int size) {
        this->size = size;
        arr = new char[size];
        top = -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(char data) {
        if (isFull()) {
            cout<< "Stack is full. Cannot push." << endl;
            return;
        }
        top++;
        arr[top] = data;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return -1;
        }
        char data = arr[top];
        top--;
        return data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot display." << endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    bool is_operator(char c){
        switch (c){
            case '+':
            case '-':
            case '/':
            case '*':
            case '^':
                return true;
            default :
                return false;
        }
    }

    int precedence(char op){
        switch (op){
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            case '^':
                return 3;
            default :
                return -1;
        }
    }

};

int main() {
    Stack s(10);
    char infix[10];
    int choice;
    char data;
    do {
         cout << "1. Push\n";
         cout << "2. Pop\n";
         cout << "3. Display\n";
         cout << "4. Exit\n";
         cout << "Enter your choice: ";
         cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter data to push: ";
                    cin >> data;
                    s.push(data);
                    break;
                case 2:
                data = s.pop();
                cout << "Popped element: " << data << endl;
                break;
                case 3:
                s.display();
                break;
                case 4:
                break;
                default:
                cout<<"INVALID CHOICE";
                break;
            }
    }while(false);
    

    cout<<"Enter the infix expression: ";
    cin>>infix;
    char postfix[10];
    int i = 0, j = 0;
    
    while(infix[i] != '\0') {
        if (s.is_operator(infix[i])) {
           int x=s.precedence(infix[i]);
           int z=s.top;
            int y=s.precedence(z);
            while(!s.isEmpty() &&  (x <= y)) {
                postfix[j++] = s.pop();
            }
            s.push(infix[i]);
        } else if (infix[i] == '('){
            s.push(infix[i]);
        } else if (infix[i] == ')'){
            while(!s.isEmpty() && s.top != '('){
                postfix[j++] = s.pop();
                   s.pop(); // remove '('
            }
            
        } 
        
        else {
            postfix[j++] = infix[i];
        }
        i++;
    }
 

    while (!s.isEmpty()) {
        postfix[j++] = s.pop();
    }

    cout << "The postfix expression is: ";
    for (int i = 0; i < j; i++) {
        cout << postfix[i];
    }
    cout << endl;

    return 0;
}