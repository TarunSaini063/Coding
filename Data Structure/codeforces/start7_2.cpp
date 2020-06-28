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
		int n, m, x;
		cin >> n >> m;
		ll sm = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			sm += x;
		}
		if (m < n || (n == 2 && m == 2) || (n == 1 || m == 1)) cout << "-1\n";
		else {
			cout << 2 * sm << '\n';
			for (int i = 1; i < n; i++)
			{
				cout << i << " " << i + 1 << '\n';
			}
			cout << n << " " << 1 << '\n';
		}
	}
	return 0;
}