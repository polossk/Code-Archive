/****
    *@author    Shen
    *@title     c
    */

#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 4005;
int n, m;

struct Edge{
	int pos, val;
	bool operator<(const Edge& a)const{
		return a.val < val;
	}
}D;

set<Edge> myset;
set<Edge>::iterator p;

struct node{
	int x, y;
	node(int a = 0,int b = 0): x(a), y(b){}
}a[N],b[N];

int dis(node a, node b){
	int dx = a.x - b.x;
	int dy = a.y - b.y;
	return dx * dx + dy * dy;
}

int St[1001];

void solve(){
    int t = n * n + m * m;
    int t1 = 0, t2 = 0;
    n = n * n; m = m * m;
    for (int i = 1; i * i < n; i++)
    {
        D.val = n - i * i;
        p = myset.find(D); if (p==myset.end()) continue;
        D = *p;
        a[t1++] = node(i, D.pos);
        a[t1++] = node(i, -D.pos);
        a[t1++] = node(-i, D.pos);
        a[t1++] = node(-i, -D.pos);
    }
    for (int i = 1; i * i < m; i++)
    {
        D.val = m - i * i;
        p = myset.find(D); if (p==myset.end()) continue;
        D = *p;
        b[t2++] = node(i, D.pos);
        b[t2++] = node(i, -D.pos);
        b[t2++] = node(-i, D.pos);
        b[t2++] = node(-i, -D.pos);
    }
    if (t1 == 0 || t2 == 0){ puts("NO"); return; }
    bool ok = false;

    int i = 0, j = 0;

    for (i = 0; i < t1; i++)
    {
        for (j = 0; j < t2; j++)
            if (dis(a[i], b[j]) == t)
            {
                if (a[i].x == b[j].x || a[i].y == b[j].y) continue;
                if (a[i].x == 0 || a[i].y == 0 || b[j].x == 0 || b[j].y == 0) continue;
                ok = true; break;
            }
        if (ok) break;
    }
    if (ok == false) { puts("NO"); return; }
    puts("YES");
    puts("0 0");
    printf("%d %d\n%d %d\n", a[i].x, a[i].y, b[j].x, b[j].y);
}

int main(){
	myset.clear();
	for (int i = 0; i <= 1000; i++){
		Edge E={i, i * i};
		myset.insert(E);
	}
	while(~scanf("%d %d", &n, &m)) solve();
    return 0;
}
