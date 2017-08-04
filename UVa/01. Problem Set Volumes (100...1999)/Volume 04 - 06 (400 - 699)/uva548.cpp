// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   uva 548                                                  *
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

const int MaxN = 10007;

int inOrder[MaxN], postOrder[MaxN];
int n, idx;

struct Node
{
    int value;
    Node* left;
    Node* right;
};

Node node[MaxN];
vector<int> res;
vector<Node*> pnt;

Node* newNode()
{
    node[idx].left = NULL;
    node[idx].right = NULL;
    return &node[idx++];
}

Node* build(int* in, int* post, int len)
{
    if (len == 0) return NULL;
    int pos = len - 1, i = len - 1;
    while (post[len - 1] != in[i]) i--;
    Node* fa = newNode();
    fa -> value = post[pos];
    fa -> left  = build(in, post, i);
    fa -> right = build(in + i + 1, post + i, pos - i);
    return fa;
}

void input()
{
    n = 1; idx = 0;
    while (getchar() != '\n')
        scanf("%d", &inOrder[n++]);
    for (int i = 0; i < n; i++)
        postOrder[i] = nextInt();
}

void dfs(Node* fa, int cur)
{
    if (!fa -> left && !fa -> right)
    {
        res.push_back(cur + fa -> value);
        pnt.push_back(fa);
        return;
    }
    if (fa ->  left) dfs(fa -> left, cur + fa -> value);
    if (fa -> right) dfs(fa -> right, cur + fa -> value);
}

void solve()
{
    input();
    Node* root = build(inOrder, postOrder, n);
    res.clear();
    pnt.clear();
    dfs(root, 0);
    int minPos = 0;
    for (int i = 1, sz = res.size(); i < sz; i++)
        minPos = res[i] < res[minPos]? i: minPos;
    printf("%d\n", pnt[minPos] -> value);
}

int main()
{
    while (~scanf("%d", &inOrder[0])) solve();
    return 0;
}
