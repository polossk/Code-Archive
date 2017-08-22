#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
//#include <cstdlib>
#include <set>
using namespace std;

#define DBG 0
#define ShowLine DBG && cout<<__LINE__<<">>| "
#define dout DBG && cout<<__LINE__<<">>| "
#define write(x) #x" = "<<(x)<<", "

set<int>Set;
int main(){
    int n,x,Max=0;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>x;
        while (Set.count(x)){
			Set.erase(x);
			x++;
        }
        Max=max(Max,x);
        Set.insert(x);
    }
    cout<<Max+1-Set.size()<<endl;
    return 0;
}
