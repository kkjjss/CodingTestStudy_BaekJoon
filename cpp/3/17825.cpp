#include <bits/stdc++.h>
using namespace std;

int m[4];
int input[10];
int val[40] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 13, 16, 19, 22, 24, 28, 27, 26, 25, 30, 35, 0};
vector<int> adj[40];
int ret = 0;

int move(int start, int dist)
{
  if (start == 32)
    return 32;
  int pos = adj[start][0];
  if (start == 5 || start == 10 || start == 15)
    pos = adj[start][1];
  dist--;

  while (dist-- && pos < 32)
    pos = adj[pos][0];

  return pos;
}

bool flag(int new_pos, int idx)
{
  if (new_pos == 32)
    return false;
  for (int i = 0; i < 4; i++)
  {
    if (i == idx)
      continue;
    else if (m[i] == new_pos)
      return true;
  }
  return false;
}

int go(int idx)
{
  if (idx == 10)
    return 0;
  int tmp = 0;
  for (int i = 0; i < 4; i++)
  {
    int temp_pos = m[i];
    int new_pos = move(m[i], input[idx]);
    if (flag(new_pos, i))
      continue;
    m[i] = new_pos;
    tmp = max(tmp, val[m[i]] + go(idx + 1));
    m[i] = temp_pos;
  }
  return tmp;
}

int main()
{
  for (int i = 0; i < 10; i++)
    cin >> input[i];

  adj[0].push_back(1);
  adj[1].push_back(2);
  adj[2].push_back(3);
  adj[3].push_back(4);
  adj[4].push_back(5);
  adj[5].push_back(6);
  adj[6].push_back(7);
  adj[7].push_back(8);
  adj[8].push_back(9);
  adj[9].push_back(10);
  adj[10].push_back(11);
  adj[11].push_back(12);
  adj[12].push_back(13);
  adj[13].push_back(14);
  adj[14].push_back(15);
  adj[15].push_back(16);
  adj[16].push_back(17);
  adj[17].push_back(18);
  adj[18].push_back(19);
  adj[19].push_back(20);
  adj[5].push_back(21);
  adj[21].push_back(22);
  adj[22].push_back(23);
  adj[23].push_back(29);
  adj[10].push_back(24);
  adj[24].push_back(25);
  adj[25].push_back(29);
  adj[15].push_back(26);
  adj[26].push_back(27);
  adj[27].push_back(28);
  adj[28].push_back(29);
  adj[29].push_back(30);
  adj[30].push_back(31);
  adj[31].push_back(20);
  adj[20].push_back(32);

  cout << go(0) << '\n';

  return 0;
}