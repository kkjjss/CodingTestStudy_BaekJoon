#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, mx;
vector<int> adj[10001];
int dp[10001];
int visited[10001];
int memo[10001] = {
    -1,
};

int dfs(int here)
{
  visited[here] = 1;
  int cnt = 1;
  for (int there : adj[here])
  {
    if (visited[there])
      continue;
    if (memo[there] == -1)
      memo[there] = dfs(there);
    cnt += memo[there];
  }
  return cnt;
}

int main()
{
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
  {
    cin >> a >> b;
    adj[b].push_back(a);
  }

  for (int i = 1; i <= n; i++)
  {
    fill(&visited[0], &visited[0] + 10001, 0);
    dp[i] = dfs(i);
    mx = max(dp[i], mx);
  }

  for (int i = 1; i <= n; i++)
    if (mx == dp[i])
      cout << i << ' ';

  return 0;
}