/****
	*@Polo-shen
	*
	*/
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <fstream>

using namespace std;
typedef long long int64;

#define DBG 0
#define ShowLine DBG && cout<<__LINE__<<">>| "
#define dout DBG && cout<<__LINE__<<">>| "
#define write(x) #x" = "<<(x)<<", "
#define awrite(array,num) #array"["<<num<<"]="<<array[num]<<" "

#ifndef min
#define min(x,y) ((x) < (y) ? (x) : (y))
#endif

#ifndef max
#define max(x,y) ((x) > (y) ? (x) : (y))
#endif
int T,tt=1;
void solve(int m,int n){
    printf("Case #%d: ",tt);tt++;
    if (m==1){
        for (int i=0;i<n;i++){
            printf("a");
        }
        printf("\n");
    }
    else if (m>=3){
        int no=0,tmpm=3;
        for (int i=0;i<n;i++){
            no=i%tmpm;
            char ch=(char)('a'+no);
            printf("%c",ch);
        }
        printf("\n");
    }
    else {
        switch(n){
            case 1:{
                printf("a\n");
                break;
            }
            case 2:{
                printf("ab\n");
                break;
            }
            case 3:{
                printf("aab\n");
                break;
            }
            case 4:{
                printf("aabb\n");
                break;
            }
            case 5:{
                printf("aaaba\n");
                break;
            }
            case 6:{
                printf("aaabab\n");
                break;
            }
            case 7:{
                printf("aaababb\n");
                break;
            }
            case 8:{
                printf("aaababbb\n");
                break;
            }
            default:{
                printf("aaaababb");
                int tmpn=n-8;
                while (tmpn>=6){
                    printf("aababb");
                    tmpn-=6;
                }
                switch (tmpn){
                    case 0:{
                        printf("\n");break;
                    }
                    case 1:{
                        printf("a\n");break;
                    }
                    case 2:{
                        printf("aa\n");break;
                    }
                    case 3:{
                        printf("aaa\n");break;
                    }
                    case 4:{
                        printf("aaaa\n");break;
                    }
                    case 5:{
                        printf("aabab\n");break;
                    }
                    default:break;
                }
            }
        }
    }
}

int main(){
    cin>>T;while (T--){
        int n,m;
        cin>>m>>n;
        solve(m,n);
    }
    return 0;
}
