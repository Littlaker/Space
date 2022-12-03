#include "sample2.h"

#include <gtest/gtest.h>

TEST(MyString, DefaultConstructor) {
  const MyString s;

  // EXPECT_STREQ 字符串比较
  EXPECT_STREQ(nullptr, s.c_string());
  EXPECT_EQ(0u, s.Length());
}

const char kHelloString[] = "Hello, world!";

TEST(MyString, CopyConstructor) {
  const MyString s1(kHelloString);
  const MyString s2 = s1;
  EXPECT_EQ(0, strcmp(s2.c_string(), kHelloString));
}

TEST(MyString, Set) {
  MyString s;

  s.Set(kHelloString);
  EXPECT_EQ(0, strcmp(s.c_string(), kHelloString));

  s.Set(s.c_string());
  EXPECT_EQ(0, strcmp(s.c_string(), kHelloString));

  s.Set(nullptr);
  EXPECT_EQ(nullptr, s.c_string());
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
