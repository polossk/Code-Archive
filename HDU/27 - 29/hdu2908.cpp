#include <iostream>
#include <cstdio> 
#include <cstring>
using namespace std;
int main(){
	int n,w,i;
	int v[101],mark[101];//mark统计图
	int s,fen;
	int max;//记录极值
	while(cin>>n>>w,n||w){
		memset(mark,0,sizeof(mark));
		max=0;
		for(i=0;i<n;i++){
			cin>>v[i];
			mark[v[i]/w]++;
			if(max<v[i])max=v[i];//输入的数中最大的数
		}
		fen=max/w;//fen表示可以分的份数
		//fen++;
		max=0;
		for(i=0;i<=fen;i++){
			if(mark[i]>max)//占份数最多。
				max=mark[i];
		}
		s=max;
		double ans;
		ans=0.01;
		for(i=0;i<=fen;i++){
			ans+=(i*1.0/fen)*(mark[fen-i]*1.0/s);
		}
		printf("%.6f\n",ans);
	}
	return 0;
}