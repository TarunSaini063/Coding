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
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n, x, ans = INT_MAX;
		cin >> n;
		vector<int>arr[n + 1];
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			arr[x].pb(i);
			if ((int)arr[x].size() >= 2)
			{
				ans = min(ans, arr[x].back() - arr[x][(int)arr[x].size() - 2]);
			}
		}
		if (ans == INT_MAX) ans = -2;
		cout << ans + 1 << '\n';
	}
	return 0;
}