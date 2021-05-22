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
	int t = 1;
	while (t--)
	{
		int n, fl = 1;
		cin >> n;
		vector<pair<int, int>> v;
		for (int i = 1; i <= 2 * n + 1; i++)
		{
			v.pb(mk(i, 2));
			if (i % 2 == 0) {
				v.pb(mk(i, 1));
				v.pb(mk(i, 3));
				v.pb(mk(i, 0));
				v.pb(mk(i, 4));
			}
			else
			{
				if (fl) v.pb(mk(i, 4)), fl = 0;
				else v.pb(mk(i, 0)), fl = 1;
			}
		}
		v.pb(mk(0, 2));
		v.pb(mk(0, 3));
		v.pb(mk(0, 4));
		if (n & 1) {
			v.pb(mk(2 * n + 2, 0));
			v.pb(mk(2 * n + 2, 1));
			v.pb(mk(2 * n + 2, 2));
		}
		else {
			v.pb(mk(2 * n + 2, 3));
			v.pb(mk(2 * n + 2, 4));
			v.pb(mk(2 * n + 2, 2));
		}
		cout << v.size() << '\n';
		for (auto i : v) {
			cout << i.ff << " " << i.ss << '\n';
		}
	}
	return 0;
}