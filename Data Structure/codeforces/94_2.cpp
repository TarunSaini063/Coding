#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define get cin
#define out cout
#define ss second
#define se(x) (int)x.size()
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
bool fun(pair<ll, ll> p1, pair<ll, ll> p2) {
	if (p1.ff == p2.ff) {
		return p1.ss >= p2.ss;
	}
	return p1.ff < p2.ff;
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		ll p, f, sn, wn, s, w;
		get >> p >> f >> sn >> wn >> s >> w;
		vector<pair<int, int>> v;
		v.pb(mk(s, sn));
		v.pb(mk(w, wn));
		sort(all(v), fun);
		ll ans = 0;
		if (s <= w) {

		}

	}
	return 0;
}