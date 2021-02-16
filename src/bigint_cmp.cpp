#include "../include/bigint.h"

bool
ugeq (const bigint &a, const bigint &b)
{
  if (a.size () != b.size ())
    {
      return a.size () > b.size ();
    }
  ssize_t size_a = a.size ();
  ublock _a, _b;
  for (int i = size_a - 1; i >= 0; --i)
    {
      _a = a.get (i), _b = b.get (i);
      if (_a == _b)
        continue;
      return _a > _b;
    }
  return true;
}

bool
operator== (const bigint &a, const bigint &b)
{
  if (a.size () != b.size () or a.sign () != b.sign ())
    return false;
  ssize_t size_b = b.size ();
  for (int i = 0; i < size_b; ++i)
    {
      if (a.get (i) != b.get (i))
        return false;
    }
  return true;
}
bool
operator!= (const bigint &a, const bigint &b)
{
  return !(a == b);
}

bool
operator< (const bigint &a, const bigint &b)
{
  if (a.sign () != b.sign ())
    {
      return a.sign ();
    }
  if (a.size () != b.size ())
    {
      return (!a.sign ()) ? (a.size () < b.size ()) : (a.size () > b.size());
    }
  ssize_t size_a = a.size ();
  ublock _a, _b;
  bool is_neg = a.sign ();
  for (int i = size_a - 1; i >= 0; --i)
    {

      _a = a.get (i), _b = b.get (i);
      if (_a == _b)
        continue;
      bool is_small = (is_neg) ? (_a > _b) : (_a < _b);
      return is_small;
    }
  return false;
}
bool
operator> (const bigint &a, const bigint &b)
{

  return (a != b) and !(a < b);
}

bigint
abs (const bigint &a)
{
  bigint b (a);
  b._sign = 0;
  return b;
}
