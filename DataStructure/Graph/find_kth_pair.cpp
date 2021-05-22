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
		int n, k;
		cin >> n >> k;
		int arr[n];
		for (int &i : arr)cin >> i;
		sort(arr, arr + n);
		vector<int> v;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				v.pb(arr[i]*arr[j]);
			}
		}
		for (int i : arr) cout << i << " ";
		cout << "\n";
		sort(all(v));
		for (int i : v) cout << i << " ";
		cout << "\n";

		k = 1;
		while (k <= n * (n - 1) / 2) {
			int l = 0, r = 1e3,  ans = 0, id = n;
			while (l <= r) {
				int mid = (l + r) / 2;
				int cnt = 0, id = n - 1;
				for (int i = 0; i < n; i++) {
					while (id > i && (arr[i]*arr[id]) > mid) {
						id--;
					}
					if (id >= i)
						cnt += (id - i);
				}
				if (cnt < k) {
					l = mid + 1;
				}
				else {
					ans = mid;
					r = mid - 1;
				}
			}
			cout << k << " " << ans << "\n";
			k++;
		}
	}
	return 0;
}