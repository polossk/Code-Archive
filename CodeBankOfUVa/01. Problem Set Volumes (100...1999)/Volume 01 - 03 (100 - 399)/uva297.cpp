// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   uva 297                                                  *
*****************************************************************************/
// 人一我百，人十我万！追逐青春的梦想，怀着自信的心，永不放弃！
//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

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

const bool WIN  = true;
const bool LOSE = false;
const char aye[] = "Yes";
const char nay[] = "No";
const char ace[] = "Alice";
const char bob[] = "Bob";

struct qtnode
{
    int id;
    qtnode* chs[4];
};

qtnode* tree(string& str, int& pos)
{
    qtnode* root = (qtnode*)malloc(sizeof(qtnode));
    root->id = 0;
    if (str[pos] == 'p') // create a new tree
    {
        for (int i = 0; i < 4; i++)
        {
            pos++;
            root->chs[i] = tree(str, pos);
        }
    }
    else if (str[pos] == 'f') // colored node
    {
        root->id = 1;
        for (int i = 0; i < 4; i++)
            root->chs[i] = NULL;
    }
    else if (str[pos] == 'e') // empty node
    {
        root->id = 2;
        for (int i = 0; i < 4; i++)
            root->chs[i] = NULL;
    }
    return root;
}

void _fdisplay(qtnode* root)
{
    if (root->id == 0)
    {
        putchar('p');
        for (int i = 0; i < 4; i++)
            _fdisplay(root->chs[i]);
    }
    else putchar(root->id == 1? 'f': 'e');
}

inline void fdisplay(qtnode* root)
{
    _fdisplay(root);
    puts("");
}

void _dfs(qtnode* t1, qtnode* t2, int dep, int& sum)
{
    if (!t1 && !t2) return;
    if (!t1)
    {
        if (t2->id == 1)
        {
            sum += (1024 >> (2 * dep));
            return;
        }
        for (int i = 0; i < 4; i++)
            _dfs(t1, t2->chs[i], dep + 1, sum);
        return;
    }
    if (!t2)
    {
        if (t1->id == 1)
        {
            sum += (1024 >> (2 * dep));
            return;
        }
        for (int i = 0; i < 4; i++)
            _dfs(t1->chs[i], t2, dep + 1, sum);
        return;
    }
    if ( (t1->id == 1) || (t2->id == 1))
    {
        sum += (1024 >> (2 * dep));
        return;
    }
    for (int i = 0; i < 4; i++)
        _dfs(t1->chs[i], t2->chs[i], dep + 1, sum);
}

inline int dfs(qtnode* t1, qtnode* t2, int dep)
{
    int sum = 0;
    _dfs(t1, t2, dep, sum);
    return sum;
}

void solve()
{
    string s1 = nextStr();
    string s2 = nextStr();
    int p = 0;
    qtnode* t1 = tree(s1, p);
    p = 0;
    qtnode* t2 = tree(s2, p);
    printf("There are %d black pixels.\n", dfs(t1, t2, 0));
}

int main()
{
    int n = nextInt();
    while (n--) solve();
    return 0;
}
