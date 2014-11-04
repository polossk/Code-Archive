#include <stack>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef struct node
{
    int ord;
    node * next;
}Node;

const int size = 512 + 1;

Node    list[size];
int X[size];
int Y[size];
bool    visit[size];
int size_x;
int size_y;
stack   <int>   stk;

void init()
{
    int i;

    for (i = 1; i <= size_x; i++)
        list[i].next = NULL;
    memset(X, 0, (size_x + 1) * sizeof(int));
    memset(Y, 0, (size_y + 1) * sizeof(int));
}

void input(int len)
{
    int i;
    int x;
    int y;
    Node*   p;

    for (i = 0; i < len; i++)
    {
        scanf("%d%d", &x, &y);
        p = new Node;
        p->ord = y;
        p->next = list[x].next;
        list[x].next = p;
    }
}

bool dfs(int x)
{
    Node*   p;

    stk.push(x);
    for (p = list[x].next; p; p = p->next)
    {
        if (!visit[p->ord])
        {
            visit[p->ord] = true;
            stk.push(p->ord);
            if (!Y[p->ord] || dfs(Y[p->ord]))
                return true;
            else
                stk.pop();
        }
    }
    stk.pop();

    return false;
}

void solve()
{
    int i;
    int top;

    for (i = 1; i <= size_x; i++)
    {
        while (!stk.empty()) stk.pop();
        memset(visit, false, size_y + 1);
        if (dfs(i))
        {
            while (!stk.empty())
            {
                top = stk.top();
                stk.pop();
                Y[top] = stk.top();
                X[stk.top()] = top;
                stk.pop();
            }
        }
    }
}

void output()
{
    int i;
    int count = 0;
    Node*   p;

    for (i = 1; i <= size_x; i++)
    {
        if (X[i]) count++;
        while (p = list[i].next)
        {
            list[i].next = p->next;
            delete p;
        }
    }

    cout << count << endl;

}

int main(void)
{
    int n;

    while (scanf("%d", &n), n)
    {
        scanf("%d%d", &size_x, &size_y);

        init();
        input(n);
        solve();
        output();

        while (!stk.empty()) stk.pop();
    }

    return 0;
}
