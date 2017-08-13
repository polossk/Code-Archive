/****
    *@PoloShen
    *Title:I
    */
#include <iostream>
#include <complex>
#include <vector>
using namespace std;

#define x real()
#define y imag()

typedef complex<double> Point;

istream& operator>>(istream& is, Point& p){
    is >> p.x >> p.y;
    return is;
}

inline double Dis(const Point& a, const Point& b = (0,0)){
    double fx = a.x - b.x;
    double fy = a.y - b.y;
    double fz = fx * fx + fy * fy;
    return fz;
}

bool judge(const Point& a, const Point& b, const Point& c){
    double xs = Dis(a, b);
    double ys = Dis(b, c);
    double zs = Dis(a, c);
    int flag = 0;
    if (xs + zs > ys) flag++;
    if (xs + ys > zs) flag++;
    if (zs + ys > xs) flag++;
    if (flag == 3) return 1;
    else return 0;
}

void solve(){
    int n; cin >> n;
    vector<Point> vpn;
    Point tmp;
    for (int i = 0; i < n; ++i){
        cin >> tmp;
        vpn.push_back(tmp);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i){
        for (int j = i + 1; j < n; ++j){
            for (int k = j + 1; k < n; ++k){
                ans += judge(vpn[i], vpn[j], vpn[k]);
            }
        }
    }
    cout << ans << endl;
}

int main(){
    int t;cin >> t;
    while (t--) solve();
    return 0;
}