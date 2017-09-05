#include <iostream>
#include <cstdio>
#include <cstring>

#define Maxn 100010

#define For_to_do(i,Start,End) for((i)=(Start);(i)<(End);(i)++)

using namespace std;
int n;
int c[Maxn];

inline int lowbit(int x){return x&(x^(x-1));}
void add(int pos,int val){
    while(pos <= Maxn){
        c[pos] += val;
        pos += lowbit(pos);
    }
}
//求sum(x)
int getsum(int x){
    int result = 0;
    while(x > 0){
        result += c[x];
        x -= lowbit(x);
    }
    return result;
}

int main(){
    int a,b;
    while(scanf("%d",&n),n){
        memset(c,0,sizeof(c));
        int i;
        For_to_do(i,0,n){
            scanf("%d%d",&a,&b);
            add(a,1);
            add(b+1,-1);
        }
        For_to_do(i,1,n)
          printf("%d ",getsum(i));
        printf("%d\n",getsum(n));
    }
    return 0;
}
