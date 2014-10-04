/****
	*@Polo-shen
	*
	*/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
int main(){
    string str;;
    int count=0;
    string::iterator iter;
    bool flag=0;
    while(getline(cin,str)){
        count=0;
        for(iter=str.begin(); iter!=str.end(); ++iter){
            if(!flag&&isalpha(*iter)){
                ++count;
                flag=1;
            }
            else if(!isalpha(*iter))
                flag=0;
        }
        cout<<count<<endl;
    }
    return 0;
}
