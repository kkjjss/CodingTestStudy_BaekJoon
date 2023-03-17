#include <bits/stdc++.h>
using namespace std;

int n, t, mm, ss, wtime[3], goal[3];

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    scanf("%d %2d:%2d", &t, &mm, &ss);
    goal[t]++;
    if (goal[t] == goal[3 - t] + 1)
      wtime[t] += 48 * 60 - (mm * 60 + ss);
    else if (goal[t] == goal[3 - t])
      wtime[3 - t] -= 48 * 60 - (mm * 60 + ss);
  }

  printf("%02d:%02d\n%02d:%02d\n", wtime[1] / 60, wtime[1] % 60, wtime[2] / 60, wtime[2] % 60);

  return 0;
}