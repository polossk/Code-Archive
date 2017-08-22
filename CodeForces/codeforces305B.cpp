#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
//#include <cstdlib>
using namespace std;

#define DBG 0
#define ShowLine DBG && cout<<__LINE__<<">>| "
#define dout DBG && cout<<__LINE__<<">>| "
#define write(x) #x" = "<<(x)<<", "

typedef long long int64;
int main(){
    int64 p,q,n,a;
    cin>>p>>q>>n;
    while (n){
        cin>>a;
        if (q==0 || a>p/q) break;
        p=p-a*q;
        swap(p,q);
        n--;
    }
    if (n||q) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}