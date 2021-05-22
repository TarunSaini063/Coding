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
const int mxn = 5e5 + 5;
ll arr[mxn], dp[2][mxn], n;
void solve(int id) {
	stack<int> s;
	s.push(0);
	for (int i = 1; i <= n; i++) {
		while (arr[i] < arr[s.top()]) s.pop();
		int idx = s.top();
		// cout << idx << '\n';
		dp[id][i] = dp[id][idx] + (i - idx) * arr[i];
		s.push(i);
	}
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		solve(0);
		reverse(arr + 1, arr + n + 1);
		solve(1);
		reverse(arr + 1, arr + n + 1);
		// for (int i = 1; i <= n; i++) cout << dp[0][i] << " ";
		// cout << "\n";
		// for (int i = 1; i <= n; i++) cout << dp[1][i] << " ";
		ll mx = 0, id = -1;
		for (int i = 1; i <= n; i++) {
			if (mx < dp[0][i] + dp[1][n - i + 1] - arr[i]) {
				mx = dp[0][i] + dp[1][n - i + 1] - arr[i];
				id = i;
			}
		}
		mx = 1e18;
		// cout << id << "\n";
		for (int i = id; i <= n; i++) {
			mx = min(mx, arr[i]);
			arr[i] = mx;
		}
		mx = 1e18;
		for (int i = id - 1; i >= 1; i--) {
			mx = min(mx, arr[i]);
			arr[i] = mx;
		}
		for (int i = 1; i <= n; i++) cout << arr[i] << " \n"[i == n];
	}
	return 0;
}