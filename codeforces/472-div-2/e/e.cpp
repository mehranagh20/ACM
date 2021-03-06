//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, double> dd;
typedef pair<dd, double> ddd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<dd> vdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef vector<vector<viii> > vvviii;
typedef vector<vector<iii> > vviii;
typedef set<int> si;
typedef vector<si> vsi;

#define F(i, n) for(int i = 0; i < n; i++)
#define F(i, j, n) for(int i = j; i < n; i++)

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define F first
#define S second
#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)

struct woo {
  int h, i;
  inline bool operator <(const woo &r) {
    if(r.i != i) return i < r.i;
    return h > r.h;
  }
};

int main() {
    ios::sync_with_stdio(0);
    int n, l, r, mxh = 0; cin >> n >> l >> r;
    vector<woo> all(n);
    forn(i, n) cin >> all[i].h, mxh += all[i].h;
    int tmpl = l;
    l = mxh - r, r = mxh - tmpl;
    forn(i, n) cin >> all[i].i;
    sort(all.begin(), all.end());
    vi dp(mxh + 1, -inf);
    dp[0] = 0;
    forn(i, n) {
      for(int h = mxh - all[i].h; h >= 0; h--) {
        dp[h + all[i].h] = max(dp[h + all[i].h],
          dp[h] + all[i].i * (h + all[i].h <= r && h + all[i].h >= l));
      }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}
