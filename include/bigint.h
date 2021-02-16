#include <cstring>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

typedef uint16_t ublock;
typedef int16_t sblock;
typedef uint32_t bblock;
typedef int32_t sbblock;

#define BLK 0x2710 // 10000
#define BLKMASK 0xFFFF
#define DECDIGITS 4

#define mul(A) ((bblock)A * BLK)
#define div(A) (static_cast<ublock> (((A * 0xd1b71759ULL) >> 45)))
#define mod(A) (static_cast<ublock> (A - BLK * div (A)))

#define _ceil(a, b) (a % b ? (a / b) + 1 : (a / b))

#define alloc(SZ)                                                             \
  {                                                                           \
    this->p = vector<ublock> (SZ);                                            \
  }

#define extend(A, SZ)                                                         \
  {                                                                           \
    A._size = SZ;                                                             \
    if (static_cast<int> (A.p.size ()) < (SZ))                                \
      {                                                                       \
        A.p.resize (2 * SZ, 0);                                               \
      }                                                                       \
  }

#define mul_ublock(A, B)                                                      \
  {                                                                           \
    ssize_t sz = A.size;                                                      \
    ublock C = 0;                                                             \
    for (ssize_t _i = 0; _i < sz; ++_i)                                       \
      {                                                                       \
        bblock P = ((bblock)A[_i] * (bblock)B) + C;                           \
        A[_i] = mod (P);                                                      \
        C = div (P);                                                          \
      }                                                                       \
    if (C)                                                                    \
      {                                                                       \
        extend (A, sz + 1);                                                   \
        A[sz] = C;                                                            \
      }                                                                       \
  }

#define add_ublock(A, B)                                                      \
  {                                                                           \
    ssize_t sz = A.size;                                                      \
    ublock C (B);                                                             \
    for (ssize_t _i = 0; _i < sz; ++_i)                                       \
      {                                                                       \
        bblock P = C + (bblock)A[_i];                                         \
        A[_i] = mod (P);                                                      \
        C = div (P);                                                          \
      }                                                                       \
    if (C)                                                                    \
      {                                                                       \
        extend (A, sz + 1);                                                   \
        A[sz] = C;                                                            \
      }                                                                       \
  }

#define madd(A, B, C)                                                         \
  {                                                                           \
    mul_ublock (A, B);                                                        \
    add_ublock (A, C);                                                        \
  }

#define addc(A, B, C)                                                         \
  {                                                                           \
    bblock P = A + B + C;                                                     \
    C = div (P);                                                              \
    A = mod (P);                                                              \
  }
#define rollback(A, id)                                                       \
  {                                                                           \
    while (id > 0 and !A.get (id))                                            \
      {                                                                       \
        --id;                                                                 \
      }                                                                       \
    A._size = id + 1;                                                         \
  }

struct bigint
{
  vector<ublock> p;
  ssize_t _size;
  bool _sign;

  bigint ();
  bigint (const int64_t);
  bigint (const char *);
  bigint (const string &);
  ssize_t size () const;
  ublock &operator[] (int);
  ublock get (int) const;
  bool is_zero () const;
  bool sign () const;
  operator string () const;
};

bool ugeq (const bigint &, const bigint &);
bigint uadd (const bigint &, const bigint &);
bigint usub (const bigint &, const bigint &); // |a|>=|b|
bigint umul (const bigint &, const bigint &);

ostream &operator<< (ostream &, const bigint &);

bigint operator+ (const bigint &, const bigint &);
bigint operator- (const bigint &, const bigint &);
bigint operator* (const bigint &, const bigint &);
bool operator== (const bigint &, const bigint &);
bool operator!= (const bigint &, const bigint &);
bool operator> (const bigint &, const bigint &);
bool operator< (const bigint &, const bigint &);
bigint abs(const bigint &);

bigint operator+ (const bigint &, const int64_t &);
bigint operator+ (const int64_t &, const bigint &);

bigint operator- (const bigint &, const int64_t &);
bigint operator- (const int64_t &, const bigint &);

bigint operator* (const bigint &, const int64_t &);
bigint operator* (const int64_t &, const bigint &);
class ErrorBigint
{
};

void show (const bigint &a);