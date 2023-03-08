#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
  while (scanf("%d", &n) != EOF)
  {
    int ret = 1;
    long long m = 1 % n;
    while (1)
    {
      if (m == 0)
      {
        printf("%d\n", ret);
        break;
      }
      else
      {
        m = (m * 10 + 1) % n;
        ret++;
      }
    }
  }

  return 0;
}