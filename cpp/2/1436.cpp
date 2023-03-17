#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
  cin >> n;

  for (int i = 666; true; i++)
  {
    if (to_string(i).find("666") != string::npos)
      n--;
    if (n == 0)
    {
      cout << i << '\n';
      break;
    }
  }

  return 0;
}