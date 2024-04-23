#include "pch.h"
#include <stack>
using namespace std;

TEST(FuncrionsTest, pushtest) {
    stack<int> stack;
    stack.push(1);
    EXPECT_EQ(1, stack.top());
}

TEST(FuncrionsTest, poptest) {
    stack<int> stack;
    stack.push(2);
    stack.push(3);
    stack.pop();
    EXPECT_EQ(2, stack.top());
}

TEST(FuncrionsTest, Toptest) {
    stack<int> stack;
    stack.push(1);
    stack.push(2);
    EXPECT_EQ(2, stack.top());
}