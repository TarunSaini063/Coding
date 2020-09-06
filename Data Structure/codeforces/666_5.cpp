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
#define FIO                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);
#define all(x) x.begin(), x.end()
ll power(ll a, ll b) {
	ll res = 1;
	a = a % mod;
	while (b) {
		if (b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b /= 2;
	}
	return res;
}
ll invmod(ll a) { return power(a, mod - 2); }
const int mxn = 2e6 + 1;
ll r1, r2, r3, dp[mxn], n, arr[mxn], d;
ll solve(int idx) {
	if (idx >= n) return -d;
	if (dp[idx] != -1) return dp[idx];
	ll mn = 1e18;
	ll curr = min(r2 + r1, (arr[idx] + 2) * r1);
	mn = min(mn, solve(idx + 1) + curr + 3 * d);
	mn = min(mn, solve(idx + 1) + d + arr[idx] * r1 + r3);
	if (idx < n - 1) {
		mn = min(mn, solve(idx + 2) + curr + min(r2 + r1, (arr[idx + 1] + 2) * r1) +
		         4 * d);
	}
	if (idx == n - 2) {
		mn = min(mn, solve(idx + 2) + 3 * d + curr + arr[idx + 1] * r1 + r3);
	}
	return dp[idx] = mn;
}
int main(void) {
	FIO int t = 1;
	// cin >> t;
	while (t--) {
		cin >> n >> r1 >> r2 >> r3 >> d;
		for (int i = 0; i < n; i++) cin >> arr[i];
		memset(dp, -1, sizeof(dp));
		cout << solve(0) << "\n";
	}
	return 0;
}