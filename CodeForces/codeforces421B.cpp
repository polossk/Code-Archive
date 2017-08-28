/****
	*@author    Shen
	*@title     E
	*/

#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

string src;
const string MirrorChar("AHIMOTUVWXY");
const int MCSize = MirrorChar.size();

void solve()
{
    bool MirrorStr = 1;
    bool MirrorChr = 1;
    int sz = src.size();
    for (int i = 0; i < sz / 2 + 1; i++)
    {
        if (src[i] == src[sz - i - 1])
            continue;
        else
        {
            MirrorStr = 0;
            break;
        }
    }
    for (int i = 0; i < sz; i++)
    {
        bool tmp = 0;
        for (int j = 0; j < MCSize; j++)
            tmp = tmp | (MirrorChar[j] == src[i]);
        if (tmp) continue;
        else
        {
            MirrorChr = 0;
            break;
        }
    }
    if (MirrorStr && MirrorChr)
        puts("YES");
    else puts("NO");
    return;
}

int main()
{
    while (cin >> src)
        solve();
    return 0;
}
