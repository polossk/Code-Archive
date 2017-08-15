// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*----Stay Hungry Stay Foolish----
*@author:	Shen
*@name	:	B
******************************************************************************/

//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <bits/stdc++.h>
using namespace std;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

typedef long long int64;

const int MaxN = 100005;
int n, a[MaxN];
bool inc[MaxN];

inline bool judge(int l, int r)
{
    if (l == 0 && r == n - 1)
        return 1;
    else if (l == 0)
        //cout << a[l] << a[r + 1] << endl;
        return a[l] < a[r + 1];
    else if (r == n - 1)
        //cout << a[l - 1] << a[r] << endl;
        return a[l - 1] < a[r];
    else
        //cout << a[l] << a[r + 1] << a[l - 1] << a[r] << endl;
        return a[l - 1] < a[r] && a[l] < a[r + 1];
    //return 1;
}

void solve()
{
    int l = 0, r = 0;
	int m = 0;
	// 0没有
	// 1有一个
	// 2有多个
	scanf("%d", &a[0]); inc[0] = 0;
	for (int i = 1; i < n; i++)
    {
		scanf("%d", &a[i]);
		inc[i] = (a[i] > a[i - 1]);
		//cout << "m = " << m << ", i = " << i << ", inc[" << i << "] = " << inc[i] << endl;
		if (m >= 2)
        {
            // WA //continue;
            if (!inc[i]) m++;
        }
		else if (m == 1)
        {
            if (!inc[i]) r++;
            else m++;
        }
        else if (m == 0)
        {
            l++; r++;
            if (!inc[i]) m = 1;
        }
    }
    l -= 1;
    //cout << l << " " << r << endl;
    //cout << m << endl;
    if (m == 0) puts("yes\n1 1");
    else if (m >= 3) puts("no");
    else if (judge(l, r))
    {
        puts("yes");
        printf("%d %d\n", l + 1, r + 1);
    }
    else puts("no");
}

int main()
{
    while (~scanf("%d", &n)) solve();
    return 0;
}
