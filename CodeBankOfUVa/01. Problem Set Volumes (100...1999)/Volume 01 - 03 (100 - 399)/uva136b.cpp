/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][SRM][1] E
#       @file         :G:\My Source Code\【ACM】训练\0711 - [NWPU][SRM][2]\E2.cpp
#       @date         :2014-07-11 19:21
#       @algorithm    :Priority Queue
******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;

const int root[3] = {2, 3, 5};
int UNgenerater(int n)
{
    priority_queue<int64, vector<int64>, greater<int64> > pq;
    set<int64> s;
    pq.push(1); s.insert(1);
    for (int i = 1; i < n; i++)
    {
        int64 x = pq.top(); pq.pop();
        for (int j = 0; j < 3; j++)
        {
            int64 y = x * root[j];
            if (!s.count(y)) s.insert(y), pq.push(y);
        }
    }
    return pq.top();
}

int main()
{
    cout << "The 1500'th ugly number is " << UNgenerater(1500) << "." << endl;
    return 0;
}
