#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
//#include <cstdlib>
using namespace std;

#define DBG 1
#define ShowLine DBG && cout<<__LINE__<<">>| "
#define dout DBG && cout<<__LINE__<<">>| "
#define write(x) #x" = "<<(x)<<", "
typedef long long int64;
#define	clr(a)		memset((a),0,sizeof (a))
#define	rep(i,a,b)	for(int i=(a);i<(int)(b);i++)
#define	per(i,a,b)	for(int i=((a)-1);i>=(int)(b);i--)
#define	inf			0x7ffffff
#define	eps			1e-6
using namespace std;
int mm[10005];
int num[10005];
bool search(int a,int b,int  key){
    if (a>b)return 0;
    int mid=(a+b)/2;
    if (mm[mid]==key){
		return 1;
    }
    if (mm[mid]>key){
		return search(a,mid-1,key);
    }
    else{
		return search(mid+1,b,key);
    }
}

int main(){
	for (int i=1;i<=10000;i++){
		mm[i]=i*i;
	}
	for (int i=10000;i>=1;i--){
		for (int j=i-1;j>=1;j--){
			int tt=i*i-j*j;
			if (tt>j*j)break;
			if (search(1,10000,tt)){
				num[i]++;
			}
		}
	}
	int n;
	scanf("%d",&n);
	int sum=0;
	for (int i=1;i<=n;i++){
		sum+=num[i];
	}
	printf("%d\n",sum);
	return 0;
}