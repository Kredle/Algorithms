#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
struct Node {
    T elem;
    int prior;
    Node<T>* next;
    Node<T>* prev;
    Node() : elem(T()), next(nullptr), prev(nullptr) {}
    Node(T el, int pr = 0, Node<T>* n = nullptr, Node<T>* p = nullptr) : elem(el), next(n), prev(p) {
        if (pr < 0) pr = 0;
        prior = pr;
    }
};

template <typename T>
class Queue {
private:
    Node<T>* last_elem;
    Node<T>* first_elem;
public:
    Queue(Node<T>* b = nullptr, Node<T>* t = nullptr) {
        if (b != nullptr && t == nullptr) {
            cout << "Wrong input. Fixing...\n";
            t = b;
          }
        else if(b == nullptr && t != nullptr) {
            cout << "Wrong input. Fixing...\n";
            b = t;
        }
        last_elem = b;
        first_elem = t;
    }

    bool isEmpty() {
        return last_elem == nullptr;
    }

    T front() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return T();
        }
        return first_elem->elem;
    }

    T back() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return T();
        }
        return last_elem->elem;
    }

    void enqueue(T n) {
        Node<T>* newNode = new Node<T>(n);
        if (isEmpty()) {
            last_elem = newNode;
            first_elem = newNode;
            return;
        }
        else {
            newNode->next = last_elem;
            last_elem->prev = newNode;
            last_elem = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        Node<T>* victim = first_elem;
        first_elem = first_elem->prev;
        if (first_elem != nullptr) first_elem->next = nullptr;
        delete victim;
    }

    void print() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        Node<T>* curr = last_elem;
        cout << "Queue: ";
        while (curr != nullptr) {
            cout << curr->elem << ' ';
            curr = curr->next;
        }
        cout << endl;
    }

    int size() {
        if (isEmpty()) return 0;
        int size = 0;
        Node<T>* curr = last_elem;
        while (curr != nullptr) {
            ++size;
            curr = curr->next;
        }
        return size;
    }
};


template <typename T>
class prior_queue {
private:
    Node<T>* last_elem;
    Node<T>* first_elem;
public:
    prior_queue(Node<T>* b = nullptr, Node<T>* t = nullptr) {
        if (b != nullptr && t == nullptr) {
            cout << "Wrong input. Fixing...\n";
            t = b;
        }
        else if (b == nullptr && t != nullptr) {
            cout << "Wrong input. Fixing...\n";
            b = t;
        }
        last_elem = b;
        first_elem = t;
    }
    bool isEmpty() {
        return last_elem == nullptr;
    }

    T front() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return T();
        }
        return first_elem->elem;
    }

    T back() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return T();
        }
        return last_elem->elem;
    }

    void enqueue(T n, int prior) {
        Node<T>* newNode = new Node<T>(n, prior);
        if (isEmpty()) {
            last_elem = newNode;
            first_elem = newNode;
            return;
        }
        if (prior < 0) {
            cout << "Error: negative prior.\n";
            prior = 0;
        }
        Node<T>* curr = last_elem;
        while (curr != nullptr && curr->prior <= prior) curr = curr->next;
        if (curr == nullptr) {
            newNode->prev = first_elem;
            first_elem->next = newNode;
            first_elem = newNode;
        }
        else {
            Node<T>* prev = curr->prev;
            if (prev == nullptr) {
                newNode->next = last_elem;
                last_elem->prev = newNode;
                last_elem = newNode;
            }
            else {
                newNode->next = prev->next;
                prev->next = newNode;
            }
        }
    }


    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        Node<T>* victim = first_elem;
        first_elem = first_elem->prev;
        if (first_elem != nullptr) first_elem->next = nullptr;
        delete victim;
    }

    void print() {
        if (isEmpty()) {
            cout << "Priority Queue is empty\n";
            return;
        }
        Node<T>* curr = last_elem;
        cout << "Priority Queue: ";
        while (curr != nullptr) {
            cout << curr->elem << '(' << curr->prior << ')' << ' ';
            curr = curr->next;
        }
        cout << endl;
    }

    int size() {
        if (isEmpty()) return 0;
        int size = 0;
        Node<T>* curr = last_elem;
        while (curr != nullptr) {
            ++size;
            curr = curr->next;
        }
        return size;
    }
};