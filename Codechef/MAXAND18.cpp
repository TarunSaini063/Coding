#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
bool cmp(pair<ll, ll> p1, pair<ll, ll> p2) {
	if (p1.ff != p2.ff) return p1.ff > p2.ff;
	return p1.ss < p2.ss;
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--) {
		ll n, k, x;
		cin >> n >> k;
		ll arr[30] = {0};
		for (ll i = 0; i < n; i++) {
			cin >> x;
			for (int j = 0; j < 30; j++) {
				arr[j] += (x & (1 << j)) == 0 ? 0 : 1;
			}
		}
		ll ans = 0;
		vector<pair<ll, ll>> tmp;
		for (ll i = 0; i < 30; i++) {
			tmp.pb(mk(arr[i] * (1 << i) * 1ll, i));
		}
		sort(all(tmp), cmp);
		for (ll i = 0; i < k; i++) {
			ans += (1 << tmp[i].ss);
		}
		cout << ans << "\n";
	}
	return 0;
}
