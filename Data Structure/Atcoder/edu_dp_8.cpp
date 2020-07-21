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
		int n, m;
		cin >> n >> m;
		vector<string> arr(n);
		for (auto &i : arr) cin >> i;
		vector<vector<ll>> dp(n, vector<ll>(m));
		int ls = 1;
		for (int i = 0; i < n; i++) {
			if (arr[i][0] == '#') ls = 0;
			dp[i][0] = ls;
		}
		ls = 1;
		for (int i = 0; i < m; i++) {
			if (arr[0][i] == '#') ls = 0;
			dp[0][i] = ls;
		}
		dp[0][0] = 0;
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				dp[i][j] = 0;
				if (arr[i - 1][j] != '#') dp[i][j] = dp[i - 1][j] % mod;
				if (arr[i][j - 1] != '#') dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
			}
		}
		cout << dp[n - 1][m - 1] << "\n";
	}
	return 0;
}