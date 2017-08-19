// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   #391 Div. 1 + Div. 2, combined A                         *
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

bool cut(vector<int> &data)
{
	if (data['B'] >= 1 && data['u'] >= 2 && data['l'] >= 1
		&& data['b'] >= 1 && data['a'] >= 2 && data['s'] >= 1
		&& data['r'] >= 1)
	{
		data['B'] -= 1; data['u'] -= 2; data['l'] -= 1;
		data['b'] -= 1; data['a'] -= 2; data['s'] -= 1;
		data['r'] -= 1; return true;
	}
	else return false;
}

int main()
{
	string s = nextStr();
	vector<int> data(255);
	for (int i = 0; i < data.size(); i++) data[i] = 0;
	for (int i = 0; i < s.size(); i++) data[s[i]]++;
	int ans = 0;
	while (cut(data)) ans++;
	cout << ans << endl;
	return 0;
}