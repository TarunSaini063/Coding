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
		int n, s, x, d = 1000, f = 1000;
		cin >> n >> s;
		s = 100 - s;
		int pr[n];
		for (int i = 0; i < n; i++) cin >> pr[i];
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			if (x == 0) d = min(d, pr[i]);
			else f = min(f, pr[i]);
		}
		if (f + d > s)cout << "no" << '\n';
		else cout << "yes" << '\n';
	}
	return 0;
}