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
		int n, st = 0;
		cin >> n;
		ll arr[n], mx = -1e18, curr = 0, sm = 0;
		vector<ll> s;
		for (auto &i : arr)cin >> i, sm += i;
		for (int i = 0; i < n; i++) {
			curr = max(curr + arr[i], arr[i]);
			mx = max(curr, mx);
			s.pb(mx);
		}
		mx = -1e18, curr = 0;
		for (int i = n - 1; i >= 0; i--) {
			curr = max(curr + arr[i], arr[i]);
			mx = max(curr, mx);
			s.pb(mx);
		}
		sort(all(s), greater<ll>());
		ll fl = -1e18;
		st = 0;
		for (auto i : s) {
			if (i == sm && st < 2) st++;
			else {fl = i; break;}
		}
		// cout << fl << "\n";
		if (fl >= sm) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}