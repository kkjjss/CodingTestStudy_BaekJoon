#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
  while (scanf("%d", &n) != EOF) // 입력 없으면 종료
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

/*
  덧셈 : (a+b) % M = ((a % M) + (b % M)) % M
  뺄셈 : (a-b) % M = ((a%M) - (a%M)) % M
  곱셈 : (a*b) % M = ((a*M) * (b*M)) % M
*/