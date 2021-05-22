#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define ar array
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
		int n;
		cin >> n;
		set<int> s, p;
		for (int i = 1, d; i <= n; i++)
			cin >> d, s.insert(d);
		ll lcm = 1LL * *s.begin() * *--s.end();
		for (int i = 2; 1LL * i * i <= lcm; i++)
			if (lcm % i == 0)p.insert(i), p.insert(lcm / i);
		cout << (s == p ? lcm : -1) << '\n';
	}
	return 0;
}