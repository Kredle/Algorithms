#include "pch.h"
#include "HashTable.h"
using namespace std;
TEST(FunctionTest, HashFunkTest) {
	HashTable a;
	EXPECT_EQ(5, a.hashFunc(5));
	EXPECT_EQ(0, a.hashFunc(20));
	EXPECT_EQ(9, a.hashFunc(229));
}
TEST(FunctionTest, IsEmptyTest) {
	HashTable a;
	EXPECT_EQ(1, a.isEmpty());
	a.insert(1, "apple");
	EXPECT_EQ(0, a.isEmpty());
}
TEST(FunctionTest, IsInTableTest) {
	HashTable a;
	a.insert(1, "apple");
	a.insert(2, "grapes");
	EXPECT_EQ(1, a.IsInTable(1));
	EXPECT_EQ(1, a.IsInTable(2));
	EXPECT_EQ(0, a.IsInTable(10));
}
TEST(FunctionTest, GetValueTest) {
	HashTable a;
	a.insert(1, "apple");
	a.insert(2, "banana");
	a.insert(7, "lemon");
	EXPECT_EQ("lemon", a.getValue(7));
	EXPECT_EQ("apple", a.getValue(1));
	EXPECT_EQ("banana", a.getValue(2));
	EXPECT_EQ(" ", a.getValue(11));
}
TEST(FunctionTest, RewriteTest) {
	HashTable a;
	a.insert(1, "apple");
	a.insert(4, "melon");
	a.rewrite(1, "banana");
	a.rewrite(4, "watermelon");
	EXPECT_EQ("banana", a.getValue(1));
	EXPECT_EQ("watermelon", a.getValue(4));
}
TEST(FunctionTest, EmptyRewriteTest) {
	HashTable a;
	testing::internal::CaptureStdout();
	a.rewrite(1, "apple");
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Empty table\n");
}
TEST(FunctionTest, NoKeyRewriteTest) {
	HashTable a;
	a.insert(1, "apple");
	testing::internal::CaptureStdout();
	a.rewrite(3, "banana");
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Key isn't found\n");
}
TEST(FunctionTest, InsertTest) {
	HashTable a;
	EXPECT_EQ(1, a.isEmpty());
	a.insert(1, "apple");
	EXPECT_EQ(0, a.isEmpty());
	EXPECT_EQ("apple", a.getValue(1));
}
TEST(FunctionTest, ExisitingKeyInsertTest) {
	HashTable a;
	a.insert(1, "apple");
	testing::internal::CaptureStdout();
	a.insert(1, "banana");
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "This key is already in table\n");
}
TEST(FunctionTest, RemoveTest) {
	HashTable a;
	a.insert(1, "apple");
	a.insert(2, "banana");
	EXPECT_EQ(0, a.isEmpty());
	a.remove(1);
	EXPECT_EQ(0, a.isEmpty());
	a.remove(2);
	EXPECT_EQ(1, a.isEmpty());
}
TEST(FunctionTest, NoKeyRemoveTest) {
	HashTable a;
	a.insert(1, "apple");
	testing::internal::CaptureStdout();
	a.remove(2);
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Key isn't found.\n");
}
TEST(FunctionTest, EmptyRemoveTest) {
	HashTable a;
	testing::internal::CaptureStdout();
	a.remove(2);
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Empty table\n");
}
TEST(FunctionTest, EmptyPrintTest) {
	HashTable a; 
	testing::internal::CaptureStdout();
	a.print();
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Empty table\n");

}
TEST(FunctionTest, PrintTest) {
	HashTable a;
	a.insert(1, "apple");
	a.insert(2, "banana");
	testing::internal::CaptureStdout();
	a.print();
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Element 0: \nElement 1: [1: apple] \nElement 2: [2: banana] \nElement 3: \nElement 4: \nElement 5: \nElement 6: \nElement 7: \nElement 8: \nElement 9: \n");
	a.insert(11, "grapes");
	a.insert(12, "melon");
	a.insert(22, "watermelon");
	testing::internal::CaptureStdout();
	a.print();
	string output1 = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output1, "Element 0: \nElement 1: [1: apple] [11: grapes] \nElement 2: [2: banana] [12: melon] [22: watermelon] \nElement 3: \nElement 4: \nElement 5: \nElement 6: \nElement 7: \nElement 8: \nElement 9: \n");
}
