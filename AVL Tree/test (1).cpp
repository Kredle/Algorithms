#include "pch.h"
#include "Paliukh_AVL_TREE.h"

TEST(FunctionTest, insert_test) {
	AVL_Tree<int> a;
	a.insert(20);
	a.insert(30);
	a.insert(25);
	a.insert(10);
	testing::internal::CaptureStdout();
	a.print_preorder();
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "25 20 10 30 ");
	a.insert(40);
	a.insert(50);
	testing::internal::CaptureStdout();
	a.print_preorder();
	string output1 = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output1, "25 20 10 40 30 50 ");

	AVL_Tree<int> a1;
	a1.insert(1);
	a1.insert(2);
	a1.insert(3);
	a1.insert(4);
	a1.insert(5);
	a1.insert(6);
	a1.insert(7);
	a1.insert(8);
	a1.insert(9);
	a1.insert(10);
	a1.insert(11);
	testing::internal::CaptureStdout();
	a1.print_preorder();
	string output2 = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output2, "4 2 1 3 8 6 5 7 10 9 11 ");
	testing::internal::CaptureStdout();
	a1.insert(3);
	string output3 = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output3, "This node is already in the tree\n");
	testing::internal::CaptureStdout();
	a1.print_preorder();
	string output4 = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output4, "4 2 1 3 8 6 5 7 10 9 11 ");

}

TEST(FunctionTest, remove_test) {
	AVL_Tree<int> a;
	a.insert(20);
	a.insert(30);
	a.insert(25);
	a.insert(10);
	testing::internal::CaptureStdout();
	a.print_preorder();
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "25 20 10 30 ");
	a.insert(40);
	a.insert(50);
	testing::internal::CaptureStdout();
	a.print_preorder();
	string output1 = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output1, "25 20 10 40 30 50 ");
	a.remove(25);
	a.remove(10);
	a.remove(30);
	testing::internal::CaptureStdout();
	a.print_preorder();
	string output2 = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output2, "40 20 50 ");

	AVL_Tree<int> a1;
	a1.insert(1);
	a1.insert(2);
	a1.insert(3);
	a1.insert(4);
	a1.insert(5);
	a1.insert(6);
	a1.insert(7);
	a1.insert(8);
	a1.insert(9);
	a1.insert(10);
	a1.insert(11);
	testing::internal::CaptureStdout();
	a1.print_preorder();
	string output3 = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output3, "4 2 1 3 8 6 5 7 10 9 11 ");
	testing::internal::CaptureStdout();
	a1.remove(24);
	string output4 = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output4, "Havent found node 24\n");
	testing::internal::CaptureStdout();
	a1.print_preorder();
	string output5 = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output5, "4 2 1 3 8 6 5 7 10 9 11 ");
	a1.remove(4);
	a1.remove(5);
	a1.remove(6);
	testing::internal::CaptureStdout();
	a1.print_preorder();
	string output6 = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output6, "7 2 1 3 10 8 9 11 ");
}

TEST(FunctionTest, find_test) {
	AVL_Tree<int> a;
	a.insert(20);
	a.insert(30);
	a.insert(25);
	a.insert(10);
	testing::internal::CaptureStdout();
	a.print_preorder();
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "25 20 10 30 ");
	a.insert(40);
	a.insert(50);
	testing::internal::CaptureStdout();
	a.print_preorder();
	string output1 = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output1, "25 20 10 40 30 50 ");
	EXPECT_EQ(-1, a.find(1));
	EXPECT_EQ(25, a.find(25));
	EXPECT_EQ(50, a.find(50));
	EXPECT_EQ(10, a.find(10));
}

TEST(FunctionTest, print_test) {
	AVL_Tree<double> a;
	a.insert(11.1);
	a.insert(22.2);
	a.insert(33.3);
	a.insert(44.4);
	a.insert(55.5);
	a.insert(26.8);
	testing::internal::CaptureStdout();
	a.print();
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "          11.1\n     22.2\n          26.8\n33.3\n     44.4\n          55.5\n");
}

TEST(FunctionTest, preorder_test) {
	AVL_Tree<double> a;
	a.insert(11.1);
	a.insert(22.2);
	a.insert(33.3);
	a.insert(44.4);
	a.insert(55.5);
	a.insert(26.8);
	testing::internal::CaptureStdout();
	a.print_preorder();
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "33.3 22.2 11.1 26.8 44.4 55.5 ");
}

TEST(FunctionTest, postorder_test) {
	AVL_Tree<double> a;
	a.insert(11.1);
	a.insert(22.2);
	a.insert(33.3);
	a.insert(44.4);
	a.insert(55.5);
	a.insert(26.8);
	testing::internal::CaptureStdout();
	a.print_postorder();
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "11.1 26.8 22.2 55.5 44.4 33.3 ");
}