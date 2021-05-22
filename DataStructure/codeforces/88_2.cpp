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
		int n, m, x, y;
		cin >> n >> m >> x >> y;
		vector<string> arr(n);
		for (auto &i : arr) cin >> i;
		int on = 0, tw = 0;
		for (auto i : arr)
		{
			for (int j = 0; j < m; j++)
			{
				if (i[j] == '.')
				{
					if (j < m - 1 && i[j + 1] == '.')
					{
						tw++;
						j++;
						continue;
					}
					else on++;
				}

			}
		}
		ll ans = x * on * 1ll + min(2 * x, y) * tw;
		cout << ans << '\n';
	}
	return 0;
}