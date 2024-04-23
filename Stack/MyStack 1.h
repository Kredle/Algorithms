#pragma once
#include <iostream>
#include "gtest/gtest.h"
using namespace std;
class Node;
using List_t = Node*;

class Node {
private:
	int value;
	List_t next;
public:
	Node(int v, List_t link) : value(v), next(link) {}
	Node() : value(0), next(nullptr) {}
	Node(const Node& n) : value(n.value), next(n.next) {}
	int getvalue() { return value; }
	List_t getnext() { return next; }
	friend class Stack;
};

class Stack {
private:
	List_t top_elem;
public:
	Stack() : top_elem(nullptr) {}
	Stack(List_t top) : top_elem(top) {}
	void push(int n) {
		List_t NewNode = new Node(n, nullptr);
		NewNode->next = top_elem;
		top_elem = NewNode;
	}
	void pop() {
		if (top_elem != nullptr) {
			List_t victim = top_elem;
			top_elem = top_elem->next;
			delete victim;
		}
		else {
			cout << "Stack is empty\n";
		}
	}
	void show() {
		if (top_elem != nullptr) cout << top_elem->value << '\n';
		else cout << "Stack is empty\n";
	}
	int gettop() { return top_elem->value; }
};