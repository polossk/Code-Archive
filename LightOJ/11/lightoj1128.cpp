#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int Maxn=100010;

int stk[Maxn],size;
int v[Maxn],p[Maxn],ans[Maxn];

struct QUE{
	int val,pos;
}que;

vector<QUE> q[Maxn];
vector<int> vec[Maxn];

int bsearch(int val){
	int l=1,r=size;
	while (l<=r){
		int mid=(l + r)/2;
		if (v[stk[mid]] >= val)r=mid-1;
		else l=mid + 1;
	}
	return stk[r + 1];
}

int dfs(int r){
	int i;
	stk[++size]=r;
	for (i=0;i<q[r].size();i++){
		ans[q[r][i].pos]=bsearch(q[r][i].val);
	}
	for (i=0;i<vec[r].size();i++){
		dfs(vec[r][i]);
	}
	size--;
}

void solve(int tt){
    int n,m,i,tnode;
    printf("Case %d:\n",tt);
    scanf(" %d %d",&n,&m);
    v[0]=1;
    for (i=0;i<n;i++){
        vec[i].clear();
        q[i].clear();
    }
    for (i=1;i<n;i++){
        scanf(" %d %d",&p[i],&v[i]);
        vec[p[i]].push_back(i);
    }
    for (i=0;i<m;i++){
        scanf(" %d %d",&tnode,&que.val);
        que.pos=i;
        q[tnode].push_back(que);
    }
    size=0;
    dfs(0);
    for (i=0;i<m;i++){
        printf("%d\n",ans[i]);
    }
}

int main(){
	int T,tt=0;
	scanf(" %d",&T);
	while (T--){
		solve(++tt);
	}
	return 0;
}
