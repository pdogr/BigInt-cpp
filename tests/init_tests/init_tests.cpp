
#include "gtest/gtest.h"
#include "bigint.h"
#include "../test_utils.h"
TEST(sanity, eq) { EXPECT_EQ(1,1); }
TEST(sanity, ne) { EXPECT_NE(1,2); }

TEST(init,zero){
  bigint b;
  EXPECT_EQ(string(b),"0");
  EXPECT_EQ(b.size(),1);
  EXPECT_EQ(b.sign(),0);
}


