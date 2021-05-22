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
		int m, n;
		cin >> m >> n;
		int arr[m][n];
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++) cin >> arr[i][j];
		}
		map<int, vector<int>> mp;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				mp[i + j].pb(arr[i][j]);
			}
		}
		int ans = 0;
		for (int i = 0; i <= (m + n - 3) / 2; i++)
		{
			int sz = mp[i].size();
			int o1 = 0, o2 = 0, z1 = 0, z2 = 0;
			for (int j = 0; j < sz; j++)
			{
				if (mp[i][j]) o1++;
				else z1++;
				if (mp[m + n - 2 - i][j]) o2++;
				else z2++;
			}
			ans += min(z1 + z2, o1 + o2);
		}
		cout << ans << '\n';
	}
	return 0;
}