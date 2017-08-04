#include <cstdio>
#include <cstring>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
#define INF 0x7fffffff
const double eps=1e-8;
const double pi=acos(-1.0);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int g,l;
        cin>>g>>l;
        if(l%g!=0)
            cout<<-1<<endl;
        else
            cout<<g<<" "<<l<<endl;
    }
    return 0;
}