#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--){
        int s[10],j;
        cin>>j;
        for(int i=0;i<10;i++){
            cin>>s[i];
        }
        sort(s,s+10);
        cout<<j<<" "<<s[7]<<endl;
    }
}
