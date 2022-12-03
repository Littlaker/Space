#include <gtest/gtest.h>

#include "prime_tables.h"

template <class T>
PrimeTable *CreatePrimeTable();

template <>
PrimeTable *CreatePrimeTable<OnTheFlyPrimeTable>() {
  return new OnTheFlyPrimeTable;
}

template <>
PrimeTable *CreatePrimeTable<PreCalculatedPrimeTable>() {
  return new PreCalculatedPrimeTable(10000);
}

template <class T>
class PrimeTableTest : public testing::Test {
 protected:
  PrimeTableTest() : table_(CreatePrimeTable<T>()) {}

  ~PrimeTableTest() {}

  PrimeTable *const table_;
};

using testing::Types;

// google test 在不同类型中复用test的方法

// 方法一：typed tests
// 前提：已知所有type

// TYPED_TEST_SUITE(TestCaseName, TypeList)
// TestCaseName 必须和 test fixture name 保持一致

typedef Types<OnTheFlyPrimeTable, PreCalculatedPrimeTable> Implementations;

TYPED_TEST_SUITE(PrimeTableTest, Implementations);

// TYPED_TEST(TestCaseName, TestName)
// google test 会对每个类型执行所有test
TYPED_TEST(PrimeTableTest, ReturnsFalseForNonPrimes) {
  EXPECT_FALSE(this->table_->IsPrime(-5));
  EXPECT_FALSE(this->table_->IsPrime(0));
  EXPECT_FALSE(this->table_->IsPrime(1));
  EXPECT_FALSE(this->table_->IsPrime(4));
  EXPECT_FALSE(this->table_->IsPrime(6));
  EXPECT_FALSE(this->table_->IsPrime(100));
}

TYPED_TEST(PrimeTableTest, ReturnsTrueForPrimes) {
  EXPECT_TRUE(this->table_->IsPrime(2));
  EXPECT_TRUE(this->table_->IsPrime(3));
  EXPECT_TRUE(this->table_->IsPrime(5));
  EXPECT_TRUE(this->table_->IsPrime(7));
  EXPECT_TRUE(this->table_->IsPrime(11));
  EXPECT_TRUE(this->table_->IsPrime(131));
}

TYPED_TEST(PrimeTableTest, CanGetNextPrime) {
  EXPECT_EQ(2, this->table_->GetNextPrime(0));
  EXPECT_EQ(3, this->table_->GetNextPrime(2));
  EXPECT_EQ(5, this->table_->GetNextPrime(3));
  EXPECT_EQ(7, this->table_->GetNextPrime(5));
  EXPECT_EQ(11, this->table_->GetNextPrime(7));
  EXPECT_EQ(131, this->table_->GetNextPrime(128));
}

using testing::Types;

// 在无法知道所有类型写测试时，可以使用 type-parameterized test 方式编写测试用例

// 首先，定义一个test fixtue 类模板
template <class T>
class PrimeTableTest2 : public PrimeTableTest<T> {};

// 接着，使用TYPED_TEST_SUITE_P声明一个test case
TYPED_TEST_SUITE_P(PrimeTableTest2);

// 然后，使用 TYPE_TEST_P 定义一个test
TYPED_TEST_P(PrimeTableTest2, ReturnsFalseForNonPrimes) {
  EXPECT_FALSE(this->table_->IsPrime(-5));
  EXPECT_FALSE(this->table_->IsPrime(0));
  EXPECT_FALSE(this->table_->IsPrime(1));
  EXPECT_FALSE(this->table_->IsPrime(4));
  EXPECT_FALSE(this->table_->IsPrime(6));
  EXPECT_FALSE(this->table_->IsPrime(100));
}

TYPED_TEST_P(PrimeTableTest2, ReturnsTrueForPrimes) {
  EXPECT_TRUE(this->table_->IsPrime(2));
  EXPECT_TRUE(this->table_->IsPrime(3));
  EXPECT_TRUE(this->table_->IsPrime(5));
  EXPECT_TRUE(this->table_->IsPrime(7));
  EXPECT_TRUE(this->table_->IsPrime(11));
  EXPECT_TRUE(this->table_->IsPrime(131));
}

TYPED_TEST_P(PrimeTableTest2, CanGetNextPrime) {
  EXPECT_EQ(2, this->table_->GetNextPrime(0));
  EXPECT_EQ(3, this->table_->GetNextPrime(2));
  EXPECT_EQ(5, this->table_->GetNextPrime(3));
  EXPECT_EQ(7, this->table_->GetNextPrime(5));
  EXPECT_EQ(11, this->table_->GetNextPrime(7));
  EXPECT_EQ(131, this->table_->GetNextPrime(128));
}

// 接着，枚举定义的所有test
// REGISTER_TYPED_TEST_SUITE_P(TestCaseName，TestName1, TestName2...)
REGISTER_TYPED_TEST_SUITE_P(PrimeTableTest2, ReturnsFalseForNonPrimes,
                            ReturnsTrueForPrimes, CanGetNextPrime);

typedef Types<OnTheFlyPrimeTable, PreCalculatedPrimeTable>
    PrimeTableImplementations;

// 最后，为具体的类型实例化test suite
// INSTANTIATE_TYPED_TEST_SUITE_P(InstanceName, TestCaseName, TestList)
INSTANTIATE_TYPED_TEST_SUITE_P(OnTheFlyAndPreCalculated,    // Instance name
                               PrimeTableTest2,             // Test case name
                               PrimeTableImplementations);  // Type list

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
