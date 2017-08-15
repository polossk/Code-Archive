/****
	*@author    Shen
	*@title     b
	*/

#include <iostream>
#include <cstdio>
using namespace std;

int ori[26], tar[26];

void Update(int buf[])
{
    char ch = 0;
    while (1)
    {
        scanf("%c", &ch);
        if (ch != '\n') buf[ch - 'a']++;
        else return;
    }
}

void solve(){
    Update(ori);
    Update(tar);
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (tar[i] == 0) continue;
        else if (ori[i] == 0) { ans = -1; break; }
        else if (ori[i] >= tar[i]) ans += tar[i];
        else if (ori[i] < tar[i]) ans += ori[i];
    }
    cout << ans << endl;
}

int main(){
    solve();
    return 0;
}
