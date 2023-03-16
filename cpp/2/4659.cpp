#include <bits/stdc++.h>
using namespace std;

string str;

bool isVowel(char c)
{
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void printFailure()
{
  cout << '<' << str << "> is not acceptable.\n";
}

void printSuccess()
{
  cout << '<' << str << "> is acceptable.\n";
}

int main()
{
  while (1)
  {
    cin >> str;
    if (str == "end")
      break;
    bool fail = false;
    int lcnt = 0, vcnt = 0;
    bool isIncludeVowel = false;
    char prev = '\0';

    for (auto c : str)
    {
      if (!c)
        break;
      if (isVowel(c))
        lcnt = 0, vcnt++, isIncludeVowel = true;
      else
        vcnt = 0, lcnt++;

      if (vcnt >= 3 || lcnt >= 3)
        fail = true;

      if (prev && prev == c && c != 'o' && c != 'e')
        fail = true;
      prev = c;
    }
    if (!isIncludeVowel)
      fail = true;
    if (fail)
      printFailure();
    else
      printSuccess();
  }

  return 0;
}