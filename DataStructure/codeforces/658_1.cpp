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
		int n, m, x;
		cin >> n >> m;
		map<int, int> mp;
		for (int i = 0; i < n; i++) {
			cin >> x;
			mp[x]++;
		}
		int ans = -1;
		for (int j = 0; j < m; j++) {
			cin >> x;
			if (mp.find(x) != mp.end()) {
				ans = x;
			}
		}
		if (ans != -1) cout << "YES\n" << 1 << " " << ans << "\n";
		else cout << "NO\n";

	}
	return 0;
}