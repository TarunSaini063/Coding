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
	int t = 1;
	// cin>>t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int &i : a) cin >> i;
		sort(a, a + n);
		int mi = 0, mx = 0;
		int minv = -2, maxv = -2;
		for (int val : a) {
			if (minv < val - 1) {
				minv = val + 1;
				++mi;
			}
			if (maxv < val + 1) {
				maxv = max(maxv + 1, val - 1);
				++mx;
			}
		}
		cout << mi << ' ' << mx << '\n';
	}
	return 0;
}