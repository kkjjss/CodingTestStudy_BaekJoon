#include <bits/stdc++.h>
using namespace std;

map<string, int> a;
map<int, string> b;
int n, m;
string input;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  string b[n + 1];

  for (int i = 1; i <= n; i++)
  {
    string name;
    cin >> name;
    b[i] = name;
    a[name] = i;
  }

  string result[m];

  for (int i = 0; i < m; i++)
  {
    cin >> input;
    if (atoi(input.c_str()) == 0) // string이면 0 반환
      result[i] = to_string(a[input]);
    else
      result[i] = b[atoi(input.c_str())];
  }

  for (auto s : result)
    cout << s << '\n';

  return 0;
}

