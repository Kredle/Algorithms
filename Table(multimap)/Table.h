#pragma once
#include <string>
#include <iostream>
using namespace std;

class Table {
public:
    typedef int KeyType;
    typedef string ValueType;
    struct KeyNode {
        int key;
        int index;
    };
    struct ValueNode {
        string value;
        int index;
    };
private:
    int size;
    int count;
    int place;
    KeyNode* keys;
    ValueNode* values;
public:
    Table(): size(0), count(0),place(1),keys(nullptr),values(nullptr){}
    Table(int s);
    Table(const Table& other);
    ~Table();
    int getCount() { return count; }
    int getplace() { return place; }
    int getsize() { return size; }
    int* getKeysArr();
    string* getValuesArr();
    void push(int key, const string value);
    void del(int key);
    string getValue(int key);
    int getKey(const string value);
    void print();
    void resize();
    bool IsinTable(int key, const string value);
};
