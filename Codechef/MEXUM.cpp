#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod  998244353
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
	while (t--)
	{
		int n;
		vector<int> arr(n);
		for (auto &i : arr)cin >> i;
		sort(all(arr));
		arr.erase(unique(all(arr)) - arr.end());
		// ll ans = 1;
		int one = 0;
		int l = 1;
		int r = 1e9 + 3;
		while (l < r)
		{
			int md = l + (r - l) / 2;
			if (binary_search(all(arr), md))
			{
				one = md;
				r = md - 1;
			}
			else l = md + 1;
		}
		cout << one << "\n";
	}
	return 0;
}