#include "pch.h"
#include <iostream>
using namespace std;

template <typename T = int>
struct Node {
    T value;
    Node<T>* left;
    Node<T>* right;
    size_t h;

    Node(T v = T(), Node<T>* l = nullptr, Node<T>* r = nullptr, size_t h = 1)
        : value(v), left(l), right(r), h(h) {}
};

template<typename T>
class AVL_Tree {
    Node<T>* tree;
public:
    AVL_Tree(Node<T>* t = nullptr) : tree(t) {}

    size_t height(Node<T>* node) {
        if (node == nullptr) return 0;
        return node->h;
    }

    void update_h(Node<T>* node) {
        if (node!=nullptr) {
            if (height(node->left) > height(node->right)) {
                node->h = 1 + height(node->left); return;
            }
            node->h = 1 + height(node->right);
            return;
        }
    }

    int balance_fac(Node<T>* node) {
        if (node == nullptr) return -1;
        return height(node->left) - height(node->right);
    }

    T find(Node<T>* a, T value) {
        if (a == nullptr) return -1;
        if (value < a->value) return find(a->left, value);
        else if (value > a->value) return find(a->right, value);
        else if (value == a->value) return value;
    }

    T find(T value) {
        return find(tree, value);
    }

    Node<T>* r_rotation(Node<T>*& y) {
        Node<T>* x = y->left;
        Node<T>* a = x->right;

        x->right = y;
        y->left = a;

        update_h(x);
        update_h(y);

        return x;
    }

    Node<T>* l_rotation(Node<T>*& x) {
        Node<T>* y = x->right;
        Node<T>* a = y->left;

        y->left = x;
        x->right = a;

        update_h(x);
        update_h(y);

        return y;
    }

    Node<T>* min_value_node(Node<T>* node) {
        Node<T>* curr = node;
        while (curr!=nullptr && curr->left != nullptr) curr = curr->left;
        return curr;
    }
    Node<T>* insert(Node<T>*& a, T value) {
        if (a == nullptr) {
            a = new Node<T>(value);
            return a;
        }
        if (value < a->value) a->left = insert(a->left, value);
        else if (value > a->value) a->right = insert(a->right, value);
        else { cout << "This node is already in the tree\n"; return a; }

        update_h(a);
        int balance = balance_fac(a);
        if (balance > 1 && value < a->left->value) {
            a = r_rotation(a);
            return a;
        }
        else if (balance < -1 && value > a->right->value) {
            a = l_rotation(a);
            return a;
        }
        else if (balance > 1 && value > a->left->value) {
            a->left = l_rotation(a->left);
            a = r_rotation(a);
            return a;
        }
        else if (balance < -1 && value < a->right->value) {
            a->right = r_rotation(a->right);
            a = l_rotation(a);
            return a;
        }
        return a;
    }

    Node<T>* remove(Node<T>*& a, T value) {
        if (a == nullptr) return a;
        if (find(value) == -1) {cout << "Havent found node " << value << '\n'; return a; }
        if (value < a->value) a->left = remove(a->left, value);
        else if (value > a->value) a->right = remove(a->right, value);
        else {
            if (a->left == nullptr) {
                Node<T>* temp = a->right;
                delete a;
                return temp;
            }
            else if (a->right == nullptr) {
                Node<T>* temp = a->left;
                delete a;
                return temp;
            }
            else {
                Node<T>* temp = min_value_node(a->right);
                a->value = temp->value;
                a->right = remove(a->right, temp->value);
            }
        }
        int balance = balance_fac(a);
        if (balance == 2 && balance_fac(a->left) >= 0) return r_rotation(a);
        else if (balance == 2 && balance_fac(a->left) == -1) {
            a->left = l_rotation(a->left);
            return r_rotation(a);
        }
        else if (balance == -2 && balance_fac(a->right) <= 0) return l_rotation(a);
        else if (balance == -2 && balance_fac(a->right) == 1) {
            a->right = r_rotation(a->right);
            return l_rotation(a);
        }
        return a;
    }



    void print(int shift, Node<T>* r) {
        if (r->left != nullptr) print(shift + 5, r->left);
        for (int i = 0; i < shift; ++i) cout << ' ';
        cout << r->value << '\n';
        if (r->right != nullptr) print(shift + 5, r->right);
    }
    Node<T>* get_root() { return tree; }

    void insert(T value) {
        insert(tree, value);
    }

    void remove(T value) {
        remove(tree, value);
    }

    void print() {
        print(0, tree);
    }
    void preorder(Node<T>* r) {
        if (r != nullptr) {
            cout << r->value << " ";
            preorder(r->left);
            preorder(r->right);
        }
    }
    void print_preorder() {
        preorder(tree);
    }
   
    void postorder(Node<T>* r) {
        if (r != nullptr) {
            postorder(r->left);
            postorder(r->right);
            cout << r->value << " ";
        }
    }
    void print_postorder() {
        postorder(tree);
    }
    
};
