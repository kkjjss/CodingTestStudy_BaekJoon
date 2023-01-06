#include <bits/stdc++.h>
using namespace std;

/**
  1. 9P7
  2. 9C7
*/

int a[9];

int permutation1()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // 입력
  for (int i = 0; i < 9; i++)
  {
    cin >> a[i];
  }

  // 순열은 정렬해서 사용
  sort(a, a + 9);

  do
  {
    int sum = 0;

    // 만들어진 순열 중 앞 7개의 합
    for (int i = 0; i < 7; i++)
      sum += a[i];

    // 합이 100이면 출력
    if (sum == 100)
      break;
  } while (next_permutation(a, a + 9));

  for (int i = 0; i < 7; i++)
    cout << a[i] << '\n';
  return 0;
}

int main()
{
  permutation1();
  return 0;
}