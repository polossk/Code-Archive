#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int re1[30],re2[30];

int main()
{
	string a,b;
	while(cin>>a>>b) {
		memset(re1,0,sizeof re1);
		memset(re2,0,sizeof re2);
		for(int i = a.length()-1;i>=0;i--) {
			re1[a[i]-'A']++;
		}
		for(int i=b.length()-1;i>=0;i--)
			re2[b[i]-'A']++;
		sort(re1,re1+26);
		sort(re2,re2+26);
		bool done=0;
		for(int i=0;i<26;i++)
			if(re1[i]!=re2[i]) {
				cout<<"NO"<<endl;
				done=1;
				break;
			}
		if(!done)
			cout<<"YES"<<endl;
	}
}


/*char inline getr(char ch,int x) {
	return (ch-'A'+x)%26+'A';
}

string ori,tar,tmp;
int main()
{
	while(cin>>tar>>ori) {
		tmp = ori;
		sort(ori.begin(),ori.end());
		sort(tar.begin(),tar.end());
		for(int i=0;i<26;i++) {
			for(int j=ori.length()-1;j>=0;j--) {
				tmp[j] = getr(ori[j],i);
			}
			sort(tmp.begin(),tmp.end());
			if(tmp == tar) {
				cout<<"YES"<<endl;
				continue;
			}
		}
		cout<<"NO"<<endl;
	}
}*/