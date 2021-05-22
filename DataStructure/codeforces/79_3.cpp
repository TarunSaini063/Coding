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
	int t;
	cin >> t;
	while (t--)
	{
		ll m, n, j = 0, ans = 0;
		cin >> n >> m;
		ll arr[n], brr[m];
		for (auto &i : arr)cin >> i;
		for (auto &i : brr)cin >> i;
		set<ll> s;
		for (ll i = 0; i < m; i++) {
			if (s.find(brr[i]) != s.end()) {
				s.erase(brr[i]);
				ans++;
				continue;
			}
			ll x = sz(s);
			for (; j < n; j++) {
				x++;
				if (arr[j] == brr[i]) { ans += 2 * (x - 1) + 1; j++; break;}
				s.insert(arr[j]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}