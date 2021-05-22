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
	// cin>>t;
	while (t--)
	{
		int n, x, y;
		cin >> n;
		int arr[n];
		map<int, set<int>> mp;
		for (int i = 0; i < n; i++) {
			cin >> x;
			arr[i] = x;
			for (int j = 0; j < x; j++) {
				cin >> y;
				mp[y].insert(i);
			}
		}
		ll ans = 0;
		for (auto i : mp) {
			ans = (ans + invmod(arr[i.ff]) * (sz(i.ss))) % mod;
		}
		ans = (((ans % mod * invmod(n)) % mod * (invmod(n - 1) % mod)));
		cout << ans << "\n";
	}
	return 0;
}