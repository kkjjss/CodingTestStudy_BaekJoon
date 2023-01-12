#include <bits/stdc++.h>
using namespace std;

int N;
map<char, int> cnt;
string result;

int main()
{
  cin >> N;

  string input[N];
  for (int i = 0; i < N; i++)
  {
    cin >> input[i];
    cnt[input[i][0]]++;
  }

  for (auto a : cnt)
  {
    if (a.second >= 5)
      result += a.first;
  }

  if (!result.empty())
    cout << result << '\n';
  else
    cout << "PREDAJA" << '\n';

  return 0;
}