#include "pch.h"
#include "Paliukh_SpareMatrix.h"

TEST(FunctionTest, insert_test) {
    SparseMatrix<int> a(5, 5);
    EXPECT_EQ(0, a.get_element(1, 1));
    a.insert(2, 1, 1);
    EXPECT_EQ(2, a.get_element(1, 1));
    testing::internal::CaptureStdout();
    a.insert(3, 6, 7);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Out_of_range\n");
}

TEST(FunctionTest, remove_test) {
    SparseMatrix<int> a(5, 5);
    testing::internal::CaptureStdout();
    a.remove(6, 7);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Out_of_range\n");
    SparseMatrix<int> b(0, 0);
    testing::internal::CaptureStdout();
    b.remove(1, 2);
    string output1 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output1, "Empty matrix\n");
    a.insert(1, 2, 2);
    testing::internal::CaptureStdout();
    a.remove(1, 2);
    string output2 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output2, "This element doesn't exist\n");
    EXPECT_EQ(1, a.get_element(2, 2));
    a.remove(2, 2);
    EXPECT_EQ(0, a.get_element(2, 2));
}

TEST(FunctionTest, get_element_test) {
    SparseMatrix<int> a(5, 5);
    EXPECT_EQ(0, a.get_element(1, 1));
    a.insert(1, 2, 2);
    EXPECT_EQ(1, a.get_element(2, 2));
    testing::internal::CaptureStdout();
    int c = a.get_element(6, 2);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Out_of_range\n");
    EXPECT_EQ(-1, c);
    SparseMatrix<int> b(0, 0);
    testing::internal::CaptureStdout();
    int d = b.get_element(1, 2);
    string output1 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output1, "Empty matrix\n");
    EXPECT_EQ(-1, d);
}

TEST(FunctionTest, print_test) {
    SparseMatrix<int> a(0, 0);
    testing::internal::CaptureStdout();
    a.print();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Empty matrix\n");
    SparseMatrix<int> b(3, 3);
    testing::internal::CaptureStdout();
    b.print();
    string output1 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output1, "0 0 0 \n0 0 0 \n0 0 0 \n");
    b.insert(1, 0, 0);
    b.insert(2, 1, 1);
    b.insert(3, 2, 2);
    b.insert(2, 0, 1);
    testing::internal::CaptureStdout();
    b.print();
    string output2 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output2, "1 2 0 \n0 2 0 \n0 0 3 \n");
}

TEST(FunctionTest, Matrix_multiplication) {
    SparseMatrix<int> a(5, 5);
    for (int i = 0; i < 5; ++i) a.insert(i + 1, i, i);
    a.insert(6, 0, 2);
    a.insert(4, 4, 2);
    /*
      | 1 0 6 0 0 |
      | 0 2 0 0 0 |
   a= | 0 0 3 0 0 |
      | 0 0 0 4 0 |
      | 0 0 4 0 5 |
    */
    SparseMatrix<int> b(5, 5);
    for (int i = 0; i < 5; ++i) b.insert(i + 1, i, 4 - i);
    b.insert(7, 0, 3);
    b.insert(8, 4, 4);
    /*
      | 0 0 0 7 1 |
      | 0 0 0 2 0 |
   b= | 0 0 3 0 0 |
      | 0 4 0 0 0 |
      | 5 0 0 0 8 |
    */
    SparseMatrix<int> d = a * b;
    /*
      | 0 0 18 7 1    |
      | 0 0 0 4 0     |
   d= | 0 0 9 0 0     |
      | 0 16 0 0 0    |
      | 25 0 12 0 40  |
    */
    testing::internal::CaptureStdout();
    d.print();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "0 0 18 7 1 \n0 0 0 4 0 \n0 0 9 0 0 \n0 16 0 0 0 \n25 0 12 0 40 \n");
}

