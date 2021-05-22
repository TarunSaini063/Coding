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
int get(int x, int dif) {
	return (x - 1) / dif;
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n, x, y, m, d;
		cin >> n >> x >> y;
		d = y - x;
		for (m = n - 1;; m--) {
			if (d % m == 0)break;
		}
		m = d / m;
		for (int i = 1; y - m > 0 && i < n; i++) y -= m;
		for (int i = 0; i < n; i++) {
			cout << y << " ";
			y += m;
		}
		cout << endl;
	}
	return 0;
}