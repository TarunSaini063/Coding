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
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> adj[n + 1], arr(n), mx(n + 1, 0);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			arr[i] = x;
			if (sz(adj[x]) == 0) {
				adj[x].pb(i);
				mx[x] = i + 1;
			}
			else
				mx[x] = max(mx[x], i - adj[x].back());
			adj[arr[i]].pb(i);
		}
		for (int i = 0; i < n; i++) {
			mx[arr[i]] = max(mx[arr[i]], n - adj[arr[i]].back());
		}
		vector<int> ans(n + 1, 1e8);
		for (int i = 0; i < n; i++) {
			ans[mx[arr[i]]] = min(arr[i], ans[mx[arr[i]]]);
		}
		int mn = 1e8;
		for (int i = 1; i <= n; i++) {
			if (ans[i] != -1) mn = min(ans[i], mn);
			ans[i] = mn;
		}
		for (int i = 1; i <= n; i++) {
			if (ans[i] == 1e8) ans[i] = -1;
			cout << ans[i] << " ";

		}
		cout << '\n';
	}
	return 0;
}