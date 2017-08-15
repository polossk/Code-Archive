/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :A
#       @file         :A.cpp
#       @date         :2014/07/17 22:00
#       @algorithm    :Easy
******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int a1, a2, a3;
int b1, b2, b3;
int n;

int main()
{
    cin >> a1 >> a2 >> a3;
    cin >> b1 >> b2 >> b3;
    cin >> n;
    int sa = a1 + a2 + a3; sa = (sa % 5 == 0)? sa / 5: sa / 5 + 1;
    int sb = b1 + b2 + b3; sb = (sb % 10 == 0)? sb / 10: sb / 10 + 1;
    if (sa + sb > n) puts("NO");
    else puts("YES");
    return 0;
}
