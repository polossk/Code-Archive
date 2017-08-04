/****
	*@Polo-shen
	*
	*/
#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <algorithm>
//#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
//#include <cstdlib>
//#include <set>

using namespace std;
typedef long long int64;

#define DBG 0
#define ShowLine DBG && cout<<__LINE__<<">>| "
#define dout DBG && cout<<__LINE__<<">>| "
#define write(x) #x" = "<<(x)<<", "

int n,point,___index;//n次幂。point代表小数点后有几位。
int si[1000],res[1000],temp[1000],l2;//si[1000]存s变成的整数，一位一位存
string s;
void init(){//让s变成一个整数串，并且记录下小数点后有几位；
	point=0;//初始化point;
	___index=0;//si的下标变量
	int l=s.length();//字符串s的长度。
	int i=l-1;
	int flag=0;
	//for(i=l-1;s[i]!='0';i--);//除去后导0
	for(int j=0;j<=i;j++){
		if(s[j]=='0'&&!___index&&!flag)/*除去前导0，前导0满足3个要求
		1.为0  2.在.前面 3.在数前面*/
			continue;
		if(s[j]=='.'){
			for(i=l-1;s[i]=='0';i--);//除去后导0
			flag=1;
			continue;
		}
		if(flag){
			si[___index++]=s[j]-48;
			point++;
		}
		else
			si[___index++]=s[j]-48;
	}
}
void print(){
	int k=point*n;
	if(l2+1>k){
	for(int i=1;i<=l2+1;i++){
		if(i==l2+1-k+1)
			cout<<".";
		cout<<res[i-1];
	}
	cout<<endl;
	}
	else{
		cout<<".";
		for(int i=0;i<k-l2-1;i++)
			cout<<"0";
		for(int i=0;i<=l2;i++)
			cout<<res[i];
		cout<<endl;
	}
}
int main(){
	while(cin>>s>>n){
	init();
	memcpy(res,si,sizeof(res));
	l2=___index-1;//记录res的长度
	for(int times=0;times<n-1;times++){//进行n-1次迭代
		int tempsize;//记录中间过程的下标
		memset(temp,0,sizeof(temp));//把中间变量置为0
		for(int i=___index-1;i>=0;i--){//对于si的每一位
			tempsize=___index-i-2;//要把这位的结果从这里开始放。模拟竖式乘法
			for(int j=l2;j>=0;j--){//乘以res中的每一位
				tempsize++;
				temp[tempsize]+=si[i]*res[j];
				if(temp[tempsize]>=10){//进位
					int k=temp[tempsize]/10;
					temp[tempsize]%=10;
					temp[tempsize+1]+=k;
				}
			}
		}
		tempsize++;
		while(temp[tempsize]!=0){//最后的大进位。
			if(temp[tempsize]>=10){
			int k=temp[tempsize]/10;
				temp[tempsize]%=10;
				temp[tempsize+1]+=k;
			}
			tempsize++;
		}
		tempsize--;
		if(tempsize>l2)//拓展res的长度
			l2=tempsize;
		for(int i=0;i<=l2;i++)//准备下一次迭代;
			res[i]=temp[l2-i];
	}
	print();
	}
	return 0;
}
