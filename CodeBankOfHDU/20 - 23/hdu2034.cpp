#pragma warning(disable : 4786)
#include <set>
#include <cstdio>
using namespace std;

int main(void)
{
    int n, m, t;
    set <int> s;
    set <int>::iterator it;

    while (scanf("%d%d", &n, &m), n + m)
    {
        while (n--)
        {
            scanf("%d", &t);
            s.insert(t);
        }
        while (m--)
        {
            scanf("%d", &t);
            if (s.count(t)) s.erase(t);
        }
        for (it = s.begin(); it != s.end(); it++)
            printf("%d ", *it);
        printf(s.size() ? "\n" : "NULL\n");
        s.clear();
    }

    return 0;
}
