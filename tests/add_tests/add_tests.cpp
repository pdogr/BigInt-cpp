#include "../test_utils.h"
#include "bigint.h"
#include "gtest/gtest.h"

class AddTest : public ::testing::Test
{
protected:
  string r1, r2;
  virtual void
  SetUp ()
  {
    string a1 = long_srandint (LLEN,true), b1 = long_srandint (LLEN,true);
    mp::cpp_int a (a1), b (b1);
    mp::cpp_int c = a + b;
    bigint ax (a1), bx (b1);
    bigint cx = ax + bx;
    r1 = string (cx), r2 = boost::lexical_cast<string> (c);
  }
  virtual void
  TearDown ()
  {
  }
};
TEST_F (AddTest, Add) { ASSERT_TRUE (r1 == r2); }