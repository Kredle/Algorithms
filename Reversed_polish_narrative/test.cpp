#include "pch.h"
#include "RPN.h"

TEST(StackTests, PushTest) {
	Stack<int> s;
	s.push(1);
	EXPECT_EQ(1, s.top());
	s.push(2);
	EXPECT_EQ(2, s.top());
}

TEST(StackTests, isEmptyTest) {
	Stack<int> s;
	EXPECT_EQ(1, s.isEmpty());
	s.push(2);
	EXPECT_EQ(0, s.isEmpty());
}

TEST(StackTests, PopTest) {
	Stack<int> s;
	s.push(1);
	s.push(2);
	EXPECT_EQ(2, s.top());
	s.pop();
	EXPECT_EQ(1, s.top());
}

TEST(StackTests, TopTest) {
	Stack<int> s;
	s.push(1);
	s.push(2);
	EXPECT_EQ(2, s.top());
	s.pop();
	EXPECT_EQ(1, s.top());
}

TEST(StackTests, LengthTest) {
	Stack<int> s;
	EXPECT_EQ(0, s.length());
	s.push(1);
	s.push(2);
	EXPECT_EQ(2, s.length());
	s.pop();
	EXPECT_EQ(1, s.length());
}

TEST(RPNTests, IsNumbTest) {
	EXPECT_EQ(0, isNumb('a'));
	EXPECT_EQ(1, isNumb('1'));
	EXPECT_EQ(0, isNumb('='));
}

TEST(RPNTests, IsOperatorTest) {
	EXPECT_EQ(0, isOperator('a'));
	EXPECT_EQ(0, isOperator('1'));
	EXPECT_EQ(1, isOperator('/'));
}

TEST(RPNTests, PriorityTest) {
	EXPECT_EQ(0, priority('a'));
	EXPECT_EQ(1, priority('+'));
	EXPECT_EQ(2, priority('*'));
	EXPECT_EQ(1, priority('-'));
	EXPECT_EQ(2, priority('/'));
}

TEST(RPNTests, CharToIntTest) {
	EXPECT_EQ(0, charToInt('0'));
	EXPECT_EQ(1, charToInt('1'));
	EXPECT_EQ(2, charToInt('2'));
	EXPECT_EQ(3, charToInt('3'));
	EXPECT_EQ(4, charToInt('4'));
}

TEST(RPNTests, ReadNumbTest) {
	string a = "12 24";
	int pos = 0;
	int b = readNumber(a, pos);
	EXPECT_EQ(12, b);
	pos += 1;
	int c = readNumber(a, pos);
	EXPECT_EQ(24, c);
}

TEST(RPNTests, CalculateTest) {
	EXPECT_EQ(3, calculate(1, 2, '+'));
	EXPECT_EQ(6, calculate(2, 3, '*'));
	EXPECT_EQ(2, calculate(4,2, '/'));
	EXPECT_EQ(-2, calculate(2, 4, '-'));
}

TEST(RPNTests, ConvertToPostfixTest) {
	EXPECT_EQ("12 4 3 + *", convertToPostfix("12 * ( 4 + 3 )"));
	EXPECT_EQ("4 6 3 - * 7 +", convertToPostfix("4 * (6 - 3) + 7"));
	EXPECT_EQ("2 3 + 5 *", convertToPostfix("( 2 + 3 ) * 5"));
	
}


TEST(RPNTests, CalculRPN_with_convertationTest) {
	EXPECT_EQ(84, calculRPN_with_convertation("12 * ( 4 + 3 )"));
	EXPECT_EQ(25, calculRPN_with_convertation("( 2 + 3 ) * 5"));
	EXPECT_EQ(19, calculRPN_with_convertation("4 * ( 6 - 3 ) + 7"));
	
}

TEST(RPNTests, CalculRPNTest) {
	EXPECT_EQ(84, calculRPN("12 4 3 + *"));
	EXPECT_EQ(25, calculRPN("2 3 + 5 *"));
	EXPECT_EQ(19, calculRPN("4 6 3 - * 7 +"));

}