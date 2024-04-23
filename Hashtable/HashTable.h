#pragma once
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class HashTable {
private:
    struct Node {
        int key;
        string value;
        Node* next;

        Node(int k,string v) : key(k), value(v), next(nullptr) {}
        Node() : key(0), value(" "), next(nullptr){}
    };

    using List_t = Node*;
    static const int size = 10;
    List_t table[size];


public:
    HashTable() {
        for (int i = 0; i < size; ++i)
            table[i] = nullptr;
    }
    ~HashTable() {
        for (int i = 0; i < size; ++i) {
            List_t curr = table[i];
            while (curr != nullptr) {
                List_t next = curr->next;
                delete curr;
                curr = next;
            }
            table[i] = nullptr;
        }
    }
    int hashFunc(int key) {
        return key % size;
    }
    bool isEmpty() {
        for (int i = 0; i < size; ++i) {
            if (table[i] != nullptr)
                return false;
        }
        return true;
    }

    void insert(int key, string value) {
        int hash = hashFunc(key);
        List_t newNode = new Node(key, value);

        List_t current = table[hash];
        while (current != nullptr) {
            if (current->key == key) {
                cout << "This key is already in table\n";
                return;
            }
            current = current->next;
        }

        if (table[hash] == nullptr) {
            table[hash] = newNode;
        }
        else {
            List_t temp = table[hash];
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    void rewrite(int key, string value) {
        int hash = hashFunc(key);
        List_t temp = table[hash];
        if (isEmpty()) {
            cout << "Empty table\n"; return;
        }
        while (temp != nullptr) {
            if (temp->key == key) {
                temp->value = value;
                return;
            }
            temp = temp->next;
        }
        cout << "Key isn't found\n";
    }
    bool IsInTable(int key) {
        int hash = hashFunc(key);
        List_t temp = table[hash];
        if (temp == nullptr) return false;
        else {
            while (temp != nullptr) {
                if (temp->key == key) return true;
                temp = temp->next;
            }
        }
        return false;
    }
    void remove(int key) {
        int hash = hashFunc(key);
        if (isEmpty()) cout << "Empty table\n";
        else {
            if (table[hash] == nullptr) {
                cout << "Key isn't found." << endl;
                return;
            }

            List_t prev = nullptr;
            List_t victim = table[hash];
            if (victim != nullptr) {
                while (victim->key != key) {
                    prev = victim;
                    victim = victim->next;
                }
            }

            if (victim == nullptr) {
                cout << "Key isn't found." << endl;
                return;
            }

            if (prev == nullptr) {
                table[hash] = victim->next;
            }
            else {
                prev->next = victim->next;
            }

            delete victim;
        }
    }

    string getValue(int key) {
        int hash = hashFunc(key);
        List_t temp = table[hash];
        while (temp != nullptr) {
            if (temp->key == key)
                return temp->value;
            temp = temp->next;
        }
        return " ";
    }

    void print() {
        if (isEmpty()) cout << "Empty table\n";
        else {
            for (int i = 0; i < size; ++i) {
                cout << "Element " << i << ": ";
                List_t temp = table[i];
                while (temp != nullptr) {
                    cout << '[' << temp->key << ": " << temp->value << "] ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
    }
};