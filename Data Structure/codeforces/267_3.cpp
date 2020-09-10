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
ll n, m, k, arr[5555];
ll mp[5555][5555];
ll fun(int id, int req) {
	// l++;
	if (req <= 0) return 0;
	if (id + req * m - 1 > n) return 0;
	if (mp[id][req] != 0) return mp[id][req];
	ll ans = 0;
	ans = max(arr[id + m - 1] - arr[id - 1] + fun(id + m, req - 1), fun(id + 1, req));
	mp[id][req] = ans;
	return ans;
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		for (int i = 1; i <= n; i++)arr[i] += arr[i - 1];
		// fun(1, k);
		for (int i = 1; i <= k; i++) {
			for (int j = i * m; j <= n; j++) {
				mp[i][j] = max(mp[i - 1][j - m] + arr[j] - arr[j - m], mp[i][j - 1]);
			}
		}
		cout << mp[k][n] << "\n";
	}
	return 0;
}