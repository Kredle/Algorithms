#pragma once
#include "pch.h"
#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
class Node {
public:
    T value;
    Node<T>* next;

    Node(T val, Node<T>* nxt) : value(val), next(nxt) {}
};

template<typename T>
class Stack {
private:
    Node<T>* top_elem;

public:
    Stack() : top_elem(nullptr) {}

    ~Stack() {
        while (top_elem != nullptr) {
            pop();
        }
    }

    void push(T value) {
        Node<T>* newNode = new Node<T>(value, top_elem);
        top_elem = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        Node<T>* temp = top_elem;
        top_elem = top_elem->next;
        delete temp;
    }

    T top() {
        if (isEmpty()) {
            cout<< "Stack is empty";
        }
        return top_elem->value;
    }

    bool isEmpty() {
        return top_elem == nullptr;
    }

    int length() {
        int len = 0;
        Node<T>* current = top_elem;
        while (current != nullptr) {
            len++;
            current = current->next;
        }
        return len;
    }
};

bool isNumb(char c) {
    return c >= '0' && c <= '9';
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
int priority(char a) {
    if (a == '+' || a == '-')  return 1;

    if (a == '*' || a == '/') return 2;

    return 0;
}
int charToInt(char c) {
    return c - '0';
}

int readNumber(const string& expr, int& pos) {
    int number = 0;
    while (pos >= 0 && pos < expr.size() && isNumb(expr[pos])) {
        number = number * 10 + charToInt(expr[pos]);
        ++pos;
    }
    return number;
}

int calculate(int operand1, int operand2, char op) {
    switch (op) {
    case '+': return operand1 + operand2;
    case '-': return operand1 - operand2;
    case '*': return operand1 * operand2;
    case '/': return operand1 / operand2;
    default: throw "Invalid operator";
    }
}
string convertToPostfix(string infix) {
    Stack<char> a;
    string output = "";
    for (int i = 0; i < infix.size(); ++i) {
        if (isNumb(infix[i])) {
            output += infix[i];
        }
        else if (infix[i] == '(') {
            if (!output.empty() && output.back() != ' ') {
                output += ' ';
            }
            a.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (!a.isEmpty() && a.top() != '(') {
                if (output.back() != ' ') {
                    output += ' ';
                }
                output += a.top();
                a.pop();
            }
            a.pop();
        }
        else if (isOperator(infix[i])) {
            while (!a.isEmpty() && priority(infix[i]) <= priority(a.top())) {
                if (output.back() != ' ') {
                    output += ' ';
                }
                output += a.top();
                a.pop();
            }
            if (!output.empty() && output.back() != ' ') {
                output += ' ';
            }
            a.push(infix[i]);
        }
        else if (infix[i] != ' ') {
            throw "Invalid symbol";
        }
    }
    while (!a.isEmpty()) {
        if (output.back() != ' ') {
            output += ' ';
        }
        output += a.top();
        a.pop();
    }
    return output;
}
int calculRPN(string expr) {

    Stack<int> operands;
    int pos = 0;

    while (pos < expr.size()) {
        if (isNumb(expr[pos])) {
            int number = readNumber(expr, pos);
            operands.push(number);
        }
        else if (isOperator(expr[pos])) {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            operands.push(calculate(operand1, operand2, expr[pos]));
        }
        else if (expr[pos] != ' ') {
            throw "Invalid symbol";
        }
        ++pos;
    }

    int result = operands.top();
    operands.pop();

    if (!operands.isEmpty()) {
        throw "Invalid expression";
    }

    return result;
}


int calculRPN_with_convertation(string expr) {
    string postfix = convertToPostfix(expr);

    Stack<int> operands;
    int pos = 0;

    while (pos < postfix.size()) {
        if (isNumb(postfix[pos])) {
            int number = readNumber(postfix, pos);
            operands.push(number);
        }
        else if (isOperator(postfix[pos])) {
            if (operands.isEmpty()) {
                throw "Invalid expression";
            }
            int operand2 = operands.top();
            operands.pop();
            if (operands.isEmpty()) {
                throw "Invalid expression";
            }
            int operand1 = operands.top();
            operands.pop();
            operands.push(calculate(operand1, operand2, postfix[pos]));
        }
        else if (postfix[pos] != ' ') {
            throw "Invalid symbol";
        }
        ++pos;
    }

    if (operands.isEmpty()) {
        throw "Invalid expression";
    }

    int result = operands.top();
    operands.pop();


    return result;
}