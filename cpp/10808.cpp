#include <bits/stdc++.h>
using namespace std;

// counting star~ map 또는 배열~
// 셀때는 맵이나 배열 써서!
// string -> MAP || int -> Array

string str;
map<char, int> m;
int arr[26]; // 전역으로 배열 선언시 자동으로 초기화 (쓰레기값X);

int solveMap()
{
  string abc = "abcdefghijklmnopqrstuvwxyz";

  for (char c : str)
    m[c]++;

  for (char c : abc)
    cout << m[c] << ' ';
  cout << '\n';

  return 0;
}

int solveArray()
{
  for (char c : str)
    arr[c - 'a']++;

  for (int i : arr)
    cout << i << ' ';
  cout << '\n';

  return 0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> str;

  solveMap();
  solveArray();
  
  return 0;
}