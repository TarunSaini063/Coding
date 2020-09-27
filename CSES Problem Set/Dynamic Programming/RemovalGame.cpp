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
int n;
const int mxn = 5e3 + 1;
ll arr[mxn], inf = -1e18, dp[mxn][mxn];
ll solve(int a, int b) {
	if (a == b) return arr[a];
	if (a > b) return 0;
	if (dp[a][b] != -1) return dp[a][b];
	return dp[a][b] = max(arr[a] + min(solve(a + 2, b), solve(a + 1, b - 1)), arr[b] + min(solve(a + 1, b - 1), solve(a, b - 2)));
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		memset(dp, -1, sizeof(dp));
		solve(0, n - 1);
		cout << dp[0][n - 1] << "\n";
	}
	return 0;
}