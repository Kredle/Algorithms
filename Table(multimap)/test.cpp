#include "pch.h"
#include "Table.h"
#include <iostream>

TEST(FunctionTest, PushTest) {
    Table table(5);
    table.push(1, "apple");
    table.push(2, "banana");
    table.push(3, "orange");

    testing::internal::CaptureStdout();
    table.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1: apple\n2: banana\n3: orange\n");
}

TEST(FunctionTest, GetValueTest) {
    Table table(5);
    table.push(1, "apple");
    table.push(2, "banana");
    table.push(3, "orange");

    EXPECT_EQ(table.getValue(2), "banana");
}

TEST(FunctionTest, GetKeyTest) {
    Table table(5);
    table.push(1, "apple");
    table.push(2, "banana");
    table.push(3, "orange");

    EXPECT_EQ(table.getKey("orange"), 3);
}

TEST(FunctionTest, DeleteTest) {
    Table table(5);
    table.push(1, "apple");
    table.push(2, "banana");
    table.push(3, "orange");
    table.push(4, "grape");

    table.del(2);

    testing::internal::CaptureStdout();
    table.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1: apple\n3: orange\n4: grape\n");
}

TEST(FunctionTest, GetCountTest) {
    Table table(5);
    table.push(1, "apple");
    table.push(2, "banana");
    EXPECT_EQ(2, table.getCount());
}

TEST(FunctionTest, GetSizeTest) {
    Table table(5);
    table.push(1, "apple");
    table.push(2, "banana");
    EXPECT_EQ(5, table.getsize());
}

TEST(FunctionTest, GetKeysArrTest) {
    Table table(5);
    table.push(1, "apple");
    table.push(2, "banana");
    table.push(3, "orange");
    table.push(4, "grape");
    int* keyArr = table.getKeysArr();
    testing::internal::CaptureStdout();
    for (int i = 0; i < table.getCount(); ++i) std::cout << keyArr[i] << ' ';
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 2 3 4 ");
}

TEST(FunctionTest, GetValueArrTest) {
    Table table(5);
    table.push(1, "apple");
    table.push(2, "banana");
    table.push(3, "orange");
    table.push(4, "grape");
    string* keyArr = table.getValuesArr();
    testing::internal::CaptureStdout();
    for (int i = 0; i < table.getCount(); ++i) std::cout << keyArr[i] << ' ';
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "apple banana orange grape ");
}

TEST(FunctionTest, GetPlaceTest) {
    Table table(5);
    table.push(1, "apple");
    table.push(2, "banana");
    EXPECT_EQ(3, table.getplace());
}
TEST(FunctionTest, ReSizeTest) {
    Table table(2);
    table.resize();
    EXPECT_EQ(4, table.getsize());
}

TEST(FunctionTest, IsinTableTest) {
    Table table(5);
    table.push(1, "apple");
    table.push(2, "banana");
    table.push(3, "orange");
    EXPECT_EQ(1, table.IsinTable(1, "apple"));
    EXPECT_EQ(0, table.IsinTable(4, "grapes"));
}

TEST(FunctionTest, WrongDelKeyTest) {
    Table table(5);
    table.push(1, "apple");
    table.push(2, "banana");
    table.push(3, "orange");
    testing::internal::CaptureStdout();
    table.del(4);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Key hasnt been found\n");
}

TEST(FunctionTest, NoKeyGetKeyTest) {
    Table table(5);
    table.push(1, "apple");
    table.push(2, "banana");
    table.push(3, "orange");
    EXPECT_EQ(table.getKey("grape"),-1);
}

TEST(FunctionTest, NoValueGetValueTest) {
    Table table(5);
    table.push(1, "apple");
    table.push(2, "banana");
    table.push(3, "orange");
    EXPECT_EQ(table.getValue(4), " ");
}

TEST(FunctionTest, PushExtsingItemTest) {
    Table table(5);
    table.push(1, "apple");
    table.push(2, "banana");
    table.push(3, "orange");
    testing::internal::CaptureStdout();
    table.push(3, "orange");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "This item alredy exists\n");
}

TEST(FunctionTest, PrintEmptyTable) {
    Table table(5);
    testing::internal::CaptureStdout();
    table.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Table is empty\n");
}

TEST(ConstructorTest, DefaultConstructor) {
    Table table;
    EXPECT_EQ(table.getsize(), 0);
    EXPECT_EQ(table.getCount(), 0);
    EXPECT_EQ(table.getplace(), 1);
}

TEST(ConstructorTest, ParametrConstructor) {
    Table table(5);
    EXPECT_EQ(table.getsize(), 5);
    EXPECT_EQ(table.getCount(), 0);
    EXPECT_EQ(table.getplace(), 1);
}

TEST(ConstructorTest, CopyConstructor) {
    Table table(5);
    table.push(1, "apple");
    table.push(2, "banana");
    table.push(3, "orange");

    Table copy(table);

    testing::internal::CaptureStdout();
    copy.print();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "1: apple\n2: banana\n3: orange\n");
}