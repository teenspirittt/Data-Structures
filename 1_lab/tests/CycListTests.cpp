//#include "../headers/CycList.h"
#include "gtest/gtest.h"

TEST(myfunctions, add) {
  GTEST_ASSERT_EQ(16 + 16, 32);
  GTEST_ASSERT_EQ(15 + 16, 32);
  GTEST_ASSERT_EQ(1 + 16, 32);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
