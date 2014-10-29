// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   uva 11234                                                *
*****************************************************************************/
// 人一我百，人十我万！追逐青春的梦想，怀着自信的心，永不放弃！
//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

//#include <bits/stdc++.h>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <cctype>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
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

struct node
{
    char data;
    node* left;
    node* right;
    node(char d = 0, node* l = 0, node * r = 0)
    {
        data = d; left = l; right = r;
    }
};

node* build(char data, node* l, node* r)
{
    node* fa = new node(data, l, r);
    return fa;
}

void solve()
{
    string buf = nextStr();
    stack<node*> s;
    queue<node*> q;
    string ans;
    for (int i = 0, sz = buf.size(); i < sz; i++)
    {
        if (islower(buf[i]))
        {
            node* tree = new node(buf[i], 0, 0);
            s.push(tree);
        }
        else
        {
            node* r = s.top(); s.pop();
            node* l = s.top(); s.pop();
            s.push(build(buf[i], l, r));
        }
    }
    q.push(s.top());
    while (!q.empty())
    {
        node* cur = q.front(); q.pop();
        ans += cur -> data;
        if (cur -> left)  q.push(cur -> left);
        if (cur -> right) q.push(cur -> right);
    }
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
    cout << endl;
}

int main()
{
    int t = nextInt();
    while (t--) solve();
    return 0;
}
