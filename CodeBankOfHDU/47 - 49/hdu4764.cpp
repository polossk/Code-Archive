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
#include <vector>
#include <map>

using namespace std;

#define DBG 0
#define ShowLine DBG && cout<<__LINE__<<">>| "
#define dout DBG && cout<<__LINE__<<">>| "
#define write(x) #x" = "<<(x)<<" "
#define awrite(array,num) #array"["<<num<<"]="<<array[num]<<" "

#ifndef min
#define min(x,y) ((x) < (y) ? (x) : (y))
#endif

#ifndef max
#define max(x,y) ((x) > (y) ? (x) : (y))
#endif

int main(){
    int N,k;
    while (cin>>N>>k && (N && k)){
        int sum=N-1;
        int tmp=sum%(k+1);
        if (tmp!=0){
            cout<<"Tang"<<endl;
        }
        else {
            cout<<"Jiang"<<endl;
        }
    }
    return 0;
}