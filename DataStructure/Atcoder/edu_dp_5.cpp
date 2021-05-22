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
		ll n, w;
		cin >> n >> w;
		ll wt[n + 1], val[n + 1], mxval = 0;
		for (int i = 0; i < n; i++) cin >> wt[i + 1] >> val[i + 1], mxval += val[i + 1];
		ll dp[n + 1][mxval + 1], ans = 0;
		for (ll i = 0; i <= mxval; i++) dp[0][i] = 1e18;
		dp[0][0] = 0;
		for (int i = 1; i <= n; i++) {
			for (ll j = 0; j <= mxval; j++) {
				if (val[i] > j) dp[i][j] = dp[i - 1][j];
				else dp[i][j] = min(dp[i - 1][j], wt[i] + dp[i - 1][j - val[i]]);
				if (dp[i][j] <= w) ans = max(ans, j);
			}
		}
		cout << ans << '\n';

	}
	return 0;
}