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
bool **dp;
int *arr;
void print(vector<int> p) {
	for (auto i : p) cout << i << " ";
	cout << "\n";
}
void solve(int i, int sum, vector<int> ans) {
	if (i == 0 && dp[0][sum] && sum != 0) {
		ans.pb(arr[0]);
		print(ans);
		return;
	}
	if (i == 0 && sum == 0) {
		print(ans);
		return;
	}
	if (dp[i - 1][sum]) {
		solve(i - 1, sum, ans);
	}
	if (arr[i] <= sum && dp[i - 1][sum - arr[i]])
	{	ans.pb(arr[i]);
		solve(i - 1, sum - arr[i], ans);
	}
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n, sum;
		cin >> n >> sum;
		arr = new int[n];
		for (int i = 0; i < n; i++) cin >> arr[i];
		dp = new bool*[n];
		for (int i = 0; i < n; i++) {
			dp[i] = new bool[sum + 1];
			dp[i][0] = true;
		}
		if (arr[0] <= sum) dp[0][arr[0]] = true;
		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= sum; j++) {
				dp[i][j] = dp[i - 1][j];
				if (arr[i] <= j) dp[i][j] |= dp[i - 1][j - arr[i]];
			}
		}
		if (!dp[n - 1][sum]) {
			cout << "not found\n";
			return 0;
		}
		solve(n - 1, sum, {});
		delete(dp);
		delete(arr);
	}
	return 0;
}