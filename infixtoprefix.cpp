// #include<iostream>
// using namespace std;

// class Stack {
    
//     int size;


// public:
// int top;
//     char* arr;
//     Stack(int size) {
//         top = -1;
//         this->size = size;
//         arr = new char[size];
//     }

//     ~Stack() {
//         delete[] arr;
//     }

//     int isFull() {
//         return top == size - 1;
//     }

//     int isEmpty() {
//         return top == -1;
//     }

//     void push(char data) {
//         if (isFull()) {
//             cout << "Stack is full. Cannot push." << endl;
//             return;
//         }
//         top++;
//         arr[top] = data;
//     }

//     char pop() {
//         if (isEmpty()) {
//             cout << "Stack is empty. Cannot pop." << endl;
//             return -1;
//         }
//         char data = arr[top];
//         top--;
//         return data;
//     }

//     void display() {
//         if (isEmpty()) {
//             cout << "Stack is empty. Cannot display." << endl;
//             return;
//         }
//         for (int i = top; i >= 0; i--) {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }

//     bool is_operator(char c){
//         switch (c){
//             case '+':
//             case '-':
//             case '/':
//             case '*':
//             case '^':
//                 return true;
//             default :
//                 return false;
//         }
//     }

//     int precedence(char op){
//         switch (op){
//             case '+':
//             case '-':
//                 return 1;
//             case '*':
//             case '/':
//                 return 2;
//             case '^':
//                 return 3;
//             default :
//                 return -1;
//         }
//     }

// };

// int main() {
//  Stack s(10);
//     Stack s2(10);
//     char infix[10];

//     cout << "Enter the infix expression: ";
//     cin >> infix;

//     int i = 0;

//     // Push characters onto s2
//     while (infix[i] != '\0') {
//         s2.push(infix[i++]);
//     }

//     // Pop characters from s2 and overwrite infix
//     i = 0;  // Reset i
//     while (!s2.isEmpty()) {
//         infix[i++] = s2.pop();
//     }

// // make ( to ) and ) to (  you fill

// i=0;
// while (infix[i] != '\0') {
//     if (s.is_operator(infix[i])) {
//         while (!s.isEmpty() && s.precedence(s.arr[s.top]) >= s.precedence(infix[i])) {
//             postfix[j++] = s.pop();
//         }
//         s.push(infix[i]);
//     } else if (infix[i] == '(') {
//         s.push(infix[i]);
//     } else if (infix[i] == ')') {
//         while (!s.isEmpty() && s.arr[s.top] != '(') {
//             postfix[j++] = s.pop();
//         }
//         s.pop(); // remove '('
//     } else {
//         postfix[j++] = infix[i];
//     }
//     i++;
// }


//     while (!s.isEmpty()) {
//         postfix[j++] = s.pop();
//     }


// // same reverse the ans as same technique you fill

// // // make ( to ) and ) to (  you fill

//     cout << "The prefix expression is: ";
//     for (int i = 0; i < j; i++) {
//         cout << postfix[i];
//     }
//     cout << endl;

//     return 0;
// }

// #include<iostream>
// using namespace std;

// class Stack {
//     int size;
// public:
//     int top;
//     char* arr;

//     Stack(int size) {
//         top = -1;
//         this->size = size;
//         arr = new char[size];
//     }

//     ~Stack() {
//         delete[] arr;
//     }

//     int isFull() {
//         return top == size - 1;
//     }

//     int isEmpty() {
//         return top == -1;
//     }

//     void push(char data) {
//         if (isFull()) {
//             cout << "Stack is full. Cannot push." << endl;
//             return;
//         }
//         top++;
//         arr[top] = data;
//     }

//     char pop() {
//         if (isEmpty()) {
//             cout << "Stack is empty. Cannot pop." << endl;
//             return -1;
//         }
//         char data = arr[top];
//         top--;
//         return data;
//     }

