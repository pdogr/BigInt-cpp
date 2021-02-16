#include "../include/bigint.h"

bigint
usub (const bigint &a, const bigint &b)
{
  ssize_t size_a = a.size (), size_b = b.size ();
  int id = -1;
  sblock borrow = 0;
  bigint nb;
  extend (nb, size_a);
  for (int i = 0; i < size_a; ++i)
    {
      sbblock p = (sbblock)a.get (i) - ((i < size_b) ? (sbblock)b.get (i) : 0)
                  - borrow;
      ublock md = (BLK + mod (p)) % BLK;
      nb[++id] = md;
      borrow = (p < 0) ? ((1 + div (-p) - ((md) ? 0 : 1))) : 0;
    }
  rollback (nb, id);
  return nb;
}

bigint
operator- (const bigint &a, const bigint &b)
{
  bool isGt = ugeq (a, b);
  function<bigint (const bigint &, const bigint &)> f
      = (a.sign() == b.sign()) ? usub : uadd;
  bigint nb = (isGt) ? f (a, b) : f (b, a);
  nb._sign = (isGt) ? a.sign() : (!b.sign());
  if (nb.is_zero ())
    {
      nb._sign = 0;
    }
  return nb;
}