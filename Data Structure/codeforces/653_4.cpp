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
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		ll arr[n];
		map<ll, ll> mp;
		for (auto &i : arr)cin >> i;
		for (int i = 0; i < n; i++) {
			ll x1 = (arr[i] + k - 1) / k * k - arr[i];
			if (x1 == 0)continue;
			mp[x1]++;
		}
		ll x = 0;
		if ((int)mp.size() == 0) {
			cout << "0\n";
			continue;
		}
		for (auto i : mp) {
			ll tp = i.ff + (i.ss - 1) * k;
			x = max(x, tp);
		}
		cout << x + 1 << "\n";
	}
	return 0;
}