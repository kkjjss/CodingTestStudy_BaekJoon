#include <bits/stdc++.h>
using namespace std;

int h, w;
int res[100][100];
char input;

int main()
{
  fill(&res[0][0], &res[0][0] + 100 * 100, -1);
  cin >> h >> w;
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      cin >> input;
      if (input != 'c')
        continue;
      res[i][j] = 0;
      for (int k = j + 1; k < w; k++)
        res[i][k] = res[i][k - 1] + 1;
    }
  }

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      cout << res[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}