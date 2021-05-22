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
int ans , dp[100000];
void dfs(int n, int m, int cnt) {
	if (n <= 0) return;
	if (dp[n] <= cnt) return;
	dp[n] = cnt;
	if (n >= m) {
		ans = min(ans, cnt + n - m);
		return;
	}
	dfs(n - 1, m, cnt + 1);
	dfs(2 * n, m, cnt + 1);
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < 100000; i++) dp[i] = 1e6;
		ans = 1e6;
		dfs(n, m, 0);
		cout << ans << "\n";
	}
	return 0;
}