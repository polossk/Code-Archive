/****
	*@Polo-shen
	*
	*/
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
int main(){
    int i,temp,sum=0,j;
    char c;
    while((c=getchar())!=EOF){
		if(c=='b')
			c=' ';
        if(c>='0'&&c<='9'){
            sum+=c-'0';
        }
        else{
            if(c!='\n'&&c!='!'){
                for(i=0;i<sum;i++){
                    printf("%c",c);
                }
            }
            else printf("\n");
            sum=0;
        }
    }
    return 0;
}
