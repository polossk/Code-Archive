/****
	*@Polo-shen
	*
	*/
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cctype>

using namespace std;
typedef long long int64;

#define DBG 0
#define ShowLine DBG && cout<<__LINE__<<">>| "
#define dout DBG && cout<<__LINE__<<">>| "
#define write(x) #x" = "<<(x)<<", "
char s1[27]="A   3  HIL JM O   2TUVWXY5";
char s2[10]="1SE Z  8 ";
int main(){
    char s[30];
    while (gets(s)){
        int pal=1,mir=1;
        int i,n=strlen(s);
        for (i=0;i<n;i++)
            if (s[i]!=s[n-i-1]){
                pal=0;
                break;
            }
        for (i=0;i<n;i++)
            if (isalpha(s[i])&&s[n-1-i]!=s1[s[i]-'A']){
                mir=0;
                break;
            }
            else if (isdigit(s[i])&&s[n-1-i]!=s2[s[i]-'1']){
                mir=0;
                break;
            }
        for (i=0;i<n;i++)
            if(s[i]=='0')s[i]='O';
        if (pal&&mir)printf("%s -- is a mirrored palindrome.\n",s);
        else if (mir)printf("%s -- is a mirrored string.\n",s);
        else if (pal)printf("%s -- is a regular palindrome.\n",s);
        else printf("%s -- is not a palindrome.\n",s);
        printf("\n");
    }
    return 0;
}
