#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

typedef long long int64;
typedef unsigned long long Uint64;

const int MAXN=50050;
map<Uint64,int> g;
int ar[MAXN][30];
int cnt[30];
void solved(int tt) {
    int L,K,Q,p;
    scanf(" %d %d",&L,&K);
    g.clear();
    memset(ar,0,sizeof(ar));
    for (int i=0;i<K;++i) {
        scanf(" %d",&Q);
        while (Q--) {
            scanf(" %d",&p);
            ar[p][i]++;
        }
    }
    int ret=p=0;
    for (int i=0;i<L;++i) {
        int mi=L+1,ma=-1;
        for (int j=0;j<K;++j) {
            if (i) ar[i][j]+=ar[i-1][j];
            mi=min(mi,ar[i][j]);
            ma=max(ma,ar[i][j]);
        }
        if (mi == ma) ret=i+1;
        for (int j=0;j<K;++j) {
            cnt[j]=ar[i][j]-mi;
        }
        Uint64 tmp=0;
        for (int j=0;j<K;++j) {
            tmp *= 16777619;
            tmp ^= cnt[j];
        }
        int t=g[tmp];
        if (t) {
            ret=max(ret,i-t+1);
        }
        else {
            g[tmp]=i+1;
        }
    }
    printf("Case %d: %d meter(s)\n",tt,ret);
}

int main (){
    int T;scanf(" %d",&T);
    int tt=0;
    while (T--){
        solved(++tt);
    }
    return 0;
}
