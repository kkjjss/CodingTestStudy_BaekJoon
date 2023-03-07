#include <bits/stdc++.h>
using namespace std;

long long a, b, c;

map<long long, long long> m;

long long sqrt(long long x, long long y)
{
  if (y == 1)
    return x % c;
  long long ret = sqrt(a, b / 2);
  ret *= (ret * ret) % c;
  if (y % 2)
    ret = (ret * a) % c;
  return ret;
}

int main()
{
  cin >> a >> b >> c;

  m[1] = a;

  sqrt(a, b);

  return 0;
}