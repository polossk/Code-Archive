#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;

const int Maxn = 128;
const int Infi = 99999999;
int n, d;

typedef struct coordinate{
	double x, y;
}coor;

coor City[Maxn];
bool isStation[Maxn];
int path[Maxn][Maxn];

int dist(int i, int j){
	return ceil(
				sqrt(
					(City[i].x - City[j].x) * (City[i].x - City[j].x)
					+
					(City[i].y - City[j].y) * (City[i].y - City[j].y)
					)
				);
}

bool bfs(){
	bool visit[Maxn];
    int toStation[Maxn];
    memset(visit,0,sizeof(visit));
    for (int i = 0; i < n; i++){
		if (isStation[i])toStation[i] = 0;
		else toStation[i] = Infi;
    }
    visit[0] = 1;
    queue<int> citylist;
    citylist.push(0);
    while (!citylist.empty()){
        int u = citylist.front();
        citylist.pop();
        for (int i = 0; i < n; i++){
            if (!visit[i] && path[u][i] <= d){
                toStation[i] = min(toStation[i], toStation[u] + path[u][i]);
                if(isStation[i]){
                    citylist.push(i);
				visit[i] = 1;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(isStation[i] && !visit[i]) return 0;
        if(!isStation[i] && toStation[i] * 2>d) return 0;
    }
    return 1;
}

void read(int n){
	for (int i = 0; i < n; i++){
		scanf("%lf%lf", &City[i].x, &City[i].y);
	}
	return;
}

void setdis(int n){
	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
			path[i][j] = path[j][i] = dist(i, j);
		}
	}
	return;
}

void solve(int n, int d){
	for (int i = 0; i < n; i++) isStation[i]=1;
    if (!bfs()){
		printf("-1\n");
		return;
	}
    for (int i = n - 1; i > 0; i--){
        isStation[i]=0;
        if(!bfs())isStation[i] = 1;
    }
    int j = n - 1;
    //直接用二进制输出了，去掉前面的零
    while (!isStation[j]) j--;
    for (int i = j; i >= 0; i--) printf("%d",isStation[i]);
    printf("\n");
}

int main(){
	while (scanf("%d%d", &n, &d) != EOF){
		read(n);
		setdis(n);
		solve(n, d);
	}
	return 0;
}