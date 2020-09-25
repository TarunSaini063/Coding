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
		int n, t1;
		cin >> n >> t1;
		ll arr[n];
		for (ll &i : arr) cin >> i;
		sort(arr, arr + n);
		ll l = 0, r = 1e18, ans = 0;
		while (l <= r) {
			ll mid = l + (r - l) / 2;
			ll tot = 0;
			for (ll i : arr) {
				tot += mid / i;
				if (tot > t1) break;
			}
			// cout << tot << "\n";
			if (tot >= t1) {
				ans = mid;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
