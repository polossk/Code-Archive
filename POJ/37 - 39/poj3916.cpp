#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        if(n==0)break;
        vector<int>v;
        vector<int>::iterator it;
        int temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            if(i==0){v.push_back(temp);continue;}
            else{
                if(temp==v.at(v.size()-1))continue;
                else v.push_back(temp);
            }
        }
        for(it=v.begin();it<v.end();it++){
            cout<<*it<<" ";
        }
        cout<<"$"<<endl;
    }
    return 0;
}
