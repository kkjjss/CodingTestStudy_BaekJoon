// 문제에서 "짝짓기" or "폭발"
//  => stack으로 풀기!!

#include <bits/stdc++.h>
using namespace std;

int n, cnt;
string input;

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    stack<char> s;
    cin >> input;

    for (char c : input)
    {
      if (!s.empty() && s.top() == c)
        s.pop();
      else
        s.push(c);
    }

    if (s.empty())
      cnt++;
  }

  cout << cnt << '\n';

  return 0;
}