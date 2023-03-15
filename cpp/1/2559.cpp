// 연속적인 수열의 합이 나올 경우 for문으로 매번 더하는 것 보다 미리 더해 놓은 값을 빼는 것이 빠르다.
#include <bits/stdc++.h>
using namespace std;

int n, k;
int temp;

int main()
{
  cin >> n >> k;

  int psum[n + 1];
  psum[0] = 0;
  int ret = -100 * n;

  for (int i = 1; i <= n; i++)
  {
    cin >> temp;
    psum[i] = psum[i - 1] + temp; // 1~i번째 입력을 모두 더한 값
  }

  for (int i = k; i <= n; i++)
  {
    ret = max(ret, psum[i] - psum[i - k]); // (i-k+1)번째부터 i번째까지 더한 값
  }

  cout << ret << '\n';

  return 0;
}
