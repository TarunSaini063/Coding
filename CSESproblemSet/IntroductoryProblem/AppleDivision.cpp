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
ll n, arr[21];
ll wt(ll mask) {
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		if ((mask & (1ll << i)) != 0) sum += arr[i];
	}
	return sum;
}

int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		cin >> n;
		ll tot = 0, ans = 1e18;
		for (int i = 0; i < n; i++) cin >> arr[i], tot += arr[i];
		for (ll mask = 0; mask < (1ll << n); mask++) {
			ll right = wt(mask);
			ll left = tot - right;
			ans = min(ans, abs(left - right));
		}
		cout << ans << "\n";
	}
	return 0;
}