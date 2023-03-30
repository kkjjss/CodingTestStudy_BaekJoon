#include <bits/stdc++.h>
using namespace std;

int dist[401][401];
const int INF = 987654321;
int cnt[80000];
vector<int> path[401][401];
vector<pair<int, int>> res;
vector<int> answer;

vector<int> solution(int n, int m, vector<int> x, vector<int> y, vector<int> z)
{
  fill(&dist[0][0], &dist[0][0] + 401 * 401, INF);
  for (int i = 0; i < m; i++)
  {
    if (dist[x[i]][y[i]])
    {
      if (dist[x[i]][y[i]] > z[i])
      {
        dist[x[i]][y[i]] = z[i];
        path[x[i]][y[i]] = {i + 1};
        dist[y[i]][x[i]] = z[i];
        path[y[i]][x[i]] = {i + 1};
      }
    }
    else
    {
      dist[x[i]][y[i]] = z[i];
      path[x[i]][y[i]] = {i};
      dist[y[i]][x[i]] = z[i];
      path[y[i]][x[i]] = {i + 1};
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i == j)
        cout << " - ";
      else
        cout << dist[i][j] << ' ';
      cout << '|';
    }
    cout << '\n';
  }

  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
      {
        // cout << dist[i][j] << ':' << dist[i][k] + dist[k][j] << '\n';
        if (min(dist[i][j], dist[i][k] + dist[k][j]) == dist[i][k] + dist[k][j])
        {
          dist[i][j] = dist[i][k] + dist[k][j];

          vector<int> newPath = path[i][k];
          newPath.insert(newPath.end(), path[k][j].begin(), path[k][j].end());
          path[i][j] = newPath;
        }
      }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i == j)
        continue;
      for (auto a : path[i][j])
        cnt[a]++;
    }
  }

  for (int i = 1; i <= m; i++)
  {
    cout << i << ':' << cnt[i] << '\n';
    pq.push({cnt[i], i});
  }

  for (int i = 1; i <= m; i++)
  {
    answer.push_back(pq.top().second);
    pq.pop();
  }

  return answer;
}

int main()
{
  for (auto i : solution(3, 3, {1, 1, 2}, {3, 2, 3}, {1, 5, 2}))
  {
    cout << i << ", ";
  }
  cout << '\n';
  return 0;
}