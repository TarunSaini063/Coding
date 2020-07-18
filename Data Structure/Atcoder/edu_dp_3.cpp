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
		int n;
		cin >> n;
		ll dp[n][3];
		for (auto &i : dp) cin >> i[0] >> i[1] >> i[2];
		for (int i = 1; i < n; i++) {
			dp[i][0] += max(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] += max(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] += max(dp[i - 1][1], dp[i - 1][0]);
		}
		cout << *max_element(dp[n - 1], dp[n - 1] + 3) << "\n";
	}
	return 0;
}