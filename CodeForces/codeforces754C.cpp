// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   #390 Div.2 C                                             *
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

const int MAXN = 105;
const int MAXM = 105;
int n, m;
int hosts[MAXN];
bool maybe[MAXM][MAXN];

bool dp(int line, int prev, vector<vector<int> > &_, vector<int> &ans)
{
	if (_[line][prev] != -1) return _[line][prev];
	if (line == m) return _[line][prev] = true;
	for (int i = 0; i < n; i++)
		if (i != prev && (hosts[line] == -1 || i == hosts[line]) && !maybe[line][i])
			if (dp( line + 1, i, _, ans ))
			{
				ans[line] = i;
				return _[line][prev] = true;
			}
	return _[line][prev] = false;
}

inline bool issep(char _)
{
	return _ == '.' || _ == ',' || _ == '!' || _ == '?' || _ == ' ';
}

void work()
{
	n = nextInt();
	vector<string> people(n);
	map<string, int> mp;
	for (int i = 0; i < n; i++)
	{
		cin >> people[i];
		mp[people[i]] = i;
	}
	m = nextInt(); cin.ignore();
	vector<string> speaker(m), msg(m);
	for (int i = 0; i < m; i++)
	{
		string s; getline(cin, s);
		int _ = s.find(':');
		speaker[i] = s.substr(0, _);
		msg[i] = s.substr(_ + 1);
	}
	for (int i = 0; i < m; i++)
	{
		hosts[i] = (speaker[i][0] == '?') ? -1 : mp[speaker[i]];
		for (int j = 0; j < n; j++) maybe[i][j] = false;
		string _ = msg[i];
		int sz = _.size();
		vector<int> idx; idx.push_back(-1);
		for (int j = 0; j < sz; j++)
			if (issep(_[j])) idx.push_back(j);
		idx.push_back(sz);
		for (int j = 0; j + 1 < idx.size(); j++)
		{
			string tmp = _.substr(idx[j] + 1, idx[j + 1] - idx[j] - 1);
			if (tmp.empty()) continue;
			// cout << "check: [" << tmp << "]" << endl;
			if (mp.count(tmp))
            {
                // cout << "-> FIND <-" << endl;
                maybe[i][mp[tmp]] = true;
            }
		}
	}

	vector<vector<int> > _(m + 1, vector<int>(n + 1, -1));
	vector<int> ans(m);
	if (!dp(0, n, _, ans))
	{
		cout << "Impossible" << endl;
		return;
	}
	for (int i = 0; i < m; i++)
	{
		cout << people[ans[i]] << ':' << msg[i] << endl;
	}
}

int main()
{
	int t = nextInt();
	while (t--) work();
	return 0;
}