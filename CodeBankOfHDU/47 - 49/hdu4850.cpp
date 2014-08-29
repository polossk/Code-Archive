/****
	*@author    Shen
	*@title     西安邀请赛D
	*/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const char* alpha = "abcdefghijklmnopqrstuvwxyz";
const int asz = 26;
const int maxN = 500000;
int maxS, len, s, state[4 * asz + 13];
char result[maxN];

int dfs(int curr, int prev)
{
    if (len >= maxN) return 0;
    if (curr > 4)//catch char
    {
        if (4 % prev == 0)
        {
            for (int i = 1; i <= prev; i++)
            {
                result[len++] = state[i];
                if (len >= maxN) break;
            }
        }
    }
    else
    {
        int stateID = state[curr - prev];
        state[curr] = stateID;
        dfs(curr + 1, prev);
        for (int i = stateID + 1; i < 26; i++)
        {
            state[curr] = i;
            dfs(curr + 1, curr);
        }
    }
    return 0;
}

inline void addStringaaa()
{
    result[len] = result[len + 1] = result[len + 2] = 'a';
    result[len + 3] = '\0';
    maxS = len + 3;
}

void solve()
{
    if (s > maxS) puts("Impossible");
    else
    {
        for (int i = 0; i < s; i++)
            printf("%c", result[i]);
        puts("");
    }
}

int main()
{
    dfs(1, 1);
    for (int i = 0; i < len; i++)
        result[i] = alpha[result[i]];
    addStringaaa();
    while (~scanf("%d", &s))
        solve();
    return 0;
}
