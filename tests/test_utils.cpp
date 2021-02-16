#include "test_utils.h"

mt19937_64 rng (chrono::steady_clock::now ().time_since_epoch ().count ());

int
randint (int l, int r)
{
  uniform_int_distribution<int> generator (l, r); // closed interval
  return generator (rng);
}

string
long_srandint (int l, bool ng)
{
  string s;
  s += char ('0' + randint (1, 9));
  --l;
  while (l)
    {
      s += char ('0' + randint (0, 9));
      --l;
    }
  if (ng and randint (0, 1))
    {
      s = "-" + s;
    }
  return s;
}

mp::cpp_int
long_brandint (string s)
{
  return boost::lexical_cast<mp::cpp_int> (s);
}

mp::cpp_int
long_brandint (int l)
{
  return boost::lexical_cast<mp::cpp_int> (long_srandint (l));
}
