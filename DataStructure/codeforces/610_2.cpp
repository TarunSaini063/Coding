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
	int t;
	cin >> t;
	while (t--) {
		int n, p, k;
		cin >> n >> p >> k;
		int arr[n];
		for (auto &I : arr)cin >> I;
		sort(arr, arr + n);
		vector<pair<int, int>> dp(n);
		for (int i = 0; i < k; i++) {
			if (p >= arr[i])
				dp[i] = mk(p - arr[i], i + 1);
			else dp[i] = mk(0, 0);
		}
		for (int i = k; i < n; i++) {
			if (dp[i - k].ff >= arr[i]) {
				dp[i] = mk(dp[i - k].ff - arr[i], dp[i - k].ss + k);
			}
		}
		int mx = 0;
		for (int i = 0; i < n; i++) {
			mx = max(mx, dp[i].ss);
		}
		cout << mx << "\n";
	}
	return 0;
}