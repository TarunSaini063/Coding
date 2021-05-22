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
bool ov(int i, int j, int x, int y)
{
	if (i > y || j < x) return false;
	return true;
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, x, a, b, u, v;
		cin >> n >> x >> m;
		u = n + 1;
		v = -1;
		while (m--)
		{
			cin >> a >> b;
			if (v != -1)
			{
				if (ov(a, b, u, v))
				{
					u = min(u, a);
					v = max(v, b);
				}
			}
			else if (x >= a && x <= b)
			{
				u = a;
				v = b;
			}
		}
		if (v != -1) cout << v - u + 1 << '\n';
		else cout << 1 << '\n';
	}
	return 0;
}