TEST(FunctionTest, Matrix_adding) {
    SparseMatrix<int> a(5, 5);
    for (int i = 0; i < 5; ++i) a.insert(i + 1, i, i);
    a.insert(6, 0, 2);
    a.insert(4, 4, 2);
    /*
      | 1 0 6 0 0 |
      | 0 2 0 0 0 |
   a= | 0 0 3 0 0 |
      | 0 0 0 4 0 |
      | 0 0 4 0 5 |
    */
    SparseMatrix<int> b(5, 5);
    for (int i = 0; i < 5; ++i) b.insert(i + 1, i, 4 - i);
    b.insert(7, 0, 3);
    b.insert(8, 4, 4);
    /*
      | 0 0 0 7 1 |
      | 0 0 0 2 0 |
   b= | 0 0 3 0 0 |
      | 0 4 0 0 0 |
      | 5 0 0 0 8 |
    */
    SparseMatrix<int> d = a + b;
    /*
      | 1 0 6 7 1  |
      | 0 2 0 2 0  |
   d= | 0 0 6 0 0  |
      | 0 4 0 4 0  |
      | 5 0 4 0 13 |
    */
    testing::internal::CaptureStdout();
    d.print();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 0 6 7 1 \n0 2 0 2 0 \n0 0 6 0 0 \n0 4 0 4 0 \n5 0 4 0 13 \n");
}

TEST(FunctionTest, Matrix_subtraction) {
    SparseMatrix<int> a(5, 5);
    for (int i = 0; i < 5; ++i) a.insert(i + 1, i, i);
    a.insert(6, 0, 2);
    a.insert(4, 4, 2);
    /*
      | 1 0 6 0 0 |
      | 0 2 0 0 0 |
   a= | 0 0 3 0 0 |
      | 0 0 0 4 0 |
      | 0 0 4 0 5 |
    */
    SparseMatrix<int> b(5, 5);
    for (int i = 0; i < 5; ++i) b.insert(i + 1, i, 4 - i);
    b.insert(7, 0, 3);
    b.insert(8, 4, 4);
    /*
      | 0 0 0 7 1 |
      | 0 0 0 2 0 |
   b= | 0 0 3 0 0 |
      | 0 4 0 0 0 |
      | 5 0 0 0 8 |
    */
    SparseMatrix<int> d = a - b;
    /*
      | 1 0 6 -7 -1 |
      | 0 2 0 -2 0  |
   d= | 0 0 0 0 0   |
      | 0 -4 0 4 0  |
      | -5 0 4 0 -3 |
    */
    testing::internal::CaptureStdout();
    d.print();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 0 6 -7 -1 \n0 2 0 -2 0 \n0 0 0 0 0 \n0 -4 0 4 0 \n-5 0 4 0 -3 \n");
}

TEST(FunctionTest, Matrix_multiplication_on_const) {
    SparseMatrix<int> a(5, 5);
    for (int i = 0; i < 5; ++i) a.insert(i + 1, i, i);
    a.insert(6, 0, 2);
    a.insert(4, 4, 2);
    /*
      | 1 0 6 0 0 |
      | 0 2 0 0 0 |
   a= | 0 0 3 0 0 |
      | 0 0 0 4 0 |
      | 0 0 4 0 5 |
    */
    SparseMatrix<int> d = a * 2;
    /*
      | 2 0 12 0 0 |
      | 0 4 0 0 0  |
   d= | 0 0 6 0 0  |
      | 0 0 0 8 0  |
      | 0 0 8 0 10 |
    */
    testing::internal::CaptureStdout();
    d.print();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "2 0 12 0 0 \n0 4 0 0 0 \n0 0 6 0 0 \n0 0 0 8 0 \n0 0 8 0 10 \n");
}

