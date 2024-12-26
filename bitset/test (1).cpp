#include "pch.h"
#include "Paliukh_bitset.h"

TEST(FunctionTest, set_pos_test) {
	_bitset<3> a;
	testing::internal::CaptureStdout();
	cout << a;
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ("000\n", output);
	a.set_pos(0);
	testing::internal::CaptureStdout();
	cout << a;
	string output1 = testing::internal::GetCapturedStdout();
	EXPECT_EQ("001\n", output1);
	testing::internal::CaptureStdout();
	a.set_pos(3);
	string output2 = testing::internal::GetCapturedStdout();
	EXPECT_EQ("Wrong pos\n", output2);
}

TEST(FunctionTest, _set_test) {
	_bitset<3> a;
	testing::internal::CaptureStdout();
	cout << a;
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ("000\n", output);
	a._set();
	testing::internal::CaptureStdout();
	cout << a;
	string output1 = testing::internal::GetCapturedStdout();
	EXPECT_EQ("111\n", output1);
}

TEST(FunctionTest, set_for_letters_test) {
	_bitset<> a;
	a.set("abcdefg");
	testing::internal::CaptureStdout();
	cout << a;
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ("00000000000000000001111111\n", output);
	_bitset<4> a1;
	testing::internal::CaptureStdout();
	a1.set("abcde");
	string output1 = testing::internal::GetCapturedStdout();
	EXPECT_EQ("Out_of_range. Use size bigger than 5 if you want include this letter to set\n", output1);
}

TEST(FunctionTest, set_for_numbers_test) {
	_bitset<4> a;
	a.set(11);
	testing::internal::CaptureStdout();
	cout << a;
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ("1011\n", output);
	a.set(16);
	testing::internal::CaptureStdout();
	cout << a;
	string output1 = testing::internal::GetCapturedStdout();
	EXPECT_EQ("0000\n", output1);
}

TEST(FunctionTest, to_ulong_test) {
	_bitset<4> a;
	a.set(11);
	testing::internal::CaptureStdout();
	cout << a;
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ("1011\n", output);
	unsigned long a_numb = a.to_ulong();
	EXPECT_EQ(a_numb, 11);
}

TEST(FunctionTest, to_letters_test) {
	_bitset<5> a;
	a.set("abe");
	testing::internal::CaptureStdout();
	a.to_letters();
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ("This set contains these letters: a b e \n", output);
	a.reset();
	testing::internal::CaptureStdout();
	a.to_letters();
	string output1 = testing::internal::GetCapturedStdout();
	EXPECT_EQ("This set is empty\n", output1);

}

TEST(FunctionTest, reset_pos_test) {
	_bitset<4> a;
	a.set(11);
	testing::internal::CaptureStdout();
	cout << a;
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ("1011\n", output);
	a.reset(0);
	testing::internal::CaptureStdout();
	cout << a;
	string output1 = testing::internal::GetCapturedStdout();
	EXPECT_EQ("1010\n", output1);
}

TEST(FunctionTest, reset_test) {
	_bitset<4> a;
	a.set(11);
	testing::internal::CaptureStdout();
	cout << a;
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ("1011\n", output);
	a.reset();
	testing::internal::CaptureStdout();
	cout << a;
	string output1 = testing::internal::GetCapturedStdout();
	EXPECT_EQ("0000\n", output1);
}

TEST(FunctionTest, test_test) {
	_bitset<4> a;
	a.set(11);
	EXPECT_EQ(1, a.test(0));
	EXPECT_EQ(1, a.test(1));
	EXPECT_EQ(0, a.test(2));
	EXPECT_EQ(1, a.test(3));
	testing::internal::CaptureStdout();
	a.test(4);
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ("Wrong pos\n", output);
}

TEST(FunctionTest, inverse_pos_test) {
	_bitset<4> a;
	a.set(11);
	EXPECT_EQ(1, a.test(0));
	EXPECT_EQ(1, a.test(1));
	EXPECT_EQ(0, a.test(2));
	EXPECT_EQ(1, a.test(3));
	a.inverse(0);
	EXPECT_EQ(0, a.test(0));
	a.inverse(2);
	EXPECT_EQ(1, a.test(2));
	testing::internal::CaptureStdout();
	a.inverse(4);
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ("Wrong pos\n", output);
}

