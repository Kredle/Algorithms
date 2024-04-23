#pragma once
#include "pch.h"
#include <iostream>
using namespace std;

template <typename T>
class SparseMatrix {
private:
    struct Node {
        T data;
        int row;
        int col;
        Node* down;
        Node* right;

        Node(T data = 0, Node* down = nullptr, Node* right = nullptr, int r = -1, int c = -1): data(data), down(down), right(right), row(r), col(c) {}
    };

    Node* rows;
    Node* cols;
    int row_count;
    int col_count;
    static const int MAX_SIZE = 20;

public:
    SparseMatrix() : rows(nullptr), cols(nullptr), row_count(0), col_count(0) {}

    SparseMatrix(int r, int c) : row_count(r), col_count(c) {
        if (c >= 0 && c <= MAX_SIZE && r >= 0 && r <= MAX_SIZE) {
            rows = new Node();
            cols = new Node();
            Node* row_curr = rows;
            Node* col_curr = cols;
            for (int i = 0; i < r; ++i) {
                row_curr->down = new Node(0, nullptr, nullptr, i, -1);
                row_curr = row_curr->down;
            }
            for (int i = 0; i < c; ++i) {
                col_curr->right = new Node(0, nullptr, nullptr, -1, i);
                col_curr = col_curr->right;
            }
        }
        else {
            cout << "Wrong size\n";
            SparseMatrix();
        }
    }
    


    Node* get_prev_by_row(int row, int col) {
        Node* current = rows;
        while (current->down!=nullptr && current->down->row < row) {
            current = current->down;
        }
        while (current->right!=nullptr && current->right->col < col) {
            current = current->right;
        }
        return current;
    }

    Node* get_prev_by_col(int row, int col) {
        Node* current = cols;
        while (current->right!=nullptr && current->right->col < col) {
            current = current->right;
        }
        while (current->down!=nullptr && current->down->row < row) {
            current = current->down;
        }
        return current;
    }

    void insert(T d, int r, int c) {
        if (r < 0 || c < 0 || r >= row_count || c >= col_count) {
            cout << "Out_of_range\n";
            return;
        }
        if (get_element(r, c) != 0) {
            cout << "This elem already exists\n";
            return;
        }
        if (d == 0) return;
        Node* prev_by_row = get_prev_by_row(r, c);
        Node* prev_by_col = get_prev_by_col(r, c);

        Node* newNode = new Node(d, nullptr, nullptr, r, c);

        newNode->right = prev_by_row->right;
        prev_by_row->right = newNode;

        newNode->down = prev_by_col->down;
        prev_by_col->down = newNode;

    }

    void remove(int r, int c) {
        if (row_count == 0) {
            cout << "Empty matrix\n";
            return;
        }
        if (r < 0 || c < 0 || r >= row_count || c >= col_count) {
            cout << "Out_of_range\n";
            return;
        }
        if (get_element(r, c) == 0) {
            cout << "This element doesn't exist\n";
            return;
        }
        Node* prev_by_row = get_prev_by_row(r, c);
        Node* prev_by_col = get_prev_by_col(r, c);
        Node* curr = prev_by_row->right;
        if (curr!=nullptr && curr->col == c) {
            prev_by_row->right = curr->right;
            prev_by_col->down = curr->down;
            delete curr;
        }
    }

    T get_element(int r, int c) {
        if (row_count == 0) {
            cout << "Empty matrix\n";
            return -1;
        }
        if (r < 0 || c < 0 || r >= row_count || c >= col_count) {
            cout << "Out_of_range\n";
            return -1;
        }
        Node* prev_by_row = get_prev_by_row(r, c);
        Node* curr = prev_by_row->right;
        T res = T();
        if (curr != nullptr && curr->col == c) res = curr->data;
        return res;
    }

