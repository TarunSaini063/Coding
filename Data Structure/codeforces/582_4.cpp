#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define ar array
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
const int mxn = 2e5 + 1;
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<vector<int>> adj(mxn);
		for (int i = 0; i < n; i++) {
			int cnt = 0, x;
			cin >> x;
			while (x) {
				adj[x].pb(cnt);
				cnt++;
				x /= 2;
			}
		}
		int ans = INT_MAX;
		for (auto &i : adj) {
			if (sz(i) >= k) {
				sort(all(i));
				int curr = 0;
				for (int j = 0; j < k; j++) curr += i[j];
				ans = min(ans, curr);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}