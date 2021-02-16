#include "../include/bigint.h"

bigint
uadd (const bigint &a, const bigint &b)
{
  ssize_t size_a = a.size (), size_b = b.size ();
  int id = -1;
  ublock carry = 0;
  bigint nb;
  extend (nb, size_a);
  for (int i = 0; i < size_a; ++i)
    {
      bblock p
          = carry + (bblock)a.get (i) + ((i < size_b) ? (bblock)b.get (i) : 0);
      nb[++id] = mod (p);
      carry = div (p);
    }
  if (carry)
    {
      extend (nb, size_a + 1);
      nb[++id] = carry;
    }
  rollback (nb, id);
  return nb;
}

bigint
operator+ (const bigint &a, const bigint &b)
{
  bool isGt = ugeq (a, b);
  function<bigint (const bigint &, const bigint &)> f
      = (a.sign() != b.sign()) ? usub : uadd;
  bigint nb = (isGt) ? f (a, b) : f (b, a);
  nb._sign = (isGt) ? a.sign() : b.sign();
  if (nb.is_zero ())
    {
      nb._sign = 0;
    }
  return nb;
}
