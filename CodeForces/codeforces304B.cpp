#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
//#include <cstdlib>
using namespace std;

#define DBG 0
#define ShowLine DBG && cout<<__LINE__<<">>| "
#define dout DBG && cout<<__LINE__<<">>| "
#define write(x) #x" = "<<(x)<<", "

int isLeapyear(int yy){
    return yy%(yy%100?4:400)?0:1;
}
int day[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},
				{31,29,31,30,31,30,31,31,30,31,30,31}};
int calday(int yy,int mm,int dd){
    int i;
    int sum=0;
    for (i=1900; i<yy; i++){
        if (isLeapyear(i))
            sum+=366;
        else
            sum+=365;
    }
    int p=isLeapyear(yy);
    for (i=1; i<mm; i++)
        sum+=day[p][i-1];
    sum+=dd;
    return sum;
}

int main(){
    char a[11];
    while (cin>>a){
        int yy=(a[0]-'0')*1000+(a[1]-'0')*100+(a[2]-'0')*10+(a[3]-'0');
        int mm=(a[5]-'0')*10+(a[6]-'0');
        int dd=(a[8]-'0')*10+(a[9]-'0');
        int pa=calday(yy,mm,dd);
        cin>>a;
        yy=(a[0]-'0')*1000+(a[1]-'0')*100+(a[2]-'0')*10+(a[3]-'0');
        mm=(a[5]-'0')*10+(a[6]-'0');
        dd=(a[8]-'0')*10+(a[9]-'0');
        int pb=calday(yy,mm,dd);
        int res=abs(pa-pb);
        cout<<res<<endl;
    }
    return 0;
}