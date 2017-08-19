// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   #390 Div.2 D                                             *
*****************************************************************************/

#include <bits/stdc++.h>
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

/*//Computational Geometry
#include <complex>
#define x real()
#define y imag()
typedef complex<double> point;
*/

// question: true
// message: false


int main()
{
	int n = nextInt();
	int k = nextInt();
	vector<int> l(n), r(n);
	vector<pair<int, int> > interval(n);
	for (int i = 0; i < n; i++)
	{
		l[i] = nextInt();
		r[i] = 1 + nextInt();
		interval[i] = make_pair(l[i], r[i]);
	}
	sort(interval.begin(), interval.end());
	priority_queue<int, vector<int>, greater<int> > pq;
	int ret = 0, l_fin, r_fin;
	for (int i = 0; i < n; i++)
	{
		int L = interval[i].first;
		pq.push(interval[i].second);
		if (pq.size() > k) pq.pop();
		if (pq.size() == k)
		{
			int R = pq.top();
			if (R - L > ret)
			{
				ret = R - L;
				l_fin = L; r_fin = R;
			}
		}
	}
	cout << ret << endl;
	if (ret == 0)
	{
		for (int i = 0; i < k; i++)
			printf("%d ", i + 1);
	}
	else
	{
		vector<int> idx;
		for (int i = 0; i < n; i++)
			if (idx.size() < k && l[i] <= l_fin && r_fin <= r[i])
				idx.push_back(i);
		for (auto i : idx) printf("%d ", i + 1);
	}
	puts("");
	return 0;
}