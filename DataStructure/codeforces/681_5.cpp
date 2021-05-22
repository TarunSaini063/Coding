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
const int mxn = 2e5 + 10;
ll sum[mxn], per[mxn], n;
void setsum(int start) {
	for (int i = start; i <= n; i++) {
		sum[i] = sum[i - 1] + per[i];
	}
}
void kth(ll k) {
	ll cnt = 1, p = 1;
	for (; cnt * p <= k; p++) {
		cnt *= p;
	}
	int start, idx;
	start = idx = n - p + 1;
	vector<int> all;
	for (int i = n - p + 1; i <= n; i++) {
		all.pb(i);
	}
	// cout << cnt << ' ' << p << " " << start << "\n";
	// cout.flush();

	while (idx <= n) {
		int j = k / cnt;
		k %= cnt;
		per[idx++] = all[j];
		all.erase(all.begin() + j);
		if (p > 1) {
			cnt /= (--p);
		}
		// cout << "k= " << k << " j= " << j << '\n';
		// cout.flush();
	}
	setsum(start);
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int q;
		ll k = 0;
		cin >> n >> q;
		for (int i = 1; i <= n; i++) {
			per[i] = i;
			sum[i] = per[i] + sum[i - 1];
		}
		while (q--) {
			int x;
			cin >> x;
			if (x == 1) {
				int l, r;
				cin >> l >> r;
				cout << sum[r] - sum[l - 1] << "\n";
				cout.flush();
			}
			else {
				cin >> x;
				k += x;
				kth(k);
				// cout << "array : " << n << '\n';
				// for (int i = 1; i <= n; i++) {
				// 	cout << per[i] << " ";
				// 	cout.flush();
				// }
				// cout << "\n";
			}
		}
	}
	return 0;
}