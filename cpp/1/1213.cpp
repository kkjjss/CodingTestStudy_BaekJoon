#include <bits/stdc++.h>
using namespace std;
string s, ret;
int cnt[200], flag;
char mid;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;
  for (char a : s)
    cnt[a + 0]++;

  for (int c = 'Z'; c >= 'A'; c--)
  {
    if (cnt[c])
    {
      if (cnt[c] & 1) // 홀수일때
      {
        mid = c;
        flag++;
        cnt[c]--;
      }
      if (flag == 2)
        break;
      for (int j = 0; j < cnt[c]; j += 2)
      {
        ret = char(c) + ret + char(c);
      }
    }
  }

  if (flag == 2)
    cout << "I'm Sorry Hansoo\n";
  else
  {
    if (mid)
      ret.insert(ret.begin() + ret.size() / 2, mid);
    cout << ret << '\n';
  }

  return 0;
}