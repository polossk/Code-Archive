// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   hdu 3787                                                 *
*****************************************************************************/

//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

//#include <bits/stdc++.h>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <string>
#include <limits>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }
inline char   nextChr() { scanf(" "); return getchar(); }
inline string nextStr() { string s; cin >> s; return s; }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  nextlld() { int64 d; scanf("%lld", &d); return d; }
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

char a1[20];
char b1[20];
char a[12];
char b[12];
int64 aa,bb;
int l1,l2;
int main()
{
      char c;
      int ii,jj,i,j;
      while(scanf("%s%s",&a1,&b1)!=EOF){
        memset(a,'0',sizeof(a));
        memset(b,'0',sizeof(b));
          l1=strlen(a1);
          l2=strlen(b1);
          for(i=0,ii=0;i<l1;i++){
            if(a1[i]!=',')
               a[ii++]=a1[i];
             }
             a[ii++]='\0';
          for(i=0,ii=0;i<l2;i++)
            if(b1[i]!=',')
               b[ii++]=b1[i];
               b[ii++]='\0';
        aa=atoi(a);
        bb=atoi(b);
        cout<<aa+bb<<endl;
        }
       return 0;
}