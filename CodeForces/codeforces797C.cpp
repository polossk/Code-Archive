// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   Educational Codeforces Round 19 C                        *
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


stack<char> s;
int cnt[26 + 1];

int main()
{
    string ans, str = nextStr();
    for (int i = 0, sz = str.size(); i < sz; i++)
    {
        cnt[str[i] - 'a']++;
    }
    int idx = 0;
    for (int i = 0, sz = str.size(); i < sz; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            char nxt = 'a' + j;
            if (!s.empty() && s.top() == nxt)
            {
                ans += nxt; s.pop(); break;
            }
            
            if (!cnt[j]) continue;
            while (idx < sz)
            {
                s.push(str[idx]);
                cnt[str[idx++] - 'a']--;
                if (s.top() == nxt)
                {
                    ans += nxt; s.pop(); break;
                }
            }
            break;
        }
    }
    cout << ans << endl;
    return 0;
}