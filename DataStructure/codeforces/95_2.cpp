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
		int n;
		cin >> n;
		vector<int>arr(n), lock(n), unlock, ans, order;
		for (int &i : arr)cin >> i;
		for (int &i : lock) cin >> i;
		for (int i = 0; i < n; i++) {
			if (lock[i] == 0) unlock.pb(i);
		}
		order = unlock;
		sort(all(order), [&](int a, int b) {
			return arr[a] > arr[b];
		});
		ans = arr;
		for (int i = 0; i < sz(unlock); i++) {
			ans[unlock[i]] = arr[order[i]];
		}
		for (int i : ans) cout << i << " ";
		cout << "\n";

	}
	return 0;
}
