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
	int t = 1, ans = 0;
	// cin >> t;
	while (t--)
	{
		int n, a, b;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			a -= b;
			if (a == 0) ans++;
			else {
				ans = 0;
			}
			if (ans >= 3) break;
		}
		if (ans >= 3) cout << "Yes\n";
		else cout << "No\n";

	}
	return 0;
}