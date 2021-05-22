#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define sz(x) (int)x.size()
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
		ll x0, x2, x1, y1, y2, y0;
		cin >> x0 >> x1 >> x2 >> y0 >> y1 >> y2;
		int m2 = min(x1, y0);
		x1 -= m2;
		int m1 = min(y1, x1);
		x1 -= m1;
		y1 -= m1;
		m2 = min(x2, y1);
		m1 = min(y2, x1);
		cout << 2 * (m2 - m1) << "\n";
	}
	return 0;
}