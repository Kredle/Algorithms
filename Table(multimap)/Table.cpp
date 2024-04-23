#include "pch.h"
#include "Table.h"
#include <iostream>
using namespace std;

Table::Table(int s): size(s),count(0),place(1) {
    keys = new KeyNode[size];
    values = new ValueNode[size];
}

Table::~Table() {
    delete[] keys;
    delete[] values;
}

bool Table::IsinTable(int key, const string value) {
    for (int i = 0; i < count; ++i) {
        if (keys[i].key == key && values[i].value == value) {
            return true;
        }
    }
    return false;
}


void Table::resize() {
    int newSize = size * 2;
    KeyNode* newKeys = new KeyNode[newSize];
    ValueNode* newValues = new ValueNode[newSize];
    for (int i = 0; i < size; ++i) {
        newKeys[i] = keys[i];
        newValues[i] = values[i];
    }
    delete[] keys;
    delete[] values;
    keys = newKeys;
    values = newValues;
    size = newSize;
}

int* Table::getKeysArr()
{
    int* result = new int[count];
    for (int i = 0; i < count; ++i) {
        result[i] = keys[i].key;
    }
    return result;
}

string* Table::getValuesArr()
{
    string* result = new string[count];
    for (int i = 0; i < count; ++i) {
        result[i] = values[i].value;
    }
    return result;
}

void Table::push(int key, const string value) {
    if (IsinTable(key, value)) {
        cout << "This item alredy exists\n";
    }
    else {
        if (count >= size) {
            resize();
        }
        else {
            keys[count].key = key;
            values[count].value = value;
            values[count].index = count;
            keys[count].index = count;
            ++count;
            ++place;
        }
    }
}

void Table::print() {
    if (count != 0) {
        for (int i = 0; i < count; ++i) {
            cout << keys[i].key << ": " << values[keys[i].index].value << endl;
        }
    }
    else cout << "Table is empty\n";
}

int Table::getKey(const string value) {
    for (int i = 0; i < count; i++) {
        if (values[i].value == value) {
            return keys[values[i].index].key;
        }
    }
    return -1;
}

string Table::getValue(int key) {
    for (int i = 0; i < count; ++i) {
        if (keys[i].key == key) {
            return values[keys[i].index].value;
        }
    }
    return " ";
}

void Table::del(int key) {
    for (int i = 0; i < count; ++i) {
        if (keys[i].key == key) {
            values[keys[i].index].value = string();
            for (int j = i + 1; j < count; ++j) {
                keys[j - 1] = keys[j];
                values[keys[j].index - 1] = values[keys[j].index];
                keys[j - 1].index = j - 1;
                values[keys[j].index - 1].index = j - 1;
            }
            --count;
            --place;

            return;
        }
    }
    cout << "Key hasnt been found\n";
}

Table::Table(const Table& other) {
    size = other.size;
    count = other.count;
    place = other.place;

    keys = new KeyNode[size];
    values = new ValueNode[size];

    for (int i = 0; i < count; ++i) {
        keys[i] = other.keys[i];
        values[i] = other.values[i];
    }
}