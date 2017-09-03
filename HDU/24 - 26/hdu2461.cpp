/****
	*@Polo-shen
	*
	*/
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
//#include <cmath>
//#include <iomanip>
//#include <fstream>
#include <cstdlib>
//#include <vector>
//#include <list>
//#include <set>

using namespace std;
typedef long long int64;

#define DBG 0
#define ShowLine DBG && cout<<__LINE__<<">>| "
#define dout DBG && cout<<__LINE__<<">>| "
#define write(x) #x" = "<<(x)<<", "

#ifndef min
#define min(x,y) ((x) < (y) ? (x) : (y))
#endif

#ifndef max
#define max(x,y) ((x) > (y) ? (x) : (y))
#endif

int n,m,num,res;
int a[25];

struct Node{
    int x1,y1,x2,y2;
    int s;
}node[25];

bool check(Node x,int u){
    if(node[u].x1>=x.x2) return 0;
    if(x.x1>=node[u].x2) return 0;
    if(node[u].y1>=x.y2) return 0;
    if(x.y1>=node[u].y2) return 0;
    return 1;
}

void judge(Node rec,int id,int k){
    Node temp;
    if(id==num+1) return ;
    for(int i=id; i<=num; i++){
        if(check(rec,a[i])){
            temp.x1=(rec.x1>node[a[i]].x1)?rec.x1:node[a[i]].x1;
            temp.y1=(rec.y1>node[a[i]].y1)?rec.y1:node[a[i]].y1;
            temp.x2=(rec.x2<node[a[i]].x2)?rec.x2:node[a[i]].x2;
            temp.y2=(rec.y2<node[a[i]].y2)?rec.y2:node[a[i]].y2;
            temp.s=(temp.x2-temp.x1)*(temp.y2-temp.y1);
            if(k%2) res+=temp.s;
            else res-=temp.s;
            judge(temp,i+1,k+1);
        }
    }
}

int main(){
    int count=1;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0&&m==0) break;
        for(int i=1; i<=n; i++){
            scanf("%d%d%d%d",&node[i].x1,&node[i].y1,&node[i].x2,&node[i].y2);
            node[i].s=(node[i].x2-node[i].x1)*(node[i].y2-node[i].y1);
        }
        printf("Case %d:\n",count++);
        for(int i=1; i<=m; i++){
            scanf("%d",&num);
            res=0;
            for(int j=1; j<=num; j++){
                scanf("%d",&a[j]);
                res+=node[a[j]].s;
            }
            for(int j=1; j<=num; j++){
                judge(node[a[j]],j+1,0);
            }
            printf("Query %d: %d\n",i,res);
        }
        puts("");
    }
    return 0;
}
