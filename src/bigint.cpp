#include "../include/bigint.h"

void
show (const bigint &a)
{
  cout << a << " " << a.size () << " " << a._size << "\n";
  for (int i = 0; i < a.size (); ++i)
    {
      cout << a.get (i) << "\t";
    }
  cout << "\n";
}

bigint::bigint ()
{
  this->_size = 1;
  this->_sign = 0;
  alloc (this->size ());
}

bigint::bigint (const int64_t num)
{
  int64_t n = num;
  this->_size = 1;
  this->_sign = 0;
  if (num < 0)
    {
      n = -num;
      this->_sign = 1;
    }
  alloc (this->size ());
  int id = 0;
  while (n)
    {
      if (id == this->size ())
        {
          extend ((*this), id);
        }
      this->p[id++] = mod (n);
      n /= BLK;
    }
}

bigint::bigint (const string &num)
{
  string s = num;
  this->_sign = 0;
  if (num[0] == '-')
    {
      this->_sign = 1;
      s = num.substr (1);
    }
  for (char c : s)
    {
      if (!(c <= '9' and c >= '0'))
        {
          cout << num << "\n";
          throw (ErrorBigint ());
        }
    }
  ssize_t n = s.size ();
  this->_size = _ceil (n, DECDIGITS);
  alloc (this->_size);
  ssize_t r = n - 1, id = 0;
  while (r - DECDIGITS + 1 >= 0)
    {
      bblock x = 0;
      for (ssize_t i = r - DECDIGITS + 1; i <= r; ++i)
        {
          x = 10 * x + (s[i] - '0');
        }
      this->p[id++] = (x & BLKMASK);
      r -= DECDIGITS;
    }
  if (r >= 0)
    {
      bblock x = 0;
      for (ssize_t i = 0; i <= r; ++i)
        {
          x = 10 * x + (s[i] - '0');
        }
      this->p[id++] = (x & BLKMASK);
    }
}

bigint::bigint (const char *s) : bigint (string (s)) {}

ublock &
bigint::operator[] (int id)
{
  return this->p[id];
}

ssize_t
bigint::size () const
{
  return this->_size;
}

bool
bigint::sign () const
{
  return this->_sign;
}
ublock
bigint::get (int id) const
{
  return this->p[id];
}

bool
bigint::is_zero () const
{
  return (this->size () == 1 and !this->get (0));
}

bigint::operator string () const
{
  string s;
  vector<string> v;
  for (int i = this->size () - 1; i >= 0; --i)
    {
      bblock m = this->p[i];
      string ss;
      for (int j = 0; j < DECDIGITS; ++j)
        {
          ss += static_cast<char> ((m % 10) + '0');
          m /= 10;
        }
      for (ssize_t j = DECDIGITS - 1; j >= 0; --j)
        {
          s += ss[j];
        }
    }
  ssize_t n = s.size (), l = 0;
  while (l < n - 1 and s[l] == '0')
    {
      ++l;
    }
  return ((this->_sign) ? "-" : "") + s.substr (l);
}

ostream &
operator<< (ostream &os, const bigint &b)
{
  os << string (b);
  return os;
}
