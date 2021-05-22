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
		int n, x, ans = 0;
		cin >> n;
		ll arr[n];
		for (auto &i : arr)cin >> i;
		int m;
		cin >> m;
		ll pw[n + 1], y;
		memset(pw, 0, sizeof(pw));
		for (int i = 0; i < m; i++)
		{
			cin >> y >> x;
			pw[x] = max(pw[x], y);
		}
		for (int i = n - 1; i >= 0; i--)pw[i] = max(pw[i], pw[i + 1]);
		for (int j = 0; j < n;)
		{
			ll k, mx = arr[j];
			for (k = 1; k <= n; k++)
			{
				if (mx > pw[k]) break;
				mx = max(mx, arr[j + k]);
			}
			if (k == 1)
			{
				ans = -1;
				break;
			}
			j += k - 1;
			ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}