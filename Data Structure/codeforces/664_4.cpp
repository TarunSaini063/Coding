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
		ll n, d, m, x;
		cin >> n >> d >> m;
		vector<ll> less, more;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (x > m) more.pb(x);
			else less.pb(x);
		}
		sort(all(more), greater<ll>());
		sort(all(less), greater<ll>());
		for (int i = 1; i < sz(less); i++) {
			less[i] += less[i - 1];
		}
		for (int i = 1; i < sz(more); i++) {
			more[i] += more[i - 1];
		}
		ll id = (n + d) / (d + 1), mx = 0;
		if (id - 1 < sz(more) && id - 1 >= 0) mx = more[id - 1];
		for (int i = 0; i < sz(less); i++) {
			ll left = n - i - 1, sum = less[i];
			id = (left + d) / (d + 1);
			if (id - 1 < sz(more) && id - 1 >= 0) sum += more[id - 1];
			mx = max(mx, sum);
		}
		cout << mx << '\n';
	}
	return 0;
}