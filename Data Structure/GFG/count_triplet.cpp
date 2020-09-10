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
struct tree {
	vector<int> BIT;
	int n;
	tree(int sz) {
		n = sz;
		BIT.assign(n + 1, 0);
	}
	void clear() {
		BIT.assign(n + 1, 0);
	}
	void upd(int id, int val) {
		for (++id; id <= n; id += id & -id) {
			BIT[id] += val;
		}
	}
	int qry(int id) {
		id++;
		int sum = 0;
		while (id > 0) {
			sum += BIT[id];
			id -= id & -id;
		}
		return sum;
	}
};
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int>arr(n);
		for (int &i : arr) cin >> i;
		vector<int> tmp = arr;
		sort(all(tmp));
		for (int i = 0; i < n; i++) {
			arr[i] = lower_bound(all(tmp), arr[i]) - tmp.begin() + 1;
		}
		tree fnw(n);
		vector<int>left(n), right(n);
		for (int i = n - 1; i >= 0; i--) {
			right[i] = (n - i - 1) - fnw.qry(arr[i]);
			fnw.upd(arr[i], 1);
		}
		fnw.clear();
		for (int i = 0; i < n; i++) {
			left[i] = fnw.qry(arr[i] - 1);
			fnw.upd(arr[i], 1);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) ans += left[i] * right[i];
		// cout << "\n";
		// for (int i : left) cout << i << " ";
		// cout << "\n";
		// for (int i : right) cout << i << " ";
		// cout << "\n";
		// for (int i : arr) cout << i << " ";
		// cout << "\n";
		cout << ans << "\n";

	}
	return 0;
}