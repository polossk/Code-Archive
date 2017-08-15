/*=============================================================================
#       COPYRIGHT NOTICE
#       Copyright (c) 2014
#       All rights reserved
#
#       @author       :Shen
#       @name         :B
#       @file         :G:\My Source Code\比赛与日常练习\0613 - CF\B
#       @date         :2014/06/14 00:52
#       @algorithm    :Simulation
=============================================================================*/

#include <cstdio>
using namespace std;

char s[2005][2005];
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        ans = 0;
        for (int j = 1; j < n && i + j < m; j++)
        {
            if (s[j][i+j] == 'L')
                ans++;
        }
        for (int j = 1; j < n && (i - j) >= 0; j++)
            if (s[j][i-j] == 'R') ans++;
        for (int j = 1; j < n; j++)
            if (s[j][i] == 'U' && j % 2 == 0) ans++;
        printf("%d ",ans);
    }
    return 0;
}

