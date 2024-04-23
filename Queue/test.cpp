#include "pch.h"
#include "Paliukh Queue.h"

TEST(Queue_FunctionTest, isEmpty_Test) {
	Queue<int> a(nullptr,nullptr);
	EXPECT_EQ(1, a.isEmpty());
	a.enqueue(1);
	EXPECT_EQ(0, a.isEmpty());
}

TEST(Queue_FunctionTest, front_Test) {
	Queue<int> a(nullptr, nullptr);
	testing::internal::CaptureStdout();
	int a1 = a.front();
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Queue is empty\n");
	a.enqueue(1);
	a.enqueue(2);
	EXPECT_EQ(1, a.front());
}

TEST(Queue_FunctionTest, back_Test) {
	Queue<int> a(nullptr, nullptr);
	testing::internal::CaptureStdout();
	int a1 = a.back();
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Queue is empty\n");
	a.enqueue(1);
	a.enqueue(2);
	EXPECT_EQ(2, a.back());
}

TEST(Queue_FunctionTest, enqueue_Test) {
	Queue<int> a(nullptr, nullptr);
	a.enqueue(1);
	EXPECT_EQ(1, a.back());
	a.enqueue(2);
	EXPECT_EQ(2, a.back());
}

TEST(Queue_FunctionTest, dequeue_Test) {
	Queue<int> a(nullptr, nullptr);
	testing::internal::CaptureStdout();
	a.dequeue();
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Queue is empty\n");
	a.enqueue(1);
	a.enqueue(2);
	EXPECT_EQ(1, a.front());
	a.dequeue();
	EXPECT_EQ(2, a.front());
}

TEST(Queue_FunctionTest, print_Test) {
	Queue<int> a(nullptr, nullptr);
	testing::internal::CaptureStdout();
	a.print();
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Queue is empty\n");
	a.enqueue(1);
	a.enqueue(2);
	testing::internal::CaptureStdout();
	a.print();
	string output1 = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output1, "Queue: 2 1 \n");
}

TEST(Queue_FunctionTest, size_Test) {
	Queue<int> a(nullptr, nullptr);
	EXPECT_EQ(0, a.size());
	a.enqueue(1);
	EXPECT_EQ(1, a.size());
	a.enqueue(2);
	EXPECT_EQ(2, a.size());
}

TEST(Prior_Queue_FunctionTest, isEmpty_Test) {
	prior_queue<int> a(nullptr, nullptr);
	EXPECT_EQ(1, a.isEmpty());
	a.enqueue(1,1);
	EXPECT_EQ(0, a.isEmpty());
}

TEST(Prior_Queue_FunctionTest, front_Test) {
	prior_queue<int> a(nullptr, nullptr);
	testing::internal::CaptureStdout();
	int a1 = a.front();
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Queue is empty\n");
	a.enqueue(1,1);
	a.enqueue(2,1);
	EXPECT_EQ(2, a.front());
}

TEST(Prior_Queue_FunctionTest, back_Test) {
	prior_queue<int> a(nullptr, nullptr);
	testing::internal::CaptureStdout();
	int a1 = a.back();
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Queue is empty\n");
	a.enqueue(1,0);
	a.enqueue(2,0);
	EXPECT_EQ(1, a.back());
}

TEST(Prior_Queue_FunctionTest, enqueue_Test) {
	prior_queue<int> a(nullptr, nullptr);
	a.enqueue(1,1);
	EXPECT_EQ(1, a.back());
	a.enqueue(2,2);
	EXPECT_EQ(1, a.back());
	a.enqueue(5, 5);
	EXPECT_EQ(5, a.front());
	a.enqueue(3, 0);
	EXPECT_EQ(3, a.back());
}

TEST(Prior_Queue_FunctionTest, dequeue_Test) {
	prior_queue<int> a(nullptr, nullptr);
	testing::internal::CaptureStdout();
	a.dequeue();
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Queue is empty\n");
	a.enqueue(1,1);
	EXPECT_EQ(1, a.front());
	a.enqueue(2,2);
	EXPECT_EQ(2, a.front());
	a.enqueue(3,2);
	EXPECT_EQ(3, a.front());
}

TEST(Prior_Queue_FunctionTest, print_Test) {
	prior_queue<int> a(nullptr, nullptr);
	testing::internal::CaptureStdout();
	a.print();
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Priority Queue is empty\n");
	a.enqueue(1, 1);
	a.enqueue(2, 1);
	testing::internal::CaptureStdout();
	a.print();
	string output1 = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output1, "Priority Queue: 1(1) 2(1) \n");
}

TEST(Prior_Queue_FunctionTest, size_Test) {
	prior_queue<int> a(nullptr, nullptr);
	EXPECT_EQ(0, a.size());
	a.enqueue(1,1);
	EXPECT_EQ(1, a.size());
	a.enqueue(2,1);
	EXPECT_EQ(2, a.size());
}