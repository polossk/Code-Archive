#include <cstdio>
#include <stack>
#include <string.h>
using namespace std;

typedef struct
{
	int w;
	int h;
} matrix;

matrix mat[30];

int main()
{
	int n;
	char c[1000];
	int m,nn,l;
	long long ans;

	matrix m1,m2,m3;
	scanf("%d",&n);
	memset(mat,0,sizeof(mat));
	for(int i=0;i<n;i++)
	{
		scanf("%s%d%d",c,&m,&nn);
		mat[c[0]-'A'].w=m;
		mat[c[0]-'A'].h=nn;
	}
	while(scanf("%s",c)!=EOF)
	{
		ans=0;
		stack<matrix> s;
		l=strlen(c);

		for(int i=0;i<l;i++)
		{
			if(c[i]=='(')
				continue;

			if(c[i]==')')
			{

				m2=s.top();
				s.pop();
				m1=s.top();
				s.pop();

				if(m1.h!=m2.w)
				{
					ans=-1;
					break;
				}
				ans+=m1.w*m1.h*m2.h;
				m1.h=m2.h;
				s.push(m1);

				continue;
			}
			s.push(mat[c[i]-'A']);

		}
		if(ans==-1)
		{
			printf("error\n");
			continue;
		}
		printf("%lld\n",ans);
	}
	return 0;
}