    SparseMatrix<T> operator* (SparseMatrix<T>& other) {
        if (row_count != other.col_count) {
            cout << "ERROR: DIFFERENT SIZES\n";
            return SparseMatrix<T>();
        }
        SparseMatrix<T> res(row_count, other.col_count);
        for (int i = 0; i < row_count; ++i) {
            for (int j = 0; j < other.col_count; ++j) {
                T sum = 0;
                for (int l = 0; l < row_count; ++l) {
                    if (get_element(i, l) != 0 && other.get_element(l, j) != 0) {
                        sum += get_element(i, l) * other.get_element(l, j);
                    }
                }

                res.insert(sum, i, j);

            }
        }
        return res;
    }

    SparseMatrix<T> operator+(SparseMatrix& other) {
        if (row_count != other.row_count && col_count != other.col_count) {
            cout << "ERROR: DIFFERENT SIZES\n";
            return SparseMatrix<T>();
        }
        SparseMatrix<T> res(row_count, col_count);
        for (int i = 0; i < row_count; ++i) {
            for (int j = 0; j < col_count; ++j) {
                T sum = get_element(i, j) + other.get_element(i, j);
                if (sum != 0) {
                    res.insert(sum, i, j);
                }
            }
        }
        return res;
    }

    SparseMatrix<T> operator-(SparseMatrix& other) {
        if (row_count != other.row_count && col_count != other.col_count) {
            cout << "ERROR: DIFFERENT SIZES\n";
            return SparseMatrix<T>();
        }
        SparseMatrix<T> res(row_count, col_count);
        for (int i = 0; i < row_count; ++i) {
            for (int j = 0; j < col_count; ++j) {
                T a = get_element(i, j) - other.get_element(i, j);
                if (a != 0) {
                    res.insert(a, i, j);
                }
            }
        }
        return res;
    }

    SparseMatrix<T> pow(int n) {
        if (n < 0) { cout << "Enter only positive numb\n"; return *this; }
        else if (n == 0) {
            SparseMatrix<T> res(row_count, col_count);
            for (int i = 0; i < row_count; ++i) {
                res.insert(1, i, i);
            }
            return res;
        }

        SparseMatrix<T> res = *this;
        for (int k = 0; k < n - 1; ++k) {
            res = res * (*this);
        }
        return res;
    }

    SparseMatrix<T> operator*(T c) {
        if (c == 0) { cout << "Error: c=0\n"; return *this; }
        SparseMatrix<T> res(row_count, col_count);
        for (int i = 0; i < row_count; ++i) {
            for (int j = 0; j < col_count; ++j) {
                T elem = c * get_element(i, j);
                if (elem != 0) {
                    res.insert(elem, i, j);
                }
            }
        }
        return res;
    }

    SparseMatrix<T> transpose() {
        SparseMatrix<T> res(col_count, row_count);
        for (int i = 0; i < row_count; ++i) {
            for (int j = 0; j < col_count; ++j) {
                T elem = get_element(i, j);
                if (elem != 0) {
                    res.insert(elem, j, i);
                }
            }
        }
        return res;
    }

    void print() {
        if (row_count > 0 && row_count <= MAX_SIZE && col_count > 0 && col_count <= MAX_SIZE) {
            Node* row_curr = rows;
            for (int i = 0; i < row_count; ++i) {
                Node* curr = row_curr->right;
                for (int j = 0; j < col_count; ++j) {
                    if (curr != nullptr && curr->col == j) {
                        cout << curr->data << ' ';
                        curr = curr->right;
                    }
                    else {
                        cout << "0 ";
                    }
                }
                cout << endl;
                row_curr = row_curr->down;
            }
        }
        else if (row_count == 0 || col_count == 0) {
            cout << "Empty matrix\n";
        }
        else {
            cout << "Size is bigger than MAX_SIZE\n";
        }
    }

    bool isEmpty() {
        for (int i = 0; i < row_count; ++i) {
            for (int j = 0; j < col_count; ++j) {
                if (get_element(i, j) != 0) return 0;
            }
        }
        return 1;
    }
};