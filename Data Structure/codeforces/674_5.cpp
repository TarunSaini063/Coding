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
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[3], b[3];
		cin >> a[0] >> a[2] >> a[1];
		cin >> b[0] >> b[2] >> b[1];
		int mx = min(a[0], b[2]) + min(a[1], b[0]) + min(a[2], b[1]);
		int mn;
		mn = min(a[0], b[1]);
		a[0] -= mn;
		mn = min(a[0], b[0]);
		a[0] -= mn;
		mn = min(a[1], b[2]);
		a[1] -= mn;
		mn = min(a[1], b[1]);
		a[1] -= mn;
		mn = min(a[2], b[0]);
		a[2] -= mn;
		mn = min(a[2], b[2]);
		a[2] -= mn;
		mn = min(a[0], b[2]) + min(a[1], b[0]) + min(a[2], b[1]);
		cout << mn << " " << mx << "\n";
	}
	return 0;
}