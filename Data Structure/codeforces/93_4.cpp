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
ll R, G, B;
ll r[205], g[205], b[205];
ll dp[205][205][205];
ll solve(int i, int j, int k) {
	if (dp[i][j][k] != -1) return dp[i][j][k];
	ll ans = 0;
	if (i < R && j < G) {
		ans = max(ans, r[i] * g[j] + solve(i + 1, j + 1, k));
	}
	if (i < R && k < B) {
		ans = max(ans, r[i] * b[k] + solve(i + 1, j, k + 1));
	}
	if (k < B && j < G) {
		ans = max(ans, g[j] * b[k] + solve(i, j + 1, k + 1));
	}
	return dp[i][j][k] = ans;
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		cin >> R >> G >> B;
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < R; i++) cin >> r[i];
		for (int i = 0; i < G; i++) cin >> g[i];
		for (int i = 0; i < B; i++) cin >> b[i];
		sort(r, r + R, greater<ll>());
		sort(g, g + G, greater<ll>());
		sort(b, B + b, greater<ll>());
		cout << solve(0, 0, 0) << '\n';
	}
	return 0;
}