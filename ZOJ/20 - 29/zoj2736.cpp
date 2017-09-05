#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin>>n){
        int a,b,c;
        a=n/100;
        b=n/10%10;
        c=n%10;
        if(a*a*a+b*b*b+c*c*c==n)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}