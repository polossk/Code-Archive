#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int n){
    if(n==1)return 0;
    double ntemp;
    ntemp=sqrt((double)n);
    int nt;nt=(int)ntemp;
    for(int i=2;i<=nt;i++){
        if(n%i==0)return 0;
    }
    return 1;
}

bool isSemiPrim(int n){
    double ntemp;
    ntemp=sqrt((double)n);
    int nt;nt=(int)ntemp+1;
    bool flag=0;
    for(int k=2;(k<=nt);k++){
        if(n%k==0){
            int temp=n/k;
            return isPrime(k)&&isPrime(temp);
        }
    }
    return flag;
}
int main()
{
    int n;
    while(cin>>n){
        //cout<<n<<" : ";
        if(n==1)cout<<"No"<<endl;
        if(isSemiPrim(n))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        if(n%100==0)cin.get();
    }
    return 0;
}