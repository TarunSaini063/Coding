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
	// cin >> t;
	while (t--)
	{
		ll n, k, x;
		cin >> n >> k;
		vector<ll>pos, neg, zero;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (x > 0) pos.pb(x);
			else if (x < 0) neg.pb(-x);
			else zero.pb(0);
		}
		ll p = sz(pos);
		n = sz(neg);
		sort(all(pos));
		sort(all(neg));
		ll z = sz(zero);
		if (p * n >= k) {
			ll l = 0, h = (1ll << 60);
			ll  ans = 0;
			while ( l <= h) {
				ll mid = l + (h - l) / 2, cnt = 0;
				ll id = n;
				for (int i = 0; i < p; i++) {
					while (id > 0 && pos[i]*neg[id - 1] >= mid)id--;
					cnt += (n - id);
				}
				if (cnt >= k) {
					ans = mid;
					l = mid + 1;
				}
				else {
					h = mid - 1 ;
				}
			}
			cout << -ans << '\n';
			return 0;
		}
		if (p * n + (p + n)*z + z * (z - 1) / 2 >= k) {
			cout << "0\n";
			return 0;
		}
		ll l = 0, h = 1e18, ans;
		k -= p * n + (p + n) * z + z * (z - 1) / 2;
		while (l <= h) {
			ll mid = l + (h - l) / 2;
			ll cnt = 0, id = p - 1;
			for (int i = 0; i < p; i++) {
				while (id > i && (pos[i]*pos[id]) > mid) {
					id--;
				}
				if (id >= i)
					cnt += (id - i);
				else break;
			}
			id = n - 1;
			for (int i = 0; i < n; i++) {
				while (id > i && (neg[i]*neg[id]) > mid) {
					id--;
				}
				if (id >= i)
					cnt += (id - i);
				else break;
			}
			if (cnt < k) {
				l = mid + 1;
			}
			else {
				ans = mid;
				h = mid - 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
