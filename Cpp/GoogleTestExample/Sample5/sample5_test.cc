#include <gtest/gtest.h>
#include <limits.h>
#include <time.h>

#include "../Sample1/sample1.h"
#include "../Sample3/sample3-inl.h"

// 声明一个QuickTest的test fixture
// 在SetUp 和 TearDown 获取开始时间、结束时间，若差值大于5，则断言为失败
class QuickTest : public testing::Test {
 protected:
  void SetUp() override { start_time_ = time(nullptr); }

  void TearDown() override {
    const time_t end_time = time(nullptr);

    EXPECT_TRUE(end_time - start_time_ <= 5) << "The test took too long.";
  }

  time_t start_time_;
};

// 声明一个派生字QuickTest的test fixture
// 那样在QuickTest中的每个test执行前、后都会调用QuickTest的SetUp和TearDown
// 从而达到复用的目的
class IntegerFunctionTest : public QuickTest {};

TEST_F(IntegerFunctionTest, Factorial) {
  // Tests factorial of negative numbers.
  EXPECT_EQ(1, Factorial(-5));
  EXPECT_EQ(1, Factorial(-1));
  EXPECT_GT(Factorial(-10), 0);

  // Tests factorial of 0.
  EXPECT_EQ(1, Factorial(0));

  // Tests factorial of positive numbers.
  EXPECT_EQ(1, Factorial(1));
  EXPECT_EQ(2, Factorial(2));
  EXPECT_EQ(6, Factorial(3));
  EXPECT_EQ(40320, Factorial(8));
}

// Tests IsPrime()
TEST_F(IntegerFunctionTest, IsPrime) {
  // Tests negative input.
  EXPECT_FALSE(IsPrime(-1));
  EXPECT_FALSE(IsPrime(-2));
  EXPECT_FALSE(IsPrime(INT_MIN));

  // Tests some trivial cases.
  EXPECT_FALSE(IsPrime(0));
  EXPECT_FALSE(IsPrime(1));
  EXPECT_TRUE(IsPrime(2));
  EXPECT_TRUE(IsPrime(3));

  // Tests positive input.
  EXPECT_FALSE(IsPrime(4));
  EXPECT_TRUE(IsPrime(5));
  EXPECT_FALSE(IsPrime(6));
  EXPECT_TRUE(IsPrime(23));
}

// 同理，QueueTest 也派生自 QuickTest
class QueueTest : public QuickTest {
 protected:
  void SetUp() override {
    // 调用基类的SetUp
    QuickTest::SetUp();

    // Second, some additional setup for this fixture.
    q1_.Enqueue(1);
    q2_.Enqueue(2);
    q2_.Enqueue(3);
  }

  // By default, TearDown() inherits the behavior of
  // QuickTest::TearDown().  As we have no additional cleaning work
  // for QueueTest, we omit it here.
  //
  // virtual void TearDown() {
  //   QuickTest::TearDown();
  // }

  Queue<int> q0_;
  Queue<int> q1_;
  Queue<int> q2_;
};

// Now, let's write tests using the QueueTest fixture.

// Tests the default constructor.
TEST_F(QueueTest, DefaultConstructor) { EXPECT_EQ(0u, q0_.Size()); }

// Tests Dequeue().
TEST_F(QueueTest, Dequeue) {
  int *n = q0_.Dequeue();
  EXPECT_TRUE(n == nullptr);

  n = q1_.Dequeue();
  EXPECT_TRUE(n != nullptr);
  EXPECT_EQ(1, *n);
  EXPECT_EQ(0u, q1_.Size());
  delete n;

  n = q2_.Dequeue();
  EXPECT_TRUE(n != nullptr);
  EXPECT_EQ(2, *n);
  EXPECT_EQ(1u, q2_.Size());
  delete n;
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
