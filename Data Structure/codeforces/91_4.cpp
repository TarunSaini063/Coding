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
const int mxn = 2e5 + 10;
int arr[mxn], brr[mxn], id[mxn];
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int x, y, k;
		cin >> x >> k >> y;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		for (int i = 1; i <= m; i++) cin >> brr[i];
		int ls = 0;
		for (int i = 0; i <= n + 1; i++) {
			if (ls <= m + 1 && arr[i] == brr[ls]) {
				id[ls] = i;
				ls++;
			}
		}
		if (ls <= m + 1) {
			cout << "-1\n";
			return 0;
		}
		ll ans = 0;
		for (int i = 0; i < m + 1; i++) {
			int mx = 0;
			for (int j = id[i]; j <= id[i + 1]; j++) mx = max(mx, arr[j]);
			int len = id[i + 1] - id[i] - 1;
			ans += 1ll * (len % k) * y;
			ans += 1ll * (len / k) * min(x, k * y);
			if (len < k && mx > arr[id[i + 1]] && mx > arr[id[i]]) {
				cout << "-1\n";
				return 0;
			}
			if (mx > arr[id[i + 1]] && mx > arr[id[i]]) {
				ans += 1ll * x - min(y * k, x);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}