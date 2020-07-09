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
	// cin>>t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		ll arr[n];
		queue<ll> q;
		set<ll> s;
		for (auto &i : arr)cin >> i, s.insert(i);
		sort(arr, arr + n);
		for (int i = 0; i < n; i++)q.push(arr[i]);
		ll ans = 0, curdis = 1;
		vector<ll> res;
		while (m) {
			int x = sz(q);
			while (x--) {
				ll y = q.front();
				q.pop();
				int fl = 0;
				if (!m) break;
				if (s.find(y - curdis) == s.end()) {
					m--;
					res.pb(y - curdis);
					ans += curdis;
					s.insert(y - curdis);
					fl = 1;
				}
				if (!m) break;
				if (s.find(y + curdis) == s.end()) {
					m--;
					ans += curdis;
					res.pb(y + curdis);
					s.insert(y + curdis);
					fl = 1;
				}
				if (fl)q.push(y);
			}
			curdis++;
		}
		// reverse(all(res));
		cout << ans << "\n";
		for (auto i : res)cout << i << " ";
		cout << "\n";
	}
	return 0;
}