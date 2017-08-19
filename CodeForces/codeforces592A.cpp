// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :                                                            *
*****************************************************************************/
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

typedef pair<int, int> Cell;

vector<Cell> A, B;

void ReadChess()
{
    for (int i = 0; i < 8; i++)
    {
        char s[10]; scanf("%s", s);
        for (int j = 0; j < 8; j++)
        {
            if (s[j] == 'W') A.push_back(make_pair(j, i));
            if (s[j] == 'B') B.push_back(make_pair(j, i));
        }
    }
}

void solve()
{
    int sza = A.size(), szb = B.size();
    int hoge = 9, piyo = 9, fuga = 0;
    for (int i = 0; i < sza; i++)
    {
        bool flag = true;
        for (int j = 0; j < szb; j++)
        {
            if (A[i].first == B[j].first && A[i].second > B[j].second)
            {
                flag = false;
                break;
            }
        }
        fuga = flag ? A[i].second : 9;
        hoge = min(hoge, fuga);
    }
    for (int i = 0; i < szb; i++)
    {
        bool flag = true;
        for (int j = 0; j < sza; j++)
        {
            if (A[j].first == B[i].first && A[j].second > B[i].second)
            {
                flag = false;
                break;
            }
        }
        fuga = flag ? 7 - B[i].second : 9;
        piyo = min(piyo, fuga);
    }
    printf("%c\n", hoge > piyo ? 'B' : 'A');
}


int main()
{
    ReadChess();
    solve();
    return 0;
}