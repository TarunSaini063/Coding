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
const int mx = 2e5;
ll arr[mx + 1];
int n, q;
struct bit
{
	ll arr[mx + 2];
	void update(int i, int x)
	{
		while (i <= n)
		{
			arr[i] += x;
			i += (i & -i);
		}
	}
	ll sum(int i)
	{
		ll res = 0;
		while (i > 0)
		{
			res += arr[i];
			i -= (i & -i);
		}
		return res;
	}
} act[2], sqt[2];
void upd(int i, int x)
{
	act[i & 1].update(i, x - arr[i]);
	act[i & 1 ^ 1].update(i, arr[i] - x);
	sqt[i & 1].update(i, i * (x - arr[i]));
	sqt[i & 1 ^ 1].update(i, i * (arr[i] - x));
	arr[i] = x;
}
int main(void)
{
	FIO
	int t, x;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cout << "Case #" << i << ": ";
		cin >> n >> q;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			upd(i, x);
		}
		ll ans = 0;
		while (q--)
		{
			char c;
			cin >> c;
			if (c == 'U')
			{
				int i, x;
				cin >> i >> x;
				upd(i, x);
			}
			else
			{
				int l, r;
				cin >> l >> r;
				l--, r--;
				ans += sqt[l & 1].sum(r + 1) - sqt[l & 1].sum(l) - (l - 1) * (act[l & 1].sum(r + 1) - act[l & 1].sum(l));
			}
		}
		cout << ans << '\n';
		for (int i = 0; i < n; i++) upd(i, 0);
	}
	return 0;
}