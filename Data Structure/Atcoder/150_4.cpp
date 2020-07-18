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
ll n, m, cd = 1, c = 1;
int lcm(int a, int b)
{
	return a / __gcd(a, b) * b;
}
int main()
{
	cin >> n >> m;
	int x;
	for (int i = 1; i <= n; i++)
	{
		ll a;
		cin >> a;
		cd = lcm(cd, a);
		c = lcm(c, a / 2);
		int tmp = 0;
		while (a % 2 == 0)
		{
			tmp++;
			a /= 2;
		}
		if (i == 1)
			x = tmp;
		else if (x != tmp || c > m)
		{
			cout << 0 << endl;
			exit(0);
		}
	}
	if (m < c)
		cout << 0;
	else
		cout << ((m - c) / cd) + 1;
	return 0;
}
