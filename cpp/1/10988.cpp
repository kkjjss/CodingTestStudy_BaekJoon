#include <bits/stdc++.h>
using namespace std;

string input;
int result = 1;

// int main()
// {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//   cout.tie(NULL);

//   cin >> input;

//   for (int i = 0; i < input.length() / 2; i++)
//   {
//     if (input[i] != input[input.length() - 1 - i])
//     {
//       result = 0;
//       break;
//     }
//   }

//   cout << result << '\n';

//   return 0;
// }

int main()
{
  cin >> input;
  string temp = input;
  reverse(temp.begin(), temp.end());

  if (temp == input)
    cout << 1 << '\n';
  else
    cout << 0 << '\n';

  return 0;
}