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
int  ans = 1e7;
string sn, sm;
vector<vector<int>> dp;
int solve(int n, int m) {
	if (n == 0) return m;
	if (m == 0) return n;
	if (dp[n][m] != -1) return dp[n][m];
	if (sn[n - 1] == sm[m - 1]) return dp[n][m] = solve(n - 1, m - 1);
	return dp[n][m] = 1 + min({solve(n - 1, m), solve(n, m - 1), solve(n - 1, m - 1)});
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		cin >> sn >> sm;
		int n = sz(sn);
		int m = sz(sm);
		dp.assign(n + 1, vector<int>(m + 1, -1));
		cout << solve(n, m);
	}
	return 0;
}