#include "sample1.h"

#include "gtest/gtest.h"

// TETS(TestSuiteName, TestName) :

// Asserition
// EXPECT_* :  断言检测失败会继续执行下一个断言
// ASSERT_* :  断言检测失败会退出当前函数

TEST(FactorialTest, Negative) {
  EXPECT_EQ(1, Factorial(-5));
  EXPECT_EQ(1, Factorial(-1));
  EXPECT_GT(Factorial(-10), 0);
}

TEST(FactorialTest, Positive) {
  EXPECT_EQ(1, Factorial(1));
  EXPECT_EQ(2, Factorial(2));
  EXPECT_EQ(6, Factorial(3));

  EXPECT_EQ(8, Factorial(8));  // 检测为false，但会继续执行下一个断言
  EXPECT_EQ(9, Factorial(9));  // 输出中会包含该断言失败的结果
  ASSERT_EQ(10, Factorial(10));  // 检测为false，不会继续执行一个断言
  EXPECT_EQ(9, Factorial(9));  // 输出中不会有该断言失败结果
}

TEST(FactorialTest, Zero) { EXPECT_EQ(1, Factorial(0)); }

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
