#include <bits/stdc++.h>
using namespace std;

int N;
int mp[64][64];

string dnq(int x, int y, int l)
{
  if (l == 1)
  {
    return to_string(mp[y][x]);
  }
  string v1 = dnq(x, y, l / 2);
  string v2 = dnq(x + l / 2, y, l / 2);
  string v3 = dnq(x, y + l / 2, l / 2);
  string v4 = dnq(x + l / 2, y + l / 2, l / 2);

  if (v1 == "1" && v2 == "1" && v3 == "1" && v4 == "1")
    return "1";
  if (v1 == "0" && v2 == "0" && v3 == "0" && v4 == "0")
    return "0";
  return "(" + v1 + v2 + v3 + v4 + ")";
}

int main()
{
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      scanf("%1d", &mp[i][j]);
    }
  }

  cout << dnq(0, 0, N) << "\n";

  return 0;
}