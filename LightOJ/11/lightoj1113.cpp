// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1113                                             *
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

const string _st = "http://www.lightoj.com/";
int t, tt;

void solve()
{
    printf("Case %d:\n", ++tt);
    vector<string> bowr;
    int it = 0;
    bowr.push_back(_st);
    string order, url;
    while (cin>>order)
    {
        switch (order[0])
        {
            case 'V':
            {
                url = nextStr();
                vector<string>::iterator ed = bowr.end();
                vector<string>::iterator i = bowr.begin();
                int sz = bowr.size(); i += it; i++;
                bowr.erase(i, ed); bowr.push_back(url); it++;
                cout << bowr[it] << endl;
                break;
            }
            case 'B':
            {
                if (it >= 1) cout << bowr[--it] << endl;
                else cout << "Ignored" << endl;
                break;
            }
            case 'F':
            {
                if (it + 1 < bowr.size()) cout << bowr[++it] << endl;
                else cout << "Ignored" << endl;
                break;
            }
            case 'N': { cout << bowr[it] << endl; break; }
            case 'Q': { return; }
            default : break;
        }
    }
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
