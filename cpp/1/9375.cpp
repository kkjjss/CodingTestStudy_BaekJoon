#include <bits/stdc++.h>
using namespace std;

// int n, m;
// map<string, int> c;
// string name, type;

// int main()
// {
//   cin >> n;
//   int result[n];

//   for (int i = 0; i < n; i++)
//   {
//     cin >> m;

//     for (int j = 0; j < m; j++)
//     {
//       cin >> name >> type;
//       c[type]++;
//     }

//     int k = 1;
//     for (auto s : c)
//     {
//       k *= s.second + 1;
//     }
//     result[i] = k - 1;

//     c.clear();
//   }

//   for (int i : result)
//   {
//     cout << i << '\n';
//   }

//   return 0;
// }

int t, n;
string a, b;

int main()
{
  cin >> t;
  while (t--)
  {
    map<string, int> _map;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
      cin >> a >> b;
      _map[b]++;
    }

    long long ret = 1; // 경우의 수는 많이 커질수 있으므로 그냥 long long으로 선언하자!

    for (auto c : _map)
    {
      ret *= ((long long)c.second + 1);
    }
    ret--;
    cout << ret << '\n';
  }
}