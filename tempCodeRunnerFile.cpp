
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

//     cout << "The postfix expression is: ";
//     for (int i = 0; i < j; i++) {
//         cout << postfix[i];
//     }
//     cout << endl;