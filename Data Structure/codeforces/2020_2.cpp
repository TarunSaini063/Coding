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
int main(void)
{
	FIO
	int t = 1;
	// cin>>t;
	while (t--)
	{
		ll n, mx, mn, prev, curr, l;
		cin >> n;
		vector<ll> mxn, mnn;
		for (ll i = 0; i < n; i++) {
			cin >> l;
			ll ch = 0;
			cin >> prev;
			mx = mn = prev;
			for (ll j = 1; j < l; j++) {
				cin >> curr;
				if (curr > prev) {
					ch = 1;
				}
				mx = max(mx, curr);
				mn = min(mn, curr);
				prev = curr;
			}
			if (ch == 0) {
				mxn.pb(mx);
				mnn.pb(mn);
			}
		}
		sort(all(mxn));
		ll ans = n * n;
		for (auto i : mnn) {
			int tmp = upper_bound(all(mxn), i) - mxn.begin();
			ans -= tmp * 1ll;
		}
		cout << ans << "\n";
	}
	return 0;
}