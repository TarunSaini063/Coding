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
	while (t--)
	{
		ll n, x, y, c;
		cin >> n >> c;
		map<pair<ll, ll>, vector<ll>> mp;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			if (x != 0 && y != 0)
				mp[mk(x % c, y % c)].pb(x);
			else mp[mk(x, y)].pb(x);
		}
		for (auto &i : mp) sort(all(i.ss));
		ll ans = 0;
		for (auto vt : mp) {
			vector<ll> pref, arr;
			pref.pb(0);
			map<ll, ll> freq;
			for (int i = 0; i < (int)vt.ss.size(); i++)
				freq[vt.ss[i]]++;
			for (auto i : freq) arr.pb(i.ff);
			for (int i = 1; i < (int)arr.size(); i++) pref.pb(freq[arr[i - 1]] * (arr[i] - arr[i - 1]));
			pref.pb(0);
			cout << "\n";
			int sz = pref.size();
			ll res = 1e18;
			for (int i = 1; i < sz; i++)
			{
				pref[i] += pref[i - 1];

			}
			// pref.pb(0);
			// for (int i = 1; i < (int)pref.size(); i++)pref[i] += pref[i - 1];
			for (auto i : pref) cout << i << " ";
			cout << '\n';
			for (int i = 1; i < sz - 1; i++)
			{
				res = min(res, pref[i] + (pref[sz - 1] - pref[i]));
				cout << i << " " << pref[i - 1] + pref[sz - 1] - pref[i] << '\n';
			}
			ans += res;
		}
		cout << mp.size() << "\n";
		cout << ans << "\n";

	}
	return 0;
}
