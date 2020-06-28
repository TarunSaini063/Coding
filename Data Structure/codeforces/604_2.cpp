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
		int n, x, r, l;
		cin >> n;
		l = n + 10;
		r = -1;
		vector<pair<int, int>> v;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			v.pb(mk(x, i));
		}
		sort(all(v));
		x = 0;
		for (auto i : v)
		{
			l = min(l, i.ss);
			r = max(r, i.ss);
			if (r - l == x++) cout << 1;
			else cout << 0;
		}
		cout << "\n";
	}
	return 0;
}