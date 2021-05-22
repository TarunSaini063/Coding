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
		ll n, mx = 0, mx2 = 0, mx3 = 0;
		cin >> n;
		ll arr[n];
		for (ll &i : arr) cin >> i;
		sort(arr, arr + n);
		ll c = 0, ans = 1e18;
		while (true) {
			ll num = 1, curr = 0;
			if (c == 0) num = 0;
			for (ll i = 0; i < n; i++) {
				curr += abs(arr[i] - num);
				ll chk = 9223372036854775807;
				if (c != 0 && num >= chk / c) break;
				num *= c;
			}
			c++;
			if (ans <= curr) {
				break;
			}
			else ans = curr;
		}
		cout << ans << "\n";
	}
	return 0;
}