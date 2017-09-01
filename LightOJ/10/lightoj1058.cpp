/****
	*@Polo-shen
	*
	*/
#include <iostream>
//#include <iomanip>
//#include <fstream>
#include <algorithm>
//#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
//#include <cstdlib>
//#include <set>

using namespace std;
typedef long long int64;

#define DBG 0
#define ShowLine DBG && cout<<__LINE__<<">>| "
#define dout DBG && cout<<__LINE__<<">>| "
#define write(x) #x" = "<<(x)<<", "

struct Node{
	int x,y;
}data[1005],mid[1001005];
int n;
int C(int k){
	return k*(k-1)/2;
}

int cmp(const Node &a,const Node &b){
	if (a.x == b.x)
		return a.y<b.y;
	return a.x<b.x;
}

void Deal(){
	int i,j,num=1,ans=0,id=-1;
	for (i=1;i<n;i++)
		for (j=i+1;j<=n;j++){
			id++;
			mid[id].x=data[i].x+data[j].x;
			mid[id].y=data[i].y+data[j].y;
		}
	sort(mid,mid+id+1,cmp);                 //注意排序区间
	for (i=0;i<id;i++){
		if (mid[i].x==mid[i+1].x && mid[i].y==mid[i+1].y)
			num++;
		else{
			ans+=C(num);
			num=1;
		}
	}
	printf("%d\n",ans);
}
int main (){
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++){
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d%d",&data[i].x,&data[i].y);
		printf("Case %d: ",cas);
		Deal ();
	}
	return 0;
}
