#include <cstdio>
#include <cstring>
#define min(x,y) ((x)<(y)?(x):(y))

struct Point
{
	int p,w;
	void get ()
	{
		scanf("%d%d",&p,&w);
	}
}p[505];

const int INF=0x0fffffff;
int f[10010];
int E,F,n;

void CompletePack ()
{
	int i;	
	for (i=0;i<=F-E;i++)
		f[i]=INF;
	f[0]=0;
	for (i=1;i<=n;i++)
		for (int j=p[i].w;j<=F-E;j++)
			f[j] = min(f[j],f[j-p[i].w]+p[i].p);    //¼ûÌâ½â
}

int main ()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&E,&F,&n);
		for (int i=1;i<=n;i++)
			p[i].get();
		CompletePack ();
		if (f[F-E] == INF)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n",f[F-E]);		
	}
	return 0;
}