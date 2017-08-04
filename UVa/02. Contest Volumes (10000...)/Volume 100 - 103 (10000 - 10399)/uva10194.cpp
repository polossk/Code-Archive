/****
	*@PoloShen
	*Title:UVaOJ 10194
	*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <cctype>
#include <map>
using namespace std;

struct Tteam{
    string name;
    int win, tie, loss, gs, ga;
    int p, g, diff;
    Tteam(){
        name = "";
        p = g = win = tie = loss = diff = gs = ga = 0;
    }
    void clear(){
        name = "";
        p = g = win = tie = loss = diff = gs = ga = 0;
    }
};

bool cmp(Tteam a, Tteam b){
    if (a.p != b.p) return a.p > b.p;
    if (a.win != b.win) return a.win > b.win;
    if (a.diff != b.diff) return a.diff > b.diff;
    if (a.gs != b.gs) return a.gs > b.gs;
    if (a.g != b.g) return a.g < b.g;
    string na(a.name),nb(b.name);
    transform(na.begin(), na.end(), na.begin(), ::tolower);
    transform(nb.begin(), nb.end(), nb.begin(), ::tolower);
    return na <= nb;
}

int N, T, G;
string tournamentname, game;
Tteam team[110];
map<string,int> tno;
string t1, t2;
int g1, g2, tn1, tn2, geshi = 0;

void result(){
    cout << tournamentname << endl;
    for (int i = 1; i <= T; i++){
        printf("%d) %s ", i, team[i].name.c_str());
        printf("%dp, %dg ", team[i].p, team[i].g);
        printf("(%d-%d-%d), ", team[i].win, team[i].tie, team[i].loss);
        printf("%dgd (%d-%d)\n", team[i].diff, team[i].gs, team[i].ga);
    }
}

void solve(){
    getline(cin, tournamentname);
    scanf("%d\n", &T);
    for (int i = 1; i <= T; i++){
        team[i].clear();
        getline(cin, team[i].name);
        tno[team[i].name]=i;
    }
    scanf("%d\n",&G);
    for (int i = 1; i <= G; i++){
        getline(cin, t1, '#');
        scanf("%d@%d#", &g1, &g2);
        getline(cin, t2);
        tn1 = tno[t1];
        tn2 = tno[t2];
        team[tn1].gs += g1;
        team[tn2].gs += g2;
        team[tn1].ga += g2;
        team[tn2].ga += g1;
        team[tn1].tie += (g1 == g2);
        team[tn2].tie += (g1 == g2);
        team[tn1].loss += (g1 < g2);
        team[tn2].loss += (g1 > g2);
        team[tn1].win += (g1 > g2);
        team[tn2].win += (g1 < g2);
    }
    for (int i = 1; i <= T; i++){
        team[i].p = 3 * team[i].win + team[i].tie;
        team[i].g = team[i].tie + team[i].win + team[i].loss;
        team[i].diff = team[i].gs - team[i].ga;
    }
    sort(team + 1, team + T + 1, cmp);
    if (geshi) putchar('\n');
    geshi++;
    result();
}

int main(){
    scanf("%d\n",&N);
    while (N--) solve();
    return 0;
}