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
		int n, b, m, x, ans = 0;
		cin >> n >> m >> b;
		pair<int, int> curr;
		b--;
		cin >> x;
		int l = x / m * m;
		int u = l + m - 1;
		curr = mk(l , min(n - 1, u));
		ans++;
		// cout << curr.ff << " " << curr.ss << "\n";
		while (b--)
		{
			cin >> x;
			if (x > curr.ss || x < curr.ff) {
				ans++;
				l = x / m * m;
				u = l + m - 1;
				curr = mk(l , min(n - 1, u));
				// cout << curr.ff << " " << curr.ss << "\n";

			}
		}
		cout << ans << '\n';
	}
	return 0;
}