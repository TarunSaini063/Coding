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
bool ov(int i, int j, int k, int l)
{
	if (i > l || j < k) return false;
	return true;
}
bool cmp(const pair<int, int>p1, const pair<int, int> p2)
{
	if (p1.ff != p2.ff) return p1.ff < p2.ff;
	return p1.ss <= p2.ss;
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		ll n, x, y;
		ll mn = INT_MAX	, mx = INT_MIN;
		cin >> n;
		for (ll i = 0; i < n; i++)
		{
			cin >> x >> y;
			mn = min(mn, y);
			mx = max(mx, x);
		}
		mx -= mn;
		if (mx < 0) mx = 0;
		cout << mx << '\n';

	}
	return 0;
}