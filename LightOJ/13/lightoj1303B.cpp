/****
	*@Polo-shen
	*
	*/
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
//#include <algorithm>
#include <cmath>
//#include <iomanip>
//#include <fstream>
//#include <cstdlib>
#include <vector>
#include <stack>
#include <list>
//#include <set>
//#include <map>

using namespace std;
typedef long long int64;

#define DBG 0
#define ALG 0

#if DBG
	#include <cstdlib>
	#define pause system("pause")
	#define ShowLine cout<<__LINE__<<">|\t"
	#define dout cout<<__LINE__<<">|\t"
	#define write(x) #x" = "<<(x)<<" "
	#define awrite(array,num) #array"["<<num<<"]="<<array[num]<<" "
#else
	#define pause ;
	#define ShowLine DBG && cout<<__LINE__<<">|\t"
	#define dout DBG && cout<<__LINE__<<">|\t"
	#define write(x) #x" = "<<(x)<<" "
	#define awrite(array,num) #array"["<<num<<"]="<<array[num]<<" "
#endif // DBG

#if ALG
	#include <algorithm>
#else
	#ifndef min
		#define min(x,y) ((x) < (y) ? (x) : (y))
	#endif
	#ifndef max
		#define max(x,y) ((x) > (y) ? (x) : (y))
	#endif
#endif // ALG

void sprint(string s){
	if (DBG){
		string::size_type sz=s.size();
		for (int i=0;i<sz;i++){
			printf("%c",s[i]);
		}
		puts("|< EOL >|\n\n");
	}
	else return;
}

template <typename T>
void _vprint(vector<T> v){
	if (DBG){
        int sz=v.size();
        for (int i=0;i<sz;i++){
            cout<<awrite(v,i)<<" ";
        }
        cout<<"\n|< End Of Vector >|\n"<<endl;
	}
	else return;
}

template <typename T>
void _aprint(T a[],int _array_size,int _array_0=0){
	if (DBG){
        int sz=_array_size;
        for (int i=_array_0;i<sz;i++){
            cout<<awrite(a,i)<<" ";
        }
        cout<<"\n|< End Of Array >|\n"<<endl;
	}
	else return;
}

template <typename T>
void _lprint(list<T> l){
	if (DBG){
        if (l.empty()){
            cout<<"List is empty.";
            cout<<"\n|< End Of List >|\n"<<endl;
        }
        else {
            list<T> ltmp=l;
            int sz=l.size();
            for (int i=0;i<sz;i++){
                cout<<ltmp.front()<<" ";
                ltmp.pop_front();
            }
            cout<<"\n|< End Of List >|\n"<<endl;
        }
	}
	else return;
}

template <typename T>
bool _aempty(T a[],int _array_size,int _array_0=0){
    bool flag=1;
    int st=_array_0;
    int ed=_array_size;
    for (int i=st;i<ed;i++){
        if (a[i]){
            flag=0;
            break;
        }
    }
    return flag;
}

/***
	*Title:
	*
	*/

void solve(int t,int n,int m){
    /*
    * t -> number of test cases
    * n -> number of people
    * m -> number of lift
    */
    bool tryd[21][21];
    memset(tryd,0,sizeof(tryd));
    list<int> pline;
    for (int i=1;i<=n;i++){
        pline.push_back(i);
    }
    int lift[m+1];int curl=0;
    for (int i=0;i<=m;i++){
        lift[i]=0;
    }
    int res=0;
    while (1){
        curl=((curl+1)%m == 0)? m : (curl+1+m)%m;
        res+=5;
        dout<<write(curl)<<endl;
        _aprint(lift,m+1,1);
        _lprint(pline);
        //dout<<write(pline.front())<<endl;
        int pfront=(pline.empty())?0:pline.front();
        dout<<write(pfront)<<endl;
        dout<<awrite(lift,curl)<<endl;
        //pause;
        if (lift[curl] != 0){
            //get out lift
            bool GofL=1;
            for (int i=1;i<=m;i++){
                if (tryd[lift[curl]][i] == 1)
                    continue;
                else {
                    GofL=0;
                    break;
                }
            }
            dout<<">| --- "<<lift[curl]<<" get out lift"<<endl;
            if (!GofL)pline.push_back(lift[curl]);
            lift[curl]=0;
        }
        if (!(pline.empty())){
            for (list<int>::iterator it=pline.begin();it!=pline.end();it++){
                int np=*it;
                if (tryd[np][curl] == 0){
                    //get in lift
                    tryd[np][curl]=1;
                    lift[curl]=np;
                    dout<<">| --- "<<lift[curl]<<" get in lift"<<endl;
                    pline.erase(it);
                    break;
                }
            }
        }
        _aprint(lift,m+1,1);
        _lprint(pline);
        //pause;

        if (_aempty(lift,m+1) && pline.empty()){
            break;
        }
    }
    printf("Case %d: %d\n",t,res);
    return;
}

int main(){
	int T;cin>>T;int t=0;
	while (T--){
        int n,m;
        cin>>n>>m;
        solve(++t,n,m);
	}
	return 0;

}
