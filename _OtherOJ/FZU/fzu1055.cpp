#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int n,i,vis[26];
    char s[10];
    while(scanf("%d",&n)){
        if(n==-1)
        break;
        memset(vis,0,sizeof(vis));
        vis[0]=1;
        for(i=0;i<n;i++){
            scanf("%s",s);
            vis[s[0]-'a']=vis[s[2]-'a'];
        }
        int flag=1;int sum=0;
        for(i=0;i<26;i++){
            if(vis[i]){
                sum++;
                if(sum==1)
                    printf("%c",i+'a');
                else
                    printf(" %c",i+'a');
                flag=0;
            }
        }
        if(flag==1) printf("none");
        printf("\n");
    }
}