#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
using namespace std;

int in[40], out[40], f[40];
bool vis[40];
int find(int x)
{
	if (x == f[x]) return x;
	return f[x] = find(f[x]);  
}
void  merge(int x, int y)
{
	f[find(x)] = find(y); 
}
int main()
{
	int t, n;
	scanf("%d", &t);
	while (t--)
	{
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i <26; i++)
		f[i] = i;
		scanf("%d\n", &n);
		char s[1010];
		for (int i= 1; i <= n; i++)
		{
			scanf("%s", s);
			int l = strlen(s) - 1;
			in[s[0] - 'a'] ++;
			out[s[l] - 'a'] ++;
			vis[s[0] - 'a']  = 1;
			vis[s[l] - 'a']  = 1;
			merge(s[0] - 'a', s[l] - 'a');
		}
		int cnt = 0;
		for(int i = 0; i < 26; i++) 
        { 
            if((vis[i]) && f[i] == i) 
                cnt++; 
        } 
        if(cnt != 1) 
        { 
            cout<<"The door cannot be opened."<<endl; 
            continue; 
        } 
        
		cnt = 0;int  b1 = 0, b2 = 0;
		for (int i = 0; i < 26; i++)
		{
			if (in[i] != out[i]) cnt++;
			if (in[i]!=0||out[i]!=0) 

			if (in[i] - out[i] >= 2 || out[i] - in[i] >= 2) cnt =10;
			b1 += (in[i] > out[i]);
			b2 += (in[i] < out[i]);
		}
		if ((cnt > 2) || (b1 !=  b2)) 
		{
			printf("The door cannot be opened.\n");
			continue;
		}
		printf("Ordering is possible.\n");
		
	}
	return 0;
}