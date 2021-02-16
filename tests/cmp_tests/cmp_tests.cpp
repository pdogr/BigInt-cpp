#include "../test_utils.h"
#include "bigint.h"
#include "gtest/gtest.h"

class CmpTest : public ::testing::Test
{
protected:
  int r1, r2;
  string a1, b1;
  unsigned fails;

  virtual void
  SetUp ()
  {
    fails = 0;
    a1 = long_srandint (LLEN, true), b1 = long_srandint (LLEN, true);
    mp::cpp_int a (a1), b (b1);
    bigint ax (a1), bx (b1);
    r1 = (ax < bx) ? 1 : 0;
    r2 = (a < b) ? 1 : 0;
  }
  virtual void
  TearDown ()
  {
    if (fails > 0)
      {
        std::cerr << "wtf bro sees failures" << std::endl;
      }
  }
};
TEST_F (CmpTest, Cmp)
{
  EXPECT_EQ (r1, r2);
  fails += ::testing::Test::HasFailure ();
}