#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 998244353
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
		ll k, n;
		vector<pair<ll, ll>> len;
		cin >> n >> k;
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			len.pb(mk(a, b));
		}
		ll arr[2 * n + 10] = {0}, ans = 0;
		arr[1] = 1;
		for (int i = 1; i <=  n; i++) {
			ans += arr[i];
			ans %= mod;
			for (int j = 0; j < k; j++) {
				arr[i + len[j].ff] += ans;
				arr[i + len[j].ss + 1] -= ans;
				if (arr[i + len[j].ss + 1] < 0) arr[i + len[j].ss + 1] += mod;
			}
		}
		ans = arr[n] % mod;
		cout << ans << "\n";
	}
	return 0;
}