/****
	*@Polo-shen
	*
	*/
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;
typedef long long int64;

#define DBG 0
#define ShowLine DBG && cout<<__LINE__<<">>| "
#define dout DBG && cout<<__LINE__<<">>| "
#define write(x) #x" = "<<(x)<<", "

int main(){
    int64 a,b,n;
    int number=0;
	int s=0;
    while((cin>>a>>b) && (a!=-1 || b!=-1)){
        number++;
		s=1;
		n=a;
        while(n>1){
            if(n%2)
                n=n*3+1;
            else
                n/=2;
            if(n>b)break;
            s++;
        }
        printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n",number,a,b,s);
    }
    return 0;
}
