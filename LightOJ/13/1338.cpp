// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1338                                             *
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

const char aye[] = "Yes";
const char nay[] = "No";
int t, tt;
int a[26], b[26];
string s1, s2;
void solve()
{
    getline(cin, s1);   getline(cin, s2);
    fill(a, a + 26, 0); fill(b, b + 26, 0);
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    for (int sz = s1.size(), i = 0; i < sz; i++)
        if (isalpha(s1[i])) a[s1[i] - 'a']++;
    for (int sz = s2.size(), i = 0; i < sz; i++)
        if (isalpha(s2[i])) b[s2[i] - 'a']++;
    for (int i = 0; i < 26; i++)
        if (a[i] != b[i])
    {
        printf("Case %d: %s\n", ++tt, nay);
        return;
    }
    printf("Case %d: %s\n", ++tt, aye);
}

int main()
{
    t = nextInt(); getchar(); while (t--) solve();
    return 0;
}
