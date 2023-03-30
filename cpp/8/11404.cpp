#include <bits/stdc++.h>
using namespace std;

int n, m, dist[101][101], a, b, c;
const int INF = 987654321;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fill(&dist[0][0], &dist[0][0] + 101 * 101, INF);
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> a >> b >> c;
    dist[a][b] = dist[a][b] ? min(dist[a][b], c) : c;
  }

  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i == j)
        printf("0 ");
      else
        printf("%d ", dist[i][j] == INF ? 0 : dist[i][j]);
    }
    cout << '\n';
  }

  cin >> n >> m;
}