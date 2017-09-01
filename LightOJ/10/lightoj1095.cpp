/****
	*@Polo-shen
	*
	*/
#include <iostream>
//#include <iomanip>
//#include <fstream>
#include <algorithm>
#include <cmath>
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

int64 C[1010][1010],F[1010],p=1000000007;
int main(){
    for (int i=0;i<=1005;i++)
		for (int j=0;j<=1005;j++)
		if (j==0||j==i)
			C[i][j]=1;
		else
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;
    F[0]=1;
    for (int i=1;i<=1005;i++)
		F[i]=F[i-1]*i%p;
    int T;
    scanf("%d",&T);
    for (int test=1;test<=T;test++){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        int64 ans=F[n-k];
        for (int i=1;i<=(m-k);i++){
            if(i&1)
				ans=((ans-C[m-k][i]*F[n-k-i])%p+p)%p;
            else
				ans=((ans+C[m-k][i]*F[n-k-i])%p+p)%p;
        }
        ans=ans*C[m][k]%p;
        printf("Case %d: %lld\n",test,ans);
    }
    return 0;
}
