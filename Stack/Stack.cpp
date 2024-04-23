#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> stack;
	stack.push(15);
	stack.push(20);
	stack.push(100);
	cout << "Top elem: " << stack.top() << '\n';
	stack.pop();
	cout << "Top elem: " << stack.top() << '\n';
	stack.pop();
	cout << "Top elem: " << stack.top() << '\n';

}