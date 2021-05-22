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
const int mxn = 1e3 + 1;
ll arr[mxn][mxn];
void solve(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> arr[i][j];
	}
	ll ans = 0;
	for (int i = 0; i < 2 * n ; i++) {
		ll curr = 0;
		int x = max(n - i, 0);
		int y = max(0, i - n);
		while (x < n && y < n) {
			curr += arr[x][y];
			x++, y++;
		}
		ans = max(ans, curr);
	}
	cout << ans << "\n";
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}