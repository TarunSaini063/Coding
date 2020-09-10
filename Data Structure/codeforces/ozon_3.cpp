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
		ll n, m;
		cin >> n >> m;
		ll arr[n];
		for (ll &i : arr)cin >> i;
		if (n >= 2 * m) cout << "0\n";
		else {
			ll ans = 1;
			for (int i = 0; i < n && ans != 0; i++) {
				for (int j = i + 1; j < n && ans != 0; j++) {
					ans = (ans % m * (abs(arr[i] - arr[j])) % m) % m;
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}