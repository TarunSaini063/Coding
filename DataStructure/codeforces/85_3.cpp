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
// #ifndef ONLINE_JUDGE
// 	freopen("input1.txt", "r", stdin);
// 	freopen("output1.txt", "w", stdout);
// #endif
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		ll n, a, b;
		cin >> n;
		vector<pair<ll, ll>> arr(n);
		for (auto &j : arr)
		{
			cin >> a >> b;
			j = mk(a, b);
		}
		ll mn = 1e18;
		ll ans = 0;
		for (ll i = 0; i < n; i++)
		{
			ll nt = (i + 1) % n;
			a = min(arr[nt].ff, arr[i].ss);
			ans += arr[nt].ff - a;
			mn = min(mn, a);
		}

		cout << mn + ans << "\n";
	}
	return 0;
}