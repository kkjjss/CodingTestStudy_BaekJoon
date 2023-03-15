#include <bits/stdc++.h>
using namespace std;

int A, B, C, a, b, cnt[104], ret;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> B >> C;

  for (int i = 0; i < 3; i++)
  {
    cin >> a >> b;
    for (int j = a; j < b; j++)
      cnt[j]++;
  }

  for (int i = 0; i < 100; i++)
  {
    if (cnt[i] == 1)
      ret += A;
    else if (cnt[i] == 2)
      ret += B * 2;
    else if (cnt[i] == 3)
      ret += C * 3;
  }

  cout << ret << '\n';

  return 0;
}

/*
int price[4];
pair<int, int> truck[3];
int timeTable[100];
int sum;

int solve()
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = truck[i].first; j < truck[i].second; j++)
      timeTable[j]++;
  }

  for (int i : timeTable)
  {
    sum += price[i] * i;
  }

  cout << sum << '\n';

  return 0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 1; i <= 3; i++)
  {
    cin >> price[i];
  }

  for (int i = 0; i < 3; i++)
  {
    int x, y;
    cin >> x >> y;
    truck[i] = {x, y};
  }

  solve();

  return 0;
}
 */
