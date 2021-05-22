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
bool ovr(int i, int j, int x, int y)
{
	if (i > y || j < x) return false;
	return true;
}
int get(int n, int k)
{
	// cout << n << "\n";
	return (n + k) / (k + 1);
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<pair<int, int>> arr, res, fres;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '1')
			{
				arr.pb(mk(max(0, i - k), min(i + k, n - 1)));
			}
		}
		if (arr.size() == 0)
		{
			cout << (n + k) / (k + 1) << '\n';
		}
		else {
			sort(all(arr));
			ll ans = 0;
			res.pb(arr[0]);
			for (int i = 1; i < (int)arr.size(); i++) {
				if (res.back().ss < arr[i].ff) res.push_back(arr[i]);
				else
					res.back().ss = max(res.back().ss, arr[i].ss);
			}
			int tmp[n];
			memset(tmp, 0, sizeof(tmp));
			for (auto i : res)
			{
				for (int j = i.ff; j <= i.ss; j++) tmp[j] = 1;
			}
			// for (auto i : tmp) cout << i << " ";
			// cout << '\n';
			for (int i = 0; i < n; i++)
			{
				if (tmp[i] == 0)
				{
					int j = i;
					while (j < n && tmp[j] == 0) j++;
					// cout << i << " " << j - i << "\n";
					ans += get(j - i, k);
					i = j;
				}
			}
			cout << ans << '\n';

		}
	}
	return 0;
}