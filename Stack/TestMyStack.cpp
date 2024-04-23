#include "pch.h"
#include "MyStack.h"
#include "gtest/gtest.h"
#include "string"

TEST(FunctionTest, pushtest) {
    List_t list = new Node(1, new Node(2, nullptr));
    Stack stack(list);
    stack.push(3);
    EXPECT_EQ(3, stack.gettop());
}

TEST(FunctionTest, poptest) {
	List_t list = new Node(1, new Node(2, nullptr));
	Stack stack(list);
	stack.pop();
	EXPECT_EQ(2, stack.gettop());
}

TEST(FunctionTest, emptypop) {
	Stack stack;
	testing::internal::CaptureStdout();
	stack.pop();
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Stack is empty\n");
}

TEST(FunctionTest, showtest) {
	List_t l = new Node(25, new Node(11, new Node(13, nullptr)));
	Stack stack(l);
	testing::internal::CaptureStdout();
	stack.show();
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "25\n");
}

TEST(FunctionTest, emptyshowtest) {
	Stack stack;
	testing::internal::CaptureStdout();
	stack.show();
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Stack is empty\n");
}

TEST(ConstructorTest, NodeDefault) {
	Node n;
	EXPECT_EQ(n.getvalue(), 0);
	EXPECT_EQ(n.getnext(), nullptr);
}

TEST(ConstructorTest, NodeParametru) {
	Node a(5, nullptr);
	Node b(6, &a);
	EXPECT_EQ(b.getvalue(), 6);
	EXPECT_EQ(b.getnext(), &a);
}

TEST(ConstructorTest, NodeCopy) {
	Node a(4, nullptr);
	Node b(a);
	EXPECT_EQ(b.getvalue(), 4);
	EXPECT_EQ(b.getnext(), nullptr);
}
