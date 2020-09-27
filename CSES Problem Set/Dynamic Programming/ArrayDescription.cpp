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
		int n, m;
		cin >> n >> m;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		ll dp[n][m + 1];
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i <= m; i++) dp[0][i] = 1;
		if (arr[0] != 0) {
			for (int i = 0; i <= m; i++) {
				if (arr[0] != i) dp[0][i] = 0;
			}
		}
		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = dp[i - 1][j];
				if (j > 1) dp[i][j] += dp[i - 1][j - 1];
				if (j < m) dp[i][j] += dp[i - 1][j + 1];
				dp[i][j] %= mod;
			}
			if (arr[i] != 0) {
				for (int j = 1; j <= m; j++) {
					if (arr[i] != j) {
						dp[i][j] = 0;
					}
				}
			}
		}
		ll ans = 0;
		for (int i = 1; i <= m; i++) ans = (ans + dp[n - 1][i]) % mod;
		cout << ans;
	}
	return 0;
}