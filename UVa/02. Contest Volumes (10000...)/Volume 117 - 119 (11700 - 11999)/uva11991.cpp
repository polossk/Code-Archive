/****
	*@Polo-shen
	*
	*/
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <sstream>

using namespace std;
typedef long long int64;

#define DBG 0
#define ShowLine DBG && cout<<__LINE__<<">>| "
#define dout DBG && cout<<__LINE__<<">>| "
#define write(x) #x" = "<<(x)<<", "

#ifndef min
#define min(x,y) ((x) < (y) ? (x) : (y))
#endif

#ifndef max
#define max(x,y) ((x) > (y) ? (x) : (y))
#endif

#define rep(i,s,e) for(int i= (s);i<=(e);++i)
using namespace std;
const int maxn = 1000010;
vector<int> num[maxn];
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)==2){
        for (int i=1;i<=n;i++){
            int a;
            scanf("%d",&a);
            num[a].push_back(i);
        }
        while(m--){
            int k,v;
            scanf("%d%d",&k,&v);
            if(num[v].size()<k)
                printf("0\n");
            else
                printf("%d\n",num[v][k-1]);
        }
    }
    return 0;
}
