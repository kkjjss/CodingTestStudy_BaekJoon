#include <bits/stdc++.h>
using namespace std;

int N;
string pattern;

// vector<string> split(string input, string delimiter)
// {
//   vector<string> ret;
//   long long pos;
//   string token = "";

//   while ((pos = input.find(delimiter)) != string::npos)
//   {
//     token = input.substr(0, pos);             // 구분자 앞쪽
//     ret.push_back(token);                     // 배열에 저장
//     input.erase(0, pos + delimiter.length()); //
//   }
//   ret.push_back(input);
//   return ret;
// }

// int main()
// {
//   cin >> N;
//   string input[N];
//   string result[N];

//   cin >> pattern;
//   vector<string> p = split(pattern, "*");

//   for (int i = 0; i < N; i++)
//   {
//     cin >> input[i];
//     if (input[i].substr(0, p[0].length()) == p[0] && input[i].substr(input[i].length() - p[1].length(), input[i].length()) == p[1])
//       result[i] = "DA";
//     else
//       result[i] = "NE";
//   }

//   for (string a : result)
//   {
//     cout << a << '\n';
//   }

//   return 0;
// }

int main()
{
  cin >> N;
  string input;
  string result[N];

  cin >> pattern;
  int pos = pattern.find('*');
  string prefix = pattern.substr(0, pos);
  string suffix = pattern.substr(pos + 1);

  for (int i = 0; i < N; i++)
  {
    cin >> input;
    if (prefix.size() + suffix.size() > input.size())
      result[i] = "NE";
    else if (input.substr(0, pos) == prefix && (input.substr(input.length() - suffix.length()) == suffix))
      result[i] = "DA";
    else
      result[i] = "NE";
  }

  for (string a : result)
  {
    cout << a << '\n';
  }

  return 0;
}