#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int cnt[1000];
int N,B;

void solve()
{
	memset(cnt,0,sizeof(cnt));
	for(int i = 2; i <= N; i++)
	{
		int tmp = i;
		for(int j = 2; j <= tmp && j <= B; j++)
		{
			while(tmp % j == 0)
			{
				cnt[j]++;
				tmp /= j;
			}
		}
	}
	int ans1 = 0;
	while(1)
	{
		int tmp = B;
		for(int i = 2; i <= tmp; i++)
		{
			while(tmp % i == 0 && cnt[i] > 0)
			{
				cnt[i]--;
				tmp /= i;
			}
		}
		if(tmp == 1) ans1++;
		else break;
	}

	double sum=0;
	for(int i = 2; i <= N; i++)
		sum += log10(double(i));
	sum /= log10(double(B));
	int ans2 = floor(sum + 1e-9) + 1;
	
	cout << ans1 << ' ' << ans2 << endl;
}
int main()
{
	while(cin >> N >> B) solve();
	return 0;
}