TEST(FunctionTest, inverse_test) {
	_bitset<4> a;
	a.set(11);
	EXPECT_EQ(1, a.test(0));
	EXPECT_EQ(1, a.test(1));
	EXPECT_EQ(0, a.test(2));
	EXPECT_EQ(1, a.test(3));
	a.inverse();
	EXPECT_EQ(0, a.test(0));
	EXPECT_EQ(0, a.test(1));
	EXPECT_EQ(1, a.test(2));
	EXPECT_EQ(0, a.test(3));
}

TEST(FunctionTest, count_test) {
	_bitset<4> a;
	a.set(11);
	EXPECT_EQ(3, a.count());
	_bitset<> a1;
	EXPECT_EQ(0, a1.count());
}

TEST(FunctionTest, none_test) {
	_bitset<4> a;
	EXPECT_EQ(1, a.none());
	a.set(1);
	EXPECT_EQ(0, a.none());
}

TEST(FunctionTest, all_test) {
	_bitset<4> a;
	EXPECT_EQ(0, a.all());
	a.set(15);
	EXPECT_EQ(1, a.all());
}

TEST(FunctionTest, any_test) {
	_bitset<4> a;
	EXPECT_EQ(0, a.any());
	a.set(15);
	EXPECT_EQ(1, a.any());
	a.set(1);
	EXPECT_EQ(1, a.any());
}

TEST(FunctionTest, size_test) {
	_bitset<> a;
	EXPECT_EQ(26, a.size());
	_bitset<4> a1;
	EXPECT_EQ(4, a1.size());
	_bitset<0> a2;
	EXPECT_EQ(0, a2.size());
}

TEST(FunctionTest, ostream_oprerator_test) {
	_bitset<4> a;
	a.set(11);
	testing::internal::CaptureStdout();
	cout << a;
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ("1011\n", output);
}

TEST(FunctionTest, AND_operator_test) {
	_bitset<4> a;
	a.set(11); // a = 1011
	_bitset<4> b;
	b.set(8); //b = 1000
	a &= b;
	testing::internal::CaptureStdout();
	cout << a; // a= 1000
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ("1000\n", output);
}

TEST(FunctionTest, OR_operator_test) {
	_bitset<4> a;
	a.set(11); // a = 1011
	_bitset<4> b;
	b.set(4); //b = 0100
	a |= b;
	testing::internal::CaptureStdout();
	cout << a; // a= 1111
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ("1111\n", output);
}

TEST(FunctionTest, XOR_operator_test) {
	_bitset<4> a;
	a.set(11); // a = 1011
	_bitset<4> b;
	b.set(8); //b = 1000
	a ^= b;
	testing::internal::CaptureStdout();
	cout << a; // a= 0011
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ("0011\n", output);
}

TEST(FunctionTest, is_not_equal_operator_test) {
	_bitset<4> a;
	a.set(11); // a = 1011
	_bitset<4> b;
	b.set(8); //b = 1000
	EXPECT_EQ(1, a!=b);
	b.set(11);//b=1011
	EXPECT_EQ(0, a != b);
}

TEST(FunctionTest, is_equal_operator_test) {
	_bitset<4> a;
	a.set(11); // a = 1011
	_bitset<4> b;
	b.set(8); //b = 1000
	EXPECT_EQ(0, a == b);
	b.set(11);//b=1011
	EXPECT_EQ(1, a == b);
}

TEST(FunctionTest, shift_left_operator_test) {
	_bitset<5> a("11100");
	a >>= 2;
	testing::internal::CaptureStdout();
	cout << a;  //00111
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ("00111\n", output);
	_bitset<7> a1("1110001");
	a1 >>= 3;
	testing::internal::CaptureStdout();
	cout << a1; //0001110
	string output1 = testing::internal::GetCapturedStdout();
	EXPECT_EQ("0001110\n", output1);
}

TEST(FunctionTest, shift_right_operator_test) {
	_bitset<5> a("00111");
	a <<= 2;
	testing::internal::CaptureStdout();
	cout << a;  //11100
	string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ("11100\n", output);
	_bitset<7> a1("1110001");
	a1 <<= 3;
	testing::internal::CaptureStdout();
	cout << a1; //0001000
	string output1 = testing::internal::GetCapturedStdout();
	EXPECT_EQ("0001000\n", output1);
}
