/****
    *@Polo-shen
    *
    */
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
 
using namespace std;
typedef long long int64;
 
#define DBG 0
#define ShowLine DBG && cout<<__LINE__<<">>| "
#define dout DBG && cout<<__LINE__<<">>| "
#define write(x) #x" = "<<(x)<<", "
 
#ifndef min
#define min(x,y) ((x) < (y) ? (x) : (y))
#endif
 
#ifndef max
#define max(x,y) ((x) > (y) ? (x) : (y))
#endif
 
 
/*
*类名：BigNumber
*成员变量：
*   int d[maxl]
*       d[0]为当前的位数
*       其余d[i]位表示第i位上的数，每4位压缩为一个万进制数位
*构造函数：
*   BigNumber(string s) 从字符串s构造
*成员函数：
*   string toString()   输出为字符串
*重载运算符：
*   + , - , * , / , % , < , == , !=
*重载流运算符：
*   << , >>
*注意事项：
*   运算过程和结果都不能包含负数；
*   答案最长长度为(maxl - 1) * 4；
*   做除法时，余数保存在全局变量__d里面。
*/
 
const int ten[4]={1,10,100,1000};
const int maxl=1000;
class BigNumber{
public:
    int d[maxl];
    BigNumber(string s){
        int len=s.size();
        memset(d,0,sizeof(d));
        d[0]=(len-1)/4+1;
        int j,k;
        for (int i=len-1;i>=0;i--){
            j=(len-1-i)/4+1;
            k=(len-1-i)%4;
            d[j]+=ten[k]*(int)(s[i]-'0');
        }
        while (d[0]>1 && d[d[0]]==0){
            d[0]--;
        }
    }
 
    BigNumber(){
        *this=BigNumber(string("0"));
    }
 
    string toString(){
        string s("");
        int i,j,temp;
        for (i=3;i>=1;i--){
            if (d[d[0]]>=ten[i]){
                break;
            }
        }
        temp=d[d[0]];
        for (j=i;j>=0;j--){
            s+=(char)(temp/ten[j]+'0');
            temp%=ten[j];
        }
        for (i=d[0]-1;i>0;i--){
            temp=d[i];
            for (j=3;j>=0;j--){
                s+=(char)(temp/ten[j]+'0');
                temp%=ten[j];
            }
        }
        return s;
    }
 
    bool operator<(const BigNumber& b){
        if (d[0]!=b.d[0]){
            return d[0]<b.d[0];
        }
        for (int i=d[0];i>0;i--){
            if (d[i]!=b.d[i]){
                return d[i]<b.d[i];
            }
        }
        return 0;
    }
 
    bool operator==(const BigNumber& b){
        if (d[0]!=b.d[0]){
            return 0;
        }
        for (int i=d[0];i>0;i--){
            if (d[i]!=b.d[i]){
                return 0;
            }
        }
        return 1;
    }
 
    bool operator!=(const BigNumber& b){
        if (d[0]!=b.d[0]){
            return 1;
        }
        for (int i=d[0];i>0;i--){
            if (d[i]!=b.d[i]){
                return 1;
            }
        }
        return 0;
    }
 
}zero("0"),one("1"),__d,temp,mid1[15];
 
BigNumber operator+(const BigNumber& a,const BigNumber& b){
    BigNumber c;
    c.d[0]=max(a.d[0],b.d[0]);
    int x=0;
    for (int i=1;i<=c.d[0];i++){
        x=a.d[i]+b.d[i]+x;
        c.d[i]=x%10000;
        x/=10000;
    }
    while (x!=0){
        c.d[++c.d[0]]=x%10000;
        x/=10000;
    }
    return c;
}
 
BigNumber operator-(const BigNumber& a,const BigNumber& b){
    BigNumber c;
    c.d[0]=a.d[0];
    int x=0;
    for (int i=1;i<=c.d[0];i++){
        x=10000+a.d[i]-b.d[i]+x;
        c.d[i]=x%10000;
        x/=10000-1;
    }
    while ((c.d[0]>1) && (c.d[c.d[0]]==0)){
        --c.d[0];
    }
    return c;
}
 
BigNumber operator*(const BigNumber& a,const BigNumber& b){
    BigNumber c;
    c.d[0]=a.d[0]+b.d[0];
    int x;
    for (int i=1;i<=a.d[0];i++){
        x=0;
        for (int j=1;j<=b.d[0];j++){
            x=a.d[i]*b.d[j]+x+c.d[i+j-1];
            c.d[i+j-1]=x%10000;
            x/=10000;
        }
        c.d[i+b.d[0]]=x;
    }
    while ((c.d[0]>1) && (c.d[c.d[0]]==0)){
        --c.d[0];
    }
    return c;
}
 
BigNumber operator*(const BigNumber& a,const int& b){
    BigNumber c;
    c.d[0]=a.d[0];
    int x=0;
    for (int i=1;i<=a.d[0];i++){
        x=a.d[i]*b+x;
        c.d[i]=x%10000;
        x/=10000;
    }
    while (x>0){
        c.d[++c.d[0]]=x%10000;
        x/=10000;
    }
    while ((c.d[0]>1) && (c.d[c.d[0]]==0)){
        --c.d[0];
    }
    return c;
}
 
