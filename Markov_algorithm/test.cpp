#include "pch.h"
#include "Paliukh_Markov_algoritm.h"

TEST(FunctionTest, markov_algorithm_test) {
	Rule a[5] = { Rule(String("A"),String("apple")),Rule(String("B"),String("bag")), Rule(String("T"),String("the")),
	Rule(String("S"),String("shop")), Rule(String("the shop"),String("my brother")) };
	String input("I bought a B of As from T S.");
	String output = markov_algorithm(input, a, 5);
	testing::internal::CaptureStdout();
	cout << output;
	string output1 = testing::internal::GetCapturedStdout();
	EXPECT_EQ("I bought a bag of apples from my brother.", output1);

	Rule a1[3] = { Rule(String("1"),String("0|")), Rule(String("|0"),String("0||")),Rule(String("0"),String("")) };
	String input1("101");
	String output2 = markov_algorithm(input1, a1, 3);
	testing::internal::CaptureStdout();
	cout << output2;
	string output3 = testing::internal::GetCapturedStdout();
	EXPECT_EQ("|||", output3);
}

TEST(FunctionTest, markov_algorithm_terminating_rule_test) {
	Rule a1[3] = { Rule(String("ab"),String("bb")), Rule(String("aaa"),String("a"),1),Rule(String("ba"),String("aa")) };
	String input1("abba");
	String output2 = markov_algorithm(input1, a1, 3);
	testing::internal::CaptureStdout();
	cout << output2;
	string output3 = testing::internal::GetCapturedStdout();
	EXPECT_EQ("ba", output3);
}
