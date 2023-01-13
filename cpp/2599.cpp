// #include <bits/stdc++.h>
// using namespace std;

// int N;
// int am, af;
// int bm, bf;
// int cm, cf;

// int main()
// {
//   cin >> N;

//   cin >> am >> af;
//   cin >> bm >> bf;
//   cin >> cm >> cf;

//   char f[N];

//   for (int i = 0; i < N; i++)
//   {
//     if (i < af)
//       f[i] = 'a';
//     else if (af <= i && i < af + bf)
//       f[i] = 'b';
//     else
//       f[i] = 'c';
//   }

//   do
//   {
//     bool check = true;
//     int ab = 0, ac = 0, ba = 0, bc = 0, ca = 0, cb = 0;

//     for (int i = 0; i < N; i++)
//     {
//       if (i < am)
//       {
//         if (f[i] == 'a')
//         {
//           check = false;
//           break;
//         }
//         else
//         {
//           if (f[i] == 'b')
//             ab++;
//           else if (f[i] == 'c')
//             ac++;
//         }
//       }
//       else if (am <= i && i < am + bm)
//       {
//         if (f[i] == 'b')
//         {
//           check = false;
//           break;
//         }
//         else
//         {
//           if (f[i] == 'a')
//             ba++;
//           else if (f[i] == 'c')
//             bc++;
//         }
//       }
//       else if (am + bm <= i)
//       {
//         if (f[i] == 'c')
//         {
//           check = false;
//           break;
//         }
//         else
//         {
//           if (f[i] == 'a')
//             ca++;
//           else if (f[i] == 'b')
//             cb++;
//         }
//       }
//     }

//     if (check)
//     {
//       cout << ab << ' ' << ac << '\n'
//            << ba << ' ' << bc << '\n'
//            << ca << ' ' << cb << '\n';
//       break;
//     }
//   } while (next_permutation(f, f + N));

//   return 0;
// }

// 시간 초과!