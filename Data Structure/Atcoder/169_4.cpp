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
		ll n, j = 2;
		int cnt = 0, ans = 0;
		vector<int> arr;
		cin >> n;
		while (j * j <= n) {
			cnt = 0;
			while (n % j == 0) {
				n /= j;
				cnt++;
			}
			// cout << j << " " << cnt << '\n';
			j++;
			if (cnt)arr.pb(cnt);
		}
		if (n > 1) arr.pb(1);
		for (auto i : arr) {
			ans += (sqrt(1 + 8 * i) - 1) / 2;
		}
		cout << ans << '\n';
	}
	return 0;
}