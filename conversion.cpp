/*Implement C++ program for expression conversion as infix to postfix and its evaluation using stack based on given conditions:
1. Operands and operator, both must be single character.
2. Input Postfix expression must be in a desired format.
3. Only '+', '-', '*' and '/ ' operators are expected.*/

#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to check if a character is an operand
bool isOperand(char ch) {
    return isalnum(ch);
}

// Convert infix expression to postfix expression
string infixToPostfix(const string& infix) {
    stack<char> s;
    string postfix = "";

    for (char ch : infix) {
        if (isOperand(ch)) {
            postfix += ch; // Append operand to postfix
        } else if (ch == '(') {
            s.push(ch); // Push '(' onto stack
        } else if (ch == ')') {
            // Pop from stack until '(' is found
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Pop '('
        } else if (isOperator(ch)) {
            // Pop operators with higher or equal precedence
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch); // Push current operator
        }
    }

    // Pop remaining operators in the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Evaluate a postfix expression
int evaluatePostfix(const string& postfix) {
    stack<int> s;

    for (char ch : postfix) {
        if (isOperand(ch)) {
            s.push(ch - '0'); // Convert char to int and push
        } else if (isOperator(ch)) {
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();
            switch (ch) {
                case '+': s.push(operand1 + operand2); break;
                case '-': s.push(operand1 - operand2); break;
                case '*': s.push(operand1 * operand2); break;
                case '/': s.push(operand1 / operand2); break;
            }
        }
    }

    return s.top(); // Final result
}

int main() {
    string infixExpression;

    cout << "Enter infix expression: ";
    cin >> infixExpression;

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    int result = evaluatePostfix(postfixExpression);
    cout << "Result after evaluation: " << result << endl;

    return 0;
}
