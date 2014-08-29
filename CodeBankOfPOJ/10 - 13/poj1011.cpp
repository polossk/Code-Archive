#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int64;

int sticks[65];
bool used[65];
int n, sum, goal ;

inline bool cmp(const int& a, const int& b) { return a > b; }

bool dfs (int cur, int index, int cnt){
	if (cnt == sum / goal)
		return true;

	for (int i=index;i < n;i++){
		if (i && !used[i - 1] && (sticks[i] == sticks[i - 1])) continue; // opt4
		if (used[i]) continue;
		if (sticks[i] + cur > goal) continue;
		used[i] = true;
		if (sticks[i] + cur == goal)
		{
			if (dfs(0, 0, cnt + 1)) return true;
			used[i] = false;
			return false;
		}
		if (!dfs(cur + sticks[i], i + 1, cnt))
		{
			used[i]=false;
			if (cur == 0) return false;	//opt5
		}
		else return true;
	}

	return false;
}

int main (){
	while (~scanf("%d", &n) && n)
	{
		sum = goal = 0; 
		memset(sticks, 0, sizeof (sticks));
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &sticks[i]);
			sum += sticks[i];
		}
		sort(sticks, sticks + n, cmp); // opt1
		for (goal = sticks[0]; goal <= sum; goal++) // opt2
		{ 
			if (sum % goal != 0) continue; // opt3
			memset(used, 0, sizeof (used));
			if (dfs(0, 0, 0)) { printf("%d\n", goal); break; }
		}
	}
	return 0;
}