//     void display() {
//         if (isEmpty()) {
//             cout << "Stack is empty. Cannot display." << endl;
//             return;
//         }
//         for (int i = top; i >= 0; i--) {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }

//     bool is_operator(char c){
//         switch (c){
//             case '+':
//             case '-':
//             case '/':
//             case '*':
//             case '^':
//                 return true;
//             default :
//                 return false;
//         }
//     }

//     int precedence(char op){
//         switch (op){
//             case '+':
//             case '-':
//                 return 1;
//             case '*':
//             case '/':
//                 return 2;
//             case '^':
//                 return 3;
//             default :
//                 return -1;
//         }
//     }

// };

// int main() {
//     Stack s(10);
//     char infix[10], postfix[10], prefix[10];
//     int i = 0, j = 0;

//     cout << "Enter the infix expression: ";
//     cin >> infix;

//     // Push characters onto s2
//     while (infix[i] != '\0') {
//         s.push(infix[i++]);
//     }

//     // Pop characters from s and overwrite infix
//     i = 0;  // Reset i
//     while (!s.isEmpty()) {
//         infix[i++] = s.pop();
//     }

//     // Reverse the infix expression
//     i = 0;  // Reset i
//     while (infix[i] != '\0') {
//         if (infix[i] == '(') {
//             infix[i] = ')';
//         } else if (infix[i] == ')') {
//             infix[i] = '(';
//         }
//         i++;
//     }

//     // Convert infix to prefix
//     i = 0;
//     while (infix[i] != '\0') {
//         if (s.is_operator(infix[i])) {
//             while (!s.isEmpty() && s.precedence(s.arr[s.top]) >= s.precedence(infix[i])) {
//                 postfix[j++] = s.pop();
//             }
//             s.push(infix[i]);
//         } else if (infix[i] == '(') {
//             s.push(infix[i]);
//         } else if (infix[i] == ')') {
//             while (!s.isEmpty() && s.arr[s.top] != '(') {
//                 postfix[j++] = s.pop();
//             }
//             s.pop(); // remove '('
//         } else {
//             postfix[j++] = infix[i];
//         }
//         i++;
//     }

//     while (!s.isEmpty()) {
//         postfix[j++] = s.pop();
//     }

//     // Reverse the postfix expression to get the prefix expression
//     i = 0;  // Reset i
//     while (j > 0) {
//         prefix[i++] = postfix[--j];
//     }

//     // Print the prefix expression
//     i = 0;  // Reset i
//     cout << "The prefix expression is: ";
//     while (prefix[i] != '\0') {
//         cout << prefix[i++];
//     }
//     cout << endl;

//     return 0;
// }



#include<iostream>
#include<cstring>
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

    bool is_operator(char c) {
        switch (c) {
            case '+':
            case '-':
            case '/':
            case '*':
            case '^':
                return true;
            default:
                return false;
        }
    }

    int precedence(char op) {
        switch (op) {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            case '^':
                return 3;
            default:
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

    int infixLength = strlen(infix);

    // Allocate memory dynamically for the prefix array
    char* prefix = new char[infixLength + 1];

    // Push characters onto the stack
    while (infix[i] != '\0') {
        s.push(infix[i++]);
    }

    // Pop characters from the stack and overwrite infix
    i = 0;  // Reset i
    while (!s.isEmpty()) {
        infix[i++] = s.pop();
    }

    // Reverse the infix expression
    i = 0;  // Reset i
    while (infix[i] != '\0') {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
        i++;
    }

    // Convert infix to postfix
    i = 0;
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

    // Reverse the postfix expression to get the prefix expression
    i = 0;  // Reset i
    while (j > 0) {
        prefix[i++] = postfix[--j];
    }

    // Null-terminate the prefix expression
    prefix[i] = '\0';

    // Print the prefix expression
    cout << "The prefix expression is: " << prefix << endl;

    // Deallocate dynamically allocated memory
    delete[] prefix;

    return 0;
}

