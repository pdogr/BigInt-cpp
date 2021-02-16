#include "../include/bigint.h"

bigint
operator+ (const bigint &a, const int64_t &b)
{
  return a + bigint (b);
}

bigint
operator+ (const int64_t &a, const bigint &b)
{
  return bigint (a) + b;
}

bigint
operator- (const bigint &a, const int64_t &b)
{
  return a - bigint (b);
}

bigint
operator- (const int64_t &a, const bigint &b)
{
  return bigint (a) - b;
}

bigint
operator* (const bigint &a, const int64_t &b)
{
  return a * bigint (b);
}

bigint
operator* (const int64_t &a, const bigint &b)
{
  return bigint (a) * b;
}
