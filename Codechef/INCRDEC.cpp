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
		map<int, int> mp;
		int x, n, fl = 0, freq = 0, mx = 0;
		cin >> n;
		vector<int> v1, v2;
		for (int i = 0; i < n; i++) {
			cin >> x;
			mp[x]++;
			if (mp[x] > 2) fl = 1;
			if (mp[x] == 1) v1.pb(x);
			else v2.pb(x);
			if (mx <= x) {
				mx = x;
				freq = mp[x];
			}
		}
		if (fl || freq == 2) {
			cout << "NO\n";
			continue;
		}
		sort(all(v1));
		if (v2.size() != 0) sort(all(v2), greater<int>());
		if (v2.size() == 0) {
			v2.pb(v1[0]);
			v1.erase(v1.begin());
		}
		cout << "YES\n";
		for (auto i : v1) cout << i << " ";
		for (auto i : v2) cout << i << " ";
		cout << "\n";

	}
	return 0;
}