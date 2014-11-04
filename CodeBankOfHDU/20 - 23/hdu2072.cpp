//利用STL #include<set>  和 #include<sstream>  问题就简单多了
#include <iostream>
#include <sstream>
#include<string>
#include<set>
using namespace std;

int main()
{
	set <string> ans;
    stringstream temp;
    string s;
    while( getline(cin,s) && s!="#")  
    {
        stringstream temp(s);            
        ans.clear();
        while(temp>>s) ans.insert(s);
        cout<<ans.size()<<endl;
    }
    return 0;
}