#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

// I'm too shameless to use this...
// Forgive me, please...
#pragma GCC optimize ("O2")

using namespace std;

inline int diff(char a, char b)
{
    if (a == b) return 0;
    else
    {
        if ((int)a + b == 138) return 4;
        else return 5;
    }
}

char ser1[50010], ser2[50010], sert[50010];
int la, lb, mdlt, mv;

inline int mindlt(int i, int place)
{
    int a = la - i, b = lb - place;
    return abs(b - a) * 3;
}

int nxt[4][50010];
struct rec
{
    int place, pwr;
    rec (void) {}
    rec (int pl0, int pw0) : place(pl0), pwr(pw0) {}
};

inline int dlt(int a, int b) { return abs(a - b); }

rec roll[2][50010], *f, *g;
int qmr[2], *mf, *mg;

inline void try_add(int i, int place, int pwr)
{
    if (pwr + mindlt(i, place) >= mv) return;
    while (*mg)
    {
        int lpla = g[(*mg) - 1].place, lpwr = g[(*mg) - 1].pwr;
        int tt = (place - lpla) * 3;
        if (pwr <= lpwr - tt) --(*mg);
        else if (tt + lpwr > pwr) break;
        else return;
    }
    g[(*mg)++] = rec(place, pwr);
}

int main()
{
    while (~scanf("%s %s", ser1, ser2))
    {
        la = strlen(ser1), lb = strlen(ser2);
        if (la < lb)
        {
            strcpy(sert, ser1);
            strcpy(ser1, ser2);
            strcpy(ser2, sert); swap(la, lb);
        }
        for (int j = 0; j < 4; j++) nxt[j][lb] = lb;
        for (int i = lb - 1; i >= 0; i--)
        {
            for (int j = 0; j < 4; j++) nxt[j][i] = nxt[j][i + 1];
            if (ser2[i] == 'A') nxt[0][i] = i;
            else if (ser2[i] == 'G') nxt[1][i] = i;
            else if (ser2[i] == 'C') nxt[2][i] = i;
            else nxt[3][i] = i;
        }
        mdlt = min(la, lb) / 5, mv = min(5 * mdlt, 28800);
        mf = &qmr[0], mg = &qmr[1];
        f = roll[0], g = roll[1]; *mf = *mg = 0;
        f[(*mf)++] = rec(0, 0);
        for (int i = 1; i <= la; i++)
        {
            for (int m = 0; m < *mf; m++)
            {
                int place = f[m].place, pwr = f[m].pwr;
                if (dlt(i, place) <= mdlt) try_add(i, place, pwr + 3);
                while (m == *mf - 1 || place <= f[m + 1].place)
                {
                    if (place >= lb || dlt(i, place + 1) > mdlt) break;
                    int mr = diff(ser1[i - 1], ser2[place]);
                    try_add(i, place + 1, pwr + mr);
                    int tpl = place;
                    if (mr == 5)
                    {
                        if (ser1[i - 1] == 'A') place = nxt[0][place];
                        else if (ser1[i - 1] == 'G' || ser1[i - 1] == 'C') place = min(nxt[1][place], nxt[2][place]);
                        else place = nxt[3][place];
                    }
                    else if (mr == 0) break;
                    else
                    {
                        if (ser1[i - 1] == 'G') place = nxt[1][place];
                        else place = nxt[2][place];
                    }
                    pwr += (place - tpl) * 3;
                    if (pwr + mindlt(i - 1, place) >= mv) break;
                }
            }
            swap(f, g), *mf = *mg;
            *mg = 0;
        }
        int place = f[(*mf) - 1].place, pwr = f[(*mf) - 1].pwr;
        printf("%d\n", (lb - place) * 3 + pwr);
    }
    return 0;
}
