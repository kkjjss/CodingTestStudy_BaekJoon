// 최단경로
// 다익스트라 알고리즘
#include <bits/stdc++.h>
using namespace std;

int V, E, s;
int u, v, w;
int dist[20001];
const int INF = 987654321;
vector<pair<int, int>> adj[20001];
bool visited[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
  fill(dist, dist + 20001, INF); // 최단경로를 구할 것이기 때문에 최대값으로 초기화
  cin >> V >> E;
  cin >> s;
  for (int i = 0; i < E; i++)
  {
    cin >> u >> v >> w;
    adj[u].push_back({w, v}); // 인접 리스트 생성
  }

  pq.push({0, s}); // 시작점까지 거리는 0
  dist[s] = 0;     // 시작점 까지 거리는 0

  while (pq.size())
  {
    int here = pq.top().second;     // 시작점으로부터 현재 정점 위치
    int here_dist = pq.top().first; // 시작점으로부터 현재 정점까지의 최단 경로

    pq.pop();

    if (dist[here] != here_dist) // 우선순위 큐 내에 있는 경로중 최단 경로가 아니게 된 경로는 무시
      continue;

    for (pair<int, int> p : adj[here]) // 현재 정점과 이어져 있는 정점
    {
      int there = p.second;
      int there_dist = p.first;
      if (dist[there] > dist[here] + there_dist)
      { // 기존 최단 경로보다 짧다면 갱신
        dist[there] = dist[here] + there_dist;
        pq.push({dist[there], there});
      }
    }
  }

  for (int i = 1; i <= V; i++)
  {
    if (dist[i] == INF)
      cout << "INF\n";
    else
      cout << dist[i] << '\n';
  }
}