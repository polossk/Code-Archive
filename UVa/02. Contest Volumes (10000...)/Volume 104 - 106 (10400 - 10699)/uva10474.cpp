/****
	*@PoloShen
	*Title:UVa 10474
	*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

vector<int> v;
int number[10001];

void solve(int N, int Q){
    v.clear();
    memset(number, 0, sizeof(number));
    v.resize(N);
    for (int i = 0; i < N; ++i){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; ++i){
        if(number[v[i]]==0) number[v[i]]=i+1;
    }
    while (Q--){
        int t;
        cin>>t;
        if(number[t]==0) cout<<t<<" not found\n";
        else cout<<t<<" found at "<<number[t]<<endl;
    }
}

int main(){
//#define __LOCAL__
#ifdef __LOCAL__
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif // __LOCAL__
    int tt = 1;
    int N, Q;
    while (1){
        cin>>N>>Q;
        if (N == 0 && Q == 0) break;
        cout<<"CASE# "<<tt<<":\n";
        solve(N,Q);
        tt++;
    }
    return 0;
}