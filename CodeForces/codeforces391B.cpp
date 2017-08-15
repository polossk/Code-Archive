/****
	*@PoloShen
	*Title:B
	*/
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 1020;
const int M = 400005;
string s;
int a[N], ans, len;
int vis[N];
struct node
{
    int pos,ans;
    node(int a=0,int b=0):pos(a),ans(b) {}
};
int dfs(int x)
{
    if(vis[x])return vis[x];
    for(int i = x+1; i < len; i+=2)if(s[x]==s[i])
            vis[x] = max(dfs(i),vis[x]);
    vis[x] ++;
    return vis[x];
}
int main()
{
    int i, j, n;
    while(getline(cin, s))
    {
        memset(vis, 0, sizeof(vis));
        len = s.size();
        ans = 1;
        for(i=0; i<len; i++)if(vis[i]==false)ans = max(ans,dfs(i));
        printf("%d\n",ans);
    }
    return 0;
}