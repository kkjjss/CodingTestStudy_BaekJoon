// priority queue 연습
#include <bits/stdc++.h>
using namespace std;

long long n;
double a;

int main()
{
  priority_queue<double> pq;
  cin >> n;
  for (long long i = 0; i < n; i++)
  {
    cin >> a;
    if (pq.size() == 7)
    {
      pq.push(a);
      pq.pop();
    }
    else
      pq.push(a);
  }

  vector<double> res;
  while (pq.size())
  {
    res.push_back(pq.top());
    pq.pop();
  }

  reverse(res.begin(), res.end());

  for (auto i : res)
  {
    printf("%.3f\n", i);
  }

  return 0;
}