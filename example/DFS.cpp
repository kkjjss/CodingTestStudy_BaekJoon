#include <bits/stdc++.h>
using namespace std;

vector<int> adj[6];
int visited[6];

void dfs(int u)
{
  cout << u << '\n';
  visited[u] = 1;
  for (auto v : adj[u])
  {
    if (visited[v] != 1)
    {
      dfs(v);
    }
  }
  return;
}

int main()
{
  adj[1].push_back(2);
  adj[1].push_back(3);
  adj[2].push_back(1);
  adj[2].push_back(4);
  adj[2].push_back(5);
  adj[3].push_back(1);
  adj[4].push_back(2);
  adj[5].push_back(2);

  dfs(1);

  return 0;
}