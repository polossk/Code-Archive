// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   uvalive 3565                                             *
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

/*//Computational Geometry
#include <complex>
#define x real()
#define y imag()
typedef complex<double> point;
*/
string s;
int ans, L, N;
const int MAXL = 16000;
int tt;

int ones, newlen, len;

void dfs(int idx)
{
    if (newlen > L || ones > N || ans > 1) return;
    if (idx >= len) { ans += (newlen == L) && (ones == N); return; }
    if (s[idx] == '1')
    {
        for (int j = idx, k = 0, tmpones = 1; j < len; j++)
        {
            if (k < MAXL) k = k * 2 + s[j] - '0';
            tmpones &= s[j] - '0';
            if (s[j + 1] != '1')
            {
                if (k > 2)
                {
                    newlen += k; ones += k;
                    dfs(j + 1);
                    newlen -= k; ones -= k;
                }
                if (tmpones && j - idx < 2)
                {
                    int tmplen = j - idx + 1;
                    newlen += tmplen; ones += tmplen;
                    dfs(j + 1);
                    newlen -= tmplen; ones -= tmplen;
                }
            }
        }
    }
    else { newlen++; dfs(idx + 1); newlen--; }
}

int main()
{
    while (cin >> L >> N)
    {
        if (L == 0) break;
        s = nextStr(); len = s.size();
        ans = ones = newlen = 0; dfs(0);
        printf("Case #%d: %s\n", ++tt, ans > 1 ? "NOT UNIQUE" : ans ? "YES" : "NO");
    }
    return 0;
}