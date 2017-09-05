#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

vector<int>s[110];
vector<int>c[110];
int dp[110];

int main(){
    int T;
    int m,n;
    cin>>T;
    while (T--){
        scanf("%d%d",&m,&n);
        int x,y,z;
        for (int i=0;i<=m;i++){
            s[i].clear();
            c[i].clear();
            dp[i]=0;
        }
        for (int i=0;i<n;i++){
            scanf("%d%d%d",&x,&y,&z);
            if(x>m||y>m)continue;
            if(x>y)continue;
            if(x<1)continue;
            s[y].push_back(x);
            c[y].push_back(z);
        }
        for (int i=1;i<=m;i++){
            dp[i]=dp[i-1];
            int sz=s[i].size();
            for (int j=0;j<sz;j++){
                dp[i]=max(dp[i],dp[s[i][j]-1]+c[i][j]);
            }
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}