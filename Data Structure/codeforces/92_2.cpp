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
vector<int> arr;
const int mxn = 2e5 + 10;
int dp[6][2][mxn];
int n, k, z;
int solve(int rm, int lf, int lrm, int id) {
	// cout << rm << " " << lf << " " << lrm << " " << id << "\n";
	if (dp[lrm][lf][id] != -1) return dp[lrm][lf][id];
	if (rm == 0) return 0;
	int tmp = 0;
	if (lf == 0 && lrm > 0 && id > 0) {
		tmp = max(tmp, solve(rm - 1, 1, lrm - 1, id - 1) + arr[id - 1]);
	}
	tmp = max(tmp, solve(rm - 1, 0, lrm, id + 1) + arr[id + 1]);
	return dp[lrm][lf][id] = tmp;
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> k >> z;
		arr = vector<int>(n);
		for (auto &i : arr) cin >> i;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= z; j++)
			{
				dp[j][0][i] = dp[j][1][i] = -1;
			}
		}
		int ans = solve(k, 0, z, 0) + arr[0];
		cout << ans << "\n";
	}
	return 0;
}