bool smaller(const BigNumber& a,const BigNumber& b,int delta){
    if (a.d[0]+delta!=b.d[0]){
        return a.d[0]+delta<b.d[0];
    }
    for (int i=a.d[0];i>0;i--){
        if (a.d[i]!=b.d[i+delta]){
            return a.d[i]<b.d[i+delta];
        }
    }
    return 1;
}
 
void Minus(BigNumber& a,const BigNumber& b,int delta){
    int x=0;
    for (int i=1;i<=a.d[0]-delta;i++){
        x=10000+a.d[i+delta]-b.d[i]+x;
        a.d[i+delta]=x%10000;
        x=x/10000-1;
    }
    while ((a.d[0]>1) && (a.d[a.d[0]]==0)){
        a.d[0]--;
    }
}
 
BigNumber operator/(const BigNumber& a,const BigNumber& b){
    BigNumber c;
    __d=a;
    int i,j,temp;
    mid1[0]=b;
    for (i=1;i<=13;i++){
        mid1[i]=mid1[i-1]*2;
    }
    for (i=a.d[0]-b.d[0];i>=0;i--){
        temp=8192;
        for (j=13;j>=0;j--){
            if (smaller(mid1[j],__d,i)){
                Minus(__d,mid1[j],i);
                c.d[i+1]+=temp;
            }
            temp/=2;
        }
    }
    c.d[0]=max(1,a.d[0]-b.d[0]+1);
    while ((c.d[0]>1) && (c.d[c.d[0]]==0)){
        --c.d[0];
    }
    return c;
}
 
BigNumber operator%(const BigNumber& a,const BigNumber& b){
    BigNumber c;BigNumber d=a;
    c=a/b;
    c=c*b;
    c=d-c;
    return c;
}
 
istream& operator>>(istream& is,BigNumber& n){
    string s;
    is>>s;
    int len=s.size();
    memset(n.d,0,sizeof(n.d));
    n.d[0]=(len-1)/4+1;
    int j,k;
    for (int i=len-1;i>=0;i--){
        j=(len-1-i)/4+1;
        k=(len-1-i)%4;
        n.d[j]+=ten[k]*(int)(s[i]-'0');
    }
    while (n.d[0]>1 && n.d[n.d[0]]==0){
        --n.d[0];
    }
    return is;
}
 
ostream& operator<<(ostream& os,BigNumber& n){
    os<<n.toString();
    return os;
}
 
/*
*类名：NumberTheory
*成员变量：
*   无
*构造函数：
*   无
*成员函数：
*   BigNumber gcd(BigNumber a,BigNumber b)  最小公倍数
*   BigNumber lcm(BigNumber a,BigNumber b)  最大公约数
*   BigNumber gcd_ex(BigNumber a,BigNumber b,
*                   BigNumber& x,BigNumber& y)
*   扩展欧几里得方法：
*       传入参数：a , b , x , y
*       返回值：gcd(a,b)
*       间接返回值 x , y
*       其中，ax + by = gcd(a,b)
*   BigNumber A(BigNumber n,BigNumber m)    排列数A(n,m)
*   BigNumber C(BigNumber n,BigNumber m)    组合数C(n,m)
*注意事项：
*   使用时请通过使用nt这个实例来实现函数调用；
*   具体的数据类型请使用具体的nt实例；
*   计算组合数和排列数的方法均为暴力方法，请注意时间要求；
*   如果使用int类型下的本NumberTheory类，请考虑有可能的数据溢出。
*/
 
class NumberTheory{
    public:
        BigNumber gcd(BigNumber a,BigNumber b){
            return (b==zero)?a:gcd(b,a%b);
        }
        BigNumber lcm(BigNumber a,BigNumber b){
            return a/gcd(a,b)*b;
        }
        BigNumber gcd_ex(BigNumber a,BigNumber b,BigNumber& x,BigNumber& y){
            if (b==zero){
            x=one;
            y=zero;
            return a;
            }
            BigNumber d=gcd_ex(b,a%b,x,y);
            BigNumber t=x;
            x=y;BigNumber t1=a/b;t1=t1*y;
            y=t-t1;
            return d;
        }
        BigNumber A(BigNumber n,BigNumber m){
            BigNumber p=one;BigNumber temp;
            while (m!=zero){
                temp=p*n;
                p=p*n;
                m=m-one;
                n=n-one;
            }
            return p;
        }
        BigNumber C(BigNumber n,BigNumber m){
            BigNumber i=m,c=one;
            m=one;
            while (i!=zero){
                c=c*n;
                c=c/m;
                n=n-one;i=i-one;
                m=m+one;
            }
            return c;
        }
}nt;
 
BigNumber rocks(BigNumber n,BigNumber k){
    if (n<k)return zero;
    else{
        BigNumber a,c;
        a=nt.A(n,k);
        c=nt.C(n,k);
        BigNumber res;
        res=a*c;
        return res;
    }
}
 
int main(){
    int T,tt=1;
    cin>>T;
    while (T--){
        BigNumber n,k,ans;
        cin>>n>>k;
        ans=rocks(n,k);
        cout<<"Case "<<tt++<<": "<<ans<<endl;
    }
}
 