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
int arr[100], n, dp[100001][100];
set<int> s;
void solve(int id, int curr) {
	if (dp[curr][id] != -1) return;
	s.insert(curr);
	if (id >= n) return;
	dp[curr][id] = 1;
	solve(id + 1, curr);
	solve(id + 1, curr + arr[id]);
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
		solve(0, 0);
		s.erase(0);
		cout << sz(s) << '\n';
		for (int i : s) cout << i << " ";
	}
	return 0;
}