#include <bits/stdc++.h>
using namespace std;

string input;

int main()
{
  getline(cin, input);

  for (int i = 0; i < input.length(); i++)
  {
    if ('A' <= input[i] && input[i] <= 'Z')
      input[i] = char((input[i] - 'A' + 13) % 26 + 'A');
    else if ('a' <= input[i] && input[i] <= 'z')
      input[i] = char((input[i] - 'a' + 13) % 26 + 'a');
  }

  cout << input << '\n';

  return 0;
}