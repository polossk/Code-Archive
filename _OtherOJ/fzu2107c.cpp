#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=(1<<4);
int f[6][N][2]={0};//f[i][j][k]//放完第i-1行第i行的状态j，k=1放曹操
void dfs(int row,int col,int pre,int now,int cao,int k){
    if(col>=4){//放完4列,pre={1111}
        f[row][now][cao]+=k;//放完pre得到f[now]+=f[pre]
        //cout<<row<<" "<<now<<" "<<cao<<endl;
        return;
    }
    if(pre&(1<<col)){//第col已经放过
        dfs(row,col+1,pre,now,cao,k);
        return;
    }
    //a grid
    dfs(row,col+1,pre|(1<<col),now,cao,k);
    //a 1*2
    dfs(row,col+1,pre|(1<<col),now|(1<<col),cao,k);//放一竖，多出一块
    int t=(1<<col)|(1<<(col+1));
    if(col<3&&(pre&(1<<(col+1)))==0){
        //a 2*1
        dfs(row,col+1,pre|t,now,cao,k);
        //put caocao
        if(cao==0)dfs(row,col+1,pre|t,now|t,1,k);
    }
}
int main(){
    int i,j,k;
    f[0][N-1][0]=1;
    for(i=1;i<=5;i++)
        for(j=0;j<N;j++){
            if(f[i-1][j][0])dfs(i,0,j,0,0,f[i-1][j][0]);
            if(f[i-1][j][1])dfs(i,0,j,0,1,f[i-1][j][1]);
        }
    scanf("%d",&k);
    while(k--){
        scanf("%d",&i);
        printf("%d\n",f[i+1][0][1]);
    }
    return 0;
}