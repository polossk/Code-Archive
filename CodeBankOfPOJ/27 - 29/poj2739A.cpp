#include <iostream>
#include <vector>
using namespace std;
const int MaxN = 10016;
vector<int> p;
vector<bool> isPrime;
void init()
{
    isPrime = vector<bool>(MaxN + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= MaxN; ++i)
    {
        if (isPrime[i])
        {
            p.push_back(i);
            for (int j = i * 2; j <= MaxN; j += i)
                isPrime[j] = false;
        }
    }
}
int n;
int main()
{
    init(); int sz = p.size();
    while (cin >> n && n)
    {
        int l = 0, r = 0, sum = 0, res = 0;
        while (true)
        {
            while (sum < n && r < sz) sum += p[r++];
            if (sum < n) break;
            else if (sum == n) res++;
            sum -= p[l++];
        }
        cout << res << endl;
    }
    return 0;
}
