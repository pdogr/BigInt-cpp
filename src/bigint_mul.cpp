#include "../include/bigint.h"

bigint
umul (const bigint &a, const bigint &b)
{
  ssize_t size_a = a.size (), size_b = b.size ();
  ssize_t sz = size_a + size_b;
  bigint nb;
  extend (nb, sz + 1);
  for (int i = 0; i < size_a; ++i)
    {
      ublock cm = 0, ca = 0;
      for (int j = 0; j < size_b; ++j)
        {
          bblock p = (bblock)a.get (i) * b.get (j) + cm;

          cm = div (p);
          addc (nb[i + j], mod (p), ca);
        }
      addc (nb[i + size_b], cm, ca);
      if (ca)
        {
          addc (nb[i + size_b + 1], 0, ca);
        }
    }
  return nb;
}

bigint
operator* (const bigint &a, const bigint &b)
{
  if (a.is_zero () or b.is_zero ())
    {
      return bigint ("0");
    }
  bigint nb = umul (a, b);
  nb._sign = (a.sign() == b.sign()) ? 0 : 1;
  return nb;
}

