/****
	*@Polo-shen
	*
	*/
#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <algorithm>
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

#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class Combinations_Mod
{
private:
	int64 factorial[1000010];
public:
	int64 Montgomery (int64 s,int64 index,int64 mod){
		int64 ans=1;
		s%=mod;
		while (index>=1)
		{
			if ((index&1)==1)   //ÆæÊý
				ans=(ans*s)%mod;
			index>>=1;
			s=s*s%mod;
		}
		return ans;
	}

	int64 exp_mod (int64 s,int64 index,int64 p){
		if(index==0)
			return 1;
		if(index==1)
			return s%p;
		int64 t=exp_mod(s,index/2,p);
		t=t*t%p;
		if (index&1)
			t=(t*s)%p;
		return t;
	}

	int64 exGcd (int64 a,int64 b,int64 &x,int64 &y){
		int64 r,t;
		if (b==0)
		{
			x=1;
			y=0;
			return a;
		}
		r=exGcd(b,a%b,x,y);
		t=x;
		x=y;
		y=t-a/b*y;
		return r;
	}

	int64 cm (int64 n,int64 m,int64 p){
		if (m>n)
			return 0;
		int64 a=1,b=1;
		while (m)
		{
			a=(a*n)%p;
			b=(b*m)%p;
			m--;
			n--;
		}
		return a*Montgomery(b,p-2,p)%p;
	}

	int64 cal (int64 n,int64 mod){
		int64 x,y;
		exGcd(n,mod,x,y);
		return (x%mod+mod)%mod;
	}

	int64 getC (int64 n,int64 m,int64 mod){
		return factorial[n]*cal(factorial[m],mod)*cal(factorial[n-m],mod)%mod;
	}

	int64 Lucas (int64 n,int64 m,int64 p){
		if (m==0)
			return 1;
		return (Lucas(n/p,m/p,p)*cm(n%p,m%p,p))%p;
	}

	void Init (int64 p){
		factorial[0]=1;
		for (int i=1;i<=p;i++)
			factorial[i]=factorial[i-1]*i%p;
	}

	int64 Lucas_init (int64 a,int64 m,int64 p){
		int64 ans = 1;
		Init (p);
		while (a && m){
			int64 aa = a%p;
			int64 bb = m%p;
			if (aa < bb)
				return 0;
			ans = ans*factorial[aa]*exp_mod(factorial[bb]*factorial[aa-bb]%p,p-2,p)%p;
			a/=p;
			m/=p;
		}
		return ans;
	}
}ob;

int main (){
	int T;
	int64 n,m;
	scanf("%d",&T);
	ob.Init(1000003);
	for (int Cas=1;Cas<=T;Cas++){
		scanf("%lld%lld",&n,&m);
		printf("Case %d: %lld\n",Cas,ob.getC(n,m,1000003));
	}
	return 0;
}
