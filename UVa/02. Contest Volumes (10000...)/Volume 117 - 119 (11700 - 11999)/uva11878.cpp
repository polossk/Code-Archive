/****
	*@PoloShen
	*Title:E
	*/
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

string ori;

bool solve(){
    stringstream bufc;
    bufc << ori;
    int a, b; char op;
    bufc >> a >> op >> b;
    stringstream buf;
    buf << a << op << b << '=';
    int ans = (op == '+')? a+b: a-b;
    buf << ans;
    string crt = buf.str();
    return crt == ori;
}

int main(){
    int ans = 0;
    while (cin >> ori) ans += solve();
    cout << ans << endl;
    return 0;
}