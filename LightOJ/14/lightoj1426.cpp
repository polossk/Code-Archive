#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

typedef pair<int, int> pnt;
typedef vector<pnt> vp;
const int D = 4, N = 16;
const int  di[D] = { 0 , -1 ,  1 ,  0 };
const int  dj[D] = { 1 ,  0 ,  0 , -1 };
const char dc[D] = {'E', 'N', 'S', 'W'};

vp s, u, v;
queue<vp> q;
map<vp, string> mov;

char a[N][N];
bool vis[N][N];
int r, c, nxti[N][N][4], nxtj[N][N][4];


void min_represent(vp& v){
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
}

bool in_bounds(int i,int j){
    return 1<=i && i<=r && 1<=j && j<=c;
}

void Read(){
    scanf("%d %d",&r,&c);
    for (int i=1;i<=r;i++)
		scanf("%s",a[i]+1);
	return;
}

void Init(){
    s.clear();
    for (int i=1;i<=r;i++)
	for (int j=1;j<=c;j++)
		for (int d=0;d<D;d++)
			if (a[i][j] == '.'){
				s.push_back(pnt(i,j));
				int& ni=nxti[i][j][d];
				int& nj=nxtj[i][j][d];
				for (ni=i+di[d],nj=j+dj[d];in_bounds(ni,nj) && a[ni][nj]=='.';ni+=di[d],nj+=dj[d]){}
				if (in_bounds(ni,nj)){
						ni-=di[d];
						nj-=dj[d];
				}
		}
	return;
}

bool dfs(int i,int j){
    if (!in_bounds(i,j))return 1;
	if (!((vis[i][j]<1) ? vis[i][j]=1,1 : 0))return 0;
	for (int d=0;d<D;d++)
        if(dfs(nxti[i][j][d],nxtj[i][j][d]))
            return 1;
    return 0;
}

bool impossible(){
    for (int i=1;i<=r;i++)
	for (int j=1;j<=c;j++)
		if(a[i][j] == '.')
            if(memset(vis,0,sizeof(vis)),!dfs(i,j))
                return 1;
    return 0;
}

string BFS(){
    mov.clear();
    mov[s] = "";
    while (!q.empty()) q.pop();
    for (q.push(s); !q.empty(); q.pop()){
        u=q.front();
        int sz_u=((int)(u).size());
        if (!sz_u) return mov[u];
        for (int d=0;d<D;d++){
            v.clear();
            for (int k_u=((int)(u).size()),k=0;k<k_u;k++){
                int ni=nxti[u[k].first][u[k].second][d];
                int nj=nxtj[u[k].first][u[k].second][d];
                if(in_bounds(ni, nj)) v.push_back(pnt(ni, nj));
            }
            min_represent(v);
            if (mov.find(v) == mov.end()){
				 mov[v]=mov[u]+dc[d];
				 q.push(v);
            }
        }
    }
    return "";
}


string min_moves(){
    return impossible()?"Impossible":BFS();
}

void solve(int tt){
	Read();
	Init();
	printf("Case %d: %s\n",tt,min_moves().c_str());
	return;
}

int main() {
    int T;scanf("%d",&T);int tt=0;
    while (T--){
		solve(++tt);
    }
    return 0;
}