TEST(FunctionTest, transpose_test) {
    SparseMatrix<int> a(5, 5);
    for (int i = 0; i < 5; ++i) a.insert(i + 1, i, i);
    a.insert(6, 0, 2);
    a.insert(4, 4, 2);
    /*
      | 1 0 6 0 0 |
      | 0 2 0 0 0 |
   a= | 0 0 3 0 0 |
      | 0 0 0 4 0 |
      | 0 0 4 0 5 |
    */
    SparseMatrix<int> a1 = a.transpose();
    testing::internal::CaptureStdout();
    a1.print();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 0 0 0 0 \n0 2 0 0 0 \n6 0 3 0 4 \n0 0 0 4 0 \n0 0 0 0 5 \n");
    SparseMatrix<int> b(5, 5);
    for (int i = 0; i < 5; ++i) b.insert(i + 1, i, 4 - i);
    b.insert(7, 0, 3);
    b.insert(8, 4, 4);
    /*
      | 0 0 0 7 1 |
      | 0 0 0 2 0 |
   b= | 0 0 3 0 0 |
      | 0 4 0 0 0 |
      | 5 0 0 0 8 |
    */
    SparseMatrix<int> b1 = b.transpose();
    testing::internal::CaptureStdout();
    b1.print();
    string output1 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output1, "0 0 0 0 5 \n0 0 0 4 0 \n0 0 3 0 0 \n7 2 0 0 0 \n1 0 0 0 8 \n");
    SparseMatrix<int> b2(3, 2);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) b2.insert(1, i, j);
    }
    /*
       | 1 1 |
   b2= | 1 1 |
       | 1 1 |
    */
    b2 = b2.transpose();
    /*
       | 1 1 1 |
   b2= | 1 1 1 |
    */
    testing::internal::CaptureStdout();
    b2.print();
    string output2 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output2, "1 1 1 \n1 1 1 \n");
}

TEST(FunctionTest, pow_test) {
    SparseMatrix<int> a(5, 5);
    for (int i = 0; i < 5; ++i) a.insert(i + 1, i, i);
    a.insert(6, 0, 2);
    a.insert(4, 4, 2);
    /*
      | 1 0 6 0 0 |
      | 0 2 0 0 0 |
   a= | 0 0 3 0 0 |
      | 0 0 0 4 0 |
      | 0 0 4 0 5 |
    */
    SparseMatrix<int> a1 = a.pow(2);
    /*
       | 1 0 24 0 0  |
       | 0 4 0 0 0   |
   a1= | 0 0 9 0 0   |
       | 0 0 0 16 0  |
       | 0 0 32 0 25 |
    */
    testing::internal::CaptureStdout();
    a1.print();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 0 24 0 0 \n0 4 0 0 0 \n0 0 9 0 0 \n0 0 0 16 0 \n0 0 32 0 25 \n");
    SparseMatrix<int> a2 = a.pow(3);
    /*
       | 1 0 78 0 0    |
       | 0 8 0 0 0     |
   a1= | 0 0 27 0 0    |
       | 0 0 0 64 0    |
       | 0 0 196 0 125 |
    */
    testing::internal::CaptureStdout();
    a2.print();
    string output1 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output1, "1 0 78 0 0 \n0 8 0 0 0 \n0 0 27 0 0 \n0 0 0 64 0 \n0 0 196 0 125 \n");
    SparseMatrix<int> a3(2, 2);
    a3.insert(1, 0, 0);
    a3.insert(1, 1, 1);
    a3.insert(1, 0, 1);
    a3.insert(1, 1, 0);
    /*
       | 1 1 |
   a3= | 1 1 |
    */
    SparseMatrix<int> a4 = a3.pow(2);
    /*
       | 2 2 |
   a4= | 2 2 |
    */
    testing::internal::CaptureStdout();
    a4.print();
    string output2 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output2, "2 2 \n2 2 \n");
}

TEST(FunctionTest, isEmpty_test) {
    SparseMatrix<int> a(2, 2);
    EXPECT_EQ(1, a.isEmpty());
    a.insert(1, 0, 0);
    EXPECT_EQ(0, a.isEmpty());
}