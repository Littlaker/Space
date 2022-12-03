#include <gtest/gtest.h>

#include "sample3-inl.h"

// Test fixture :
// 继承自 testing::Test

class QueueTestSample3 : public testing::Test {
  // 定义protected的成员变量，让它们能在派生类中访问
 protected:
  // 虚函数 SetUp 会在每个test被调用之前执行
  void SetUp() override {
    q1_.Enqueue(1);
    q2_.Enqueue(2);
    q2_.Enqueue(3);
  }

  // 虚函数 TearDown 会在每个test被调用之后执行
  void TearDown() override {}

  // 静态helper函数
  static int Double(int n) { return 2 * n; }

  // 测试Queue::Map函数
  void MapTester(const Queue<int> *q) {
    const Queue<int> *const new_q = q->Map(Double);

    ASSERT_EQ(q->Size(), new_q->Size());

    for (const QueueNode<int> *n1 = q->Head(), *n2 = new_q->Head();
         n1 != nullptr; n1 = n1->next(), n2 = n2->next()) {
      EXPECT_EQ(2 * n1->element(), n2->element());
    }

    delete new_q;
  }

  Queue<int> q0_;
  Queue<int> q1_;
  Queue<int> q2_;

 private:
  Queue<int> q3_;
};

// TEST_F(TestSuiteName, TestName)
// TestSuiteName 即为类名QueueTestSample3
TEST_F(QueueTestSample3, DefaultContructor) {
  // 在TEST_F能访问protected的成员变量
  EXPECT_EQ(0u, q0_.Size());

  //  EXPECT_EQ(0u, q3_.Size());  // 无法访问private成员变量
}

TEST_F(QueueTestSample3, Dequeue) {
  int *n = q0_.Dequeue();
  EXPECT_TRUE(n == nullptr);

  n = q1_.Dequeue();
  ASSERT_TRUE(n != nullptr);
  EXPECT_EQ(1, *n);
  EXPECT_EQ(0u, q1_.Size());
  delete n;

  n = q2_.Dequeue();
  ASSERT_TRUE(n != nullptr);
  EXPECT_EQ(2, *n);
  EXPECT_EQ(1u, q2_.Size());
  delete n;
}

TEST_F(QueueTestSample3, Map) {
  MapTester(&q0_);
  MapTester(&q1_);
  MapTester(&q2_);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
