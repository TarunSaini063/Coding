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
ll d, h, c;
ld solve(ll mid)
{
	ld curr = (mid * h + (mid - 1) * c) / (2 * mid - 1.0);
	return  (ld)d * 1.0 - curr;
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		cin >> h >> c >> d;
		if (h == d) cout << 1 << '\n';
		else if ((h + c) / 2.0 >= 1.0 * d) cout << 2 << '\n';
		else
		{
			ll low = 0;
			ll hig = 1e9;
			ll mid;
			for (int i = 0; i < 50; i++)
			{
				mid = (low + hig) / 2;
				if (solve(mid) < 0) low = mid;
				else hig = mid;
			}
			// cout << low << ' ' << hig << '\n';
			if (abs((ld)solve(low)) <= abs((ld)solve(hig)))
			{
				cout << 2 * low - 1 << '\n';
			}
			else cout << 2 * hig - 1 << '\n';
		}
	}
	return 0;
}