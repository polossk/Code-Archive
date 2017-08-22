// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   Codeforces Round #402 (Div. 2) D                         *
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

const int MAXN = 200000 + 5;
const int LEND = 26;

string t, p;
int len_t, len_p;

vector< vector<int> > trie;
vector<int> pos(MAXN, 0);
vector<bool> vis(MAXN, false);

void __init__()
{
    trie.resize(MAXN);
    for (auto &_ : trie) _.resize(LEND);
    for (int i = 0; i < LEND; i++)
        trie[len_t + 1][i] = len_t + 1;
    for (int i = len_t; ~i; i--)
    {
        copy(trie[i + 1].begin(), trie[i + 1].end(), trie[i].begin());
        trie[i][t[i + 1] - 'a'] = i + 1;
    }
}

bool judge()
{
    for (int i = 0, j = 1; j <= len_p; j++)
    {
        while (true)
        {
            i = trie[i][p[j] - 'a'];
            if (i > len_t || !vis[i]) break;
        }
        if (i > len_t) return 0;
    }
    return 1;
}

int binSearch(int l, int r)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        for (int i = 1; i <= mid; i++)
            vis[pos[i]] = 1;
        if (judge()) l = mid + 1;
        else r = mid - 1;
        for (int i = 1; i <= mid; i++)
            vis[pos[i]] = 0;
    }
    return r;
}


int main()
{
    cin >> t >> p;
    len_t = t.size(); t = '0' + t;
    len_p = p.size(); p = '0' + p;
    __init__();
    for (int i = 1; i <= len_t; i++)
        pos[i] = nextInt();
    printf("%d\n", binSearch(1, len_t));
    return 0;
}