// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   B                                                        *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }
inline char   nextChr() { scanf(" "); return getchar(); }
inline string nextStr() { string s; cin >> s; return s; }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  nextlld() { int64 d; scanf("%lld", &d); return d; }
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }


#define to_i(ch) (ch - '0')

void solve()
{
    string str = nextStr();
    int sz = str.size();
    bool flag = false;
    for (int i = 0; i < sz; i++)
        flag |= !(to_i(str[i]) & 1);
    if (!flag) puts("-1");
    else
    {
        int lst = to_i(str[sz - 1]);
        int pos = 0, val = 0;
        for (int i = 0; i < sz - 1; i++)
        {
            int tmp = to_i(str[i]);
            if (!(tmp & 1))
            {
                if (tmp < lst)
                {
                    swap(str[sz - 1], str[i]);
                    puts(str.c_str());
                    return;
                }
                else
                {
                    val = tmp, pos = i;
                    continue;
                }
            }
            else continue;
        }
        swap(str[sz - 1], str[pos]);
        puts(str.c_str());
    }
}

int main()
{
    solve();
    return 0;
}