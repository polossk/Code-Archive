/****
    *@PoloShen
    *Title:F
    */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int flag, n, m=4;
int vis[5][5], ans;


inline bool in(int x, int y){ return x < n && y < m; }


void dfs(int cnt){
    if (flag && cnt == n*m){
        ans++; return;
    }
    if (cnt >= n*m) return;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            if (!flag && in(i+1,j+1) && !vis[i][j] && !vis[i+1][j+1]
                    && !vis[i+1][j] && !vis[i][j+1]){
                vis[i][j] = vis[i+1][j] = vis[i][j+1] = vis[i+1][j+1] = 1;
                flag = 1;
                dfs(cnt+4);
                vis[i][j] = vis[i+1][j] = vis[i][j+1] = vis[i+1][j+1] = 0;
                flag = 0;
            }
            if (in(i+1,j) && !vis[i][j] && !vis[i+1][j]){
                vis[i+1][j] = vis[i][j] = 1;
                dfs(cnt+2);
                vis[i][j] = vis[i+1][j] = 0;
            }
            if (in(i,j+1) && !vis[i][j] && !vis[i][j+1]){
                vis[i][j] = vis[i][j+1] = 1;
                dfs(cnt+2);
                vis[i][j] = vis[i][j+1] = 0;
            }
            if (!vis[i][j]){
                vis[i][j] = 1;
                dfs(cnt+1);
                vis[i][j] = 0;
                return;
            }
        }
}


void solve(){
    scanf("%d", &n);
    memset(vis,0,sizeof(vis));
    flag = 0;
    ans = 0;
    dfs(0);
    printf("%d\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}