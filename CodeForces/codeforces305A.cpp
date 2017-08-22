#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
//#include <cstdlib>
//#include <set>

using namespace std;
typedef long long int64;

#define DBG 0
#define ShowLine DBG && cout<<__LINE__<<">>| "
#define dout DBG && cout<<__LINE__<<">>| "
#define write(x) #x" = "<<(x)<<", "

const int maxn=100+5;
int ans[maxn];
int a[maxn];
bool hash__[maxn];

int main(){
    int n;
    cin>>n;
    int cnt=0,x;
    bool flag2=0,flag3=0;
    memset(hash__,0,sizeof(hash__));
    for (int i=0; i<n; i++){
        cin>>a[i];
        x=a[i];
        if(x==0) ans[cnt++]=x,hash__[x]=1;
        else if(x==100) ans[cnt++]=x,hash__[x]=1;
        else if(x%10==0&&!flag2) ans[cnt++]=x,flag2=1,hash__[x]=1;
        else if(x/10==0&&!flag3) ans[cnt++]=x,flag3=1,hash__[x]=1;
    }
    if (!flag2 && !flag3){
        for (int i=0; i<n; i++)
            if (!hash__[a[i]]){
                ans[cnt++]=a[i];
                break;
            }
    }
    cout<<cnt<<endl;
    for (int i=0; i<cnt; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}