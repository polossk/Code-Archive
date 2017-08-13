/****
    *@PoloShen
    *Title:A
    */
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int transform(int x,int y,string s){
    int sum = 0;
    for (int i=0;i<s.size();i++){
        if (s[i]>='0' && s[i]<='9')
            sum=sum*x+s[i]-'0';
        else sum=sum*x+s[i]-'a'+10;
    }
    return sum;
}

inline int toDec(int Base, string Value){
    return transform(Base, 10, Value);
}

void solve(){
    string a, b; int c;
    cin >> a >> b >> c;
    int A, B, k, d;
    A = toDec(c, a);
    B = toDec(c, b);
    k = A / B;
    d = A % B;
    cout << "(" << k << "," << d << ")" << endl;
}

int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
}