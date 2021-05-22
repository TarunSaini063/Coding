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
		ll n;
		cin >> n;
		vector<ll>arr(n);
		for (ll &i : arr) cin >> i;
		vector<string> s(n);
		for (auto &i : s) cin >> i;
		ll dp[n][2];
		dp[0][0] = 0;
		dp[0][1] = arr[0];
		for (int i = 1; i < n; i++) {
			dp[i][0] = dp[i][1] = 1e18;
			if (s[i] >= s[i - 1]) {
				dp[i][0] = dp[i - 1][0];
			}
			string last = s[i - 1];
			reverse(all(last));
			if (last <= s[i]) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
			string tmp = s[i];
			reverse(all(tmp));
			if (tmp >= s[i - 1]) dp[i][1] = arr[i] + dp[i - 1][0];
			if (tmp >= last) dp[i][1] = min(dp[i][1], arr[i] + dp[i - 1][1]);
			if (dp[i][0] == 1e18 && dp[i][1] == 1e18) {
				cout << "-1\n";
				return 0;
			}
		}
		cout << min(dp[n - 1][0], dp[n - 1][1]) << "\n";
	}
	return 0;
}