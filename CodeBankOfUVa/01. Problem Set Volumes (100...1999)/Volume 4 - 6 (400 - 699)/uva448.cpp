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
void generater(int A,int f){
	while (f--){
		for (int i=1;i<2*A;i++){
			int itmp=i;
			if (itmp>A)itmp=2*A-itmp;
			for (int j=1;j<=itmp;j++){
				printf("%d",itmp);//cout<<itmp;
			}
			printf("\n");//cout<<endl;
		}
		if(f)printf("\n");//cout<<endl;
	}
}
int main(){
    int n,i=0;cin>>n;
    while (n--){
		if (i!=0)printf("\n");i++;
		int a,f;cin>>a>>f;
		generater(a,f);
    }
    return 0;
}
