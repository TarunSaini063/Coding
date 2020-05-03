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
// #ifndef ONLINE_JUDGE
// 	freopen("input1.txt", "r", stdin);
// 	freopen("output1.txt", "w", stdout);
// #endif
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> arr(n), mx(n), mn(n);
		for (auto &j : arr) cin >> j;
		mx[0] = arr[0];
		mn[n - 1] = arr[n - 1];
		ll res = 0;
		for (int i = 1; i < n; i++)
		{
			mx[i] = max(mx[i - 1], arr[i]);
			mn[n - i - 1] = min(mn[n - i], arr[n - i - 1]);
		}
		for (int i = 0; i < n; i++) res = max(res, 0ll + mx[i] - mn[i]);
		ll j = 0, curr = 0, ch = 0;
		while (ch < res)
		{
			if (curr == 0) curr = 2;
			else curr *= 2;
			ch = curr - 1;
			j++;
		}
		// cout << curr / 2 << " ";
		cout << j << "\n";
	}
	return 0;
}