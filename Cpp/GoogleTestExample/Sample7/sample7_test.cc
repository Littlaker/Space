#include <gtest/gtest.h>

#include "prime_tables.h"

//  使用 value-parameterized test 测试

using ::testing::TestWithParam;
using ::testing::Values;

// 为了防止test之间互相影响，应该创建和销毁测试的对象，而不是重复使用一个
// 对象。以下的例子会顶一个工厂函数，在test SetUp的时候初始化对象，而后在
// test TearDown的时候销毁它。

typedef PrimeTable *CreatePrimeTableFunc();

PrimeTable *CreateOnTheFlyPrimeTable() { return new OnTheFlyPrimeTable(); }

template <size_t max_precalculated>
PrimeTable *CreatePreCalculatedPrimeTable() {
  return new PreCalculatedPrimeTable(max_precalculated);
}

// 继承自testing::TestWithParam, 而不是testing::Test
// 在成员函数中，可以通过GetParam() 获取到参数的指针

class PrimeTableTestSmpl7 : public TestWithParam<CreatePrimeTableFunc *> {
 public:
  ~PrimeTableTestSmpl7() override { delete table_; }

  // GetParam() 返回的是CreatePrimeTableFunc的函数指针
  // 在SetUp中调用函数指针实例化测试对象
  void SetUp() override { table_ = (*GetParam())(); }

  void TearDown() override {
    delete table_;
    table_ = nullptr;
  }

 protected:
  PrimeTable *table_;
};

TEST_P(PrimeTableTestSmpl7, ReturnsFalseForNonPrimes) {
  EXPECT_FALSE(table_->IsPrime(-5));
  EXPECT_FALSE(table_->IsPrime(0));
  EXPECT_FALSE(table_->IsPrime(1));
  EXPECT_FALSE(table_->IsPrime(4));
  EXPECT_FALSE(table_->IsPrime(6));
  EXPECT_FALSE(table_->IsPrime(100));
}

TEST_P(PrimeTableTestSmpl7, ReturnsTrueForPrimes) {
  EXPECT_TRUE(table_->IsPrime(2));
  EXPECT_TRUE(table_->IsPrime(3));
  EXPECT_TRUE(table_->IsPrime(5));
  EXPECT_TRUE(table_->IsPrime(7));
  EXPECT_TRUE(table_->IsPrime(11));
  EXPECT_TRUE(table_->IsPrime(131));
}

TEST_P(PrimeTableTestSmpl7, CanGetNextPrime) {
  EXPECT_EQ(2, table_->GetNextPrime(0));
  EXPECT_EQ(3, table_->GetNextPrime(2));
  EXPECT_EQ(5, table_->GetNextPrime(3));
  EXPECT_EQ(7, table_->GetNextPrime(5));
  EXPECT_EQ(11, table_->GetNextPrime(7));
  EXPECT_EQ(131, table_->GetNextPrime(128));
}

// 实例化 test suite 并绑定两个创建PrimeTable的函数指针作为测试参数
// INSTANTIATE_TYPED_TEST_SUITE_P(InstanceName, TestCaseName, TestList)
INSTANTIATE_TEST_SUITE_P(OnTheFlyAndPreCalculated, PrimeTableTestSmpl7,
                         Values(&CreateOnTheFlyPrimeTable,
                                &CreatePreCalculatedPrimeTable<1000>));

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
