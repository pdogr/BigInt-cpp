#include <boost/lexical_cast.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <random>

using namespace std;

using namespace __gnu_pbds;
namespace mp = boost::multiprecision;

#ifndef SLEN
#define SLEN 30
#endif
#ifndef MLEN
#define MLEN 500
#endif
#ifndef LLEN
#define LLEN 4000
#endif

int randint (int, int);
string to_string (int);
string long_srandint (int, bool = false);
mp::cpp_int long_brandint (string);

