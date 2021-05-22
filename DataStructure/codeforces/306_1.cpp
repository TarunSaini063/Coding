#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
bool merge(pair<int, int> p1, pair<int, int>p2) {
	if (p1.ff > p2.ss || p1.ss < p2.ff) return true;
	return false;
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		size_t i = -1;
		vector<pair<int, int>> v1, v2;
		while (true) {
			i = s.find("AB", i + 1);
			if (i >= sz(s)) break;
			v1.pb(mk(i, i + 1));
		}
		i = -1;
		while (true) {
			i = s.find("BA", i + 1);
			if (i >= sz(s)) break;
			v2.pb(mk(i, i + 1));
		}
		if (sz(v1) == 0 || sz(v2) == 0) cout << "NO\n";
		else {
			if (merge(v1[0], v2.back()) || merge(v1.back(), v2[0])) {
				cout << "YES\n";
			}
			else cout << "NO\n";
		}
	}
	return 0;
}