// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   uvalive 6884                                             *
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

const int MAXN = 11;
const int MAXC = 26 + 4;

char s[MAXN][MAXN];
int n, num[MAXC];
bool vis[MAXC], ban_zero[MAXC], used[MAXN];
vector<int> idx, slen;
vector<char> t;

inline int str2int(int index, int len)
{
    return std::accumulate(s[index], s[index] + len, 0,
        [](int _, char x) -> int
        {
            return _ * 10 + num[x - 'A'];
        });
}

inline int _dbg_str2int(int index, int len)
{
    int _ = std::accumulate(s[index], s[index] + len, 0,
        [](int _, char x) -> int
        {
            return _ * 10 + num[x - 'A'];
        });
    cout << s[index] << " " << _ << endl;
    return _;
}

bool judge()
{
    int sum = std::accumulate(idx.begin(), idx.end(), 0,
        [](int _, int x) -> int { return _ + str2int(x, slen[x]); });
    bool ret = sum == str2int(n - 1, slen.back());
    // if (!ret) return ret;
    // int _ = std::accumulate(idx.begin(), idx.end(), 0,
    //     [](int _, int x) -> int { return _ + _dbg_str2int(x, slen[x]); });
    // int _2 = _dbg_str2int(n - 1, slen.back());
    // cout << "======================" << endl;
    // return _ == _2;
    return sum == str2int(n - 1, slen.back());
}

int dfs(int now)
{
    int ans = 0;
    // cout << __func__ << "( " << now << " ) ->" << endl;
    if (now >= t.size()) return judge() ? 1 : 0;
    for (int i = 0; i < 10; i++)
    {
        if (used[i]) continue;
        if (i == 0 && ban_zero[t[now] - 'A'])
            continue;
        num[t[now] - 'A'] = i;
        used[i] = 1;
        ans += dfs(now + 1);
        used[i] = 0;
    }
    return ans;
}

void solve()
{
    idx.clear(); slen.clear(); t.clear();
    for (int i = 0; i + 1 < n; i++) idx.push_back(i);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    int anslen = strlen(s[n - 1]);
    for (int i = 0; i + 1 < n; i++)
        slen.push_back(strlen(s[i]));
    int maxlen = std::accumulate(slen.begin(), slen.end(), 0,
        [](int _, int x) -> int { return max(_, x); });
    if (maxlen > anslen) { puts("0"); return; }
    slen.push_back(anslen);

    memset(num, 0, sizeof num);
    memset(vis, 0, sizeof vis);
    memset(used, 0, sizeof used);
    memset(ban_zero, 0, sizeof ban_zero);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < slen[i]; j++)
            if (!vis[s[i][j] - 'A'])
    {
        t.push_back(s[i][j]);
        vis[s[i][j] - 'A'] = true;
    }
                
    for (int i = 0; i < n; i++)
        ban_zero[s[i][0] - 'A'] = true;

    printf("%d\n", dfs(0));
}

int main()
{
    while (~scanf("%d", &n)) solve();
    return 0;
}