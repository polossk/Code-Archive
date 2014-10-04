#include <iostream>
#include <cstdio>
using namespace std;
int q[10005], p[10005];
int main()
{
    int k, r, n;
    char ch;
    while (cin >> k)
    {
        n = 0;
          while (1)
          {
              scanf("%d%c", &p[n++], &ch);
              if (ch == '\n') break;
          }
          q[0] = p[0];
          printf("q(x): %d", q[0]);
          for (int i = 1; i < n - 1; i++)
          {
              q[i] = q[i - 1] * k + p[i];
              printf(" %d" , q[i]);
          }
          printf("\nr = %d\n\n", q[n - 2] * k + p[n - 1]);
    }
    return 0;
}
