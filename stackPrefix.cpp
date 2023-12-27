#include<iostream>
using namespace std;

class Stack {
    
    int size;


public:
int top;
    char* arr;
    Stack(int size) {
        top = -1;
        this->size = size;
        arr = new char[size];
    }

    ~Stack() {
        delete[] arr;
    }

    int isFull() {
        return top == size - 1;
    }

    int isEmpty() {
        return top == -1;
    }

    void push(char data) {
        if (isFull()) {
            cout << "Stack is full. Cannot push." << endl;
            return;
        }
        top++;
        arr[top] = data;
    }

    char pop() {
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
    char infix[10], postfix[10];
    int i = 0, j = 0;

    cout << "Enter the infix expression: ";
    cin >> infix;

while (infix[i] != '\0') {
    if (s.is_operator(infix[i])) {
        while (!s.isEmpty() && s.precedence(s.arr[s.top]) >= s.precedence(infix[i])) {
            postfix[j++] = s.pop();
        }
        s.push(infix[i]);
    } else if (infix[i] == '(') {
        s.push(infix[i]);
    } else if (infix[i] == ')') {
        while (!s.isEmpty() && s.arr[s.top] != '(') {
            postfix[j++] = s.pop();
        }
        s.pop(); // remove '('
    } else {
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