#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
int main(void)
{
	FIO
	int n, x;
	cin >> n >> x;
	int arr[n];
	vector<pair<int, pair<int, int>>> dp(n);
	for (auto &i : arr) cin >> i;
	sort(arr, arr + n);
	dp[0] = mk(arr[0], mk(1, 1));
	for (int i = 1; i < n; i++)
	{
		pair<int, int> p;
		dp[i].ff = dp[i - 1].ff;
		if (dp[i - 1].ss.ff * x == dp[i - 1].ss.ss)
		{
			dp[i].ff += (dp[i - 1].ss.ff + 1) * arr[ dp[i - 1].ss.ss];
			p = mk(dp[i - 1].ss.ff + 1, dp[i - 1].ss.ss + 1);
		}
		else
		{
			dp[i].ff += (dp[i - 1].ss.ff) * arr[ dp[i - 1].ss.ss];
			p = mk(dp[i - 1].ss.ff, dp[i - 1].ss.ss + 1);
		}
		dp[i].ss = p;
	}
	for (auto i : dp) cout << i.ff << ' ';
	return 0;
}