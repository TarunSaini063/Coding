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
//#ifndef ONLINE_JUDGE
//	freopen("input1.txt","r",stdin);
//	freopen("output1.txt","w",stdout);
//#endif
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		ll ans = b;
		if (ans >= a) cout << ans << "\n";
		else
		{
			if (c <= d) cout << -1 << "\n";
			else
			{
				ll dif = c - d;
				dif = (a - b + dif - 1) / dif;
				ans += dif * c;
				cout << ans << "\n";
			}
		}
	}
	return 0;
}