#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

const int MaxN = 100005;
const int INF  = 0x3f3f3f3f;
int a[MaxN];
int main()
{
    int M, T, U, F, D;
    char ch;
    int ans = 0;
    bool isFind = false;
    cin >> M >> T >> U >> F >> D;
    for (int i = 0; i < T; i++)
    {
        cin >> ch;
        if (!isFind)
        {
            int tmp;
            if (ch == 'u' || ch == 'd') tmp = U + D;
            else tmp = 2 * F;
            if (M < tmp) { ans = i; isFind = true; }
            else M -= tmp;
        }
    }
    cout << ans << endl;
    return 0;
}