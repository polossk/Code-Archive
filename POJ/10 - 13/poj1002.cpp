/****
	*@PoloShen
	*Title:UVaOJ 755
	*/
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
const int MaxN = 131072;
char s[31];
int n, data[MaxN];

int Hash()
{
    int sum=0;
    for (int i = 0, k = 0; k < 7; ++i)
	{
        if(s[i] >= '0' && s[i] <= '9')
		{
            sum *= 10; ++k;
            sum += (s[i] - '0');
        }
        else if(s[i] >= 'A' && s[i] < 'Z')
		{
            sum *= 10; ++k;
            sum += ((s[i] - 'A' - ( s[i] > 'Q' )) / 3 + 2);
        }
    }
    return sum;
}

void solve()
{
    scanf("%d",&n); getchar();
	fill(data, data + MaxN, 0);
    for(int tmp = 0; tmp < n; ++tmp)
	{
        gets(s);
        data[tmp] = Hash();
    }
    sort(data, data + n);
    bool p = 0; n--;
    for (int i = 0,num = 1; i < n;i += num = 1)
	{
        while (data[i] == data[i+1]) { num++; i++; }
        if (num > 1)
		{
            printf("%03d-%04d %d\n", data[i] / 10000, data[i] % 10000, num);
            p = 1;
        }
    }
    if (!p) printf("No duplicates.\n");
    printf("\n");
}

int main()
{
    solve();
    return 0;
}