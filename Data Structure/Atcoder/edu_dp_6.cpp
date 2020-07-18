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
		string s, t;
		cin >> s >> t;
		int n = sz(s), len;
		int m = sz(t);
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
				else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		len = dp[n][m];
		vector<char> ans;
		while (len) {
			if (s[n - 1] == t[m - 1]) ans.pb(s[n - 1]), n--, m--, len--;
			else if (dp[n][m] == dp[n - 1][m]) n--;
			else m--;
		}
		reverse(all(ans));
		for (auto i : ans) cout << i;
		cout << '\n';
	}
	return 0;
}