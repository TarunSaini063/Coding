#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define ar array
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n, k;
		cin >> k;
		string s;
		cin >> s;
		n = sz(s);
		vector<int> ids;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') ids.pb(i);
		}
		if (sz(ids) < k) {
			cout << "0\n";
		}
		else {
			ll ans = 0, last = 0;
			if (k == 0) {
				if (sz(ids) == 0) {
					ll cnt = n;
					cout << cnt*(cnt + 1) / 2 << "\n";
					continue;
				}
				for (int i = 0; i < sz(ids); i++) {
					ll cnt = ids[i] - last;
					ans += cnt * (cnt + 1) / 2;
					last = ids[i] + 1;
				}
				ll cnt = n - ids.back() - 1;
				ans += cnt * (cnt + 1) / 2;
				cout << ans << "\n";
				continue;
			}
			for (int i = 0; i + k <= sz(ids); i++) {
				ll left = (i > 0 ? (ids[i] - ids[i - 1] - 1) : ids[i]);
				ll right = (i + k < sz(ids) ? ids[i + k] - ids[i + k - 1] - 1 : n - ids[i + k - 1] - 1);
				ans += left + right + left * right + 1;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}