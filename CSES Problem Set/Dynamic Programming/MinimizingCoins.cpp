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
int arr[101], ans = 1e8, n;
void solve(int cnt, int sum, int id) {
	if (sum < 0) return;
	if (sum == 0) {
		ans = min(ans, cnt);
		return;
	}
	if (id >= n) return;
	solve(cnt + 1, sum - arr[id], id);
	solve(cnt, sum, id + 1);
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int x;
		cin >> n >> x;
		for (int i = 0; i < n; i++) cin >> arr[i];
		// sort(arr, arr + n);
		// solve(0, x, 0);
		ll dp[x + 1] = {0};
		for (int i = 1; i <= x; i++) {
			dp[i] = 1e9;
			for (int j = 0; j < n; j++) {
				if (arr[j] <= i) {
					dp[i] = min(dp[i], dp[i - arr[j]] + 1);
				}
			}
		}
		ans = dp[x];
		if (ans == 1e9) ans = -1;
		cout << ans << "\n";
	}
	return 0;
}